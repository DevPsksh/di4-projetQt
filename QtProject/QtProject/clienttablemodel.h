#ifndef CLIENTTABLEMODEL_H
#define CLIENTTABLEMODEL_H

#include <QAbstractTableModel>
#include "client.h"

class ClientTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    explicit ClientTableModel(const QList<Client*>& listeDesClients, QObject *parent = 0);
        explicit ClientTableModel(QObject *parent = 0);

        // Header:
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

        // Basic functionality:
        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

        QVariant data(int row, int col) const;

        QList<Client *> getClients() const;
        void setClients(const QList<Client *> &value);



    private:
        QList<Client*> listeDesClients;
        void update();

};

#endif // CLIENTTABLEMODEL_H
