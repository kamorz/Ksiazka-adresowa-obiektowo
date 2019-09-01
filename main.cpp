#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    cout<<"---PROGRAM TESTOWY PRZEPROWADZI CIE KROK PO KROKU PRZEZ SWOJE FUNKCJONALNOSCI---"<<endl<<endl;

    //REJESTRACJA NOWEGO UZYTKOWNIKA
    cout<<"Najpierw stworz nowego uzytkownika:"<<endl<<endl;
    ksiazkaAdresowa.rejestracjaUzytkownika();
    system("cls");

    //TESTOWO-WYSWIETLENIE UZYTKOWNIKOW
    cout<<"Zaloguj sie teraz na jedno z kont."<<endl<<"Dla uproszczenia- ponizej znajduje sie lista uzytkownikow wraz z ich haslami:"<<endl<<endl;
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //LOGOWANIE
    int idZalogowanegoUzytkownika= ksiazkaAdresowa.logowanieUzytkownika();
    cout<<"Sprawdzenie poprawnosci - Numer ID zalogowanego uzytkownika: "<<idZalogowanegoUzytkownika<<endl<<endl;
    system("pause");

    //ZMIANA HASLA
    cout<<"Nastapi teraz zmiana hasla..."<<endl;
    system("pause");
    system("cls");
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);


    //WCZYTANIE ADRESATOW ZALOGOWANEGO UZYTKOWNIKA
    int idOstatniegoAdresata=ksiazkaAdresowa.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
    cout<<"Sprawdzenie poprawnosci - ID ostatniego z wczytanych adresatow: "<<idOstatniegoAdresata<<endl;
    cout<<"W kolejnym kroku nastapi wyswietlenie adresatow: "<<endl;
    system("pause");
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();


    //DODAWANIE NOWEGO ADRESATA
    cout<<"W kolejnym kroku nastapi dodanie nowego adresata."<<endl;
    system("pause");
    idOstatniegoAdresata =ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);


    //PONOWNE WYSWIETLENIE
    cout<<"Sprawdzenie- wyswietlenie listy wraz z nowo-dodanym uzytkownikiem:"<<endl;
    system("pause");
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();


    //WYLOGOWANIE
    cout<<"Za chwile nastapi wylogowanie..."<<endl;
    system("pause");
    idZalogowanegoUzytkownika= ksiazkaAdresowa.wylogujUzytkownika();
    cout<<"Wylogowano! Aktualnie nikt nie jest zalogowany- ID uzytkownika wynosi: "<<idZalogowanegoUzytkownika<<endl;
}
