#include "mainwindow.h"
#include <QApplication>
#include "dialoglogin.h"
#include "c_init_bd.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "interfacebd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    C_INIT_BD::Creation_BD();


    DialogLogin l;
    bool connected = QDialog::Accepted;

    if(l.exec() == connected){
        MainWindow w;
        w.show();

        //Affichage le nombre des INSERT
        int exitValue = a.exec();
        qDebug() << "Nombre des requetes INSERT utilisées :" << InterfaceBD::INSERT_COUNTER ;
        return exitValue;
    }

    //QTL
    // 1.Création Multimap
        std::multimap<int,std::string> map;

        // 2.Ajout des Valeurs
        map.insert(std::pair<int,std::string>(1,"titi"));
        map.insert(std::pair<int,std::string>(4,"toto"));
        map.insert(std::pair<int,std::string>(3,"tutu"));
        map.insert(std::pair<int,std::string>(4,"tata"));

        //3.Suppression de l'element 3
        map.erase(3);

        //4.Ajout de L'element 0, tete
        map.insert(std::pair<int,std::string>(0,"tete"));

        //5.Affichage dans l'ordre des clés
        for(std::multimap<int, std::string>::iterator it = map.begin(); it != map.end(); it++)
            qDebug() << it->first << " : " << QString::fromStdString(it->second );


    return 0;
}
