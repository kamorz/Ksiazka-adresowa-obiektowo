#include "KsiazkaAdresowa.h"

int KsiazkaAdresowa::pobierzIDZalogowanegoUzytkownika()
{
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

int KsiazkaAdresowa::pobierzIdOstatniegoAdresata()
{
    return adresatMenedzer->pobierzIdOstatniegoAdresata();
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
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer= new AdresatMenedzer (NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

int KsiazkaAdresowa::wylogujUzytkownika()
{
    return uzytkownikMenedzer.wylogujUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer=NULL;

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
    adresatMenedzer->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    adresatMenedzer->wyszukajAdresatowPoImieniu();
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    adresatMenedzer->wyszukajAdresatowPoNazwisku();
}

void KsiazkaAdresowa::dodajAdresata()
{
    adresatMenedzer->dodajAdresata(pobierzIDZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::edytujAdresata()
{
    adresatMenedzer->edytujAdresata();
}

void KsiazkaAdresowa::usunAdresata()
{
    adresatMenedzer->usunAdresata();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyswietl adresatow" << endl;
    cout << "3. Wyszukaj adresata po imieniu" << endl;
    cout << "4. Wyszukaj adresata po nazwisku" << endl;
    cout << "5. Edytuj adresata" << endl;
    cout << "6. Usun adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "8. Zmien haslo" << endl;
    cout << "9. Wyloguj sie" << endl;
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

