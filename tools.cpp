#include "tools.h"

#include <QString>
#include <QStringList>

Tools::Tools()
{

}

QString Tools::toUpperCaseCamelCase(const QString &str)
{
    // 将字符串分割为单词
    QStringList words = str.split(' ');

    // 将每个单词的首字母转换为大写，并拼接起来
    QString result;
    for (const QString& word : words) {
        if (!word.isEmpty()) {
            result.append(word.left(1).toUpper());
            result.append(word.mid(1));
        }
    }

    return result;
}

QString Tools::toLowerCaseCamelCase(const QString &str)
{
    QString rData = toUpperCaseCamelCase(str);

    if(!rData.isEmpty()){
        auto aChar = rData.at(0).toLower();
        rData.replace(0,1,aChar);
    }
    return rData;
}
