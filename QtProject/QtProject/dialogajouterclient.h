#ifndef DIALOGAJOUTERCLIENT_H
#define DIALOGAJOUTERCLIENT_H

#include <QDialog>
#include "interfacebd.h"
#include "controleurressource.h"
#include "ressourcelistmodel.h"
#include "controleurclient.h"

namespace Ui {
class DialogAjouterClient;
}

class DialogAjouterClient : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjouterClient(QWidget *parent = 0);
    explicit DialogAjouterClient(Client *client, QWidget *parent = 0);
    ~DialogAjouterClient();

private slots:
    void on_pushButton_annuler_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::DialogAjouterClient *ui;
    Client *client;
    ControleurRessource cr;
    RessourceListModel *rlm;
    bool majClient;
};

#endif // DIALOGAJOUTERCLIENT_H
