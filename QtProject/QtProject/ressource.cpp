#include "ressource.h"

Ressource::Ressource()
{
}

Ressource::Ressource(int idR, QString nom, QString prenom, int idT){
    this->idRessource = idR;
    this->nom = nom;
    this->prenom = prenom;
    this->idType = idT;
}

Ressource::Ressource(QString nom, QString prenom, int idType)
{
    this->nom = nom;
    this->prenom = prenom;
    this->idType = idType;
}

int Ressource::getIdRessource(){
    return this->idRessource;
}

void Ressource::setIdRessource(int idr){
    this->idRessource = idr;
}

int Ressource::getIdType(){
    return this->idType;
}

void Ressource::setIdType(int idt){
    this->idType = idt;
}

QString Ressource::getNom(){
    return this->nom;
}

void Ressource::setNom(QString nom){
    this->nom = nom;
}

QString Ressource::getPrenom(){
    return this->prenom;
}

void Ressource::setPrenom(QString prenom){
    this->prenom = prenom;
}
