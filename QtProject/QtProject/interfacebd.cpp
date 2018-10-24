#include "interfacebd.h"

int InterfaceBD::INSERT_COUNTER = 0;

InterfaceBD::InterfaceBD()
{
        db = QSqlDatabase::database("connection-name");

        if(!db.open()){
            qDebug() << "Erreur base de donnees non ouverte" << db.lastError();
        }
}

bool InterfaceBD::ajouterClientBD(Client *client)
{
        QSqlQuery query(this->db);
        query.prepare("INSERT INTO TClient (Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite) VALUES (:nom, :prenom, :adresse, :ville, :cp, :commentaire, :tel, :dateRdv, :dureeRdv, :priorite)");
        query.bindValue(":nom", client->getNom());
        query.bindValue(":prenom", client->getPrenom());
        query.bindValue(":adresse", client->getAdresse());
        query.bindValue(":ville", client->getVille());
        query.bindValue(":cp", client->getCp());
        query.bindValue(":commentaire", client->getCommentaire());
        query.bindValue(":tel", client->getTel());
        query.bindValue(":dateRdv", client->getDateRdv());
        query.bindValue(":dureeRdv", client->getDureeRdv());
        query.bindValue(":priorite", client->getPriorite());
InterfaceBD::INSERT_COUNTER++;
        bool b_test =  query.exec();
        if(!b_test){
            qDebug() << "Erreur InterfaceBD::ajouterClientBD : " << query.lastError();
        }

        return b_test;

}

bool InterfaceBD::modifierClientBD(Client *client)
{
        QSqlQuery query(this->db);
        query.prepare("UPDATE TClient SET Nom = :nom, Prenom = :prenom, Adresse = :adresse, Ville = :ville, CP = :cp, Commentaire = :commentaire, Tel = :tel, DateRdv = :dateRdv, DureeRdv = :dureeRdv, Priorite = :priorite WHERE Id = :idClient ");
        query.bindValue(":idClient", client->getId() );
        query.bindValue(":nom", client->getNom());
        query.bindValue(":prenom", client->getPrenom());
        query.bindValue(":adresse", client->getAdresse());
        query.bindValue(":ville", client->getVille());
        query.bindValue(":cp", client->getCp());
        query.bindValue(":commentaire", client->getCommentaire());
        query.bindValue(":tel", client->getTel());
        query.bindValue(":priorite", client->getPriorite());
        query.bindValue(":dureeRdv", client->getDureeRdv());
        query.bindValue(":dateRdv", client->getDateRdv());
        qDebug() << "Update" << client->getId();
        bool b_test = query.exec();
        if(!b_test){
            qDebug() << "Erreur InterfaceBD::modifierClientBD : " << query.lastError();
        }

        return b_test;
}

bool InterfaceBD::supprimerClientBD(int idClient)
{
        QSqlQuery query(this->db);
        query.prepare("DELETE FROM TClient WHERE Id = :idClient");
        query.bindValue(":idClient", idClient);

        bool b_test = query.exec();
        if(!b_test){
            qDebug() << "Erreur InterfaceBD::supprimerClientBD : " << query.lastError();
        }

        return b_test;
}

Client *InterfaceBD::trouverClientParIdBD(int idClient)
{
        Client* client = nullptr;

        QSqlQuery query(db);
        query.prepare("SELECT Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient WHERE Id = :idclient");
        query.bindValue(":idclient", idClient);
        bool b_test = query.exec();
        if(b_test && query.next()){
            QString nom = query.value(0).toString();
            QString prenom = query.value(1).toString();
            QString adresse = query.value(2).toString();
            QString ville = query.value(3).toString();
            QString cp = query.value(4).toString();
            QString commentaire = query.value(5).toString();
            int tel = query.value(6).toInt();
            QDate dateRdv = query.value(7).toDate();
            int dureeRdv = query.value(8).toInt();
            int priorite = query.value(9).toInt();

            return new Client(idClient, nom, prenom, adresse, ville, cp, dateRdv, dureeRdv,priorite, tel, commentaire);
        }else if(! b_test){
            qDebug() << "Erreur InterfaceBD::trouverClientParIdBD : " << query.lastError();
        }

        return client;
}

QList<Client *> InterfaceBD::trouverTousLesClientsBD()
{


    QSqlQuery query(this->db);
    QString queryStr = "SELECT * FROM TClient";
    bool b_test = query.exec(queryStr);

    QList<Client*> listeDesClients;
    if(b_test)
    {
        while(query.next())
        {
            int id = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            QString adresse = query.value(3).toString();
            QString ville = query.value(4).toString();
            QString cp = query.value(5).toString();
            QString commentaire = query.value(6).toString();
            int tel = query.value(7).toInt();
            QDate dateRdv = query.value(8).toDate();
            int dureeRdv = query.value(9).toInt();
            int priorite = query.value(10).toInt();
            Client* client = new Client(id, nom, prenom, adresse, ville, cp, dateRdv, dureeRdv,priorite, tel, commentaire);
            listeDesClients.append(client);
        }
    }
    else
    {
        qDebug() << "Erreur InterfaceBD::trouverTousLesClientsBD : " << query.lastError();
    }

    return listeDesClients;
}

QList<Client *> InterfaceBD::trouverClientsParNomPrenomIdDateDebutDateFinBD(QString &nom, QString &prenom, int &id, QDate &dateDebut, QDate &dateFin)
{
        QSqlQuery query(this->db);
        query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient WHERE Nom LIKE :nom OR Prenom LIKE :prenom OR id = :id OR DateRdv BETWEEN :dateDebut AND :dateFin");
        bool b_test = query.exec();
        QList<Client*> listeDesClients;
        query.bindValue("Id", id);
        query.bindValue(":nom", nom+'%');
        query.bindValue(":prenom", prenom+'%');
        query.bindValue(":dateDebut", dateDebut);
        query.bindValue(":dateFin", dateFin);
        if(b_test){
            while(query.next()){
                int id = query.value(0).toInt();
                QString nom = query.value(1).toString();
                QString prenom = query.value(2).toString();
                QString adresse = query.value(3).toString();
                QString ville = query.value(4).toString();
                QString cp = query.value(5).toString();
                QString commentaire = query.value(6).toString();
                int tel = query.value(7).toInt();
                QDate dateRdv = query.value(8).toDate();
                int dureeRdv = query.value(9).toInt();
                int priorite = query.value(10).toInt();

                Client* client = new Client(id, nom, prenom, adresse, ville, cp, dateRdv, dureeRdv,priorite, tel, commentaire);
                listeDesClients.append(client);
            }
        }else{
            qDebug() << "Erreur InterfaceBD::trouverClientsParNomPrenomIdDateDebutDateFinBD : " << query.lastError();
        }

        return listeDesClients;
}

QList<Client *> InterfaceBD::trouverClientsParNomPrenomIdBD(QString &nom, QString &prenom, int &id)
{
    QSqlQuery query(this->db);
    QList<Client*> listeDesClients;
    query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient WHERE Nom LIKE :nom OR Prenom LIKE :prenom OR id = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":id", id);
    bool b_test = query.exec();
    if(b_test){
        while(query.next()){
            int id = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            QString adresse = query.value(3).toString();
            QString ville = query.value(4).toString();
            QString cp = query.value(5).toString();
            QString commentaire = query.value(6).toString();
            int tel = query.value(7).toInt();
            QDate dateRdv = query.value(8).toDate();
            int dureeRdv = query.value(9).toInt();
            int priorite = query.value(10).toInt();

            Client* client = new Client(id, nom, prenom, adresse, ville, cp, dateRdv, dureeRdv,priorite, tel, commentaire);
            listeDesClients.append(client);
        }
    }else{
        qDebug() << "Erreur InterfaceBD::trouverClientsParNomPrenomIdBD : " << query.lastError();
    }

    return listeDesClients;
}

QList<Client *> InterfaceBD::trouverClientsParNomPrenomDateDebutDateFinBD(QString &nom, QString &prenom, QDate &dateDebut, QDate &dateFin)
{
    QSqlQuery query(this->db);
    QList<Client*> listeDesClients;
    query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient WHERE Nom LIKE :nom OR Prenom LIKE :prenom OR DateRdv BETWEEN :dateDebut AND :dateFin");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateDebut", dateDebut);
    query.bindValue(":dateFin", dateFin);
    bool b_test = query.exec();
    if(b_test){
        while(query.next()){
            int id = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            QString adresse = query.value(3).toString();
            QString ville = query.value(4).toString();
            QString cp = query.value(5).toString();
            QString commentaire = query.value(6).toString();
            int tel = query.value(7).toInt();
            QDate dateRdv = query.value(8).toDate();
            int dureeRdv = query.value(9).toInt();
            int priorite = query.value(10).toInt();

            Client* client = new Client(id, nom, prenom, adresse, ville, cp, dateRdv, dureeRdv,priorite, tel, commentaire);
            listeDesClients.append(client);
        }
    }else{
        qDebug() << "Erreur InterfaceBD::trouverClientsParNomPrenomDateDebutDateFinBD : " << query.lastError();
    }

    return listeDesClients;
}

QList<Client *> InterfaceBD::trouverClientsParNomPrenomDateFinBD(QString &nom, QString &prenom, QDate &dateFin)
{
    QSqlQuery query(this->db);
    QList<Client*> listeDesClients;
    query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient WHERE Nom LIKE :nom OR Prenom LIKE :prenom OR DateRdv <= :dateFin");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateFin", dateFin);
    bool b_test = query.exec();
    if(b_test){
        while(query.next()){
            int id = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            QString adresse = query.value(3).toString();
            QString ville = query.value(4).toString();
            QString cp = query.value(5).toString();
            QString commentaire = query.value(6).toString();
            int tel = query.value(7).toInt();
            QDate dateRdv = query.value(8).toDate();
            int dureeRdv = query.value(9).toInt();
            int priorite = query.value(10).toInt();

            Client* client = new Client(id, nom, prenom, adresse, ville, cp, dateRdv, dureeRdv,priorite, tel, commentaire);
            listeDesClients.append(client);
        }
    }else{
        qDebug() << "Erreur InterfaceBD::trouverClientsParNomPrenomDateFinBD : " << query.lastError();
    }

    return listeDesClients;
}

QList<Client *> InterfaceBD::trouverClientsParNomPrenomDateDebutBD(QString &nom, QString &prenom, QDate &dateDebut)
{
    QSqlQuery query(this->db);
    QList<Client*> listeDesClients;
    query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient WHERE Nom LIKE :nom OR Prenom LIKE :prenom OR DateRdv >= :dateDebut");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateDebut", dateDebut);
    bool b_test = query.exec();
    if(b_test){
        while(query.next()){
            int id = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            QString adresse = query.value(3).toString();
            QString ville = query.value(4).toString();
            QString cp = query.value(5).toString();
            QString commentaire = query.value(6).toString();
            int tel = query.value(7).toInt();
            QDate dateRdv = query.value(8).toDate();
            int dureeRdv = query.value(9).toInt();
            int priorite = query.value(10).toInt();

            Client* client = new Client(id, nom, prenom, adresse, ville, cp, dateRdv, dureeRdv,priorite, tel, commentaire);
            listeDesClients.append(client);
        }
    }else{
        qDebug() << "Erreur InterfaceBD::trouverClientsParNomPrenomDateDebutBD : " << query.lastError();
    }

    return listeDesClients;
}

QList<Client *> InterfaceBD::trouverClientsParNomPrenomBD(QString &nom, QString &prenom)
{
    QSqlQuery query(this->db);
    QList<Client*> listeDesClients;
    query.prepare("SELECT Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DateRdv, DureeRdv, Priorite FROM TClient WHERE Nom LIKE :nom OR Prenom LIKE :prenom");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    bool b_test = query.exec();
    if(b_test){
        while(query.next()){
            int id = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            QString adresse = query.value(3).toString();
            QString ville = query.value(4).toString();
            QString cp = query.value(5).toString();
            QString commentaire = query.value(6).toString();
            int tel = query.value(7).toInt();
            QDate dateRdv = query.value(8).toDate();
            int dureeRdv = query.value(9).toInt();
            int priorite = query.value(10).toInt();

            Client* client = new Client(id, nom, prenom, adresse, ville, cp, dateRdv, dureeRdv,priorite, tel, commentaire);
            listeDesClients.append(client);
        }
    }else{
        qDebug() << "Erreur InterfaceBD::trouverClientsParNomPrenomBD : " << query.lastError();
    }

    return listeDesClients;
}

bool InterfaceBD::ajouterRessourceBD(Ressource *ressource)
{
    QSqlQuery query(this->db);
    QString qyertStr = "INSERT INTO TRessource (Nom, Prenom, IdType) VALUES ('"+ressource->getNom()+"','"+ressource->getPrenom()+"', "+QString::number(ressource->getIdType())+")";
    //query.prepare("INSERT INTO TRessource (Nom, Prenom, IdType) VALUES (:nom, :prenom; :idType)");
    query.prepare(qyertStr);
    /*query.bindValue(":nom", ressource->getNom());
    query.bindValue(":prenom", ressource->getPrenom());
    query.bindValue(":idType", ressource->getIdType());*/
    qDebug() << qyertStr;
    qDebug() << ressource->getNom() << ressource->getPrenom() << ressource->getIdType();
    bool b_test = query.exec();
InterfaceBD::INSERT_COUNTER++;
    if(!b_test){
        qDebug() << "Erreur InterfaceBD::ajouterRessourceBD : " << query.lastError();
    }

    return b_test;
}

bool InterfaceBD::modifierRessourceBD(Ressource *ressource)
{
    QSqlQuery query(this->db);
    query.prepare("UPDATE TRessource SET Id = :id, Nom = :nom, Prenom = :prenom, IdType = :idType WHERE Id = :id");

    query.bindValue(":id", ressource->getIdRessource());
    query.bindValue(":nom", ressource->getNom());
    query.bindValue(":prenom", ressource->getPrenom());
    query.bindValue(":idType", ressource->getIdType());

    bool b_test = query.exec();
    if(!b_test){
        qDebug() << "Erreur InterfaceBD::modifierRessourceBD : " << query.lastError();
    }

    return b_test;
}

bool InterfaceBD::supprimerRessourceBD(Ressource *ressource)
{
    QSqlQuery query(this->db);
    query.prepare("DELETE FROM TRessource WHERE Id = :id");
    query.bindValue(":id", ressource->getIdRessource());

    bool b_test = query.exec();
    if(!b_test){
        qDebug() << "Erreur InterfaceBD::supprimerRessourceBD : " << query.lastError();
    }

    return b_test;
}

Ressource *InterfaceBD::trouverRessourceParIdBD(int idRessource)
{
        Ressource* ressource = nullptr;

        QSqlQuery query(db);
        query.prepare("SELECT Nom, Prenom, IdType FROM TRessource WHERE Id = :idressource");
        query.bindValue(":idressource", idRessource);
        bool b_test = query.exec();
        if(b_test && query.next()){
            QString nom = query.value(0).toString();
            QString prenom = query.value(1).toString();
            int idType = query.value(2).toInt();

            return new Ressource(idRessource, nom, prenom, idType);
        }else if(! b_test){
            qDebug() << "Erreur InterfaceBD::trouverRessourceParIdBD : " << query.lastError();
        }

        return ressource;
}

QList<Ressource *> InterfaceBD::trouverTousLesRessoucesBD()
{
    QSqlQuery query(this->db);
    query.prepare("SELECT Id, Nom, Prenom, IdType FROM TRessource");

    bool b_test = query.exec();
    QList<Ressource*> listeDesRessources;
    if(b_test){
        while(query.next()){
            int idRessource = query.value(0).toInt();
            QString nom = query.value(1).toString();
            QString prenom = query.value(2).toString();
            int idType = query.value(3).toInt();

            Ressource* ressource = new Ressource(idRessource, nom, prenom, idType);

            listeDesRessources.append(ressource);
        }
    }else{
        qDebug() << "Erreur InterfaceBD::trouverTousLesRessoucesBD : " << query.lastError();
    }

    return listeDesRessources;
}

bool InterfaceBD::ajouterCompteBD(Compte *compte)
{
    QSqlQuery query(this->db);
    query.prepare("INSERT INTO TCompte (Id, IdRessource, Login, MdP) VALUES (:idCompte, :idRessource, :login, :mdp)");
    query.bindValue(":id", compte->getId());
    query.bindValue(":idRessource", compte->getIdRessource());
    query.bindValue(":login", compte->getLogin());
    query.bindValue(":mdp", compte->getMdp());
    bool b_test = query.exec();
InterfaceBD::INSERT_COUNTER++;
    if(!b_test){
        qDebug() << "Erreur InterfaceBD::ajouterCompteBD : " << query.lastError();
    }

    return b_test;
}

bool InterfaceBD::supprimerCompteBD(int idCompte)
{
    QSqlQuery query(this->db);
    query.prepare("DELETE FROM TCompte WHERE Id = :idCompte");
    query.bindValue(":idCompte", idCompte);

    bool b_test = query.exec();
    if(!b_test){
        qDebug() << "Erreur InterfaceBD::supprimerCompteBD : " << query.lastError();
    }

    return b_test;
}

bool InterfaceBD::supprimerCompteParIdRessource(int idRessource)
{
    QSqlQuery query(this->db);
    query.prepare("DELETE FROM TCompte WHERE IdRessource = :idRessource");
    query.bindValue(":idRessource", idRessource);

    bool b_test = query.exec();
    if(!b_test){
        qDebug() << "Erreur InterfaceBD::supprimerCompteParIdRessource : " << query.lastError();
    }

    return b_test;
}

Compte* InterfaceBD::trouverCompteParIdRessourceBD(int idRessource)
{
    Compte* compte = nullptr;

    QSqlQuery query(db);
    query.prepare("SELECT Id, Login, MdP FROM TCompte WHERE IdRessource = :idRessource");
    query.bindValue(":idRessource", idRessource);
    bool b_test = query.exec();
    if(b_test && query.next()){
        int idType = query.value(0).toInt();
        QString login = query.value(1).toString();
        QString mdp = query.value(2).toString();

        return new Compte(idType, idRessource, login, mdp);
    }else if(! b_test){
        qDebug() << "Erreur InterfaceBD::trouverCompteParIdRessourceBD : " << query.lastError();
    }

    return compte;
}

QList<Compte *> InterfaceBD::trouverTousLesComptesBD()
{
    QSqlQuery query(this->db);
    query.prepare("SELECT Id, IdRessource, Login, MdP FROM TCompte");
    bool b_test = query.exec();
    QList<Compte*> listeDesComptes;
    if(b_test){
        while(query.next()){
            int idCompte= query.value(0).toInt();
            QString login = query.value(2).toString();
            QString mdp = query.value(3).toString();
            int idRessource = query.value(1).toInt();

            Compte* compte = new Compte(idCompte, idRessource, login, mdp);
            listeDesComptes.append(compte);
        }
    }else{
        qDebug() << "Erreur InterfaceBD::trouverTousLesComptesBD : " << query.lastError();
    }

    return listeDesComptes;
}

bool InterfaceBD::verifierExistenceCompte(QString login, QString mdp)
{
    QSqlQuery query(this->db);
    query.prepare("SELECT * FROM TCompte WHERE Login = :login AND MdP = :mdp");

    query.bindValue(":login",login );
    query.bindValue(":mdp", mdp);

    return (query.exec() && query.next());
}

bool InterfaceBD::ajouteType(Type *type)
{
    QSqlQuery query(this->db);
    query.prepare("INSERT INTO TType (Id, Label) VALUES(:idType, :label)");
    query.bindValue(":idType", type->getId());
    query.bindValue(":label", type->getLabel());

    bool b_test = query.exec();
InterfaceBD::INSERT_COUNTER++;
    if(!b_test){
        qDebug() << "Erreur InterfaceBD::verifierExistenceCompte : " << query.lastError();
    }

    return b_test;
}

Type *InterfaceBD::trouverTypeParId(int idType)
{
    Type* type = nullptr;

    QSqlQuery query(db);
    query.prepare("SELECT Id, Label FROM TType WHERE Id = :idType");
    query.bindValue(":idType", idType);
    bool b_test = query.exec();
    if(b_test && query.next()){
        int id = query.value(0).toInt();
        QString label = query.value(1).toString();

        return new Type(id, label);
    }else if(! b_test){
        qDebug() << "Erreur InterfaceBD::trouverTypeParId : " << query.lastError();
    }

    return type;
}

Type *InterfaceBD::trouverTypeParLabel(QString label)
{
    Type* type = nullptr;

    QSqlQuery query(db);
    query.prepare("SELECT Id, Label FROM TType WHERE Label = :label");
    query.bindValue(":label", label);
    bool b_test = query.exec();
    if(b_test && query.next()){
        int id = query.value(0).toInt();
        QString label = query.value(1).toString();

        return new Type(id, label);
    }else if(! b_test){
        qDebug() << "Erreur InterfaceBD::trouverTypeParLabel : " << query.lastError();
    }

    return type;
}

bool InterfaceBD::supprimerType(int idType)
{
    QSqlQuery query(this->db);
    query.prepare("DELETE FROM TType WHERE Id = :idType");
    query.bindValue(":idType", idType);

    bool b_test = query.exec();
    if(!b_test){
        qDebug() << "Erreur InterfaceBD::supprimerType : " << query.lastError();
    }

    return b_test;
}

QList<Type *> InterfaceBD::trouverTousLesTypes()
{
    QSqlQuery query(this->db);
    query.prepare("SELECT Id, Label FROM TType");
    bool b_test = query.exec();
    QList<Type*> listeDesTypes;
    if(b_test){
        while(query.next()){
            int idType= query.value(0).toInt();
            QString label = query.value(1).toString();

            Type* type = new Type(idType, label);
            listeDesTypes.append(type);
        }
    }else{
        qDebug() << "Erreur InterfaceBD::trouverTousLesTypes : " << query.lastError();
    }

    return listeDesTypes;
}



