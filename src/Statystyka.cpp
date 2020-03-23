#include "Statystyka.hh"


/**************************************
 * Funkcja zwieksza liczbe poprawnych *
 *  odpowiedzi.                       * 
 **************************************/
bool zwieksz_poprawne (Statystyka &Stat) {
  Stat.l_popr = Stat.l_popr + 1;
  return true;
}


/**************************************
 * Funkcja zwieksza liczbe pytan.     * 
 **************************************/
bool zwieksz_bledne (Statystyka &Stat) {
  Stat.l_bledne = Stat.l_bledne + 1;
  return true;
}

/************************************
 * Inicjuje strukture na statystyki *
 ************************************/
bool inicjuj_statystyka (Statystyka &Stat) {
  Stat.l_bledne = 0;
  Stat.l_popr = 0;
  return true;
}


int zwroc_l_blednych (Statystyka &Stat) {
  return Stat.l_bledne;
}

 
int zwroc_l_poprawnych (Statystyka &Stat) {
  return Stat.l_popr;
}


int zwroc_proc_poprawnych (Statystyka &Stat) {
  int procent;
  procent = (Stat.l_popr * 100) / (Stat.l_bledne+Stat.l_popr);
  return procent;
}
