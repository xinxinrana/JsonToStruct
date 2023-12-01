#ifndef STRUCTTEST_H
#define STRUCTTEST_H


#include <QString>
#include <QList>
#include <QJsonObject>
#include <QJsonArray>


struct Delete_21793{

    QString href_22115;

    QList<QString> methods_22115List;

    void operator<<(const QJsonObject& json){

        href_22115          = json.value("href").toString();

        const auto& arrmethods = json.value("methods").toArray();
        for(const auto& item : arrmethods){
            QString i;
            i = item.toString();
            methods_22115List << i;
        }
    }
};

struct Self_21793{

    QString href_31273;

    QList<QString> methods_31273List;

    void operator<<(const QJsonObject& json){

        href_31273          = json.value("href").toString();

        const auto& arrmethods = json.value("methods").toArray();
        for(const auto& item : arrmethods){
            QString i;
            i = item.toString();
            methods_31273List << i;
        }
    }
};

struct Update_21793{

    QString href_5097;

    QList<QString> methods_5097List;

    void operator<<(const QJsonObject& json){

        href_5097         = json.value("href").toString();

        const auto& arrmethods = json.value("methods").toArray();
        for(const auto& item : arrmethods){
            QString i;
            i = item.toString();
            methods_5097List << i;
        }
    }
};

struct _links_41{

    Self_21793 self_21793;

    Delete_21793 delete_21793;

    Update_21793 update_21793;

    void operator<<(const QJsonObject& json){

        self_21793         << json.value("self").toObject();
        delete_21793       << json.value("delete").toObject();
        update_21793       << json.value("update").toObject();
    }
};

struct _meta_41{

    int perPage_6921;

    int version_6921;

    QString selfLink_6921;

    QVariant nextLink_6921;

    QString lastLink_6921;

    QString firstLink_6921;

    int totalItems_6921;

    int totalPages_6921;

    int currentPage_6921;

    QVariant previousLink_6921;

    void operator<<(const QJsonObject& json){

        perPage_6921           = json.value("perPage").toInt();
        version_6921           = json.value("version").toInt();
        selfLink_6921          = json.value("selfLink").toString();
        nextLink_6921          = json.value("nextLink").toString();
        lastLink_6921          = json.value("lastLink").toString();
        firstLink_6921         = json.value("firstLink").toString();
        totalItems_6921        = json.value("totalItems").toInt();
        totalPages_6921        = json.value("totalPages").toInt();
        currentPage_6921       = json.value("currentPage").toInt();
        previousLink_6921      = json.value("previousLink").toString();
    }
};

struct Departments_3993{

    QString head_20921;

    QString name_20921;

    void operator<<(const QJsonObject& json){

        head_20921       = json.value("head").toString();
        name_20921       = json.value("name").toString();
    }
};

struct Employees_3993{

    int id_25579;

    QString role_25579;

    QString name_25579;

    int salary_25579;

    void operator<<(const QJsonObject& json){

        id_25579           = json.value("id").toInt();
        role_25579         = json.value("role").toString();
        name_25579         = json.value("name").toString();
        salary_25579       = json.value("salary").toInt();
    }
};

struct Company_41{

    QString name_3993;

    QList<QVariant> employees_3993List;

    QList<QVariant> departments_3993List;

    void operator<<(const QJsonObject& json){

        name_3993             = json.value("name").toString();

        const auto& arremployees = json.value("employees").toArray();
        for(const auto& item : arremployees){
            QVariant i;
            i = item.toString();
            employees_3993List << i;
        }

        const auto& arrdepartments = json.value("departments").toArray();
        for(const auto& item : arrdepartments){
            QVariant i;
            i = item.toString();
            departments_3993List << i;
        }
    }
};

struct Field3_7557{

    QString subField1_32760;

    QString subField2_32760;

    void operator<<(const QJsonObject& json){

        subField1_32760       = json.value("subField1").toString();
        subField2_32760       = json.value("subField2").toString();
    }
};

struct CustomFields_41{

    QString field1_7557;

    QString field2_7557;

    Field3_7557 field3_7557;

    void operator<<(const QJsonObject& json){

        field1_7557      = json.value("field1").toString();
        field2_7557      = json.value("field2").toString();
        field3_7557      << json.value("field3").toObject();
    }
};

struct Address_31566{

    QString city_1806;

    QString state_1806;

    QString street_1806;

    QString country_1806;

    QString postalCode_1806;

    void operator<<(const QJsonObject& json){

        city_1806            = json.value("city").toString();
        state_1806           = json.value("state").toString();
        street_1806          = json.value("street").toString();
        country_1806         = json.value("country").toString();
        postalCode_1806      = json.value("postalCode").toString();
    }
};

struct FamilyMembers_31566{

    QString name_6280;

    QString relation_6280;

    void operator<<(const QJsonObject& json){

        name_6280          = json.value("name").toString();
        relation_6280      = json.value("relation").toString();
    }
};

struct PhoneNumbers_31566{

    QString type_5580;

    QString number_5580;

    void operator<<(const QJsonObject& json){

        type_5580        = json.value("type").toString();
        number_5580      = json.value("number").toString();
    }
};

struct Person_41{

    int age_31566;

    QString name_31566;

    QString email_31566;

    QList<QString> hobbies_31566List;

    Address_31566 address_31566;

    bool isMarried_31566;

    QList<QVariant> phoneNumbers_31566List;

    QList<QVariant> familyMembers_31566List;

    void operator<<(const QJsonObject& json){

        age_31566                 = json.value("age").toInt();
        name_31566                = json.value("name").toString();
        email_31566               = json.value("email").toString();

        const auto& arrhobbies = json.value("hobbies").toArray();
        for(const auto& item : arrhobbies){
            QString i;
            i = item.toString();
            hobbies_31566List << i;
        }
        address_31566             << json.value("address").toObject();
        isMarried_31566           = json.value("isMarried").toBool();

        const auto& arrphoneNumbers = json.value("phoneNumbers").toArray();
        for(const auto& item : arrphoneNumbers){
            QVariant i;
            i = item.toString();
            phoneNumbers_31566List << i;
        }

        const auto& arrfamilyMembers = json.value("familyMembers").toArray();
        for(const auto& item : arrfamilyMembers){
            QVariant i;
            i = item.toString();
            familyMembers_31566List << i;
        }
    }
};

struct Product_32607{

    QString name_21992;

    int price_21992;

    int quantity_21992;

    void operator<<(const QJsonObject& json){

        name_21992           = json.value("name").toString();
        price_21992          = json.value("price").toInt();
        quantity_21992       = json.value("quantity").toInt();
    }
};

struct Transactions_41{

    int id_32607;

    QString type_32607;

    QString date_32607;

    int amount_32607;

    Product_32607 product_32607;

    void operator<<(const QJsonObject& json){

        id_32607            = json.value("id").toInt();
        type_32607          = json.value("type").toString();
        date_32607          = json.value("date").toString();
        amount_32607        = json.value("amount").toInt();
        product_32607       << json.value("product").toObject();
    }
};

struct MainStruct{

    QList<QString> notes_41List;

    _meta_41 _meta_41;

    Person_41 person_41;

    _links_41 _links_41;

    Company_41 company_41;

    bool isActive_41;

    QString updatedAt_41;

    QString createdAt_41;

    QList<QVariant> transactions_41List;

    CustomFields_41 customFields_41;

    void operator<<(const QJsonObject& json){


        const auto& arrnotes = json.value("notes").toArray();
        for(const auto& item : arrnotes){
            QString i;
            i = item.toString();
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
            QVariant i;
            i = item.toString();
            transactions_41List << i;
        }
        customFields_41    << json.value("customFields").toObject();
    }
};




#endif


//#endif // STRUCTTEST_H
