#ifndef TOOLS_H
#define TOOLS_H
class QString;

class Tools
{
public:
    Tools();

    // 命名检查
    static QString namingCheck(const QString& str,bool* isOk = nullptr);

    // 大驼峰
    static QString toUpperCaseCamelCase(const QString& str);

    //小驼峰
    static QString toLowerCaseCamelCase(const QString& str);
};

#endif // TOOLS_H
