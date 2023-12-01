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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QStringList wordList;
//    wordList << "apple" << "banana" << "cherry" << "date" << "elderberry";
//    QStringListModel *model = new QStringListModel(wordList);
//    QCompleter *completer = new QCompleter(model, ui->lineEdit);
//    completer->setCaseSensitivity(Qt::CaseInsensitive);
//    completer->setWrapAround(false);
//    completer->setCompletionMode(QCompleter::PopupCompletion);
//    ui->lineEdit->setCompleter(completer);


    ui->textEdit->setText(R"({
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
})");
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
    for(const auto &key : obj.keys()){

        QString structName = Tools::toUpperCaseCamelCase(key);
        auto type = obj.value(key).type();

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

        st.data.append({type,key});
    }

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

//    MainStruct i ;
//    i << jsonObj;

    qDebug()<<__FUNCTION__;
}

