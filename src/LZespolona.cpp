#include "LZespolona.hh"

/******************************************
 * Tworzy sprzezenie do liczby zespolonej *
 ******************************************/
LZespolona sprzez(LZespolona Liczba){
  LZespolona Wynik;
  Wynik.re = Liczba.re;
  Wynik.im = Liczba.im * (-1);
  return Wynik;
}

/*********************************************
 * Liczy kwadrat modulu z liczby zespolonej  *
 *********************************************/
double modul2(LZespolona Liczba){
  double Modul = (Liczba.re * Liczba.re) + (Liczba.im * Liczba.im);
  return Modul;
}

/***********************************************************
 * Realizuje dodanie dwoch liczb zespolonych.              *
 * Argumenty:                                              *
 *    Skl1 - pierwszy skladnik dodawania,                  *
 *    Skl2 - drugi skladnik dodawania.                     *
 * Zwraca:                                                 *
 *    Sume dwoch skladnikow przekazanych jako parametry.   *
 ***********************************************************/
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;
  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/***********************************************************
 * Realizuje odejmowanie dwoch liczb zespolonych.          *
 * Argumenty:                                              *
 *    Skl1 - odjemna,                                      *
 *    Skl2 - odjemnik.                                     *
 * Zwraca:                                                 *
 *    Roznice dwoch liczb przekazanych jako argumenty.     *
 ***********************************************************/
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}


/***********************************************************
 * Realizuje mnozenie dwoch liczb zespolonych.             *
 * Argumenty:                                              *
 *    Skl1 - czynnik,                                      *
 *    Skl2 - czynnik.                                      *
 * Zwraca:                                                 *
 *    Iloczyn dwoch liczb przekazanych jako argumenty.     *
 ***********************************************************/
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl1.im * Skl2.re);
  return Wynik;
}


/***********************************************************
 * Realizuje dzielenie liczby zespolonej przez rzeczywista *
 * Warunek:                                                *
 *    Liczba rzeczywista musi byc rozna od 0               *
 * Argumenty:                                              *
 *    Skl1 - czynnik,                                      *
 *    Modul - czynnik.                                     *
 * Zwraca:                                                 *
 *    Iloraz dwoch liczb przekazanych jako argumenty.      *
 ***********************************************************/
LZespolona  operator / (LZespolona  Skl1,  double Modul){
  LZespolona  Wynik;
  if(Modul != 0){
    Wynik.re = Skl1.re / Modul;
    Wynik.im = Skl1.im / Modul;
    return Wynik;
  }
  std::cerr << "Nie można dzielić przez 0" << endl;
  std::cerr << "Koniec dzialania programu" << endl << endl;
  exit(1);
}

/***********************************************************
 * Realizuje dzielenie dwoch liczb zespolonych.            *
 * Warunek:                                                *
 *    Dzielnik jest rozny od 0                             *
 * Argumenty:                                              *
 *    Skl1 - dzielna,                                      *
 *    Skl2 - dzielnik.                                     *
 * Zwraca:                                                 *
 *    Iloracz dwoch liczb przekazanych jako argumenty.     *
 ***********************************************************/
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona Wynik;
  LZespolona Sprzezenie = sprzez(Skl2);
  LZespolona Licznik = Skl1 * Sprzezenie;
  double Modul = modul2(Skl2);
  Wynik = Licznik / Modul;
  return Wynik;
}

/************************************************************
 * Tworzy nowa liczbe zespolona.                            *
 * Argumenty:                                               *
 *    Re - czesc rzeczywista liczby zespolonej,             *
 *    Im - czesc urojona liczby zespolonej.                 *
 * Zwraca:                                                  *
 *    Utworzona liczbe zespolona.                           *
 ************************************************************/
LZespolona utworz(double Re, double Im){
  LZespolona Nowa;
  Nowa.re = Re;
  Nowa.im = Im;
  return Nowa;
}

/*************************************************************
 * Przeciazenie operatora dla wyswietlania liczb zespolonych *
 * Argumenty:                                                *
 *    Liczba - struktura z liczba do wyswietlrnia            *
 *    strm - strumien podawany na wejscie operatora          *
 *************************************************************/
std::ostream & operator << (std::ostream &strm, const LZespolona &Liczba) {
  cout << '(' << Liczba.re << showpos << Liczba.im << noshowpos << "i)";
  return strm; 
}

/*************************************************************
 * Przeciazenie operatora dla wczytywania liczb zespolonych  *
 * Argumenty:                                                *
 *    Liczba - struktura na liczbe do wczytania              *
 *    strm - strumien podawany na wejscie operatora          *
 *************************************************************/
std::istream & operator >> (std::istream &strm, LZespolona &Liczba) {
  char znak;
  strm >> znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit);

  strm >> Liczba.re >> Liczba.im >> znak;
  if (znak != 'i')
    strm.setstate(std::ios::failbit);

  strm >> znak;
  if (znak != ')')
    strm.setstate(std::ios::failbit);
  return strm;
}

/**************************************************************
 * Przeciazenie operatora dla porownywania liczb zespolonych  *
 * Argumenty:                                                 *
 *    Odpowiedz - pierwsza porównywana liczba                 *
 *    Wynik - druga poronwywana liczba                         *
 **************************************************************/
bool operator == (LZespolona Odpowiedz, LZespolona Wynik){
  if (Odpowiedz.re == Wynik.re)
    if (Odpowiedz.im == Wynik.im)
      return true;
  return false;
}

/**************************************************************
 * Przeciazenie operatora dla rozrozniania liczb zespolonych  *
 * Argumenty:                                                 *
 *    Odpowiedz - pierwsza porównywana liczba                 *
 *    strm - druga poronwywana liczba                         *
 **************************************************************/
bool operator != (LZespolona Odpowiedz, LZespolona Wynik){
  if (Odpowiedz == Wynik)
    return false;
  return true;
}
