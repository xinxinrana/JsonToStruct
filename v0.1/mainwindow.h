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
#include <ctime>


#if 1




#endif

// ============================

class QJsonObject;


struct StructTemplate
{
    StructTemplate() {qsrand(static_cast<uint>(qrand() + time(nullptr))); }
    int thisDataKeyLenMax= -1;      // 参数名最长是（梅花对齐）

    // Json 类型 ，json key ，Qt 中的名字
    QList<std::tuple<QJsonValue::Type,QString,QString>> data;
    QMap<QString,QJsonValue::Type> arraySubType;
    QMap<QString,int> arrayNestedLayers ;
    QString thiskey;    // obj 的名字，对应结构体名称

    QString randomSuffix = QString("_") + QString::number(qrand());    // 解决相同名字问题
    bool randomSuffixEnable = true;



    QString toString()const {
        QString rData;
        rData += "struct ";
        rData += thiskey + "{\n\n";
        for(auto item: data){
            const auto& jsonType = std::get<0>(item);
            const auto& name = std::get<1>(item);

            if(randomSuffixEnable){
                auto& cName = const_cast<QString&>(name);
                cName = std::get<2>(item);
            }

            QString itemType,itemName;

            if(jsonType == QJsonValue::Object){
                itemType = Tools::toUpperCaseCamelCase(name);
                itemName = Tools::toLowerCaseCamelCase(name);
            }
            else if(jsonType == QJsonValue::Array){

                if(arrayNestedLayers.contains(name)){
                    auto lay = arrayNestedLayers.value(name);
                    auto InnerLayerType = JsonTypeToQType(arraySubType.value(name));
                    QString subType = "%1";
                    for(int i = 0 ; i < lay ; ++i){
                        subType = subType.arg("QList<%1>");
                    }

                    if(arraySubType.value(name) == QJsonValue::Object){
                        itemType = subType.arg(Tools::toUpperCaseCamelCase(name));
                    }else{
                        itemType = subType.arg(InnerLayerType);
                    }
                }
                else if(arraySubType.value(name) == QJsonValue::Object){
                    itemType = Tools::toUpperCaseCamelCase(name);
                }
                else{
                    itemType = JsonTypeToQType(arraySubType.value(name));
                }

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
        QString table = "\t";
        rData += table + "void operator<<(const QJsonObject& json){ \n\n";

        table += "\t";
        for(auto item : data){

            const auto jsonType = std::get<0>(item);
            const auto name = std::get<1>(item);
            const auto qName = std::get<1>(item);

            if(randomSuffixEnable){
                const_cast<QString&>(qName) = std::get<2>(item);
            }


            QString subStr;

            if(jsonType == QJsonValue::Object){
                subStr += table + qName + QString(thisDataKeyLenMax-name.length(),' ')
                          + QString(" << json.value(\"%0\").toObject();").arg(name);
            }
            else if(jsonType == QJsonValue::Array){

                auto itemType = Tools::toUpperCaseCamelCase(qName);
                subStr += "\n";
                subStr += table + QString("const auto& arr%0 = json.value(\"%0\").toArray();\n").arg(name);
                subStr += table + QString("for(const auto& item : arr%0){ \n").arg(name);
                table  += "\t";
                if(arrayNestedLayers.contains(qName)){
                    // TODO 主要解决   像 QList<QList<QList<QString>>> 的赋值问题；
                    // 暂时先不管 过编译为主
                    auto lay = arrayNestedLayers.value(qName);
                    auto InnerLayerType = JsonTypeToQType(arraySubType.value(qName));
                    QString subType = "%1";
                    for(int i = 1 ; i < lay ; ++i){
                        subType = subType.arg("QList<%1>");
                    }

                    if(arraySubType.value(qName) == QJsonValue::Object){
                        itemType = subType.arg(Tools::toUpperCaseCamelCase(name));
                    }else{
                        itemType = subType.arg(InnerLayerType);
                    }

                    subStr += table + itemType + QString(" i; \n");
                }
                else if(arraySubType.value(qName) ==  QJsonValue::Object){
                    subStr += table + itemType + QString(" i; \n");
                    subStr += table + QString("i << item.toObject(); \n");
                }else{
                    subStr += table + JsonTypeToQType(arraySubType.value(qName)) + QString(" i; \n");
                    subStr += table + QString("i = item.to%1(); \n").arg(JsonTypeToConvertType(arraySubType.value(qName)));
                }

                subStr += table + QString("%1 << i; \n").arg(qName+"List");
                table.remove(table.count()-1,1);
                subStr += table + QString("}");

            }
            else{
                subStr += table + qName + QString(thisDataKeyLenMax-name.length() + 1 ,' ');
                subStr += QString("= json.value(\"%0\").to%1();")
                                    .arg(name)
                                    .arg(JsonTypeToConvertType(jsonType));
            }
            rData += subStr + "\n";
        }
        table.remove(table.count()-1,1);
        rData += table + "}";

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
        map.insert(QJsonValue::Null,"QVariant");
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
    void getQtTypeTreeFromJsonObj(const QJsonObject &obj, const QString &thiskey = "");

private:
    Ui::MainWindow *ui;

    QList<StructTemplate> m_structTemplates;
};
#endif // MAINWINDOW_H
