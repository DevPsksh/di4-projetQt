#ifndef CONTROLEURRESSOURCE_H
#define CONTROLEURRESSOURCE_H

#include <QList>
#include "ressource.h"

class ControleurRessource
{
public:
    ControleurRessource();

    bool ajouterRessource(Ressource *ressource);
    bool modifierRessource(Ressource *ressource);
    bool supprimerRessource(Ressource *ressource);
    Ressource* trouverRessourceParId(int idRessource);
    QList<Ressource*> trouverTousLesRessouces();
};

#endif // CONTROLEURRESSOURCE_H
