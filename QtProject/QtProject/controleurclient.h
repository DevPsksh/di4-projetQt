#ifndef CONTROLEURCLIENT_H
#define CONTROLEURCLIENT_H

#include <QList>
#include "client.h"

class ControleurClient
{
public:
    ControleurClient();

    bool ajouterClient(Client *client);
    bool modifierClient(Client *client);
    bool supprimerClient(int idClient);
    Client* trouverClientParId(int idClient);
    QList<Client*> trouverTousLesClientsBD();
    QList<Client*> trouverClientsParNomPrenomIdDateDebutDateFin(QString &nom, QString &prenom, int &id, QDate &dateDebut, QDate &dateFin);
    QList<Client*> trouverClientsParNomPrenomId(QString &nom, QString &prenom, int &id);
    QList<Client*> trouverClientsParNomPrenomDateDebutDateFin(QString &nom, QString &prenom, QDate &dateDebut, QDate &dateFin);
    QList<Client*> trouverClientsParNomPrenomDateFin(QString &nom, QString &prenom, QDate &dateFin);
    QList<Client*> trouverClientsParNomPrenomDateDebut(QString &nom, QString &prenom, QDate &dateDebut);
    QList<Client*> trouverClientsParNomPrenom(QString &nom, QString &prenom);
};

#endif // CONTROLEURCLIENT_H
