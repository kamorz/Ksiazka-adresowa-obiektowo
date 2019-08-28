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
    cout<<"Numer ID zalogowanego uzytkownika: "<<idZalogowanegoUzytkownika<<endl<<"Za chwile nastapi wylogowanie..."<<endl<<endl;
    system("pause");

    //WYLOGOWANIE
    idZalogowanegoUzytkownika= ksiazkaAdresowa.wylogujUzytkownika();
    cout<<"Wylogowano! Aktualnie nikt nie jest zalogowany, wiec ID wynosi: "<<idZalogowanegoUzytkownika<<endl;
}
