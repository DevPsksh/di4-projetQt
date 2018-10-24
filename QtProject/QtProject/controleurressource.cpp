#include "controleurressource.h"
#include "interfacebd.h"

ControleurRessource::ControleurRessource()
{

}

bool ControleurRessource::ajouterRessource(Ressource *ressource)
{
    InterfaceBD ibd;
    return ibd.ajouterRessourceBD(ressource);
}

bool ControleurRessource::modifierRessource(Ressource *ressource)
{
    InterfaceBD ibd;
    return ibd.modifierRessourceBD(ressource);
}

bool ControleurRessource::supprimerRessource(Ressource *ressource)
{
    InterfaceBD ibd;
    return ibd.supprimerRessourceBD(ressource);
}

Ressource *ControleurRessource::trouverRessourceParId(int idRessource)
{
    InterfaceBD ibd;
    return ibd.trouverRessourceParIdBD(idRessource);
}

QList<Ressource *> ControleurRessource::trouverTousLesRessouces()
{
    InterfaceBD ibd;
    return ibd.trouverTousLesRessoucesBD();
}
