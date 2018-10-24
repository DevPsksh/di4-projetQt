#ifndef DIALOGAJOUTERDIVERS_H
#define DIALOGAJOUTERDIVERS_H

#include <QDialog>

namespace Ui {
class DialogAjouterDivers;
}

class DialogAjouterDivers : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjouterDivers(QWidget *parent = 0);
    ~DialogAjouterDivers();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogAjouterDivers *ui;
};

#endif // DIALOGAJOUTERDIVERS_H
