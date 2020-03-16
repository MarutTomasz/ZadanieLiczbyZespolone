#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
using std::cout;
using std::showpos;
using std::noshowpos;
using std::endl;
using std::cin;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator / (LZespolona  Skl1,  double Mudul);

LZespolona utworz(double Re, double Im );
bool wyswietl(LZespolona Liczba);
bool wczytaj(LZespolona &Liczba);
LZespolona sprzez(LZespolona Liczba);
double modul(LZespolona Liczba);
#endif
