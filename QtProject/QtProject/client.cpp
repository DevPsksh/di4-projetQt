#include "client.h"

Client::Client()
{
}

Client::Client(QString nom, QString prenom, QString adresse, QString ville, QString cp, QDate dateRdv, int dureeRdv, int priorite, int tel, QString commentaire)
{
    this->nom = nom;
    this->prenom= prenom;
    this->adresse = adresse;
    this->ville = ville;
    this->cp = cp;
    this->dateRdv = dateRdv;
    this->dureeRdv = dureeRdv;
    this->priorite = priorite;
    this->commentaire = commentaire;
    this->tel = tel;
}

Client::Client(int id, QString nom, QString prenom, QString adresse, QString ville, QString cp, QDate dateRdv, int dureeRdv, int priorite, int tel, QString commentaire)
{
    this->idClient = id;
    this->nom = nom;
    this->prenom= prenom;
    this->adresse = adresse;
    this->ville = ville;
    this->cp = cp;
    this->dateRdv = dateRdv;
    this->dureeRdv = dureeRdv;
    this->priorite = priorite;
    this->commentaire = commentaire;
    this->tel = tel;
}

Client::Client(QString nom, QString prenom, QString adresse, QString ville, QString cp, QDate dateRdv, int dureeRdv, int priorite)
{
    this->nom = nom;
    this->prenom= prenom;
    this->adresse = adresse;
    this->ville = ville;
    this->cp = cp;
    this->dateRdv = dateRdv;
    this->dureeRdv = dureeRdv;
    this->priorite = priorite;
}



int Client::getId()
{
    return this->idClient;
}

void Client::setId(int id)
{
    this->idClient =id;
}

QString Client::getNom(){
    return this->nom;
}

void Client::setNom(QString nom){
    this->nom = nom;
}

QString Client::getPrenom(){
    return this->prenom;
}

void Client::setPrenom(QString prenom){
    this->prenom = prenom;
}

QString Client::getAdresse(){
    return this->adresse;
}

void Client::setAdresse(QString adresse){
    this->adresse = adresse;
}

QString Client::getVille(){
    return this->ville;
}

void Client::setVille(QString ville){
    this->ville = ville;
}

QString Client::getCp(){
    return this->cp = cp;
}

void Client::setCp(QString cp){
    this->cp = cp;
}

QDate Client::getDateRdv(){
    return this->dateRdv;
}

void Client::setDateRdv(QDate dateRdv){
    this->dateRdv = dateRdv;
}

int Client::getDureeRdv(){
    return this->dureeRdv;
}

void Client::setDureeRdv(int dureeRdv){
    this->dureeRdv = dureeRdv;
}

int Client::getPriorite()
{
    return this->priorite;
}

void Client::setPriorite(int priorite){
    this->priorite = priorite;
}

QString Client::getCommentaire(){
    return this->commentaire;
}

void Client::setCommentaire(QString commentaire){
    this->commentaire = commentaire;
}

int Client::getTel(){
    return this->tel;
}

void Client::setTel(int tel){
    this->tel = tel;
}
