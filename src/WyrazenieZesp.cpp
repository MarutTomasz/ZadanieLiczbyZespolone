#include "WyrazenieZesp.hh"

/***********************************************
 * Przeciazenie operatora dla wyswietlania     *
 *   wyrazenia zespolonego.                    *
 * Argumenty:                                  *
 *    WZes - struktura z wyrazeniem zespolonym *
 *    strm - strumien na wejscie operatora     *
 ***********************************************/
std::ostream & operator << (std::ostream & strm, WyrazenieZesp &WZes) {
  cout << WZes.Arg1 << WZes.Op << WZes.Arg2;
  return strm;
}


/***********************************************
 * Przeciazenie operatora dla wyswietlania w   *
 *   operatora w wyrazeniu zespolonym.         *
 * Argumenty:                                  *
 *    OP - operator z wyrazenia zespolonego    *
 *    strm - strumien na wejscie operatora     *
 ***********************************************/
std::ostream & operator << (std::ostream & strm, Operator &OP) {

  switch(OP){
  case Op_Dodaj: {cout << " + "; break;}
  case Op_Odejmij: {cout << " - "; break;}
  case Op_Mnoz: {cout << " * "; break;}
  case Op_Dziel: {cout << " / "; break ;}
  }
  return strm;
}
  

/***********************************************
 * Funkcja obliczajaca wartosc wyrazenia       *
 *   zespolonego.                              *
 * Argumenty:                                  *
 *    WyrZ - struktura z wyrazeniem zespolonym *
 ***********************************************/
LZespolona oblicz(WyrazenieZesp WyrZ){
  LZespolona Wynik;
  
  switch(WyrZ.Op){
  case Op_Dodaj: {Wynik = WyrZ.Arg1 + WyrZ.Arg2; break;}
  case Op_Odejmij: {Wynik = WyrZ.Arg1 - WyrZ.Arg2; break;}
  case Op_Mnoz: {Wynik = WyrZ.Arg1 * WyrZ.Arg2; break;}
  case Op_Dziel: {Wynik = WyrZ.Arg1 / WyrZ.Arg2; break;}
  }
  return Wynik;
}


/***********************************************
 * Przeciazenie operatora dla wczytywania      *
 *   wyrazenia zespolonego.                    *
 * Argumenty:                                  *
 *    WZes - struktura na wyrazenie zespolone  *
 *    strm - strumien na wejscie operatora     *
 ***********************************************/
std::istream & operator >> (std::istream & strm, WyrazenieZesp &WZes) {
  strm >> WZes.Arg1 >> WZes.Op >> WZes.Arg2;
  return strm;
}


/***********************************************
 * Przeciazenie operatora dla wczytywania      *
 *   operatora w wyrazeniu zespolonym.         *
 * Argumenty:                                  *
 *    OP - operator w wyrazeniu zespolonym     *
 *    strm - strumien na wejscie operatora     *
 ***********************************************/
std::istream & operator >> (std::istream & strm, Operator &OP) {
  char znak;
  strm >> znak;
  switch(znak) {
  case '+': {OP = Op_Dodaj; break;}
  case '-': {OP = Op_Odejmij; break;}
  case '*': {OP = Op_Mnoz; break;}
  case '/': {OP = Op_Dziel; break;}
  }
  return strm;
}
