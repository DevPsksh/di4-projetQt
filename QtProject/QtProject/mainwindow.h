#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "clienttablemodel.h"
#include "controleurclient.h"
#include "ressourcetreemodel.h"
#include "controleurressource.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuitter_triggered();

    void on_actionClient_triggered();

    void on_actionRessource_triggered();

    void on_actionA_propos_triggered();

    void on_pushButton_recherche_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();


    void on_pushButton_supprimer_ressources_clicked();

    void on_pushButton_modifier_ressources_clicked();

    void on_actionDivers_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ClientTableModel *ctm;
    ControleurClient *cc;
    ControleurRessource *cr;
    RessourceTreeModel *rtm;
};

#endif // MAINWINDOW_H
