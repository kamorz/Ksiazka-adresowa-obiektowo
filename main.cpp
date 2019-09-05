#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    //int idZalogowanegoUzytkownika=0;
    int idOstatniegoAdresata;
    char wybor;

    while (true)
    {
        if (ksiazkaAdresowa.czyUzytkownikJestZalogowany()!=true)
        {
            wybor=ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();
            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                idOstatniegoAdresata=ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                system("cls");  break;
            }
        }
        else
        {
        wybor=ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();
            switch (wybor)
            {
            case '1':
                idOstatniegoAdresata =ksiazkaAdresowa.dodajAdresata(idOstatniegoAdresata);
                break;
            case '2':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                //system("pause");
                break;
            case '3':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '4':
                ksiazkaAdresowa.wylogujUzytkownika();
                system("cls");
                break;
            }
        }
    }
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
}
