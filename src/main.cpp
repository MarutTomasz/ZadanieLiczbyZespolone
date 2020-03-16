#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"


using namespace std;




int main(int argc, char **argv){

  /*
  WyrazenieZesp WyrZ;
  
  LZespolona Liczba1 = utworz(2,3);
  wyswietl(Liczba1);
  LZespolona Liczba2 = utworz(2,-4);
  wyswietl(Liczba2);

  WyrZ.Arg1 = Liczba1;
  WyrZ.Arg2 = Liczba2;
  WyrZ.Op = Op_Dodaj;

  wczytaj(WyrZ);

  Liczba1 = oblicz(WyrZ);

  wyswietl(Liczba1);
  
  */
  
  











  










    
 
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
