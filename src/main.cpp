#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyka.hh"

int main(int argc, char **argv){

  Statystyka Staty;
  LZespolona Odpowiedz;
  BazaTestu BazaT = { nullptr, 0, 0 };
  WyrazenieZesp WyrZ_PytanieTestowe;
  
  if (argc < 2) {
    cout << endl;cout << endl;
      
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }
  
  inicjuj_statystyka(Staty);
  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " :? Podaj wynik operacji: " << WyrZ_PytanieTestowe << " =" << endl;
    cout << "    Twoja odpowiedz:  ";
    cin >> Odpowiedz;
    zeruj_pomylki(Staty);
    
    while(!cin.good() && sprawdz_pomylki(Staty)){
      cin.clear();
      cin.ignore(1000,'\n');
      zwieksz_pomylka(Staty);
      cin >> Odpowiedz;
    }
    
    cin.clear();
    
    if(Odpowiedz == oblicz(WyrZ_PytanieTestowe)) {
      zwieksz_poprawne(Staty);
      cout << " :) Odpowiedz poprawna." << endl;
      cout << endl;
      cin.ignore(1000,'\n');
    }
    else {
      zwieksz_bledne(Staty);
      cout << " :( Blad. Prawidlowym wynikiem jest " << oblicz(WyrZ_PytanieTestowe) << endl;
      cout << endl;
      cin.ignore(1000,'\n');
    }
  }
  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

  cout << Staty;
}
