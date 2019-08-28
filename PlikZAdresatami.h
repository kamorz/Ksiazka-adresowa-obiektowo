#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <fstream>
#include "Adresat.h"
#include "MetodyPomocnicze.h"


using namespace std;

class PlikZAdresatami
{
string nazwaPlikuZAdresatami;

bool czyPlikJestPusty();
public:
    PlikZAdresatami();
};

#endif
