# JsonToStruct
Generate Qt Struct code snippets and constructors from Json files【从Json文件生成Qt结构代码片段和构造函数】

解决后端写一个复杂 json 后 Qt端调用不方便的问题。

生成效果如下：
```
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

	int age;

	QString email;

	int id;

	QString name;

	QList<PhoneNumbers> phoneNumbersList;

void operator<<(const QJsonObject& json){ 
	address << json.value("address").toObject();
	age = json.value("age").toInt();
	email = json.value("email").toString();
	id = json.value("id").toInt();
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

```
```
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
