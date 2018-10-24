#include "controleurcompte.h"

ControleurCompte::ControleurCompte()
{

}

bool ControleurCompte::ajouterCompte(Compte *compte)
{
    InterfaceBD ibd;
    return ibd.ajouterCompteBD(compte);
}

bool ControleurCompte::supprimerCompte(int idType)
{
    InterfaceBD ibd;
    return ibd.supprimerCompteBD(idType);
}

bool ControleurCompte::supprimerCompteParIdRessource(int idRessource)
{
    InterfaceBD ibd;
    return ibd.supprimerCompteParIdRessource(idRessource);
}

Compte *ControleurCompte::trouverCompteParIdRessource(int idRessource)
{
    InterfaceBD ibd;
    return ibd.trouverCompteParIdRessourceBD(idRessource);
}

QList<Compte *> ControleurCompte::trouverTousLesComptesBD()
{
    InterfaceBD ibd;
    return ibd.trouverTousLesComptesBD();
}

bool ControleurCompte::verifierExistenceCompte(QString pseudo, QString mdp)
{
    InterfaceBD ibd;
    return ibd.verifierExistenceCompte(pseudo, mdp);
}
