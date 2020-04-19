#include "UkladRownanLiniowych.hh"
#include <cmath>


std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown) //wczytywanie ukladu rownan
{
    Wektor wektor;
    double elem=0;

    for(int i=0; i<ROZMIAR; ++i)
    {
        Strm>>wektor;
        UklRown[i]=wektor;
    }        


    for(int i=0; i<ROZMIAR; ++i)
    {
        Strm>>elem;
        UklRown.wstaw_elem(elem,i);

    }

    return Strm;
}



std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown)//wyswietlanie ukladu rownan
{


        Strm<<"Uklad rownan: "<<std::endl<<std::endl;

                    for(int i=0; i<ROZMIAR; i++)
                    {
                        Strm<<"\t";

                        Strm<<"| "<< UklRown[i]<< "| |x_"<< i+1 <<"|  ";

                                if(i==1)
                                {

                                        Strm<<" = |";
                                }
                                else
                                {
                                    
                                        Strm<<"   |";
                                }


                        Strm<< UklRown.pobierz_elem(i)<<" |"<<std::endl<<std::endl;
                    }


                return Strm;

}



double UkladRownanLiniowych::pobierz_elem(int i) const//wczytywanie elementu z wektora wyrazow wolnych
{
    return wektor[i];
}  



void UkladRownanLiniowych::wstaw_elem(double elem, int i)//przypisywanie wartosci elementowiz wektora wyrazow wolnych

{
      wektor[i]=elem;
}




Wektor UkladRownanLiniowych::operator[](int i) const// wczytywanie wektora z macierzy wspolczynnikow
{
    return macierz[i];
}




Wektor &UkladRownanLiniowych::operator[](int i)// wyswietlanie wektora z macierzy wspolczynnikow
{
    return macierz[i];
}




double UkladRownanLiniowych::operator()(int i, int j)const//odczytywanie konkretnego elementu z macierzy wspolczynnikow
{
    return macierz[i][j];
}




double &UkladRownanLiniowych::operator()(int i, int j)//przypisywanie wartosci konkretnemu elementowi z macierzy wspolczynnikow
{
    return macierz[i][j];
}




Wektor UkladRownanLiniowych::rozwiaz()// rozwiazywanie ukladu rownan
{
    Wektor rozwiazanie;
    Wektor wektor_pomocniczy;// zmienne pomocnicze
    double wyznacznik_glowny=0;
    double wyznacznik_pomocniczy=0;
    MacierzKw macierz_pomocnicza;

    macierz_pomocnicza=macierz;//przypisanie wartosci zmiennym pomocniczym
    wyznacznik_glowny=macierz_pomocnicza.Wyznacznik();//liczenie wyznacznika glownego


        for(int i=0; i<ROZMIAR; ++i)
        {   
            macierz_pomocnicza=macierz;//przypisanie wartosci zmiennym pomocniczym
            macierz_pomocnicza[i]=wektor;// wstawianie wektora wyrazow wolnych do macierzy z ktorej liczymy wyznacznik konkretnej zmiennej
            wyznacznik_pomocniczy=macierz_pomocnicza.Wyznacznik();//oblicznie wyznacznika pomocniczego
            rozwiazanie[i]=wyznacznik_pomocniczy/wyznacznik_glowny;//wstawianie rozwiazania do wektora rozwiazan

        

        }
        //wyswietlanie wektora z rozwiazaniami
        std::cout<< "Rozwiazanie x= (\tx1,\t x2\t,\t x3\t)"<<std::endl<<std::endl;
        std::cout<<"\t\t"<<rozwiazanie[0]<<"\t"<<rozwiazanie[1]<<"\t"<<rozwiazanie[2]<<std::endl<<std::endl;
        
        

        return rozwiazanie;// zwracanie wektora rozwiazan 



}
        

Wektor UkladRownanLiniowych::wektorbledu(Wektor rozwiazanie)
{

        Wektor wektor_bledu,wektor_pomocniczy,wektor_wa;
        MacierzKw macierz_pomocnicza;
        double dlugosc_wktora_bledu=0; // zmienne pomocnicze

        macierz_pomocnicza=macierz;
        wektor_pomocniczy=wektor;// przypisanie wartosci zmiennym pomocniczym

        macierz_pomocnicza.transponuj();//transponowanie macierzy wspolczynnikow
        wektor_wa=macierz_pomocnicza*rozwiazanie;//oblicznie wartosci A*x

        wektor_bledu=wektor_wa-wektor_pomocniczy;//oblicznie wektora bledu A*x-b

        dlugosc_wktora_bledu=wektor_bledu*wektor_bledu;
        dlugosc_wktora_bledu=sqrt(dlugosc_wktora_bledu);//liczenie dlugosci wektora bledu


        //wyswietlanie wektora bledu oraz jego dlugosci
        std::cout<< "Wektor bledu Ax-b =("<<wektor_bledu[0]<<","<<wektor_bledu[1]<<","<<wektor_bledu[2]<<")"<<std::endl<<std::endl;
        std::cout<< "Dlugosc wektora bledu ||Ax-b|| = ("<<wektor_bledu[0]<<","<<wektor_bledu[1]<<","<<wektor_bledu[2]<<")"<<std::endl<<std::endl;
        

    return wektor_bledu;//zwracanie wektora bledu



}