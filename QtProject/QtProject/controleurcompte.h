#ifndef CONTROLEURCOMPTE_H
#define CONTROLEURCOMPTE_H

#include "interfacebd.h"

class ControleurCompte
{
public:
    ControleurCompte();

    bool ajouterCompte(Compte *compte);
    bool supprimerCompte(int idType);
    bool supprimerCompteParIdRessource(int idRessource);
    Compte* trouverCompteParIdRessource(int idRessource);
    QList<Compte*> trouverTousLesComptesBD();
    bool verifierExistenceCompte(QString pseudo, QString mdp);
};

#endif // CONTROLEURCOMPTE_H
