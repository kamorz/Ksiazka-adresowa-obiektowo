#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami)
    {

    };
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    int wylogujUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wyswietlWszystkichAdresatow();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    int dodajAdresata(int idOstatniegoAdresata);
    char wybierzOpcjeZMenuUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    int pobierzIDZalogowanegoUzytkownika();
    int pobierzIDOstatniegoAdresata();
    bool czyUzytkownikJestZalogowany();
};

#endif
