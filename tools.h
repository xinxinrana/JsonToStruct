#ifndef TOOLS_H
#define TOOLS_H
class QString;

class Tools
{
public:
    Tools();
    static QString toUpperCaseCamelCase(const QString& str);
    static QString toLowerCaseCamelCase(const QString& str);
};

#endif // TOOLS_H
