#ifndef TYPE_H
#define TYPE_H

#include <QString>

class Type
{
public:
    Type();
    Type(int id, QString label);

    int getId();
    void setId(int id);
    QString getLabel();
    void setLabel(QString label);

private:
    int id;
    QString label;
};

#endif // TYPE_H
