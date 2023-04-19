# Examen 2020-2021

- Temps disponible: 1 heure

## Question 1

On considère la classe "Entier" représentant un nombre entier et dont l'attribut permettant de stocker la valeur entière devra être alloué dynamiquement. La déclaration de cette classe est la suivante :

```c++
class Entier
{
public:
    Entier();
    Entier(int);
    ~Entier();
    Entier(const Entier&);

    Entier& operator=(const Entier&);
    Entier& operator=(int);

    friend ostream& operator<<(ostream&, const Entier&);

private:
    int* valeur;
}
```

Ecrire le code du constructeur par copie de cette classe.

### Réponse 1

```c++
Entier::Entier(const Entier& e)
{
    valeur = new int;
    *valeur = *e.valeur;
}
```

## Question 2

Étant donné la classe suivante (fonctionnelle), qui simule une pile (Last In First out) :

```c++
class PileIntStat
{
public:
    PileIntStat(int taille=100);
    int get_taille();
    bool est_vide();
    void empile(int v);
    int depile();
private:
    int tab[100];
    int top;
    int taille;
}
```

```c++
#include "pileintstat.h"

PileIntStat::PileIntStat(int t)
{
    if (t >= 100)
        taille = 100;
    else
        taille = t;
    top = -1;
}

int PileIntStat::get_taille()
{
    return taille;
}

bool PileIntStat::est_vide()
{
    return top == -1;
}

void PileIntStat::empile(int v)
{
    top++;
    tab[top] = v;
}

int PileIntStat::depile()
{
    int v = tab[top];
    top--;
    return v;
}
```

Étant donné le programme principal suivant, que voit-on s’imprimer à l’écran ?

```c++
int main()
{
    PuleIntStat p(10);
    cout << "Taille de la pile : " << p.get_taille() << endl;
    p.empile(22);
    p.empile(207);

    int v;
    while (!p.est_vide())
    {
        v = p.depile();
        cout << "Valeur : " << v << endl;
    }
    return 0;
}
```

Veuillez choisir une réponse.

a. (rien ne s’affiche car le programme plante)

b.

```text
Taille de la pile : 10
```

c.

```text
Taille de la pile : 10
Valeur : 207
```

d.

```text
Taille de la pile : 10
Valeur : 207
Valeur : 22
```

### Réponse 2

d.

```text
Taille de la pile : 10
Valeur : 207
Valeur : 22
```

## Question 3

On considère la classe "Entier" représentant un nombre entier et dont l'attribut permettant de stocker la valeur entière devra être alloué dynamiquement. La déclaration de cette classe est la suivante :

```c++
class Entier
{
public:
    Entier();
    Entier(int);
    ~Entier();
    Entier(const Entier&);

    Entier& operator=(const Entier&);
    Entier& operator=(int);

    friend ostream& operator<<(ostream&, const Entier&);

private:
    int* valeur;
}
```

Proposer un programme principal utilisant toutes la capacités de cette classe.

### Réponse 3

```c++
int main()
{
    Entier e1(10);
    Entier e2(e1);
    Entier e3;
    Entier* e4 = new Entier(20);

    e1 = 20;
    e2 = *e4;

    cout << e1 << endl;
    cout << e2 << endl;

    delete e4;

    return 0;
}
```

## Question 4

On considère la classe "Entier" représentant un nombre entier et dont l'attribut permettant de stocker la valeur entière devra être alloué dynamiquement. La déclaration de cette classe est la suivante :

```c++
class Entier
{
public:
    Entier();
    Entier(int);
    ~Entier();
    Entier(const Entier&);

    Entier& operator=(const Entier&);
    Entier& operator=(int);

    friend ostream& operator<<(ostream&, const Entier&);

private:
    int* valeur;
}
```

Ecrire le code du constructeur sans argument de cette classe.

### Réponse 4

```c++
Entier::Entier()
{
    valeur = new int;
    *valeur = 0;
}
```

## Question 5

On considère la classe "Entier" représentant un nombre entier et dont l'attribut permettant de stocker la valeur entière devra être alloué dynamiquement. La déclaration de cette classe est la suivante :

```c++
class Entier
{
public:
    Entier();
    Entier(int);
    ~Entier();
    Entier(const Entier&);

    Entier& operator=(const Entier&);
    Entier& operator=(int);

    friend ostream& operator<<(ostream&, const Entier&);

private:
    int* valeur;
}
```

Ecrire le code du destructeur de cette classe.

### Réponse 5

```c++
Entier::~Entier()
{
    delete valeur;
}
```

## Question 6

On considère la classe "Entier" représentant un nombre entier et dont l'attribut permettant de stocker la valeur entière devra être alloué dynamiquement. La déclaration de cette classe est la suivante :

```c++
class Entier
{
public:
    Entier();
    Entier(int);
    ~Entier();
    Entier(const Entier&);

    Entier& operator=(const Entier&);
    Entier& operator=(int);

    friend ostream& operator<<(ostream&, const Entier&);

private:
    int* valeur;
}
```

Ecrire le code du constructeur de cette classe ayant un argument entier.

### Réponse 6

```c++
Entier::Entier(int v)
{
    valeur = new int;
    *valeur = v;
}
```

## Question 7

Soit la classe "Compteur" suivante :

```c++
class Compteur
{
public:
    Compteur();
    void inc();
    void dec();
    int get_valeur();

private:
    int valeur;
}
```

```c++
Compteur::Compteur() {
    valeur = 0;
}

void Compteur::inc() {
    valeur++;
}

void Compteur::dec() {
    valeur--;
    if (valeur < 0)
        valeur = 0;
}

int Compteur::get_valeur() {
    return valeur;
}
```

On souhaite maintenant une classe "Compteur_borne" héritant de la classe "Compteur", et dont l'incrémentation de la valeur ne pourra excéder une valeur limite, qui devra être un attribut de la classe et initialisée par le constructeur qui recevra la valeur en argument.

Ecrire la classe "Compteur_borne" (déclaration de la classe et code des méthodes) permettant d'obtenir ce comportement.

### Réponse 7

```c++
class Compteur_borne : public Compteur
{
public:
    Compteur_borne(int);

private:
    int borne;
}
```

```c++
Compteur_borne::Compteur_borne(int b) : Compteur()
{
    borne = b;
}

Compteur_borne::inc()
{
    if (valeur < borne)
        valeur++;
}
```

## Question 8

On considère la classe "Entier" représentant un nombre entier et dont l'attribut permettant de stocker la valeur entière devra être alloué dynamiquement. La déclaration de cette classe est la suivante :

```c++
class Entier
{
public:
    Entier();
    Entier(int);
    ~Entier();
    Entier(const Entier&);

    Entier& operator=(const Entier&);
    Entier& operator=(int);

    friend ostream& operator<<(ostream&, const Entier&);

private:
    int* valeur;
}
```

Ecrire le code des deux surcharges de l'opérateur d'affectation (=) de cette classe.

### Réponse 8

```c++
Entier& Entier::operator=(const Entier& e)
{
    if (this != &e)
    {
        *valeur = *e.valeur;
    }

    return *this;
}

Entier& Entier::operator=(int v)
{
    *valeur = v;

    return *this;
}
```

## Question 9

Étant donné la classe suivante (fonctionnelle), qui simule une pile (Last In First out) :

```c++
class PileIntStat
{
public:
    PileIntStat(int taille=100);
    int get_taille();
    bool est_vide();
    void empile(int v);
    int depile();
private:
    int tab[100];
    int top;
    int taille;
}
```

```c++
#include "pileintstat.h"

PileIntStat::PileIntStat(int t)
{
    if (t >= 100)
        taille = 100;
    else
        taille = t;
    top = -1;
}

int PileIntStat::get_taille()
{
    return taille;
}

bool PileIntStat::est_vide()
{
    return top == -1;
}

void PileIntStat::empile(int v)
{
    top++;
    tab[top] = v;
}

int PileIntStat::depile()
{
    int v = tab[top];
    top--;
    return v;
}
```

On veut pouvoir afficher tous les éléments d’une pile avec l’opérateur "<<" (que l'on suppose déclaré comme ami de la classe PileIntStat). Laquelle des versions suivantes de cet opérateur est LA meilleure, sachant que l’usage de la méthode serait le suivant :

```c++
int main()
{
    PileIntStat p(13);
    for (int q = 0; q < 13; q++)
        p.empile(q);
    cout << p;
    return 0;
}
```

Veuillez choisir une réponse.

a.

```c++
ostream& operator<<(ostream& sortie, PileIntStat& V)
{
    for (int i = 0; i < min(V.top + 1, V.taille); i++)
        sortie << V->tab[i] << " ";
    return sortie;
}
```

b.

```c++
ostream& operator<<(ostream& sortie, PileIntStat* V)
{
    for (int i = 0; i < min(V.top + 1, V.taille); i++)
        sortie << V->tab[i] << " ";
    return sortie;
}
```

c.

```c++
ostream& operator<<(ostream& sortie, PileIntStat& V)
{
    for (int i = 0; i < min(V.top + 1, V.taille); i++)
        sortie << V.tab[i] << " ";
    return sortie;
}
```

### Réponse 9

c.

```c++
ostream& operator<<(ostream& sortie, PileIntStat& V)
{
    for (int i = 0; i < min(V.top + 1, V.taille); i++)
        sortie << V.tab[i] << " ";
    return sortie;
}
```

Explication :

- L'option a. est incorrecte car on ne peut pas utiliser l'opérateur "->" sur un objet de type PileIntStat, mais seulement sur un pointeur sur PileIntStat.

- L'option b. est incorrecte car le paramètre de la fonction doit être une référence et non un pointeur.

## Question 10

On considère la classe "Entier" représentant un nombre entier et dont l'attribut permettant de stocker la valeur entière devra être alloué dynamiquement. La déclaration de cette classe est la suivante :

```c++
class Entier
{
public:
    Entier();
    Entier(int);
    ~Entier();
    Entier(const Entier&);

    Entier& operator=(const Entier&);
    Entier& operator=(int);

    friend ostream& operator<<(ostream&, const Entier&);

private:
    int* valeur;
}
```

Ecrire le code de l'opérateur d'écriture "<<" ami de cette classe.

### Réponse 10

```c++
ostream& operator<<(ostream& sortie, const Entier& e)
{
    sortie << *e.valeur;
    return sortie;
}
```

## Question 11

Étant donné la classe suivante (fonctionnelle), qui simule une pile (Last In First out) :

```c++
class PileIntStat
{
public:
    PileIntStat(int taille=100);
    int get_taille();
    bool est_vide();
    void empile(int v);
    int depile();
private:
    int tab[100];
    int top;
    int taille;
}
```

```c++
#include "pileintstat.h"

PileIntStat::PileIntStat(int t)
{
    if (t >= 100)
        taille = 100;
    else
        taille = t;
    top = -1;
}

int PileIntStat::get_taille()
{
    return taille;
}

bool PileIntStat::est_vide()
{
    return top == -1;
}

void PileIntStat::empile(int v)
{
    top++;
    tab[top] = v;
}

int PileIntStat::depile()
{
    int v = tab[top];
    top--;
    return v;
}
```

Imaginons que nous ayons développé une classe générique, appelée PileStat, pour gérer des piles d’objets quelconques, et munie de l'opérateur d'écriture "<<". Quelle impression obtiendrions-nous à l’écran si on exécutait le programme suivant :

```c++
int main()
{
    int size = 10;
    PileIntStat p(size);
    for (int i = 0; i < size; i++)
        p.empile(i);
    PileIntStat q(size);
    for (int i = 100; i < 100 + size; i++)
        q.empile(i);

    PileStat<PileIntStat> A;
    A.empile(q);
    A.empile(p);
    cout << endl << A;
    return 0;
}
```

Veuillez choisir une réponse.

a. (rien car le programme plante)

b. `0x7ffeee8866d0  0x7ffeee886870`

c. `0  1  2  3  4  5  6  7  8  9  100  101  102  103  104  105  106  107  108  109`

d. `100  0`

e. `100  101  102  103  104  105  106  107  108  109  0  1  2  3  4  5  6  7  8  9`

### Réponse 11

La réponse dépend de la façon dont on a défini l'opérateur d'écriture "<<" pour la classe générique `PileStat`, et si l'opérateur d'écriture "<<" est défini pour la classe `PileIntStat`.

Donc les réponses possibles sont a, b et c.

Mais la réponse est probablement a. si on considère que l'opérateur d'écriture n'est toujours pas défini. La réponse est c. si on considère que l'opérateur d'écriture est défini pour la classe `PileIntStat` (e.g. celui de la question précédente).

Explication :

- L'operateur d'écriture "<<" n'est pas défini pour la classe `PileIntStat`, donc même si on a défini l'opérateur d'écriture "<<" pour la classe générique `PileStat`, le programme devrait planter quand on essaie d'afficher un objet `PileIntStat` avec l'opérateur d'écriture "<<".
- L'option b. pourrait être correcte si la m
- Les options c, d et e est devraient être incorrectes car l'opérateur d'écriture "<<" n'est pas défini pour la classe `PileIntStat`.
- Cependant, si on considère que l'opérateur d'écriture "<<" est défini pour la classe `PileIntStat`, alors l'option c. est correcte.

## Question 12

Étant donné la classe suivante (fonctionnelle), qui simule une pile (Last In First out) :

```c++
class PileIntStat
{
public:
    PileIntStat(int taille=100);
    int get_taille();
    bool est_vide();
    void empile(int v);
    int depile();
private:
    int tab[100];
    int top;
    int taille;
}
```

```c++
#include "pileintstat.h"

PileIntStat::PileIntStat(int t)
{
    if (t >= 100)
        taille = 100;
    else
        taille = t;
    top = -1;
}

int PileIntStat::get_taille()
{
    return taille;
}

bool PileIntStat::est_vide()
{
    return top == -1;
}

void PileIntStat::empile(int v)
{
    top++;
    tab[top] = v;
}

int PileIntStat::depile()
{
    int v = tab[top];
    top--;
    return v;
}
```

Imaginons que nous ayons développé une classe générique, appelée PileStat, pour gérer des piles d’objets quelconques, et munie de l'opérateur d'écriture "<<". Lesquels de ces programmes principaux vous semblent corrects ?

Veuillez choisir au moins une réponse.

a.

```c++
int main()
{
    PileIntStat q(55);
    PileStat<PileIntStat*> A;
    A.empile(&q);
    cout << endl << A;
    return 0;
}
```

b.

```c++
int main()
{
    int size = 13;
    PuleStat<char> w(size);
    for (int q = 60; q < 60 + size; q++)
        w.empile(q);
    cout << endl << w;
    return 0;
}
```

c.

```c++
int main()
{
    PileIntStat q(55);
    PileStat<PileIntStat> A;
    A.empile(q);
    cout << endl << A;
    return 0;
}
```

### Réponse 12

Soit a et b, soit toutes les réponses sont correctes.

Explication :

- Dans l'option a. on a une pile de pointeurs vers des objets `PileIntStat`. On empile une adresse de `PileIntStat` dans la pile (un pointeur). L'operateur "<<" est défini pour les adresses.
- Dans l'option b. on a une pile de caractères. On empile des ints, mais ils sont convertis en caractères implicitement. L'operateur "<<" est défini pour les caractères.
- Dans l'option c. on a une pile d'objets `PileIntStat`. On empile des objets `PileIntStat` dans la pile. L'operateur "<<" normalement n'est pas défini pour les objets `PileIntStat`, sauf si on utilise celui de la question 10.

## Question 13

Étant donné la classe suivante (fonctionnelle), qui simule une pile (Last In First out) :

```c++
class PileIntStat
{
public:
    PileIntStat(int taille=100);
    int get_taille();
    bool est_vide();
    void empile(int v);
    int depile();
private:
    int tab[100];
    int top;
    int taille;
}
```

```c++
#include "pileintstat.h"

PileIntStat::PileIntStat(int t)
{
    if (t >= 100)
        taille = 100;
    else
        taille = t;
    top = -1;
}

int PileIntStat::get_taille()
{
    return taille;
}

bool PileIntStat::est_vide()
{
    return top == -1;
}

void PileIntStat::empile(int v)
{
    top++;
    tab[top] = v;
}

int PileIntStat::depile()
{
    int v = tab[top];
    top--;
    return v;
}
```

Indiquer le ou les programmes principaux corrects :

Veuillez choisir au moins une réponse.

a.

```c++
int main()
{
    PileIntStat q(10);
    p->empile(13);
    cout << "Pile vie ? : " << q->est_vide() << endl;
    return 0;
}
```

b.

```c++
int main()
{
    PileIntStat p(7);
    p[0] = -33;
    return 0;
}
```

c.

```c++
int main()
{
    PileIntStat p(10);
    cout << "Taille de la pile : " << p.get_taille() << endl;
    p.empile(22);
    p.empile(207);
    return 0;
}
```

d.

```c++
int main()
{
    int size = 200;
    PileIntStat s(size);
    for (int i = 0; i < size; i++)
        s.empile(i);
    return 0;
}
```

e.

```c++
int main()
{
    PileIntStat **q = new PileIntStat*[10];
    for (int i = 0; i < 10; i++)
        q[i] = new PileIntStat(3 * (i + 5));
    cout << q[0]->est_vide() << endl;
    cout << q[1]->get_taille() << endl;
    delete [] q;
    return 0;
}
```

f.

```c++
int main()
{
    PileIntStat *v = new PileIntStat();
    v->empile(22);
    PileIntStat p1(13);
    p1.empile(v.depile());
    delete p1;
    return 0;
}
```

g.

```c++
int main()
{
    PileIntStat *v = new PileIntStat();
    cout << "Taille de la pile : " << v->get_taille() << endl;
    v->empile(22);
    cout << v->est_vide();
    delete v;
    return 0;
}
```

### Réponse 13

c. et g. sont définitivement corrects. e. est correct si on ne considère pas le memory leak. Les autres réponses sont incorrectes.

Explication :

- a. est faux car on ne peut pas utiliser l'operateur "->" sur un objet.
- b. est faux car on ne peut pas accéder à un élément de la pile directement avec l'operateur "[]".
- c. est correct.
- d. est faux car on ne peut pas empiler plus d'éléments que la taille de la pile (limitée à 100).
- e. fonctionne mais il y a un memory leak. À la fin on efface l'array, mais on n'efface pas les éléments de l'array dynamiquement crées.
- f. est faux car on ne peut pas utiliser l'operateur "." sur un pointeur. De plus, on ne peut pas effacer un objet directement avec delete.
- g. est correct.

## Question 14

Étant donné la classe suivante (fonctionnelle), qui simule une pile (Last In First out) :

```c++
class PileIntStat
{
public:
    PileIntStat(int taille=100);
    int get_taille();
    bool est_vide();
    void empile(int v);
    int depile();
private:
    int tab[100];
    int top;
    int taille;
}
```

```c++
#include "pileintstat.h"

PileIntStat::PileIntStat(int t)
{
    if (t >= 100)
        taille = 100;
    else
        taille = t;
    top = -1;
}

int PileIntStat::get_taille()
{
    return taille;
}

bool PileIntStat::est_vide()
{
    return top == -1;
}

void PileIntStat::empile(int v)
{
    top++;
    tab[top] = v;
}

int PileIntStat::depile()
{
    int v = tab[top];
    top--;
    return v;
}
```

Pour cette classe, on souhaite implémenter un opérateur += qui ajoute une pile à une autre pile existante. Attention : les éléments de la pile à droite de l’opérateur sont dépilés au fur et à mesure qu’ils sont ajoutés à la pile à gauche de l’opérateur.

Parmi les choix ci-dessous, quelle est l’implémentation optimale de cet opérateur (une seule solution optimale) ?

Veuillez choisir une réponse.

a.

```c++
PileIntStat PileIntStat::operator+=(PileIntStat D)
{
    PileIntStat W(this->top + D.top + 2);
    while ((top < taille - 1) && (!est_vide()))
        W.empile(this->depile());
    while ((D.top < taille - 1) && (!D.est_vide()))
        W.empile(D.depile());
    return W;
}
```

b.

```c++
PileIntStat PileIntStat::operator+=(PileIntStat &D)
{
    while ((top < taille -1) && (!D.est_vide()))
        this->empile(D.depile());
    return *this;
}
```

c.

```c++
PileIntStat PileIntStat::operator+=(PileIntStat &D)
{
    PileIntStat W(this->top + D.top + 2);
    while ((top < taille) && (!est_vide()))
        W.empile(this->depile());
    while ((D.top < taille) && (!D.est_vide()))
        W.empile(D.depile());
    return W;
}
```

d.

```c++
PileIntStat& PileIntStat::operator+=(PileIntStat &D)
{
    while ((top < taille - 1) && (!D.est_vide()))
        this->empile(D.depile());
    return *this;
}
```

### Réponse 14

d.

```c++
PileIntStat& PileIntStat::operator+=(PileIntStat &D)
{
    while ((top < taille -1) && (!D.est_vide()))
        this->empile(D.depile());
    return *this;
}
```

Explication :

- a et c. ne sont pas optimales car on crée une nouvelle pile W qui n'est pas nécessaire.
- b. aussi retourne une copie de la pile.
- d. est optimale car on retourne une référence à la pile.
