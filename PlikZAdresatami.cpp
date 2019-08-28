#include "PlikZAdresatami.h"

PlikZAdresatami::PlikZAdresatami()
{
    nazwaPlikuZAdresatami="Adresaci.txt";
}

bool PlikZAdresatami::czyPlikJestPusty()
{
    fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}
