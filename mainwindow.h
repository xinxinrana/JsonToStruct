#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qjsonarray.h"
#include "tools.h"

#include <QMainWindow>
#include <QJsonValue>
#include <QMap>
#include <QList>
#include <QRegularExpression>
#include <QJsonObject>


struct Address{

    QString city;

    QString postalCode;

    QString state;

    QString street;

    void operator<<(const QJsonObject& json){
        city = json.value("city").toString();
        postalCode = json.value("postalCode").toString();
        state = json.value("state").toString();
        street = json.value("street").toString();
    }
};

struct PhoneNumbers{

    QString number;

    QString type;

    void operator<<(const QJsonObject& json){
        number = json.value("number").toString();
        type = json.value("type").toString();
    }
};

struct Users{

    Address address;

    double age;

    QString email;

    double id;

    QString name;

    QList<PhoneNumbers> phoneNumbersList;

    void operator<<(const QJsonObject& json){
        address << json.value("address").toObject();
        age = json.value("age").toDouble();
        email = json.value("email").toString();
        id = json.value("id").toDouble();
        name = json.value("name").toString();
        const auto& arr = json.value("phoneNumbers").toArray();
        for(const auto& item : arr){
            PhoneNumbers i;
            i << item.toObject();
            phoneNumbersList << i;
        }
    }
};

struct MainStruct{

    QList<Users> usersList;

    void operator<<(const QJsonObject& json){
        const auto& arr = json.value("users").toArray();
        for(const auto& item : arr){
            Users i;
            i << item.toObject();
            usersList << i;
        }
    }
};


// ============================

class QJsonObject;


struct StructTemplate
{
    StructTemplate() {}
    QList<std::tuple<QJsonValue::Type,QString>> data;
    QString thiskey;


    QString toString()const {
        QString rData;
        rData += "struct ";
        rData += thiskey + "{\n\n";
        for(auto item: data){
            const auto& jsonType = std::get<0>(item);
            const auto& name = std::get<1>(item);

            QString itemType,itemName;

            if(jsonType == QJsonValue::Object){
                itemType = Tools::toUpperCaseCamelCase(name);
                itemName = Tools::toLowerCaseCamelCase(name);
            }
            else if(jsonType == QJsonValue::Array){
                itemType = Tools::toUpperCaseCamelCase(name);
                itemName = name + "List";
                itemType = QString("QList<%1>").arg(itemType);
            }else{
                itemType = JsonTypeToQType(jsonType);
                itemName = name;
            }

            rData += "\t";
            rData += itemType + " " + itemName + ";\n\n";
        }
        rData += funcFormJson() += "\n";
        rData += "};";

        return rData;
    }


    QString funcFormJson()const{
        QString rData;
        rData += "void operator<<(const QJsonObject& json){ \n";
        for(auto item : data){
            rData += "\t";
            const auto& jsonType = std::get<0>(item);
            const auto& name = std::get<1>(item);

            QString subStr;
            if(jsonType == QJsonValue::Object){
                subStr += name + QString(" << json.value(\"%0\").toObject();").arg(name);
            }
            else if(jsonType == QJsonValue::Array){

                auto itemType = Tools::toUpperCaseCamelCase(name);
                subStr += QString("const auto& arr = json.value(\"%0\").toArray();\n").arg(name);
                subStr += QString("for(const auto& item : arr){ \n");
                subStr += itemType + QString(" i; \n");
                subStr += QString("i << item.toObject(); \n");
                subStr += QString("%1 << i; \n}").arg(name+"List");
            }
            else{
                subStr += name + QString(" = json.value(\"%0\").to%1();")
                                    .arg(name)
                                    .arg(JsonTypeToConvertType(jsonType));
            }
            rData += subStr + "\n";
        }
        rData += "}";

        return rData;
    }


//tools
    // 字符串"QList<Type>"中提取出"Type"
    QString extractTypeFromQListString(const QString& str)const {
        QRegularExpression re("QList<(\\w+)>"); // 定义正则表达式：QList<(\w+)>
        QRegularExpressionMatch match = re.match(str); // 进行匹配
        if (match.hasMatch()) {
            return match.captured(1); // 提取并返回第一个捕获组（即"Type"）
        } else {
            return QString(); // 如果没有匹配到，则返回空字符串
        }
    }

    QString JsonTypeToQType(QJsonValue::Type type) const {

        QMap<QJsonValue::Type,QString> map;
        map.insert(static_cast<QJsonValue::Type>(-1),"int");
        map.insert(QJsonValue::Null,"Null");
        map.insert(QJsonValue::Bool,"bool");
        map.insert(QJsonValue::Double,"double");
        map.insert(QJsonValue::String,"QString");
        map.insert(QJsonValue::Array,"QList");
        map.insert(QJsonValue::Object,"Object");
        map.insert(QJsonValue::Undefined,"Undefined");

        return map.value(type);
    }

    QString JsonTypeToConvertType(QJsonValue::Type type) const {

        QMap<QJsonValue::Type,QString> map;
        map.insert(static_cast<QJsonValue::Type>(-1),"Int");
        map.insert(QJsonValue::Null,"String");
        map.insert(QJsonValue::Bool,"Bool");
        map.insert(QJsonValue::Double,"Double");
        map.insert(QJsonValue::String,"String");
        map.insert(QJsonValue::Array,"Array");
        map.insert(QJsonValue::Object,"Object");
        map.insert(QJsonValue::Undefined,"String");

        return map.value(type);
    }
};



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    void extracted(QJsonObject &obj, QString &rData);
    void getQtTypeTreeFromJsonObj(const QJsonObject &obj, const QString &thiskey = "");

private:
    Ui::MainWindow *ui;

    QList<StructTemplate> m_structTemplates;
};
#endif // MAINWINDOW_H
