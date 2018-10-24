#include "clienttablemodel.h"


ClientTableModel::ClientTableModel(const QList<Client*>& listeDesClients, QObject *parent)
    : QAbstractTableModel(parent)
{
    this->listeDesClients = listeDesClients;
}

ClientTableModel::ClientTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant ClientTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
            return QVariant();

    if (orientation == Qt::Horizontal) {
        switch(section)
        {
        case 0:
            return "Nom";
        case 1:
            return "Prenom";
        case 2:
            return "Date du rendez-vous";
        case 3:
            return "Numéro d'identification";
        case 4:
            return "Adresse";
        case 5:
            return "Ville";

        }
    }
    return QVariant();
}

int ClientTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return listeDesClients.count();
}

int ClientTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 6;
}

QVariant ClientTableModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole || !index.isValid() ||
            index.row() >= this->listeDesClients.count() || index.column() >= this->columnCount())
    {
        return QVariant();
    }
    switch(index.column())
    {
    case 0:
        return listeDesClients.at(index.row())->getNom();
    case 1:
        return listeDesClients.at(index.row())->getPrenom();
    case 2:
        return listeDesClients.at(index.row())->getDateRdv();
    case 3:
        return listeDesClients.at(index.row())->getId();
    case 4:
        return listeDesClients.at(index.row())->getAdresse();
    case 5:
        return listeDesClients.at(index.row())->getVille();;
    }

    return QVariant();
}

QVariant ClientTableModel::data(int row, int col) const
{
    if (row >= this->listeDesClients.count() || col >= this->columnCount())
    {
        return QVariant();
    }
    switch(col)
    {
    case 0:
        return listeDesClients.at(row)->getNom();
    case 1:
        return listeDesClients.at(row)->getPrenom();
    case 2:
        return listeDesClients.at(row)->getDateRdv();
    case 3:
        return listeDesClients.at(row)->getId();
    case 4:
        return listeDesClients.at(row)->getAdresse();
    case 5:
        return listeDesClients.at(row)->getVille();;

    }

    return QVariant();
}

void ClientTableModel::update()
{
    QModelIndex topLeft = index(0, 0);
    QModelIndex bottomRight = index(rowCount() - 1, columnCount() - 1);
    emit dataChanged(topLeft, bottomRight);
    emit layoutChanged();
}

QList<Client *> ClientTableModel::getClients() const
{
    return listeDesClients;
}

void ClientTableModel::setClients(const QList<Client *> &value)
{
    listeDesClients = value;
    update();
}
