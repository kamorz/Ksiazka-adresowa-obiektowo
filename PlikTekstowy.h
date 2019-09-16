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



