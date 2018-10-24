#include "controleurclient.h"
#include "interfacebd.h"

ControleurClient::ControleurClient()
{
}

bool ControleurClient::ajouterClient(Client *client)
{
    InterfaceBD ibd;
    return ibd.ajouterClientBD(client);
}

bool ControleurClient::modifierClient(Client *client)
{
    InterfaceBD ibd;
    return ibd.modifierClientBD(client);
}

bool ControleurClient::supprimerClient(int idClient)
{
    InterfaceBD ibd;
    return ibd.supprimerClientBD(idClient);
}

Client *ControleurClient::trouverClientParId(int idClient)
{
    InterfaceBD ibd;
    return ibd.trouverClientParIdBD(idClient);
}

QList<Client *> ControleurClient::trouverTousLesClientsBD()
{
    InterfaceBD ibd;
    return ibd.trouverTousLesClientsBD();
}

QList<Client *> ControleurClient::trouverClientsParNomPrenomIdDateDebutDateFin(QString &nom, QString &prenom, int &id, QDate &dateDebut, QDate &dateFin)
{
    InterfaceBD ibd;
    return ibd.trouverClientsParNomPrenomIdDateDebutDateFinBD(nom, prenom, id, dateDebut, dateFin);
}

QList<Client *> ControleurClient::trouverClientsParNomPrenomId(QString &nom, QString &prenom, int &id)
{
    InterfaceBD ibd;
    return ibd.trouverClientsParNomPrenomIdBD(nom, prenom, id);
}

QList<Client *> ControleurClient::trouverClientsParNomPrenomDateDebutDateFin(QString &nom, QString &prenom, QDate &dateDebut, QDate &dateFin)
{
    InterfaceBD ibd;
    return ibd.trouverClientsParNomPrenomDateDebutDateFinBD(nom, prenom, dateDebut, dateFin);
}

QList<Client *> ControleurClient::trouverClientsParNomPrenomDateFin(QString &nom, QString &prenom, QDate &dateFin)
{
    InterfaceBD ibd;
    return ibd.trouverClientsParNomPrenomDateFinBD(nom , prenom , dateFin);
}

QList<Client *> ControleurClient::trouverClientsParNomPrenomDateDebut(QString &nom, QString &prenom, QDate &dateDebut)
{
    InterfaceBD ibd;
    return ibd.trouverClientsParNomPrenomDateDebutBD(nom, prenom, dateDebut);
}

QList<Client *> ControleurClient::trouverClientsParNomPrenom(QString &nom, QString &prenom)
{
    InterfaceBD ibd;
    return ibd.trouverClientsParNomPrenomBD(nom, prenom);
}




