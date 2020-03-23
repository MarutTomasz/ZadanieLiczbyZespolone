#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

struct Statystyka {
  int l_bledne;
  int l_popr;
};

bool zwieksz_poprawne (Statystyka &Stat);
bool zwieksz_bledne (Statystyka &Stat);
bool inicjuj_statystyka (Statystyka &Stat);
int zwroc_l_poprawnych (Statystyka &Stat);
int zwroc_l_blednych (Statystyka &Stat);
int zwroc_proc_poprawnych (Statystyka &Stat);

#endif
