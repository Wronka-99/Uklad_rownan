#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH
#include "Macierz.hh"
#include <iostream>
#include "Macierz.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {
  
      Wektor wektor; //pola prywatne
      MacierzKw macierz;

  public:
  
        Wektor rozwiaz(); //funkcja rozwiazujaca uklad rownan oraz wyswietlajaca wektor z rozwiazaniem
        Wektor wektorbledu(Wektor rozwiazanie); // funkcja liczaca oraz wyswietlajaca wektor bledu oraz jego dlugosc

        double pobierz_elem(int i) const;// odczytywanie dowolnego elementu z wektora wyrazow wolnych
        void wstaw_elem(double elem, int i);// przypisanie wartosci do dowolnego elementu z wektora wyrazow wolnych
        
        Wektor operator[](int i) const;//odczytanie dowolnego wektora wspolczynnikow ukladu rownan
        Wektor &operator[](int i);    //zmiana dowolnego wektora wspolczynnikow ukladu rownan
        double operator()(int i, int j)const;// odczytywanie dowolnego elementu z macierzy wspolczynnikow 
        double &operator()(int i, int j);     //zmiana dowolnego elementu z macierzy wspolczynnikow
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown);


#endif
