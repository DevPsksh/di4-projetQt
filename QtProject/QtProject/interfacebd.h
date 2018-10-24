#ifndef INTERFACEBD_H
#define INTERFACEBD_H

#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QSqlRecord>

#include "client.h"
#include "ressource.h"
#include "compte.h"
#include "type.h"

class InterfaceBD
{
public:
    InterfaceBD();

    bool testerConnectionBD();

    bool ajouterClientBD(Client *client);
    bool modifierClientBD(Client *client);
    bool supprimerClientBD(int idClient);
    Client* trouverClientParIdBD(int idClient);
    QList<Client*> trouverTousLesClientsBD();
    QList<Client*> trouverClientsParNomPrenomIdDateDebutDateFinBD(QString &nom, QString &prenom, int &id, QDate &dateDebut, QDate &dateFin);
    QList<Client*> trouverClientsParNomPrenomIdBD(QString &nom, QString &prenom, int &id);
    QList<Client*> trouverClientsParNomPrenomDateDebutDateFinBD(QString &nom, QString &prenom, QDate &dateDebut, QDate &dateFin);
    QList<Client*> trouverClientsParNomPrenomDateFinBD(QString &nom, QString &prenom, QDate &dateFin);
    QList<Client*> trouverClientsParNomPrenomDateDebutBD(QString &nom, QString &prenom, QDate &dateDebut);
    QList<Client*> trouverClientsParNomPrenomBD(QString &nom, QString &prenom);

    bool ajouterRessourceBD(Ressource *ressource);
    bool modifierRessourceBD(Ressource *ressource);
    bool supprimerRessourceBD(Ressource *ressource);
    Ressource* trouverRessourceParIdBD(int idRessource);
    QList<Ressource*> trouverTousLesRessoucesBD();

    bool ajouterCompteBD(Compte *compte);
    bool supprimerCompteBD(int idType);
    bool supprimerCompteParIdRessource(int idRessource);
    Compte* trouverCompteParIdRessourceBD(int idRessource);
    QList<Compte*> trouverTousLesComptesBD();
    bool verifierExistenceCompte(QString pseudo, QString mdp);

    bool ajouteType(Type *type);
    Type* trouverTypeParId(int idType);
    Type* trouverTypeParLabel(QString label);
    bool supprimerType(int idType);
    QList<Type*> trouverTousLesTypes();

    static int INSERT_COUNTER;

private:
    QSqlDatabase db;


};

#endif // INTERFACEBD_H
