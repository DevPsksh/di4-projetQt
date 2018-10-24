#ifndef DIALOGAPROPOS_H
#define DIALOGAPROPOS_H

#include <QDialog>

namespace Ui {
class Dialogapropos;
}

class Dialogapropos : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogapropos(QWidget *parent = 0);
    ~Dialogapropos();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialogapropos *ui;
};

#endif // DIALOGAPROPOS_H
