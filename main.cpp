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

    //LOGOWANIE
    int idZalogowanegoUzytkownika= ksiazkaAdresowa.logowanieUzytkownika();
    cout<<"Sprawdzenie poprawnosci: Numer ID zalogowanego uzytkownika: "<<idZalogowanegoUzytkownika<<endl<<endl;
    system("pause");

    //ZMIANA HASLA
    cout<<"Nastapi teraz zmiana hasla..."<<endl;
    system("pause");
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);

    //WYLOGOWANIE
    cout<<"Za chwile nastapi wylogowanie..."<<endl;
    system("pause");
    idZalogowanegoUzytkownika= ksiazkaAdresowa.wylogujUzytkownika();
    cout<<"Wylogowano! Aktualnie nikt nie jest zalogowany- ID uzytkownika wynosi: "<<idZalogowanegoUzytkownika<<endl;
}
