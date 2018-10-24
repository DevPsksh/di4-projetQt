#ifndef DIALOGAJOUTERRESSOURCE_H
#define DIALOGAJOUTERRESSOURCE_H

#include <QDialog>
#include "controleurcompte.h"
#include "controleurressource.h"
#include "ressourcetreemodel.h"
#include "controleurtype.h"
#include "compte.h"

namespace Ui {
class DialogAjouterRessource;
}

class DialogAjouterRessource : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjouterRessource(QWidget *parent = 0);
    explicit DialogAjouterRessource(Ressource* ressource, QWidget *parent = 0);
    ~DialogAjouterRessource();

private slots:
    void on_pushButton_annuler_clicked();


    void on_pushButton_ok_clicked();

private:
    Ui::DialogAjouterRessource *ui;
    Ressource *ressource;
    bool majRessource;
    ControleurCompte cc;
    ControleurRessource cr;
    ControleurType ct;
    RessourceTreeModel *rtm;

    bool verifierInformations(QString nom, QString prenom, int idType, QString pseudo, QString mdp);
};

#endif // DIALOGAJOUTERRESSOURCE_H
