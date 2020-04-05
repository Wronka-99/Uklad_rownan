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
 Wektor wektor1;
 Wektor wektor2;
 double wektor3;
 
bool dl;
  cin>>wektor1;
  cin>>wektor2;

  wektor3=wektor1*wektor2;
  cout<<wektor2-wektor1;
  cout << endl << " Start programu " << endl << endl;
}
