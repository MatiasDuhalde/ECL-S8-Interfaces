/*************************************************************
 * Exemple 5.1 : Fonctions de permutation avec arguments par  *
 * référence et par adresse                                   *
 **************************************************************/

#include <iostream>

using namespace std;

int somme(int, int);
void permutation_p(int *, int *);
void permutation_r(int &, int &);

int main() {
  int x, y;
  cout << " Donner la valeur de x: ";
  cin >> x;
  cout << " Donner la valeur de y: ";
  cin >> y;

  cout << "Valeurs de x et y :" << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;

  int s = somme(x, y);
  cout << "Valeur de " << x << " + " << y << ": " << s << endl;

  int *px, *py;
  px = &x;
  py = &y;
  permutation_p(px, py);
  cout << "Valeurs de x et y apres permutation :" << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;

  permutation_r(x, y);
  cout << "Valeurs de x et y apres nouvelle permutation:" << endl;
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;

  return 0;
}

int somme(int a, int b)  // passage d'arguments par copie
{
  return a + b;
}

void permutation_p(int *a, int *b)  // passage d'arguments par adresse
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void permutation_r(int &a, int &b)  // passage d'arguments par référence
{
  int temp = a;
  a = b;
  b = temp;
}
