#include "compte.h"

Compte::Compte()
{

}

Compte::Compte(int id, int idRessource, QString login, QString mdp)
{
    this->id = id;
    this->idRessource = idRessource;
    this->login = login;
    this->mdp = mdp;
}

Compte::Compte(int idRessource, QString login, QString mdp)
{
    this->idRessource = idRessource;
    this->login = login;
    this->mdp = mdp;
}

int Compte::getId(){
    return this->id;
}

void Compte::setId(int id){
    this->id = id;
}

int Compte::getIdRessource(){
    return this->idRessource;
}

void Compte::setIdRessource(int idr){
    this->idRessource = idr;
}

QString Compte::getLogin(){
    return this->login;
}

void Compte::setLogin(QString login){
    this->login = login;
}

QString Compte::getMdp(){
    return this->mdp;
}

void Compte::setMdp(QString mdp){
    this->mdp = mdp;
}
