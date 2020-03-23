#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyka.hh"

using namespace std;

int main(int argc, char **argv){

  LZespolona Wynik;
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

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  inicjuj_statystyka(Staty);
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " :? Podaj wynik operacji: ";
    cout << WyrZ_PytanieTestowe << " =" << endl;
    cout << "    Twoja odpowiedz:  ";
    cin >> Odpowiedz;
    Wynik = oblicz(WyrZ_PytanieTestowe);
    
    if(!cin.good()){
      cin.clear();
      cout << "    Niepoprawnie wpisana liczba zepolona" << endl;
      cout << endl;
      zwieksz_bledne(Staty);
    }
    else {
      if(Odpowiedz == Wynik) {
	zwieksz_poprawne(Staty);
	cout << " :) Odpowiedz poprawna." << endl;
	cout << endl;
	cin.ignore(1000,'\n');
      }
      else {
	zwieksz_bledne(Staty);
	cout << " :( Blad. Prawidlowym wynikiem jest " << Wynik << endl;
	cout << endl;
	cin.ignore(1000,'\n');
      
      }
    }
  }




 

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

  cout << " Ilosc dobrych odpowiedzi: " << zwroc_l_poprawnych(Staty) << endl;
  cout << " Ilosc blednych odpowiedzi: " << zwroc_l_blednych(Staty) << endl;
  cout << " Wynik procentowy dobrych odpowiedzi: " << zwroc_proc_poprawnych(Staty) << "%" << endl;
  cout << endl;
}
