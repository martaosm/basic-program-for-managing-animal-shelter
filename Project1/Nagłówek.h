#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <set>
#include <stack>
#include <regex>

using namespace std;

class Zwierze
{
public:
	string imie;
	int wiek;
	int id_z;
	string barwa;
	string lekarstwa;
	Zwierze() :imie("zwierze"), wiek(0), id_z(0), barwa("N/A"), lekarstwa("N/A") {}
	virtual void wczytaj(int r) = 0;
	virtual void wy_wiek(int x, int z) = 0;
	virtual void wypisz_lek() = 0;
	virtual int jakaBarwa(string odp, int licznik) = 0;
	virtual void wypiszInfo() = 0;
};
class Pies :public Zwierze
{
public:
	string imie;
	int wiek;
	int id_z;
	string barwa;
	string lekarstwa;
	string tresura;
	void wczytaj(int r);
	void wy_wiek(int x, int z);
	void wypisz_lek();
	void czyTresowany();
	int jakaBarwa(string odp, int licznik);
	void wypiszInfo();
	Pies() :imie("Pies"), wiek(0), id_z(0), barwa("N/A"), lekarstwa("N/A"), tresura("N/A") {}
};
class Kot :public Zwierze
{
public:
	string imie;
	int wiek;
	int id_z;
	string barwa;
	string lekarstwa;
	string cecha_charakteru;
	void wczytaj(int r);
	void wy_wiek(int x, int z);
	void wypisz_lek();
	int jakaCecha(string odp, int licznik);
	int jakaBarwa(string odp, int licznik);
	void wypiszInfo();
	Kot() :imie("Kot"), wiek(0), id_z(0), barwa("N/A"), lekarstwa("N/A"), cecha_charakteru("N/A") {}
};
class Lek
{
public:
	int id;
	string nazwa;
	string objawy;
	int koszt;
	void wczytaj(int r);
	void wypiszDostepneLeki();
	Lek() :id(0), nazwa("lek"), objawy("N/A"), koszt(0) {}
};
class Pacjent
{
public:
	int id_p;
	int ilosc_lekow;
	int koszt_utrzym;
	vector<int> id_lek;
	void wczytajDoTab(int r, Pies** tab1, int num1, Kot** tab2, int num2);
	void noweLeki(int id_zwierz, int nowe_l);
	Pacjent() :id_p(0), ilosc_lekow(0),koszt_utrzym(0), id_lek() {}
};
int ilosc_psow();
int ilosc_kotow();
Pies** wypisz_p();
Kot** wypisz_k();
void dopisywanie_do_pliku();
void wy_wiek(Pies** tab1, Kot** tab2, int num1, int num2);
void tworzenie_tab_ubarw_p(int x, int y, Pies** tab1, Kot** tab2, int wybor);
void wypisz_barwa(int wybor, string odp, int num1, int num2, Pies** tab1, Kot** tab2);
void wypiszZwierzetaZLekarstwami(Pies** tab1, Kot** tab2, int num1, int num2);
void wypisz_tres(int num1, Pies** tab1);
vector<string> funkcja(vector<string> vec);
void tworzenie_tab_charakt(int y, Kot** tab2);
void wypisz_cecha(int y, Kot** tab2);
Lek** wypisz();
int ilosc_lekow();
Pacjent** wypiszP(int num, int r, Pies** tab1, int num1, Kot** tab2, int num2);
int ile_pacjentow_psy(Pies** tab1, int num1);
int ile_pacjentow_koty(Kot** tab2, int num2);
vector<int> pacjenci(Pies** tab1, int num1, Kot** tab2, int num2);
Pacjent** zebyBledowNieWywalalo();