#include "controleurtype.h"

ControleurType::ControleurType()
{

}

bool ControleurType::ajouteType(Type *type)
{
    InterfaceBD ibd;
    return ibd.ajouteType(type);
}

Type *ControleurType::trouverTypeParId(int idType)
{
    InterfaceBD ibd;
    return ibd.trouverTypeParId(idType);
}

Type *ControleurType::trouverTypeParLabel(QString label)
{
    InterfaceBD ibd;
    return ibd.trouverTypeParLabel(label);
}

bool ControleurType::supprimerType(int idType)
{
    InterfaceBD ibd;
    return ibd.supprimerType(idType);
}

QList<Type *> ControleurType::trouverTousLesTypes()
{
    InterfaceBD ibd;
    return ibd.trouverTousLesTypes();
}
