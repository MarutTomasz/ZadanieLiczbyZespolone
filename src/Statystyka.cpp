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
 * Funkcja zwieksza liczbe blednych   *
 * odpowiedzi.                        * 
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
  Stat.pomylka = 0;
  return true;
}

/**************************************
 * Funkcja zwraca liczbe blednych     *
 * odpowiedzi.                        * 
 **************************************/
int zwroc_l_blednych (const Statystyka &Stat) {
  return Stat.l_bledne;
}

/**************************************
 * Funkcja zwraca liczbe poprawnych   *
 * odpowiedzi.                        * 
 **************************************/
int zwroc_l_poprawnych (const Statystyka &Stat) {
  return Stat.l_popr;
}

/**************************************
 * Funkcja zwraca procent             * 
 * poprawnych odpowiedzi.             *
 **************************************/
int zwroc_proc_poprawnych (const Statystyka &Stat) {
  int procent;
  procent = (Stat.l_popr * 100) / (Stat.l_bledne+Stat.l_popr);
  return procent;
}

/*********************************
 * Zeruje liczbe pomylek po      *
 * przejsciu do nowego pytania   *
 *********************************/
bool zeruj_pomylki(Statystyka &Stat){
  Stat.pomylka = 0;
  return true;
}

/**************************************
 * Funkcja zwieksza ilosc pomylek     * 
 * przy wpisywaniu odpowiedzi         *
 **************************************/
bool zwieksz_pomylka (Statystyka &Stat) {
  Stat.pomylka++;
  return true;
}

/*****************************
 * Funkcja sprawdza ilosc    * 
 * zrobionych pomylek        *
 *****************************/
bool sprawdz_pomylki (const Statystyka &Stat) {
  if (Stat.pomylka == 0){
    cout << endl;
    cout << "    Niepoprawnie wpisana liczba zepolona" << endl;
    cout << "    Pozostały 3 proby" << endl;
    cout << "    Twoja odpowiedz:  ";
    return true;
  }
  else if (Stat.pomylka == 1){
    cout << endl;
    cout << "    Niepoprawnie wpisana liczba zepolona" << endl;
    cout << "    Pozostały 2 proby" << endl;
    cout << "    Twoja odpowiedz:  ";
    return true;
  }
  else if (Stat.pomylka == 2){
    cout << endl;
    cout << "    Niepoprawnie wpisana liczba zepolona" << endl;
    cout << "    Pozostała ostatnia proba" << endl;
    cout << "    Twoja odpowiedz:  ";
    return true;
  }
  return false;
}

/****************************************
 * Przeciazenie operatora wyswietlania  *
 * dla statystyk                        * 
 ****************************************/
std::ostream & operator << (std::ostream & strm, const Statystyka &Stat) {
  strm << " Ilosc dobrych odpowiedzi: " << zwroc_l_poprawnych(Stat) << endl;
  strm << " Ilosc blednych odpowiedzi: " << zwroc_l_blednych(Stat) << endl;
  strm << " Wynik procentowy dobrych odpowiedzi: " << zwroc_proc_poprawnych(Stat) << "%" << endl;
  strm << endl;
  return strm;
}
