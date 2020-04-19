#include "Macierz.hh"
#include <iostream>
#include <cmath>




MacierzKw::MacierzKw()// konstruktor macierzy
{

    for(int a=0; a<ROZMIAR; a++)
    {
        for(int b=0; b<ROZMIAR; b++)
        {

            tablica[a][b]=0;
        }

    }


}


std::ostream &operator<<(std::ostream &Strm, const MacierzKw &Mac)//przeciazenie operatora << w celu wyswietlania
        {
            for (int i = 0; i < ROZMIAR; i++)
            {
                Strm << Mac[i] << " " << std::endl;
            }

            return Strm;
        }




std::istream &operator>>(std::istream &Strm, MacierzKw &Mac)//przeciazenie operatora >> w celu wczytywania
        {
            Wektor elem;
            for (int i = 0; i < ROZMIAR; i++)
            {
                Strm >> elem;
                Mac[i] = elem;
            }
            
            return Strm;
        }



 MacierzKw  MacierzKw::operator* (double liczba)//mnozenie macierzy przez liczbe 
{
    
    MacierzKw macierz;

    for(int i=0; i <ROZMIAR; ++i)
    {
        for(int j=0; j< ROZMIAR;++j)
        {
            macierz[i][j]+=tablica[i][j]*liczba;
            
        }
    }

    return macierz;
}

 MacierzKw  operator*(double liczba,  MacierzKw macierz2)//mnozenie liczby przez macierz
{
     MacierzKw macierz;    

    for(int i=0; i <ROZMIAR; ++i)
    {
        for(int j=0; j< ROZMIAR;++j)
        {
            macierz[i][j]+=macierz2[i][j]*liczba;
            
        }
    }

    return macierz;

}


 MacierzKw  MacierzKw::operator* ( MacierzKw  Macierz2)//mnozenie macierzy przez macierz
{
     MacierzKw macierz;    

    for(int i=0; i <ROZMIAR; ++i)
    {
        for(int j=0; j< ROZMIAR;++j)
        {
            macierz[i][j]=tablica[abs(i-2)][j]*Macierz2[i][abs(j-2)]+tablica[abs(i-1)][j]*Macierz2[i][abs(j-1)]+tablica[i][j]*Macierz2[i][j];
            
        }
    }

    return macierz;

}




Wektor MacierzKw::operator*(Wektor wektor)
{
    
    Wektor wynik;

    for(int i=0; i <ROZMIAR; ++i)
    {
        for(int j=0; j< ROZMIAR;++j)
        {
            wynik[i]+=tablica[i][j]*wektor[j];
            
        }
    }

    return wynik;
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






double MacierzKw::Wyznacznik()
{
    double wynik=1;
    double elem=0;

    for(int i=0; i<ROZMIAR-1; ++i)//ta petla porusza sie po kolumnach
    {

        for(int j=i+1; j<ROZMIAR; ++j)//ta petla porusza sie po wierszach
        {

            elem=-tablica[j][i]/tablica[i][i];//wartosc ktora bedziemy zerowac kolumne


            for(int n=i;n<ROZMIAR; ++n)
            {

                tablica[j][n]+=(elem*tablica[i][n]);//zerowanie elementow kolumny

            }    
        }
    }

    for(int q=0; q<ROZMIAR; ++q)
    {
         wynik=(tablica[q][q]*wynik);//obliczanie wartosci wyznacznika
    }


    return wynik;
}





void MacierzKw::transponuj()//Transponowanie macierzy
 {
     double tablica_pom[ROZMIAR][ROZMIAR];

     for(int a=0; a<ROZMIAR; a++)
     {
         for(int b=0; b<ROZMIAR; b++)
         {
            
            tablica_pom[a][b]=tablica[b][a];   // przypisanie wartosci macierzy pomocniczej         
        }
     }

     for(int a=0; a<ROZMIAR; a++)
     {
         for(int b=0; b<ROZMIAR; b++)
         {
            
            tablica[a][b]=tablica_pom[a][b];     // transponowanie       
        }
     }
 }


 MacierzKw  MacierzKw::operator+ ( MacierzKw  Macierz2)// dodawanie macierzy
 {
     MacierzKw macierz;

     for(int i=0; i<ROZMIAR; i++)
     {

         macierz[i]=tablica[i]+Macierz2[i];

     }


    return macierz;


 }



  MacierzKw  MacierzKw::operator- ( MacierzKw  Macierz2)// odejmowane macierzy
 {
     MacierzKw macierz;

     for(int i=0; i<ROZMIAR; i++)
     {

         macierz[i]=tablica[i]-Macierz2[i];

     }


    return macierz;


 }