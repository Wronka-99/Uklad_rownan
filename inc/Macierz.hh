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
        

        const MacierzKw & transponuj() const;
      

        const MacierzKw & odwroc() const;
        
        
        const MacierzKw & operator* (const MacierzKw & Macierz2);
        const MacierzKw & operator+ (const MacierzKw & Macierz2);
        const MacierzKw & operator- (const MacierzKw & Macierz2);
        const MacierzKw & operator* (double liczba);


        const Wektor & operator [] (int indeks) const;
        Wektor & operator [] (int indeks);

        const Wektor & zwroc_kolumne(int indeks);
        void zmien_kolumne(int indeks, Wektor Wektor2);
};

std::istream &operator>>(std::istream &Strm, MacierzKw &Mac);
std::ostream &operator<<(std::ostream &Strm, const MacierzKw &Mac);


const MacierzKw & operator*(double liczba, const MacierzKw macierz2);


#endif
