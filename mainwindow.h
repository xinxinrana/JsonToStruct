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
struct Methods_29788{

    void operator<<(const QJsonObject& json){

    }
};

struct Delete_6069{

    QString href_29788;

    QList<Methods_29788> methods_29788List;

    void operator<<(const QJsonObject& json){

        href_29788          = json.value("href").toString();

        const auto& arrmethods = json.value("methods").toArray();
        for(const auto& item : arrmethods){
            Methods_29788 i;
            i << item.toObject();
            methods_29788List << i;
        }
    }
};

struct Methods_27883{

    void operator<<(const QJsonObject& json){

    }
};

struct Self_6069{

    QString href_27883;

    QList<Methods_27883> methods_27883List;

    void operator<<(const QJsonObject& json){

        href_27883          = json.value("href").toString();

        const auto& arrmethods = json.value("methods").toArray();
        for(const auto& item : arrmethods){
            Methods_27883 i;
            i << item.toObject();
            methods_27883List << i;
        }
    }
};

struct Methods_18582{

    void operator<<(const QJsonObject& json){

    }
};

struct Update_6069{

    QString href_18582;

    QList<Methods_18582> methods_18582List;

    void operator<<(const QJsonObject& json){

        href_18582          = json.value("href").toString();

        const auto& arrmethods = json.value("methods").toArray();
        for(const auto& item : arrmethods){
            Methods_18582 i;
            i << item.toObject();
            methods_18582List << i;
        }
    }
};

struct _links_41{

    Self_6069 self_6069;

    Delete_6069 delete_6069;

    Update_6069 update_6069;

    void operator<<(const QJsonObject& json){

        self_6069        << json.value("self").toObject();
        delete_6069      << json.value("delete").toObject();
        update_6069      << json.value("update").toObject();
    }
};

struct _meta_41{

    int perPage_6361;

    int version_6361;

    QString selfLink_6361;

    QVariant nextLink_6361;

    QString lastLink_6361;

    QString firstLink_6361;

    int totalItems_6361;

    int totalPages_6361;

    int currentPage_6361;

    QVariant previousLink_6361;

    void operator<<(const QJsonObject& json){

        perPage_6361           = json.value("perPage").toInt();
        version_6361           = json.value("version").toInt();
        selfLink_6361          = json.value("selfLink").toString();
        nextLink_6361          = json.value("nextLink").toString();
        lastLink_6361          = json.value("lastLink").toString();
        firstLink_6361         = json.value("firstLink").toString();
        totalItems_6361        = json.value("totalItems").toInt();
        totalPages_6361        = json.value("totalPages").toInt();
        currentPage_6361       = json.value("currentPage").toInt();
        previousLink_6361      = json.value("previousLink").toString();
    }
};

struct Departments_17751{

    QString head_30324;

    QString name_30324;

    void operator<<(const QJsonObject& json){

        head_30324       = json.value("head").toString();
        name_30324       = json.value("name").toString();
    }
};

struct Employees_17751{

    int id_15237;

    QString role_15237;

    QString name_15237;

    int salary_15237;

    void operator<<(const QJsonObject& json){

        id_15237           = json.value("id").toInt();
        role_15237         = json.value("role").toString();
        name_15237         = json.value("name").toString();
        salary_15237       = json.value("salary").toInt();
    }
};

struct Company_41{

    QString name_17751;

    QList<Employees_17751> employees_17751List;

    QList<Departments_17751> departments_17751List;

    void operator<<(const QJsonObject& json){

        name_17751              = json.value("name").toString();

        const auto& arremployees = json.value("employees").toArray();
        for(const auto& item : arremployees){
            Employees_17751 i;
            i << item.toObject();
            employees_17751List << i;
        }

        const auto& arrdepartments = json.value("departments").toArray();
        for(const auto& item : arrdepartments){
            Departments_17751 i;
            i << item.toObject();
            departments_17751List << i;
        }
    }
};

struct Field3_10607{

    QString subField1_23465;

    QString subField2_23465;

    void operator<<(const QJsonObject& json){

        subField1_23465       = json.value("subField1").toString();
        subField2_23465       = json.value("subField2").toString();
    }
};

struct CustomFields_41{

    QString field1_10607;

    QString field2_10607;

    Field3_10607 field3_10607;

    void operator<<(const QJsonObject& json){

        field1_10607       = json.value("field1").toString();
        field2_10607       = json.value("field2").toString();
        field3_10607       << json.value("field3").toObject();
    }
};

struct Notes_41{

    void operator<<(const QJsonObject& json){

    }
};

struct Address_21754{

    QString city_13223;

    QString state_13223;

    QString street_13223;

    QString country_13223;

    QString postalCode_13223;

    void operator<<(const QJsonObject& json){

        city_13223             = json.value("city").toString();
        state_13223            = json.value("state").toString();
        street_13223           = json.value("street").toString();
        country_13223          = json.value("country").toString();
        postalCode_13223       = json.value("postalCode").toString();
    }
};

struct FamilyMembers_21754{

    QString name_28443;

    QString relation_28443;

    void operator<<(const QJsonObject& json){

        name_28443           = json.value("name").toString();
        relation_28443       = json.value("relation").toString();
    }
};

struct Hobbies_21754{

    void operator<<(const QJsonObject& json){

    }
};

struct PhoneNumbers_21754{

    QString type_9722;

    QString number_9722;

    void operator<<(const QJsonObject& json){

        type_9722        = json.value("type").toString();
        number_9722      = json.value("number").toString();
    }
};

struct Person_41{

    int age_21754;

    QString name_21754;

    QString email_21754;

    QList<Hobbies_21754> hobbies_21754List;

    Address_21754 address_21754;

    bool isMarried_21754;

    QList<PhoneNumbers_21754> phoneNumbers_21754List;

    QList<FamilyMembers_21754> familyMembers_21754List;

    void operator<<(const QJsonObject& json){

        age_21754                 = json.value("age").toInt();
        name_21754                = json.value("name").toString();
        email_21754               = json.value("email").toString();

        const auto& arrhobbies = json.value("hobbies").toArray();
        for(const auto& item : arrhobbies){
            Hobbies_21754 i;
            i << item.toObject();
            hobbies_21754List << i;
        }
        address_21754             << json.value("address").toObject();
        isMarried_21754           = json.value("isMarried").toBool();

        const auto& arrphoneNumbers = json.value("phoneNumbers").toArray();
        for(const auto& item : arrphoneNumbers){
            PhoneNumbers_21754 i;
            i << item.toObject();
            phoneNumbers_21754List << i;
        }

        const auto& arrfamilyMembers = json.value("familyMembers").toArray();
        for(const auto& item : arrfamilyMembers){
            FamilyMembers_21754 i;
            i << item.toObject();
            familyMembers_21754List << i;
        }
    }
};

struct Product_2237{

    QString name_13745;

    int price_13745;

    int quantity_13745;

    void operator<<(const QJsonObject& json){

        name_13745           = json.value("name").toString();
        price_13745          = json.value("price").toInt();
        quantity_13745       = json.value("quantity").toInt();
    }
};

struct Transactions_41{

    int id_2237;

    QString type_2237;

    QString date_2237;

    int amount_2237;

    Product_2237 product_2237;

    void operator<<(const QJsonObject& json){

        id_2237           = json.value("id").toInt();
        type_2237         = json.value("type").toString();
        date_2237         = json.value("date").toString();
        amount_2237       = json.value("amount").toInt();
        product_2237      << json.value("product").toObject();
    }
};

struct MainStruct{

    QList<Notes_41> notes_41List;

    _meta_41 _meta_41;

    Person_41 person_41;

    _links_41 _links_41;

    Company_41 company_41;

    bool isActive_41;

    QString updatedAt_41;

    QString createdAt_41;

    QList<Transactions_41> transactions_41List;

    CustomFields_41 customFields_41;

    void operator<<(const QJsonObject& json){


        const auto& arrnotes = json.value("notes").toArray();
        for(const auto& item : arrnotes){
            Notes_41 i;
            i << item.toObject();
            notes_41List << i;
        }
        _meta_41           << json.value("_meta").toObject();
        person_41          << json.value("person").toObject();
        _links_41          << json.value("_links").toObject();
        company_41         << json.value("company").toObject();
        isActive_41        = json.value("isActive").toBool();
        updatedAt_41       = json.value("updatedAt").toString();
        createdAt_41       = json.value("createdAt").toString();

        const auto& arrtransactions = json.value("transactions").toArray();
        for(const auto& item : arrtransactions){
            Transactions_41 i;
            i << item.toObject();
            transactions_41List << i;
        }
        customFields_41    << json.value("customFields").toObject();
    }
};



#endif

// ============================

class QJsonObject;


struct StructTemplate
{
    StructTemplate() {qsrand(static_cast<uint>(qrand() + time(nullptr))); }
    int thisDataKeyLenMax= -1;
    QList<std::tuple<QJsonValue::Type,QString,QString>> data;
    QString thiskey;

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
                subStr += table + itemType + QString(" i; \n");
                subStr += table + QString("i << item.toObject(); \n");
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
