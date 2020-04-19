#ifndef Macierz_HH
#define Macierz_HH

#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class MacierzKw
{
  private:
        
        Wektor tablica[ROZMIAR];

  public:
        
        MacierzKw(); // konstruktor macierzy

        void transponuj(); //funkcja do transponowania macierzy
      
        double Wyznacznik();// metoda eliminacji gaussa

        MacierzKw  operator* ( MacierzKw  Macierz2); //funkcja do mnozenia macierzy przez macierz
        MacierzKw  operator+ ( MacierzKw  Macierz2); //funkcja do dodawania macierzy
        MacierzKw  operator- ( MacierzKw  Macierz2); //funkcja do odejmowania macierzy
        MacierzKw  operator* (double liczba);              //funkcja do mnozenia macierzy przez liczbe
        Wektor operator* (Wektor  wektor);       //funkcja do mnozenia macierzy przez wektor

        const Wektor & operator [] (int indeks) const; //funkcja do wyciagania wektora
        Wektor & operator [] (int indeks);   //funkcja do zmieniania wektora macierzy

       
};

std::istream &operator>>(std::istream &Strm, MacierzKw &Mac); //przeciazenie operatora do wczytywania macierzy
std::ostream &operator<<(std::ostream &Strm, const MacierzKw &Mac); //przeciazenie operatora do wyswietlania macierzy


 MacierzKw  operator*(double liczba,  MacierzKw macierz2);// funkcja ta pozwala na mnozenie liczby przez macierz


#endif
