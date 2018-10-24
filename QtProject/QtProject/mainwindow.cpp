#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogajouterclient.h"
#include "dialogajouterressource.h"
#include "dialogapropos.h"
#include "controleurclient.h"
#include <QSortFilterProxyModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Gestion de RDV");

    ui->lineEdit_prenom->setText("mon prenom");

    //initialiser la table View des clients
    cc = new ControleurClient();
    ctm = new ClientTableModel(cc->trouverTousLesClientsBD(), this );

    QSortFilterProxyModel proxyModel;
    proxyModel.setSourceModel( ctm);

    ui->tableView->setModel(ctm);

    ui->tableView->sortByColumn(0, Qt::AscendingOrder);

    //initialiser la tree list View des ressources
    rtm = new RessourceTreeModel(cr->trouverTousLesRessouces(), this);
    ui->treeView->setModel(rtm);

    ui->statusBar->showMessage("Connected", 4000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}

void MainWindow::on_actionClient_triggered()
{
    DialogAjouterClient dac;
    if(dac.exec() == QDialog::Accepted){
        ctm->setClients(cc->trouverTousLesClientsBD());
        ui->statusBar->showMessage("Ajout de client terminé ", 4000);
    }

}

void MainWindow::on_actionRessource_triggered()
{
    DialogAjouterRessource dar;
    if(dar.exec() == QDialog::Accepted){
        rtm->setRessources(cr->trouverTousLesRessouces());
        ui->statusBar->showMessage("Ajout de ressource terminé ", 4000);
    }
}

void MainWindow::on_actionA_propos_triggered()
{
    Dialogapropos dap;
    dap.exec();
}

void MainWindow::on_pushButton_recherche_clicked()
{
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    int id = ui->lineEdit_numeroID->text().toInt();
    QDate dateDebut = ui->dateEdit_debutRecherche->date();
    QDate dateFin = ui->dateEdit_finRecherche->date();

    if(ui->checkBox_dates->checkState() == Qt::Unchecked && ui->checkBox_id->checkState() == Qt::Unchecked && nom.isEmpty() && prenom.isEmpty()){
        ctm->setClients(cc->trouverTousLesClientsBD());
    }else if(ui->checkBox_dates->checkState() == Qt::Checked && ui->checkBox_id->checkState() == Qt::Unchecked){
        ctm->setClients(cc->trouverClientsParNomPrenomDateDebutDateFin(nom, prenom, dateDebut, dateFin));
    }else if(ui->checkBox_id->checkState() == Qt::Checked && ui->checkBox_dates->checkState() == Qt::Unchecked){
        ctm->setClients(cc->trouverClientsParNomPrenomId(nom, prenom , id));

    }

    ui->statusBar->showMessage("Recherche des clients reussie ", 4000);
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    QItemSelectionModel *select = this->ui->tableView->selectionModel();

    if(select->hasSelection()){
        QModelIndexList selection = select->selectedRows();

        // Multiple rows can be selected
        for(int i=0; i< selection.count(); i++)
        {
            QModelIndex index = selection.at(i);
            qDebug() << index.row();
            cc->supprimerClient(ctm->getClients()[index.row()]->getId());
        }
        ctm->setClients(cc->trouverTousLesClientsBD());
        ui->statusBar->showMessage("Client supprimé ", 4000);
    }


}

void MainWindow::on_pushButton_modifier_clicked()
{
    QItemSelectionModel *select = this->ui->tableView->selectionModel();

    if(select->hasSelection()){
        QModelIndexList selection = select->selectedRows();

        // plusieurs lignes peuvent etre selectionnees
        for(int i=0; i< selection.count(); i++)
        {
            QModelIndex index = selection.at(i);
            qDebug() << index.row();
            DialogAjouterClient dac(ctm->getClients()[index.row()], this);
            if(dac.exec() == QDialog::Accepted){
                ctm->setClients(cc->trouverTousLesClientsBD());
            }
        }
        ui->statusBar->showMessage("Client modifié ", 4000);
    }

}


void MainWindow::on_pushButton_supprimer_ressources_clicked()
{
    QModelIndexList indexes = ui->treeView->selectionModel()->selectedIndexes();
    if(indexes.size() > 0 ){
        QModelIndex indexChoisi = indexes.at(0);
        Ressource *ressource = rtm->getRessource(indexChoisi);
        if(ressource != nullptr){
            //on supprime le ressource
            cr->supprimerRessource(ressource);
            delete rtm;

            //on met a jour notre tree view
            rtm = new RessourceTreeModel(cr->trouverTousLesRessouces(), this);
            this->ui->treeView->setModel(rtm);
        }
    }
    ui->statusBar->showMessage("Ressource supprimé ", 4000);
}

void MainWindow::on_pushButton_modifier_ressources_clicked()
{
    QModelIndexList indexes = ui->treeView->selectionModel()->selectedIndexes();
        if (indexes.size() > 0) {
            QModelIndex selectedIndex = indexes.at(0);
            Ressource* ressource = rtm->getRessource(selectedIndex);
            if(ressource != NULL)
            {
                DialogAjouterRessource dialog(ressource);

                if(dialog.exec() == QDialog::Accepted)
                {
                    delete rtm;
                    //on met a jour notre tree view

                    rtm = new RessourceTreeModel(cr->trouverTousLesRessouces(),this);
                    ui->treeView->setModel(rtm);
                }
            }
            ui->statusBar->showMessage("Ressource modifié ", 4000);
        }

}

void MainWindow::on_actionDivers_triggered()
{
//    DialogAjouterDivers dad;
//    if(dad.exec() == QDialog::Accepted){
//        ctm->setClients(cc->ajouterDivers());
//        ui->statusBar->showMessage("Ajout de divers terminé ", 4000);
//    }
}

void MainWindow::on_pushButton_clicked()
{

}
