#ifndef RESSOURCETREEMODEL_H
#define RESSOURCETREEMODEL_H


#include <QAbstractItemModel>
#include <QStandardItem>

#include "ressourcetreemodel.h"
#include "ressourcetreeitem.h"
#include "ressource.h"

class RessourceTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit RessourceTreeModel(QList<Ressource *> ressources, QObject *parent = 0);
    explicit RessourceTreeModel(QObject *parent = 0);
    ~RessourceTreeModel();

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                            int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                          const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QList<Ressource *> getRessources() const;
    void setRessources(const QList<Ressource *> &value);
    Ressource* getRessource(const QModelIndex &index);

private:
    void setupModelData();
    QList<Ressource *> ressources;
    RessourceTreeItem *rootItem;

    void update();
};

#endif // RESSOURCETREEMODEL_H
