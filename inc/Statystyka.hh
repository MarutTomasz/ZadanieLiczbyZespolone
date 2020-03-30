#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <iostream>
using std::endl;
using std::cout;

/*************************
 * Struktura z polami    *
 * statystyki.           *
 *************************/
struct Statystyka {
  int l_bledne;
  int l_popr;
  int pomylka;
};

bool zwieksz_poprawne (Statystyka &Stat);
bool zwieksz_bledne (Statystyka &Stat);
bool inicjuj_statystyka (Statystyka &Stat);
bool zeruj_pomylki(Statystyka &Stat);
bool zwieksz_pomylka (Statystyka &Stat);
bool sprawdz_pomylki (const Statystyka &Stat);

std::ostream & operator << (std::ostream & strm, const Statystyka &Stat);

#endif
