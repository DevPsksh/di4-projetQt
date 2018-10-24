#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>
#include<QMessageBox>

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = 0);
    ~DialogLogin();

private slots:
    void on_pushButton_signin_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::DialogLogin *ui;
    bool isValid(QString username, QString password);
};

#endif // DIALOGLOGIN_H
