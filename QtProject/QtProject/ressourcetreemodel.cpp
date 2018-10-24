#include "ressourcetreemodel.h"

RessourceTreeModel::RessourceTreeModel(QList<Ressource *> ressources, QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new RessourceTreeItem("");
    this->ressources= ressources;
    setupModelData();
}

RessourceTreeModel::RessourceTreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new RessourceTreeItem("");
    setupModelData();
}

RessourceTreeModel::~RessourceTreeModel()
{
    delete rootItem;
}

QVariant RessourceTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    RessourceTreeItem *item = static_cast<RessourceTreeItem *>(index.internalPointer());
    return item->data();
}

Qt::ItemFlags RessourceTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}

QVariant RessourceTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data();

    return QVariant();
}

QModelIndex RessourceTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
            return QModelIndex();

    RessourceTreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<RessourceTreeItem*>(parent.internalPointer());

    RessourceTreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex RessourceTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    RessourceTreeItem *childItem = static_cast<RessourceTreeItem*>(index.internalPointer());
    RessourceTreeItem *parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int RessourceTreeModel::rowCount(const QModelIndex &parent) const
{
    RessourceTreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<RessourceTreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int RessourceTreeModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

void RessourceTreeModel::setupModelData()
{
    RessourceTreeItem *typesItem = new RessourceTreeItem("Types");
    RessourceTreeItem *nomsItem = new RessourceTreeItem("Noms");

    RessourceTreeItem *banquierAItem = new RessourceTreeItem("Banquier A");
    typesItem->appendChild(banquierAItem);

    RessourceTreeItem *banquierBItem = new RessourceTreeItem("Banquier B");
    typesItem->appendChild(banquierBItem);

    RessourceTreeItem *insureurLogementItem = new RessourceTreeItem("Insureur Logement");
    typesItem->appendChild(insureurLogementItem);

    RessourceTreeItem *insureurVoitureItem = new RessourceTreeItem("Insureur voiture");
    typesItem->appendChild(insureurVoitureItem);

    RessourceTreeItem *insureurVieItem = new RessourceTreeItem("Insureur vie");
    typesItem->appendChild(insureurVieItem);

    RessourceTreeItem *diversItem = new RessourceTreeItem("divers");
    typesItem->appendChild(diversItem);

    RessourceTreeItem *informaticienItem = new RessourceTreeItem("Informaticien et divers");
    typesItem->appendChild(informaticienItem);

    foreach (Ressource* ressource, this->ressources) {
        nomsItem->appendChild(new RessourceTreeItem(ressource));
        switch(ressource->getIdType())
        {
        case 1:
            banquierAItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 2:
            banquierBItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 3:
            insureurLogementItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 4:
            insureurVoitureItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 5:
            insureurVieItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 6:
            diversItem->appendChild(new RessourceTreeItem(ressource));
            break;
        case 7:
            informaticienItem->appendChild(new RessourceTreeItem(ressource));
            break;
        }
    }

    rootItem->appendChild(typesItem);
    rootItem->appendChild(nomsItem);
}

void RessourceTreeModel::update()
{
    QModelIndex topLeft = index(0, 0);
    QModelIndex bottomRight = index(rowCount() - 1, columnCount() - 1);
    emit dataChanged(topLeft, bottomRight);
    emit layoutChanged();
}

QList<Ressource *> RessourceTreeModel::getRessources() const
{
    return ressources;
}

void RessourceTreeModel::setRessources(const QList<Ressource *> &value)
{
    ressources = value;
    delete rootItem;
    rootItem = new RessourceTreeItem("");

    setupModelData();
    update();
}

Ressource *RessourceTreeModel::getRessource(const QModelIndex &index)
{
    if (!index.isValid())
        return NULL;

    RessourceTreeItem *item = static_cast<RessourceTreeItem *>(index.internalPointer());
    return item->getRessource();
}

