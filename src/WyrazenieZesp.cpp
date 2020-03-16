#include "WyrazenieZesp.hh"

void wyswietl(WyrazenieZesp WyrZ){
  cout << '(' << WyrZ.Arg1.re << showpos << WyrZ.Arg1.im << noshowpos << "i)";

  switch(WyrZ.Op){
  case Op_Dodaj:  {
    cout << " + ";
    break;
  }
    
  case Op_Odejmij:  {
    cout << " - ";
    break;
  }
    
  case Op_Mnoz:  {
    cout << " * ";
    break;
  }
    
  case Op_Dziel:  {
    cout << " / ";
    break;
  }
  }
    
  cout << '(' << WyrZ.Arg2.re << showpos << WyrZ.Arg2.im << noshowpos << "i)" << endl;
  
}


LZespolona oblicz(WyrazenieZesp WyrZ){

  LZespolona Wynik;
  
  switch(WyrZ.Op){
  case Op_Dodaj:  {
    Wynik = WyrZ.Arg1 + WyrZ.Arg2;
    break;
  }
    
  case Op_Odejmij:  {
    Wynik = WyrZ.Arg1 - WyrZ.Arg2;
    break;
  }
    
  case Op_Mnoz:  {
    Wynik = WyrZ.Arg1 * WyrZ.Arg2;
    break;
  }
    
  case Op_Dziel:  {
    Wynik = WyrZ.Arg1 / WyrZ.Arg2;
    break;
  }
  }
 
  return Wynik;

}


bool wczytaj(WyrazenieZesp &WyrZ){
  char znak;

  cin >> znak;
  if (znak != '(')
    return false;
    
  cin >> WyrZ.Arg1.re >> WyrZ.Arg1.im >> znak;

  if (znak != 'i')
    return false;
  
  cin >> znak;
  
  if (znak != ')')
    return false;

  cin >> znak;

  if (znak == '+')
    WyrZ.Op = Op_Dodaj; 
  else if (znak == '-')
    WyrZ.Op = Op_Odejmij;
  else if (znak == '*')
    WyrZ.Op = Op_Mnoz;
  else if (znak == '/')
    WyrZ.Op = Op_Dziel;
  else
    return false;

  cin >> znak;
  if (znak != '(')
    return false;
    
  cin >> WyrZ.Arg2.re >> WyrZ.Arg2.im >> znak;

  if (znak != 'i')
    return false;
  
  cin >> znak;
  
  if (znak != ')')
    return false;
  
  return true;







  
}
