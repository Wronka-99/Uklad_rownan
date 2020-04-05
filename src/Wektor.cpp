#include "Wektor.hh"
#include "rozmiar.h"
#include <iostream>
#include <cmath>
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */






using namespace std;


bool Wektor::operator == ( const Wektor  &Wektor2)const
{

    bool prawda=1;

    for(int indeks=0; indeks<ROZMIAR; indeks++)
        {
           if( Wektor2[indeks]!=tablica[indeks])
           {
                prawda=0;
           }
        }
    return prawda;
}




bool Wektor::operator != ( const Wektor  &Wektor2)const
{

    bool prawda=0;

    for(int indeks=0; indeks<ROZMIAR; indeks++)
        {
           if( Wektor2[indeks]==tablica[indeks])
           {
                prawda=1;
           }
        }
    return prawda;
}




ostream &operator<<(ostream &Strm, const Wektor &Wek)
{
    for (int i = 0; i < ROZMIAR; i++)
    {
        Strm << Wek[i] << " ";
    }

    return Strm;
}

istream &operator>>(istream &Strm, Wektor &Wek)
{
    double elem;
    for (int i = 0; i < ROZMIAR; i++)
    {
        Strm >> elem;
        Wek[i] = elem;
    }
    return Strm;
}

const Wektor Wektor::operator+(const Wektor Wektor2)const
{   
    Wektor wektor3;
    for (int indeks = 0; indeks < ROZMIAR; indeks++)
    {
        wektor3[indeks] = tablica[indeks]+Wektor2[indeks];
    }
    return wektor3;
}

const Wektor Wektor::operator-(const Wektor Wektor2)const
{
   Wektor wektor3;
    for (int indeks = 0; indeks < ROZMIAR; indeks++)
    {
        wektor3[indeks] = tablica[indeks]-Wektor2[indeks];
    }
    return wektor3;
}

double Wektor::operator*(Wektor Wektor2)const
{
    double Wynik, IloczynS;
    for (int i = 0; i < ROZMIAR; i++)
    {
        IloczynS = Wektor2[i] * tablica[i];
        Wynik += IloczynS;
    }
    return Wynik;
}

const Wektor Wektor::operator*(double liczba)const
{
    Wektor Wektor2;
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor2[i] = tablica[i] * liczba;
    }
    return Wektor2;
}

Wektor operator *(double liczba, Wektor Wektor2)
{
    
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor2[i] = Wektor2[i] * liczba;
    }
        return Wektor2;

}

const Wektor Wektor::operator/(double liczba)const
{
    Wektor Wektor2;

    for (int i = 0; i < ROZMIAR; i++)
    {
        Wektor2[i] = tablica[i] / liczba;
    }
    return Wektor2;
}

double Wektor::dlugoscWektora()const
{
    double Wynik = 0;
    for (int i = 0; i < ROZMIAR; i++)
    {
        Wynik += pow(tablica[i], 2);
    }
    return sqrt(Wynik);
}


double & Wektor::operator[] (int indeks)
  {
    if(indeks<0||indeks>ROZMIAR)
    {
      std::cerr<<"Indeks jest poza zakresem"<<std::endl;
      exit(1);
    }

    return tablica[indeks];
  }


 const double & Wektor::operator[](int indeks) const
 {
    if(indeks<0||indeks>ROZMIAR)
    {
      std::cerr<<"Indeks jest poza zakresem"<<std::endl;
      exit(1);
    }

    return tablica[indeks];
  }

