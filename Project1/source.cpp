#include "Nag³ówek.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <set>
#include <stack>
#include <regex>

using namespace std;


void Pies::wypiszInfo()
{
	cout << "Imie: " << imie << endl << "Wiek: " << wiek << endl << "Id: " << id_z << endl << "Ubarwienie: " << barwa << endl << "Czy ma przypisane leki: " << lekarstwa << endl << "Czy jest wytresowany: " << tresura << endl;
	cout << "----------------------------------" << endl;
}
void Kot::wypiszInfo()
{
	cout << "Imie: " << imie << endl << "Wiek: " << wiek << endl << "Id: " << id_z << endl << "Ubarwienie: " << barwa << endl << "Czy ma przypisane leki: " << lekarstwa << endl << "Cecha charakteru: " << cecha_charakteru << endl;
	cout << "----------------------------------" << endl;
}
void Pies::wczytaj(int r)/////wczytywanie z pliku psy.txt/////
{
	string linia;
	string wiek1, id1;
	fstream plik;
	plik.open("psy.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku!";
		exit(0);
	}
	int nr_linii = 1 + r;
	int akt_nr = 1;
	while (getline(plik, linia))
	{
		if (akt_nr == nr_linii)imie = linia;
		if (akt_nr == nr_linii+1)wiek1 = linia;
		if (akt_nr == nr_linii + 2)id1 = linia;
		if (akt_nr == nr_linii+3)barwa = linia;
		if (akt_nr == nr_linii+4)lekarstwa = linia;
		if (akt_nr == nr_linii+5)tresura = linia;
		akt_nr++;
	}
	wiek = stoi(wiek1);
	id_z = stoi(id1);
	plik.close();
}
void Kot::wczytaj(int r)/////wczytywanie z pliku koty.txt/////
{
	string linia;
	string wiek1, id1;
	fstream plik;
	plik.open("koty.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku!";
		exit(0);
	}
	int nr_linii = 1 + r;
	int akt_nr = 1;
	while (getline(plik, linia))
	{
		if (akt_nr == nr_linii)imie = linia;
		if (akt_nr == nr_linii + 1)wiek1 = linia;
		if (akt_nr == nr_linii + 2)id1 = linia;
		if (akt_nr == nr_linii + 3)barwa = linia;
		if (akt_nr == nr_linii + 4)lekarstwa = linia;
		if (akt_nr == nr_linii + 5)cecha_charakteru = linia;
		akt_nr++;
	}
	wiek = stoi(wiek1);
	id_z = stoi(id1);
	plik.close();
}
int ilosc_psow()/////funkcja liczy ile jest psow/////
{
	int ilosc = 0;
	string linia;
	fstream plik;
	plik.open("psy.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku!";
		exit(0);
	}
	while (getline(plik, linia))
	{
		ilosc++;
	}
	ilosc = ilosc / 6;
	plik.close();
	return ilosc;
}
int ilosc_kotow()/////funkcja liczy ile jest kotow/////
{
	int ilosc = 0;
	string linia;
	fstream plik;
	plik.open("koty.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku!";
		exit(0);
	}
	while (getline(plik, linia))
	{
		ilosc++;
	}
	ilosc = ilosc / 6;
	plik.close();
	return ilosc;
}
Pies** wypisz_p()/////wczytywanie danych do tablicy (psy)/////
{
	int num = ilosc_psow();
	int r = 0;
	Pies** tab = new Pies * [num];
	for (int i = 0; i < num; i++)
	{
		tab[i] = new Pies;
		tab[i]->wczytaj(r);
		r = r + 6;
	}
	return tab;
}
Kot** wypisz_k()/////wczytywanie danych do tablicy (koty)/////
{
	int num = ilosc_kotow();
	int r = 0;
	Kot** tab = new Kot * [num];
	for (int i = 0; i < num; i++)
	{
		tab[i] = new Kot;
		tab[i]->wczytaj(r);
		r = r + 6;
	}
	return tab;
}
void Pies::wy_wiek(int x, int z)/////funckja wypisuje zwierzeta z podanego przedzialu wiekowego/////
{
	if (x < 0 || z>30) throw "Blad! Zle podany przedzial wiekowy.";
	if (wiek >= x && wiek <= z) cout << imie << endl;
}
void Kot::wy_wiek(int x, int z)
{
	if (x < 0 || z>30) throw "Blad! Zle podany przedzial wiekowy.";
	if (wiek >= x && wiek <= z) cout << imie << endl;
}
void wy_wiek(Pies** tab1, Kot** tab2, int num1, int num2)
{
	cout << "Prosze podac przedzial wiekowy" << endl;
	int granica_d, granica_g;
	cout << "Od ";
	cin >> granica_d;
	cout << " do ";
	cin >> granica_g;
	cout << "Psy: " << endl;
	for (int i = 0; i < num1; i++)
	{
		tab1[i]->wy_wiek(granica_d, granica_g);
	}
	cout << "Koty: " << endl;
	for (int i = 0; i < num2; i++)
	{
		tab2[i]->wy_wiek(granica_d, granica_g);
	}
}
vector<string> funkcja(vector<string> vec)/////funkcja przegl¹da wektor i usuwa z niego powtarzajace sie wartosci zostawiajac jeden egzemplarz/////
{
	set<string> s1;
	int n = vec.size();
	for (int i = 0; i < n; i++)
	{
		s1.insert(vec[i]);
	}
	vector<string> wynik;
	set<string>::iterator itr;
	for (itr = s1.begin(); itr != s1.end(); itr++)
	{
		wynik.push_back(*itr);
	}
	return wynik;
}
void tworzenie_tab_ubarw_p(int x, int y, Pies** tab1, Kot** tab2, int wybor)/////funkcja tworzy wektor i wypisuje jego zawartosc/////
{
	if (wybor == 1)
	{
		string tab[10];
	    for (int i = 0; i < x; i++)
	    {
			tab[i] = tab1[i]->barwa;
	    }
	    vector<string> vec1(begin(tab), end(tab));
	    vector<string> vec2 = funkcja(vec1);
		int n = vec2.size();
	    for (int i = 0; i < n; i++)
	    {
			cout << vec2[i] << endl;
	    }
	}
	if (wybor == 2)
	{
		string tab[10];
		for (int i = 0; i < y; i++)
		{
			tab[i] = tab2[i]->barwa;
		}
		vector<string> vec1(begin(tab), end(tab));
		vector<string> vec2 = funkcja(vec1);
		int n = vec2.size();
		for (int i = 0; i < n; i++)
		{
			cout << vec2[i] << endl;
		}
	}
	if (wybor == 3)
	{
		string tab3[10];
		for (int i = 0; i < x; i++)
		{
			tab3[i] = tab1[i]->barwa;
		}
		vector<string> vec1(begin(tab3), end(tab3));
		vector<string> vec2 = funkcja(vec1);
		int n = vec2.size();
		cout << "----------------------------------" << endl;
		cout << "Psy: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << vec2[i] << endl;
		}
		cout << endl;
		cout << "----------------------------------" << endl;
		string tab4[10];
		for (int i = 0; i < y; i++)
		{
			tab4[i] = tab2[i]->barwa;
		}
		vector<string> vec3(begin(tab4), end(tab4));
		vector<string> vec4 = funkcja(vec3);
		int n1 = vec4.size();
		cout << "Koty: " << endl;
		for (int i = 0; i < n1; i++)
		{
			cout << vec4[i] << endl;
		}
	}
}
int Pies::jakaBarwa(string odp, int licznik)
{
	if (odp == barwa)
	{
		cout << imie << endl;
		licznik++;
	}
	return licznik;
}
int Kot::jakaBarwa(string odp, int licznik)
{
	if (odp == barwa)
	{
		cout << imie << endl;
		licznik++;
	}
	return licznik;
}
void wypisz_barwa(int wybor, string odp, int num1, int num2, Pies** tab1, Kot** tab2)/////funkcja wypisuje zwierzeta o konkretnym ubarwieniu/////
{
	cout << "Jakie ubarwienie Cie interesuje?" << endl << "Wybor: ";
	cin >> odp;
	int licznik = 0;
	int licznik2 = 0;
	if (wybor == 1)
	{
		for (int i = 0; i < num1; i++)
		{
			licznik += tab1[i]->jakaBarwa(odp, licznik);
		}
		if (licznik == 0) cout << "Nie ma pieskow o takim ubarwieniu." << endl;
	}
	if (wybor == 2)
	{
		for (int i = 0; i < num2; i++)
		{
			licznik += tab2[i]->jakaBarwa(odp, licznik);
		}
		if (licznik == 0)cout << "Nie ma kotkow o takim ubarwieniu." << endl;
	}
	if (wybor == 3)
	{
		cout << "----------------------------------" << endl;
		cout << "Psy: " << endl;
		for (int i = 0; i < num1; i++)
		{
			licznik += tab1[i]->jakaBarwa(odp, licznik);
		}
		if (licznik == 0) cout << "Nie ma pieskow o takim ubarwieniu." << endl;
		cout << "----------------------------------" << endl;
		cout << "Koty: " << endl;
		for (int i = 0; i < num2; i++)
		{
			licznik2 += tab2[i]->jakaBarwa(odp, licznik2);
		}
		if (licznik2 == 0)cout << "Nie ma kotkow o takim ubarwieniu." << endl;
	}
}
void Pies::wypisz_lek()
{
	if (lekarstwa == "tak")cout << imie << endl;
}
void Kot::wypisz_lek()
{
	if (lekarstwa == "tak")cout << imie << endl;
}
void wypiszZwierzetaZLekarstwami(Pies** tab1, Kot** tab2, int num1, int num2)
{
	cout << "Zwierzeta, ktore maja przypisane leki" << endl;
	cout << "Psy: " << endl;
	for (int i = 0; i < num1; i++)
	{
		tab1[i]->wypisz_lek();
	}
	cout << "Koty: " << endl;
	for (int i = 0; i < num2; i++)
	{
		tab2[i]->wypisz_lek();
	}
}
void Pies::czyTresowany()
{
	if (tresura == "tak")cout << imie << endl;
}
void wypisz_tres(int num1, Pies** tab1)/////funkcja wypisuje wytresowane psy/////
{
	cout << "Wytresowane psy: " << endl;
	for (int i = 0; i < num1; i++)
	{
		tab1[i]->czyTresowany();
	}
}
void tworzenie_tab_charakt(int y, Kot** tab2)/////funkcja tworzy wektor i wypisuje jego zawartosc/////
{
	string tab[10];
	for (int i = 0; i < y; i++)
	{
		tab[i] = tab2[i]->cecha_charakteru;
	}
	vector<string> vec1(begin(tab), end(tab));
	vector<string> vec2 = funkcja(vec1);
	int n = vec2.size();
	for (int i = 0; i < n; i++)
	{
		cout << vec2[i] << endl;
	}
}
int Kot::jakaCecha(string odp, int licznik)
{
	if (odp == cecha_charakteru) {
		cout << imie << endl;
		licznik++;
	}
	return licznik;
}
void wypisz_cecha(int num2, Kot** tab2)/////funkcja wypisuje koty z konkretna cecha charakteru/////
{
	int licznik = 0;
	string odp;
	cout << "Wybierz ceche: ";
	cin >> odp;
	for (int i = 0; i < num2; i++)
	{
		licznik += tab2[i]->jakaCecha(odp, licznik);
	}
	if (licznik == 0)cout << "Nie ma kotkow z taka cecha charakteru." << endl;
}
void Lek::wczytaj(int r)/////wczytywanie danych z pliku lek.txt/////
{
	string linia;
	string id1, koszt1;
	fstream plik;
	plik.open("lek.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku!";
		exit(0);
	}
	int nr_linii = 1 + r;
	int akt_nr = 1;
	while (getline(plik, linia))
	{
		if (akt_nr == nr_linii)id1 = linia;
		if (akt_nr == nr_linii + 1)nazwa = linia;
		if (akt_nr == nr_linii + 2)objawy = linia;
		if (akt_nr == nr_linii + 3)koszt1 = linia;
		akt_nr++;
	}
	id = stoi(id1);
	koszt = stoi(koszt1);
	plik.close();
}
void Lek::wypiszDostepneLeki()
{
	cout << "Id: " << id << endl << "Nazwa: " << nazwa << endl << "Objawy: " << objawy << endl << "Koszt: " << koszt << endl;
	cout << "----------------------------------" << endl;
}
int ilosc_lekow()/////zliczanie dostepnych lekarstw/////
{
	int ilosc = 0;
	string linia;
	fstream plik;
	plik.open("lek.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "Nie udalo sie otworzyc pliku!";
		exit(0);
	}
	while (getline(plik, linia))
	{
		ilosc++;
	}
	ilosc = ilosc / 4;
	plik.close();
	return ilosc;
}
Lek** wypisz()/////wpisywanie danych do tablicy/////
{
	int num = ilosc_lekow();
	int r = 0;
	Lek** tab = new Lek * [num];
	for (int i = 0; i < num; i++)
	{
		tab[i] = new Lek;
		tab[i]->wczytaj(r);
		r = r + 4;
	}
	return tab;
}
void dopisywanie_do_pliku()/////dopisywanie do pliku lol/////
{
	int odp;
	string imie1, barwa1, lekarstwa1, tresura1, cecha1;
	int wiek1, id;
	cout << "Jakiego gatunku jest nowe zwierze?" << endl;
	cout << "1.Pies" << endl << "2.Kot" << endl << "Odp.: ";
	cin >> odp;
	regex imie("[A-Z]{1}[a-z]");
	if (odp == 1)
	{
		fstream plik1;
		plik1.open("psy.txt", ios::out | ios::app);
		if (plik1.good() == false)
		{
			cout << "blad";
		}
		else
		{
			cout << "Imie: ";
			cin.ignore();
			getline(cin, imie1);
			if (regex_match(imie1, imie)) {
				plik1 << imie1 << endl;
			}
			else {
				cout << "Zly format imienia." << endl;
				return;
			}
			cout << "Wiek: ";
			cin >> wiek1;
			cout << "ID: ";
			cin >> id;
			cout << "Ubarwienie: ";
			cin.ignore();
			getline(cin, barwa1);
			cout << "Czy pies ma jakies lekarstwa? ";
			//cin.ignore();
			getline(cin, lekarstwa1);
			cout << "Czy pies jest wytresowany? ";
			//cin.ignore();
			getline(cin, tresura1);
			plik1 << wiek1 << endl << id << endl << barwa1 << endl << lekarstwa1 << endl << tresura1 << endl;
		}
		plik1.close();
	}
	if (odp == 2)
	{
		fstream plik2;
		plik2.open("koty.txt", ios::out | ios::app);
		if (plik2.good() == false)
		{
			cout << "blad";
		}
		else
		{
			cout << "Imie: ";
			cin.ignore();
			getline(cin, imie1);
			if (regex_match(imie1, imie)) {
				plik2 << imie1 << endl;
			}
			else {
				cout << "Zly format imienia." << endl;
				return;
			}
			cout << "Wiek: ";
			cin >> wiek1;
			cout << "ID: ";
			cin >> id;
			cout << "Ubarwienie: ";
			cin.ignore();
			getline(cin, barwa1);
			cout << "Czy kot ma jakies lekarstwa? ";
			//cin.ignore();
			getline(cin, lekarstwa1);
			cout << "Cecha charakteru: ";
			//cin.ignore();
			getline(cin, cecha1);
			plik2 << wiek1 << endl << id << endl << barwa1 << endl << lekarstwa1 << endl << cecha1 << endl;
		}
		plik2.close();
	}
}
int ile_pacjentow_psy(Pies** tab1, int num1)/////ile psow ma przypisane lekarstwo/////
{
	int p = 0;
	for (int z = 0; z < num1; z++)
	{
		if (tab1[z]->lekarstwa == "tak")
		{
			p++;
		}
	}
	return p;
}
int ile_pacjentow_koty(Kot** tab2, int num2)/////ile kotow ma przypisane lekarstwo/////
{
	int p = 0;
	for (int z = 0; z < num2; z++)
	{
		if (tab2[z]->lekarstwa == "tak")
		{
			p++;
		}
	}
	return p;
}
vector<int> pacjenci(Pies** tab1, int num1, Kot** tab2, int num2)/////funkcja tworzy wektor, do ktorego wpisuje ID zwierzecia, ktore ma przypisanie lekarstwo/////
{
	vector<int> idP;
	for (int z = 0; z < num1; z++)
	{
		if (tab1[z]->lekarstwa == "tak")
		{
			idP.push_back(tab1[z]->id_z);
		}
	}
	for (int z = 0; z < num2; z++)
	{
		if (tab2[z]->lekarstwa == "tak")
		{
			idP.push_back(tab2[z]->id_z);
		}
	}
	return idP;
}
void Pacjent::wczytajDoTab(int r, Pies** tab1, int num1, Kot** tab2, int num2)/////wpisywanie danych o pacjentach, czyli zwierzeciach, ktore maja przypisanie lekarstwo/////
{
	string linia;
	string ilosc, lekId, Pid;
	fstream plik;
	int ilosc_l, idL;
	vector<int> idP;
	idP = pacjenci(tab1, num1, tab2, num2);
	id_p = idP[r];
	cout << "Ile lekarstw przypisac do zwierzaka o ID " << id_p << "?" << endl;
	cin >> ilosc_l;
	ilosc_lekow = ilosc_l;
	cout << "Podaj ID lekow:";
	for (int j = 0; j < 1; j++)
	{
		for (int i = 0; i < ilosc_l; i++)
		{
			cin >> idL;
			id_lek.push_back(idL);
		}
	}
}
Pacjent** wypiszP(int num, int r, Pies** tab1, int num1, Kot** tab2, int num2)/////wczytywanie danych do tabeli/////
{
	Pacjent** tab = new Pacjent * [num];
	for (int i = 0; i < num; i++)
	{
		tab[i] = new Pacjent;
		tab[i]->wczytajDoTab(r, tab1, num1, tab2, num2);
		r++;
	}
	return tab;
}
Pacjent** zebyBledowNieWywalalo()
{
	Pacjent** tab = new Pacjent * [100];
	for (int i = 0; i < 100; i++)
	{
		tab[i] = new Pacjent;
	}
	return tab;
}
void Pacjent::noweLeki(int id_zwierz, int nowe_l)
{
	int lek;
	if (id_p == id_zwierz)
	{
		for (int i = 0; i < nowe_l; i++)
		{
			cin >> lek;
			id_lek.push_back(lek);
			ilosc_lekow++;
		}
	}
}