#include "dialogajouterclient.h"
#include "ui_dialogajouterclient.h"




DialogAjouterClient::DialogAjouterClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjouterClient)
{
    ui->setupUi(this);
    majClient = false;

    rlm = new RessourceListModel(cr.trouverTousLesRessouces(), this);
    ui->listView_ressource->setModel(rlm);
}

DialogAjouterClient::DialogAjouterClient(Client *client, QWidget *parent):
    QDialog(parent),
    ui(new Ui::DialogAjouterClient)
{
    ui->setupUi(this);
    this->client = client;
    majClient = true;

    //initialier les champs lorsqu'on modifie
    ui->lineEdit_adresse->setText(this->client->getAdresse());
    ui->lineEdit_cp->setText(this->client->getCp());
    ui->lineEdit_duree->setText(QString::number(this->client->getDureeRdv()));
    ui->lineEdit_nom->setText(this->client->getNom());
    ui->lineEdit_prenom->setText(this->client->getPrenom());
    ui->lineEdit_tel->setText(QString::number(this->client->getTel()));
    ui->lineEdit_ville->setText(this->client->getVille());
    ui->textEdit_commentaire->setPlainText(this->client->getCommentaire());
    ui->dateEdit->setDate(this->client->getDateRdv());
    rlm = new RessourceListModel(cr.trouverTousLesRessouces(), this);

    ui->listView_ressource->setModel(rlm);
    switch(this->client->getPriorite())
            {
            case 1:
                ui->radioButton_priorite1->setChecked(true);
                break;
            case 2:
                ui->radioButton_priorite2->setChecked(true);
                break;
            case 3:
                ui->radioButton_priorite3->setChecked(true);
                break;
            case 4:
                ui->radioButton_priorite4->setChecked(true);
                break;
            case 5:
                ui->radioButton_priorite5->setChecked(true);
                break;
            }
}

DialogAjouterClient::~DialogAjouterClient()
{
    delete ui;
}

void DialogAjouterClient::on_pushButton_annuler_clicked()
{
    reject();
}

void DialogAjouterClient::on_pushButton_ok_clicked()
{
    ControleurClient cc;
    Client client;
    QString nom = ui->lineEdit_nom->text();
    QString formatNom = nom.mid(0,1).toUpper()+nom.mid(1,nom.size() - 1).toLower();
    QString prenom = ui->lineEdit_prenom->text();
    QString formatPrenom = prenom.mid(0,1).toUpper()+prenom.mid(1,prenom.size() - 1).toLower();
    QString ville = ui->lineEdit_ville->text();
    QString formatVille = ville.mid(0,1).toUpper()+ville.mid(1,nom.size() - 1).toLower();
    QString adresse = ui->lineEdit_adresse->text();
    QString cp = ui->lineEdit_cp->text();
    QDate dateRdv = ui->dateEdit->date();
    int dureeRdv = ui->lineEdit_duree->text().toInt();
    int tel = ui->lineEdit_tel->text().toInt();
    QString commentaire = ui->textEdit_commentaire->toPlainText();

        int priorite = 1;
        if(ui->radioButton_priorite2->isChecked())
        {
            priorite = 2;
        }
        else if(ui->radioButton_priorite3->isChecked())
        {
            priorite = 3;
        }
        else if(ui->radioButton_priorite4->isChecked())
        {
            priorite = 4;
        }else if(ui->radioButton_priorite5->isChecked())
        {
            priorite = 5;
        }
    //Ajouter la liste des clients à la bd
    if(dateRdv  <= QDate::currentDate().addDays(30)){
        if(majClient){
            this->client->setAdresse(adresse);
            this->client->setNom(nom);
            this->client->setCommentaire(commentaire);
            this->client->setDateRdv(dateRdv);
            this->client->setDureeRdv(dureeRdv);
            this->client->setPriorite(priorite);
            this->client->setPrenom(prenom);
            this->client->setCp(cp);
            this->client->setVille(ville);
            this->client->setTel(tel);

            cc.modifierClient(this->client);
        }else {

            cc.ajouterClient(new Client(formatNom, formatPrenom , adresse , formatVille , cp , dateRdv, dureeRdv, priorite, tel , commentaire));
        }
     }
        accept();
}



