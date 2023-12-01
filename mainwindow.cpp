#include "mainwindow.h"
#include "ui_mainwindow.h"



#include <QCompleter>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLineEdit>
#include <QMap>
#include <QStringListModel>



static const QString complexStr(R"(
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
        "version": 1
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
)");

static const QString simpleStr(R"(
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
)");



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setText(complexStr);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    auto jsonStr = ui->textEdit->toPlainText();
    auto jsonObj = (QJsonDocument().fromJson(jsonStr.toLatin1())).object();

    getQtTypeTreeFromJsonObj(jsonObj ,"MainStruct");

    for (const auto &aStruct : m_structTemplates) {
        ui->textEdit_2->append(aStruct.toString() + "\n");
    }
}

void MainWindow::getQtTypeTreeFromJsonObj(const QJsonObject& obj ,const QString& thiskey)
{


    StructTemplate st;
    st.thiskey = thiskey;

    int len = -1;
    for(const auto &key : obj.keys()){
        const QString QKey = key;

        QString structName = Tools::toUpperCaseCamelCase(key);

        if(st.randomSuffixEnable){
            auto &changeQKey = const_cast<QString&>(QKey);
            changeQKey += st.randomSuffix;
            structName += st.randomSuffix;
        }

        auto type = obj.value(key).type();
        if(QKey.length() > len) len = QKey.length();

        if(type == QJsonValue::Object){
            getQtTypeTreeFromJsonObj(obj.value(key).toObject(),structName);
        }
        else if(type == QJsonValue::Array){
            getQtTypeTreeFromJsonObj(obj.value(key).toArray()[0].toObject(),structName);
        }else if(type == QJsonValue::Double){
            auto var = obj.value(key).toDouble();
            if(var - static_cast<int>(var) < 0.00001){
                type = static_cast<QJsonValue::Type>(-1);
            }
        }

        st.data.append({type,key,QKey});
    }

    auto sortFunc = [](std::tuple<QJsonValue::Type,QString,QString> a1 ,
                       std::tuple<QJsonValue::Type,QString,QString> a2){
        return std::get<2>(a1).length() < std::get<2>(a2).length();
    };

    qSort(st.data.begin(),st.data.end(),sortFunc);

    st.thisDataKeyLenMax = len;

    m_structTemplates.append(st);
}


void MainWindow::on_pushButton_2_clicked()
{
    auto jsonStr = ui->textEdit->toPlainText();
    auto jsonObj = (QJsonDocument().fromJson(jsonStr.toLatin1())).object();

    m_structTemplates.clear();
    getQtTypeTreeFromJsonObj(jsonObj ,"MainStruct");

    for (const auto &aStruct : m_structTemplates) {
        ui->textEdit_2->append(aStruct.funcFormJson() + "\n");
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    auto jsonStr = ui->textEdit->toPlainText();
    auto jsonObj = (QJsonDocument().fromJson(jsonStr.toLatin1())).object();

    MainStruct i ;
    i << jsonObj;

    qDebug()<<__FUNCTION__;
}

