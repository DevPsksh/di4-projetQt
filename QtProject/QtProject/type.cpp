#include "type.h"

Type::Type()
{

}

Type::Type(int id, QString label){
    this->id = id;
    this->label = label;
}

int Type::getId(){
    return this->id;
}

void Type::setId(int id){
    this->id = id;
}

QString Type::getLabel(){
    return this->label;
}

void Type::setLabel(QString label){
    this->label = label;
}
