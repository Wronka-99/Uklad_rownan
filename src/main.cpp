#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{


 UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
 Wektor wynik;


 cout << endl << " Wprowadz wierszowo uklad rownan, na koncu wpisujesz wektor wyrazow wolnych."<< endl << endl;

 cin>>UklRown;//wprowadzanie ukladu rownan z klawiatury
 cout<<UklRown;//wyswietlanie ukladu rownan
 
 wynik=UklRown.rozwiaz();//rozwiazywanie ukladu rownan
 UklRown.wektorbledu(wynik);//oblicznie i wyswietlanie wektora bledu
  
 
  
}
