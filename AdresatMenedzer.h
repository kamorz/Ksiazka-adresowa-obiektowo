#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include "Adresat.h"
#include "PlikTekstowy.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    char wybierzOpcjeZMenuEdycja();
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci= plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    int pobierzIdOstatniegoAdresata();
    void wyswietlWszystkichAdresatow();
    void wyswietlAdresatowWFormieUproszczonej();
    void wyswietlDaneAdresata(Adresat adresat);//
    int dodajAdresata(int idZalogowanegoUzytkownika);//
    void dopiszAdresataDoPliku(Adresat adresat);
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    int edytujAdresata();
    int usunAdresata();
    int podajIdWybranegoAdresata();
    void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

};

#endif
