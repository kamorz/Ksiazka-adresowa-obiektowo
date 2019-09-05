#include "KsiazkaAdresowa.h"

int KsiazkaAdresowa::pobierzIDZalogowanegoUzytkownika()
{
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

int KsiazkaAdresowa::pobierzIDOstatniegoAdresata()
{
    //return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
    if (pobierzIDZalogowanegoUzytkownika()!=0)
        return true;
    else
        return false;
}


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
    system("cls");
}

int KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
}

int KsiazkaAdresowa::wylogujUzytkownika()
{
    adresatMenedzer.wyczyscListeAdresatow();
    return uzytkownikMenedzer.wylogujUzytkownika();

}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(pobierzIDZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

int KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
     adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(pobierzIDZalogowanegoUzytkownika());
}

int KsiazkaAdresowa::dodajAdresata(int idOstatniegoAdresata)
{
     adresatMenedzer.dodajAdresata(pobierzIDZalogowanegoUzytkownika(), idOstatniegoAdresata);
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyswietl adresatow" << endl;
    cout << "---------------------------" << endl;
    cout << "3. Zmien haslo" << endl;
    cout << "4. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin.sync();
    wybor = MetodyPomocnicze::wczytajZnak();
    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin.sync();
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
