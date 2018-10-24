#ifndef COMPTE_H
#define COMPTE_H

#include <QString>

class Compte
{
public:
    Compte();
    Compte(int id, int idRessource, QString login, QString mdp);
    Compte(int idRessource, QString login, QString mdp);

    int getId();
    void setId(int id);
    int getIdRessource();
    void setIdRessource(int idr);
    QString getLogin();
    void setLogin(QString login);
    QString getMdp();
    void setMdp(QString mdp);

private:
    int id, idRessource;
    QString login, mdp;
};

#endif // COMPTE_H
