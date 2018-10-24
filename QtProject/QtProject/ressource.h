#ifndef RESSOURCE_H
#define RESSOURCE_H

#include<QString>

class Ressource
{
public:
    Ressource();
    Ressource(int idRessource, QString nom, QString prenom, int idType);
    Ressource(QString nom, QString prenom, int idType);

    int getIdRessource();
    void setIdRessource(int idr);
    int getIdType();
    void setIdType(int idt);
    QString getNom();
    void setNom(QString nom);
    QString getPrenom();
    void setPrenom(QString prenom);

private:
    int idRessource, idType;
    QString nom, prenom;
};

#endif // RESSOURCE_H
