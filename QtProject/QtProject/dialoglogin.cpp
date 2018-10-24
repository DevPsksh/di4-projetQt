#include "dialoglogin.h"
#include "ui_dialoglogin.h"

#include"interfacebd.h"

DialogLogin::DialogLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLogin)
{
    ui->setupUi(this);

    QPixmap loginPix(":/rec/icns/000000028829.png");
    this->ui->label_iconLogin->setPixmap(loginPix);
    this->ui->label_iconLogin->setScaledContents(true);
    this->ui->label_iconLogin->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

DialogLogin::~DialogLogin()
{
    delete ui;
}

void DialogLogin::on_pushButton_signin_clicked()
{
    QString username, password;
    username = ui->lineEdit_userName->text();
    password = ui->lineEdit_password->text();
    if(isValid(username, password)){
        accept();
    }else{
        QMessageBox::warning(this, "Sign In", "Log In failed ! \n Username or password is not correct ;) ");
        ui->lineEdit_password->setText("");
    }
}

bool DialogLogin::isValid(QString username, QString password){
    InterfaceBD ibd;
    return ibd.verifierExistenceCompte(username, password);
}

void DialogLogin::on_pushButton_cancel_clicked()
{
    close();
}
