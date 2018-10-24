#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDate>

class Client
{
public:
    Client();
    Client(QString nom, QString prenom, QString adresse, QString ville, QString cp, QDate dateRdv, int dureeRdv, int priorite, int tel, QString commentaire);
    Client(QString nom, QString prenom, QString adresse, QString ville, QString cp, QDate dateRdv, int dureeRdv, int priorite);
    Client(int id, QString nom, QString prenom, QString adresse, QString ville, QString cp, QDate dateRdv, int dureeRdv, int priorite, int tel, QString commentaire);

    int getId();
    void setId(int id);
    int getTel();
    void setTel(int tel);
    int getDureeRdv();
    void setDureeRdv(int dureeRdv);
    int getPriorite();
    void setPriorite(int priorite);
    QString getNom();
    void setNom(QString nom);
    QString getPrenom();
    void setPrenom(QString prenom);
    QString getAdresse();
    void setAdresse(QString adresse);
    QString getVille();
    void setVille(QString ville);
    QString getCp();
    void setCp(QString cp);
    QString getCommentaire();
    void setCommentaire(QString commentaire);
    QDate getDateRdv();
    void setDateRdv(QDate dateRdv);

private:
    int idClient, tel, dureeRdv, priorite;
    QString nom, prenom, adresse, ville, cp, commentaire;
    QDate dateRdv;
};

#endif // CLIENT_H
