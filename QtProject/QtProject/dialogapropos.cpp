#include "dialogapropos.h"
#include "ui_dialogapropos.h"

Dialogapropos::Dialogapropos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogapropos)
{
    ui->setupUi(this);

    QPixmap polyPix(":/rec/icns/poly.png");
    this->ui->label_poly->setPixmap(polyPix);
    this->ui->label_poly->setScaledContents(true);
    this->ui->label_poly->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    QPixmap crPix(":/rec/icns/Copyright-Symbol.jpg");
    this->ui->label_cr->setPixmap(crPix);
    this->ui->label_cr->setScaledContents(true);
    this->ui->label_cr->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
}

Dialogapropos::~Dialogapropos()
{
    delete ui;
}

void Dialogapropos::on_pushButton_clicked()
{
    reject();
}
