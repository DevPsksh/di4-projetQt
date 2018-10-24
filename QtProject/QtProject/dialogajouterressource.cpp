#include "dialogajouterressource.h"
#include "ui_dialogajouterressource.h"

#include <QMessageBox>

DialogAjouterRessource::DialogAjouterRessource(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjouterRessource)
{
    ui->setupUi(this);
    this->ressource = nullptr;
    majRessource = false;

}

DialogAjouterRessource::DialogAjouterRessource(Ressource *ressource, QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogAjouterRessource)
{
    ui->setupUi(this);

    this->ressource = ressource;
    majRessource = true;
    //init();

    ui->lineEdit_nom->setText(ressource->getNom());
    ui->lineEdit_prenom->setText(ressource->getNom());
    switch(ressource->getIdType())
            {
            case 1:
                ui->radioButton_banquierA->setChecked(true);
                break;
            case 2:
                ui->radioButton_banquierB->setChecked(true);
                break;
            case 3:
                ui->radioButton_assureurVoiture->setChecked(true);
                break;
            case 4:
                ui->radioButton_assureurLogement->setChecked(true);
                break;
            case 5:
                ui->radioButton_assureurVie->setChecked(true);
                break;
            case 6:
                ui->radioButton_informaticien->setChecked(true);
                Compte* compte = this->cc.trouverCompteParIdRessource(ressource->getIdRessource());
                ui->lineEdit_pseudo->setText(compte->getLogin());
                ui->lineEdit_mdp->setText(compte->getMdp());
                break;
            }
}

DialogAjouterRessource::~DialogAjouterRessource()
{
    delete ui;
}

void DialogAjouterRessource::on_pushButton_annuler_clicked()
{
    reject();
}

bool DialogAjouterRessource::verifierInformations(QString nom, QString prenom, int idType, QString pseudo, QString mdp)
{
    if(idType == 6){
        return !(nom.isEmpty() && prenom.isEmpty() && pseudo.isEmpty() && mdp.isEmpty());
    }else{
        return !(nom.isEmpty() && prenom.isEmpty());
    }
}


void DialogAjouterRessource::on_pushButton_ok_clicked()
{
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString login = ui->lineEdit_pseudo->text();
    QString mdp = ui->lineEdit_mdp->text();

    QString typeLabel = "Informaticien";
    int typeId = 7;
    bool estInformaticien = true;

    if(ui->radioButton_banquierA->isChecked())
        {
            typeId = 1;
            typeLabel = "Banquier A";
            estInformaticien = false;
        } else if(ui->radioButton_banquierB->isChecked())
        {
            typeId = 2;
            typeLabel = "Banquier B";
            estInformaticien = false;
        } else if(ui->radioButton_assureurLogement->isChecked())
        {
            typeId = 3;
            typeLabel = "Assureur Logement";
            estInformaticien = false;
        } else if(ui->radioButton_assureurVoiture->isChecked())
        {
            typeId = 4;
            typeLabel = "Assureur Voiture";
            estInformaticien = false;
        } else if(ui->radioButton_assureurVie->isChecked())
        {
            typeId = 5;
            typeLabel = "Assureur Vie";
            estInformaticien = false;
        }else if(ui->radioButton_divers->isChecked())
    {
        typeId = 6;
        typeLabel = "Divers";
        estInformaticien = false;
    }

    if(verifierInformations(nom, prenom, typeId, login, mdp)){

            if(!majRessource){
                cr.ajouterRessource(new Ressource(nom, prenom, typeId));
                if(estInformaticien){
                    cc.ajouterCompte(new Compte( cr.ajouterRessource(ressource), login, mdp));
                }
            }else{
                if(this->ressource->getIdType() == 7){
                    //on supprime l'ancien compte
                    cc.supprimerCompteParIdRessource(ressource->getIdRessource());
                }
                //on met a jour notre ressource
                ressource->setNom(nom);
                ressource->setPrenom(prenom);
                ressource->setIdType(typeId);


                //on modifier la base de donnee
                cr.modifierRessource(ressource);

                if(estInformaticien){
                    //on ajoute le nouveau compte de l'informaticien
                    cc.ajouterCompte(new Compte(ressource->getIdRessource(), login, mdp));
                }
            }

            accept();
            }
            else{
                QMessageBox::warning(this, "Erreur", "Des informations fournies ne sont pas valides!");
            }
}
