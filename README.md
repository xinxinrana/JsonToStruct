# JsonToStruct
Generate Qt Struct code snippets and constructors from Json files【从Json文件生成Qt结构代码片段和构造函数】

解决后端写一个复杂 json 后 Qt端调用不方便的问题。

生成效果如下：
```c++
struct Address_22551{

	QString city_18706;

	QString state_18706;

	QString street_18706;

	QString postalCode_18706;

	void operator<<(const QJsonObject& json){ 

		city_18706             = json.value("city").toString();
		state_18706            = json.value("state").toString();
		street_18706           = json.value("street").toString();
		postalCode_18706       = json.value("postalCode").toString();
	}
};

struct PhoneNumbers_22551{

	QString type_2041;

	QString number_2041;

	void operator<<(const QJsonObject& json){ 

		type_2041        = json.value("type").toString();
		number_2041      = json.value("number").toString();
	}
};

struct Users_41{

	int id_22551;

	int age_22551;

	QString name_22551;

	QString email_22551;

	Address_22551 address_22551;

	QList<PhoneNumbers_22551> phoneNumbers_22551List;

	void operator<<(const QJsonObject& json){ 

		id_22551                 = json.value("id").toInt();
		age_22551                = json.value("age").toInt();
		name_22551               = json.value("name").toString();
		email_22551              = json.value("email").toString();
		address_22551            << json.value("address").toObject();

		const auto& arrphoneNumbers = json.value("phoneNumbers").toArray();
		for(const auto& item : arrphoneNumbers){ 
			PhoneNumbers_22551 i; 
			i << item.toObject(); 
			phoneNumbers_22551List << i; 
		}
	}
};

struct MainStruct{

	QList<Users_41> users_41List;

	void operator<<(const QJsonObject& json){ 


		const auto& arrusers = json.value("users").toArray();
		for(const auto& item : arrusers){ 
			Users_41 i; 
			i << item.toObject(); 
			users_41List << i; 
		}
	}
};


```
```json
测试的Json
{
  "users": [
    {
      "id": 1,
      "name": "John Doe",
      "email": "john@example.com",
      "age": 30,
      "address": {
        "street": "123 Main St",
        "city": "New York",
        "state": "NY",
        "postalCode": "10001"
      },
      "phoneNumbers": [
        {
          "type": "home",
          "number": "555-1234"
        },
        {
          "type": "work",
          "number": "555-5678"
        }
      ]
    },
    {
      "id": 2,
      "name": "Jane Smith",
      "email": "jane@example.com",
      "age": 25,
      "address": {
        "street": "456 Elm St",
        "city": "San Francisco",
        "state": "CA",
        "postalCode": "94101"
      },
      "phoneNumbers": [
        {
          "type": "home",
          "number": "555-9876"
        },
        {
          "type": "mobile",
          "number": "555-4321"
        }
      ]
    }
  ]
}
```

![image](https://github.com/xinxinrana/JsonToStruct/assets/102397752/34da9926-3f52-486f-bcd6-8a7d6fec4ca0)

复杂Json ：

```json

{
    "_links": {
        "delete": {
            "href": "/api/v1/complex-data/12345",
            "methods": [
                "DELETE"
            ]
        },
        "self": {
            "href": "/api/v1/complex-data/12345",
            "methods": [
                "GET"
            ]
        },
        "update": {
            "href": "/api/v1/complex-data/12345",
            "methods": [
                "PUT"
            ]
        }
    },
    "_meta": {
        "currentPage": 1,
        "firstLink": "/api/v1/complex-data?page=1&perPage=10",
        "lastLink": "/api/v1/complex-data?page=",
        "nextLink": null,
        "perPage": 10,
        "previousLink": null,
        "selfLink": "/api/v1/complex-data?page=1&perPage=10",
        "totalItems": 3,
        "totalPages": 1,
        "version": 1,
        "testTheList":[
            [["s1","s2"],["s12","s21"]],[["s222","sxxx"],["s12","sc"]]
        ],
        "testTheList2":[
            [{"key":1,"key2":true},{"key":1,"key2":false}],[{"key":100,"key2":true},{"key":20,"key2":false}]
        ]
    },
    "company": {
        "departments": [
            {
                "head": "Alice",
                "name": "Engineering"
            },
            {
                "head": "Bob",
                "name": "Management"
            }
        ],
        "employees": [
            {
                "id": 1,
                "name": "Alice",
                "role": "Engineer",
                "salary": 100000
            },
            {
                "id": 2,
                "name": "Bob",
                "role": "Manager",
                "salary": 120000
            }
        ],
        "name": "Example Corp"
    },
    "createdAt": "2023-05-23T10:00:00Z",
    "customFields": {
        "field1": "value1",
        "field2": "value2",
        "field3": {
            "subField1": "subValue1",
            "subField2": "subValue2"
        }
    },
    "isActive": true,
    "notes": [
        "This is a complex JSON file example."
    ],
    "person": {
        "address": {
            "city": "Anytown",
            "country": "USA",
            "postalCode": "12345",
            "state": "CA",
            "street": "123 Main St"
        },
        "age": 30,
        "email": "johndoe@example.com",
        "familyMembers": [
            {
                "name": "Jane Doe",
                "relation": "spouse"
            },
            {
                "name": "Baby Doe",
                "relation": "child"
            }
        ],
        "hobbies": [
            "reading",
            "traveling"
        ],
        "isMarried": false,
        "name": "John Doe",
        "phoneNumbers": [
            {
                "number": "555-1234",
                "type": "home"
            },
            {
                "number": "555-5678",
                "type": "work"
            }
        ]
    },
    "transactions": [
        {
            "amount": 100,
            "date": "2023-01-01",
            "id": 1,
            "product": {
                "name": "Product A",
                "price": 100,
                "quantity": 1
            },
            "type": "purchase"
        },
        {
            "amount": 200,
            "date": "2023-01-02",
            "id": 2,
            "product": {
                "name": "Product B",
                "price": 200,
                "quantity": 1
            },
            "type": "refund"
        }
    ],
    "updatedAt": "2023-05-23T11:00:00Z"
}

```

结果（还有部分没实现）：

```C++
#ifndef STRUCTTEST_H
#define STRUCTTEST_H


#include <QString>
#include <QList>
#include <QJsonObject>
#include <QJsonArray>


template <typename T>
void setArray(T& arr,const QJsonArray& data)
{
    auto item = arr.value(0);
    for(int i = 0 ; i < data.count() ; ++i){
        auto curItem = item;
        setData(curItem ,data.at(i));
        arr.append(curItem);
    }
}

template <typename T>
void setData(T& arr,const QJsonValue& data){
    setArray(arr , data.toArray());
}

void setData(QString& arr,const QJsonValue& data){
    arr = data.toString();
}



struct Delete_28097{

    QString href_21089;

    QList<QString> methods_21089List;

    void operator<<(const QJsonObject& json){

        href_21089          = json.value("href").toString();

        const auto& arrmethods = json.value("methods").toArray();
        for(const auto& item : arrmethods){
            QString i;
            i = item.toString();
            methods_21089List << i;
        }
    }
};

struct Self_28097{

    QString href_29550;

    QList<QString> methods_29550List;

    void operator<<(const QJsonObject& json){

        href_29550          = json.value("href").toString();

        const auto& arrmethods = json.value("methods").toArray();
        for(const auto& item : arrmethods){
            QString i;
            i = item.toString();
            methods_29550List << i;
        }
    }
};

struct Update_28097{

    QString href_17536;

    QList<QString> methods_17536List;

    void operator<<(const QJsonObject& json){

        href_17536          = json.value("href").toString();

        const auto& arrmethods = json.value("methods").toArray();
        for(const auto& item : arrmethods){
            QString i;
            i = item.toString();
            methods_17536List << i;
        }
    }
};

struct Temp_links_41{

    Self_28097 self_28097;

    Delete_28097 delete_28097;

    Update_28097 update_28097;

    void operator<<(const QJsonObject& json){

        self_28097         << json.value("self").toObject();
        delete_28097       << json.value("delete").toObject();
        update_28097       << json.value("update").toObject();
    }
};

struct TestTheList2_9551{

    int key_1076;

    bool key2_1076;

    void operator<<(const QJsonObject& json){

        key_1076       = json.value("key").toInt();
        key2_1076      = json.value("key2").toBool();
    }
};


void setData(TestTheList2_9551& arr,const QJsonValue& data){
    arr << data.toObject();
}

struct Temp_meta_41{

    int version_9551;

    int perPage_9551;

    QVariant nextLink_9551;

    QString selfLink_9551;

    QString lastLink_9551;

    QString firstLink_9551;

    int totalItems_9551;

    int totalPages_9551;

    int currentPage_9551;

    QList<QList<QList<QString>>> testTheList_9551List;

    QVariant previousLink_9551;

    QList<QList<TestTheList2_9551>> testTheList2_9551List;

    void operator<<(const QJsonObject& json){

        version_9551           = json.value("version").toInt();
        perPage_9551           = json.value("perPage").toInt();
        nextLink_9551          = json.value("nextLink").toString();
        selfLink_9551          = json.value("selfLink").toString();
        lastLink_9551          = json.value("lastLink").toString();
        firstLink_9551         = json.value("firstLink").toString();
        totalItems_9551        = json.value("totalItems").toInt();
        totalPages_9551        = json.value("totalPages").toInt();
        currentPage_9551       = json.value("currentPage").toInt();
        previousLink_9551      = json.value("previousLink").toString();


        // 目标：
        // arrtestTheList ->  QList<QList<QList<QString>>>

        const auto& arrtestTheList = json.value("testTheList").toArray();
        setArray(testTheList_9551List,arrtestTheList);
        const auto& arrtestTheList2 = json.value("testTheList2").toArray();
        setArray(testTheList2_9551List,arrtestTheList2);
    }
};

struct Departments_27623{

    QString head_26420;

    QString name_26420;

    void operator<<(const QJsonObject& json){

        head_26420       = json.value("head").toString();
        name_26420       = json.value("name").toString();
    }
};

struct Employees_27623{

    int id_31177;

    QString role_31177;

    QString name_31177;

    int salary_31177;

    void operator<<(const QJsonObject& json){

        id_31177           = json.value("id").toInt();
        role_31177         = json.value("role").toString();
        name_31177         = json.value("name").toString();
        salary_31177       = json.value("salary").toInt();
    }
};

struct Company_41{

    QString name_27623;

    QList<Employees_27623> employees_27623List;

    QList<Departments_27623> departments_27623List;

    void operator<<(const QJsonObject& json){

        name_27623              = json.value("name").toString();

        const auto& arremployees = json.value("employees").toArray();
        for(const auto& item : arremployees){
            Employees_27623 i;
            i << item.toObject();
            employees_27623List << i;
        }

        const auto& arrdepartments = json.value("departments").toArray();
        for(const auto& item : arrdepartments){
            Departments_27623 i;
            i << item.toObject();
            departments_27623List << i;
        }
    }
};

struct Field3_22398{

    QString subField1_12429;

    QString subField2_12429;

    void operator<<(const QJsonObject& json){

        subField1_12429       = json.value("subField1").toString();
        subField2_12429       = json.value("subField2").toString();
    }
};

struct CustomFields_41{

    QString field1_22398;

    QString field2_22398;

    Field3_22398 field3_22398;

    void operator<<(const QJsonObject& json){

        field1_22398       = json.value("field1").toString();
        field2_22398       = json.value("field2").toString();
        field3_22398       << json.value("field3").toObject();
    }
};

struct Address_7843{

    QString city_16246;

    QString state_16246;

    QString street_16246;

    QString country_16246;

    QString postalCode_16246;

    void operator<<(const QJsonObject& json){

        city_16246             = json.value("city").toString();
        state_16246            = json.value("state").toString();
        street_16246           = json.value("street").toString();
        country_16246          = json.value("country").toString();
        postalCode_16246       = json.value("postalCode").toString();
    }
};

struct FamilyMembers_7843{

    QString name_14517;

    QString relation_14517;

    void operator<<(const QJsonObject& json){

        name_14517           = json.value("name").toString();
        relation_14517       = json.value("relation").toString();
    }
};

struct PhoneNumbers_7843{

    QString type_6744;

    QString number_6744;

    void operator<<(const QJsonObject& json){

        type_6744        = json.value("type").toString();
        number_6744      = json.value("number").toString();
    }
};

struct Person_41{

    int age_7843;

    QString name_7843;

    QString email_7843;

    QList<QString> hobbies_7843List;

    Address_7843 address_7843;

    bool isMarried_7843;

    QList<PhoneNumbers_7843> phoneNumbers_7843List;

    QList<FamilyMembers_7843> familyMembers_7843List;

    void operator<<(const QJsonObject& json){

        age_7843                = json.value("age").toInt();
        name_7843               = json.value("name").toString();
        email_7843              = json.value("email").toString();

        const auto& arrhobbies = json.value("hobbies").toArray();
        for(const auto& item : arrhobbies){
            QString i;
            i = item.toString();
            hobbies_7843List << i;
        }
        address_7843            << json.value("address").toObject();
        isMarried_7843          = json.value("isMarried").toBool();

        const auto& arrphoneNumbers = json.value("phoneNumbers").toArray();
        for(const auto& item : arrphoneNumbers){
            PhoneNumbers_7843 i;
            i << item.toObject();
            phoneNumbers_7843List << i;
        }

        const auto& arrfamilyMembers = json.value("familyMembers").toArray();
        for(const auto& item : arrfamilyMembers){
            FamilyMembers_7843 i;
            i << item.toObject();
            familyMembers_7843List << i;
        }
    }
};

struct Product_26164{

    QString name_1284;

    int price_1284;

    int quantity_1284;

    void operator<<(const QJsonObject& json){

        name_1284          = json.value("name").toString();
        price_1284         = json.value("price").toInt();
        quantity_1284      = json.value("quantity").toInt();
    }
};

struct Transactions_41{

    int id_26164;

    QString type_26164;

    QString date_26164;

    int amount_26164;

    Product_26164 product_26164;

    void operator<<(const QJsonObject& json){

        id_26164            = json.value("id").toInt();
        type_26164          = json.value("type").toString();
        date_26164          = json.value("date").toString();
        amount_26164        = json.value("amount").toInt();
        product_26164       << json.value("product").toObject();
    }
};

struct MainStruct{

    QList<QString> notes_41List;

    Person_41 person_41;

    Company_41 company_41;

    bool isActive_41;

    QString updatedAt_41;

    Temp_meta_41 temp_meta_41;

    QString createdAt_41;

    Temp_links_41 temp_links_41;

    QList<Transactions_41> transactions_41List;

    CustomFields_41 customFields_41;

    void operator<<(const QJsonObject& json){


        const auto& arrnotes = json.value("notes").toArray();
        for(const auto& item : arrnotes){
            QString i;
            i = item.toString();
            notes_41List << i;
        }
        person_41          << json.value("person").toObject();
        company_41         << json.value("company").toObject();
        isActive_41        = json.value("isActive").toBool();
        updatedAt_41       = json.value("updatedAt").toString();
        temp_meta_41           << json.value("_meta").toObject();
        createdAt_41       = json.value("createdAt").toString();
        temp_links_41          << json.value("_links").toObject();

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


//#endif // STRUCTTEST_H

```

