#ifndef CONTROLEURTYPE_H
#define CONTROLEURTYPE_H

#include "interfacebd.h"

class ControleurType
{
public:
    ControleurType();

    bool ajouteType(Type *type);
    Type* trouverTypeParId(int idType);
    Type* trouverTypeParLabel(QString label);
    bool supprimerType(int idType);
    QList<Type*> trouverTousLesTypes();
};

#endif // CONTROLEURTYPE_H
