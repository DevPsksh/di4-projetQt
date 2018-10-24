#include "dialogajouterdivers.h"
#include "ui_dialogajouterdivers.h"

#include<ressource.h>
#include"controleurressource.h"

DialogAjouterDivers::DialogAjouterDivers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjouterDivers)
{
    ui->setupUi(this);
}

DialogAjouterDivers::~DialogAjouterDivers()
{
    delete ui;
}

void DialogAjouterDivers::on_pushButton_clicked()
{
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    ControleurRessource cr;

    cr.ajouterRessource(new Ressource(nom, prenom, 6));

}
