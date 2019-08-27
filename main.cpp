#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    /*ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow(); */
    int idZalogowanegoUzytkownika= ksiazkaAdresowa.logowanieUzytkownika();
    cout<<"Numer ID zalogowanego uzytkownika: "<<idZalogowanegoUzytkownika<<endl;
}
