#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    int idZalogowanegoUzytkownika=0;
    int idOstatniegoAdresata;
    char wybor;

    while (true)
    {
        if (idZalogowanegoUzytkownika == 0)
        {
            cout << "    >>> MENU  GLOWNE <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Koniec programu" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            cin>>wybor;
            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika= ksiazkaAdresowa.logowanieUzytkownika();
                idOstatniegoAdresata=ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                system("cls");
                break;
            }
        }
        else
        {
            system("cls");
            cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyswietl adresatow" << endl;
            cout << "---------------------------" << endl;
            cout << "3. Zmien haslo" << endl;
            cout << "4. Wyloguj sie" << endl;
            cout << "---------------------------" << endl;
            cout<<"Proba- id zalogowanego: "<<idZalogowanegoUzytkownika<<" ostatnie ID: "<<idOstatniegoAdresata<<endl<<endl;
            cout << "Twoj wybor: ";
            cin>>wybor;
            switch (wybor)
            {
            case '1':
                idOstatniegoAdresata =ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
                break;
            case '2':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                //system("pause");
                break;
            case '3':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
                break;
            case '4':
                idZalogowanegoUzytkownika= ksiazkaAdresowa.wylogujUzytkownika();
                system("cls");
                break;
            }
        }
    }
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
}
