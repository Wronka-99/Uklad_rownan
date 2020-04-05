#include "Macierz.hh"
#include <iostream>






std::ostream &operator<<(std::ostream &Strm, const MacierzKw &Mac)
        {
            for (int i = 0; i < ROZMIAR; i++)
            {
                Strm << Mac[i] << " " << std::endl;
            }

            return Strm;
        }




std::istream &operator>>(std::istream &Strm, MacierzKw &Mac)
        {
            Wektor elem;
            for (int i = 0; i < ROZMIAR; i++)
            {
                Strm >> elem;
                Mac[i] = elem;
            }
            
            return Strm;
        }





const Wektor & MacierzKw::operator [] (int indeks) const
        {
            if(indeks<0||indeks>ROZMIAR)
            {
            std::cerr<<"Indeks jest poza zakresem"<<std::endl;
            exit(1);
            }

            return tablica[indeks];
        }






Wektor & MacierzKw::operator [] (int indeks)
        {
            if(indeks<0||indeks>ROZMIAR)
            {
            std::cerr<<"Indeks jest poza zakresem"<<std::endl;
            exit(1);
            }

            return tablica[indeks]; 
        }




