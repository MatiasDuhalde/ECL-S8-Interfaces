#ifndef COMPTEUR_H
#define COMPTEUR_H

#include <QObject>

class Compteur : public QObject
{
    Q_OBJECT
public:
    explicit Compteur(QObject *parent = nullptr);
    Q_INVOKABLE void increment();
    Q_INVOKABLE void decrement();

    Q_PROPERTY(QString cptQML READ readCompteur NOTIFY cptChanged)

signals:
    void cptChanged();

private:
    int fCompteur;
    QString readCompteur();

};

#endif // COMPTEUR_H
