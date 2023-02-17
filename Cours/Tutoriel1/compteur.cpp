#include "compteur.h"

Compteur::Compteur(QObject *parent)
    : QObject{parent}
{
    fCompteur = 10;
    emit cptChanged();
}

void Compteur::increment(){
    if (fCompteur < 15) {
        fCompteur++;
        emit cptChanged();
    }
}

void Compteur::decrement(){
    if (fCompteur > 5) {
        fCompteur--;
        emit cptChanged();
    }
}

QString Compteur::readCompteur() {
    return QString::number(fCompteur);
}
