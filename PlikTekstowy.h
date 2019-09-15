#include <iostream>
#include <fstream>

#include "Adresat.h"
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"


using namespace std;

#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

class PlikTekstowy
{
    const string NAZWA_PLIKU;
    public:
    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {
    }
    string pobierzNazwePliku();
    bool czyPlikJestPusty();

};

#endif

#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

class PlikZAdresatami : public PlikTekstowy
{
    int idOstatniegoAdresata;
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    PlikZAdresatami (string nazwaPliku) : PlikTekstowy(nazwaPliku)
    {
        idOstatniegoAdresata=0;
    };
    int pobierzIdOstatniegoAdresata();
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void dopiszAdresataDoPliku(Adresat adresat);
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
};

#endif

#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

class PlikZUzytkownikami : public PlikTekstowy
{
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami (string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
};

#endif
