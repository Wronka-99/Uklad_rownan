#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

/*
 *  Klasa modeluje pojęcie wektora,
 *  którego rozmiar jest z góry
 *  zdefiniowany.
 */
class Wektor
{
private:
  double tablica[ROZMIAR]; //Zmienna przechowująca elementy wektora

public:

 
 
 const Wektor operator+(const Wektor Wektor2)const;                          //Dodawnie wektorow
 const Wektor operator-(const Wektor Wektor2)const;                          //Odejmowanie wektorow
 const Wektor operator/(double liczba)const;                       //Iloraz wektora przez liczbe
 const Wektor operator*(double liczba)const;                       //Iloczyn wektora przez liczbe
 double operator*(Wektor Wektor2)const;                          //Iloczyn skalarny
 
double dlugoscWektora()const;  
  
bool operator != (const Wektor &W2)const;  
bool operator == (const Wektor &W2)const;                             //Oblicza dlugosc wektora
  
  
double & operator[] (int indeks);
const double & operator[](int indeks) const;


};

std::istream &operator>>(std::istream &Strm, Wektor &Wek);
std::ostream &operator<<(std::ostream &Strm, const Wektor &Wek);

Wektor operator *(double liczba, Wektor Wektor2);


#endif