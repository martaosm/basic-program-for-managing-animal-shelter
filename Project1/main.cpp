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

int main()
{
	Pies** tab1 = wypisz_p();
	Kot** tab2 = wypisz_k();
	Lek** tab3 = wypisz();
	int num3 = ilosc_lekow();
	Pacjent** tab4 = zebyBledowNieWywalalo();
	int wybor = 1;
	while (wybor != 0)
	{
		cout << "Witamy w systemie zarzadzania schroniskiem! Prosimy o wybranie czynnosci, ktora chcesz wykonac?" << endl;
		cout << "1. Wypisanie listy zwierzat" << endl;
		cout << "2. Dopisanie nowego zwierzecia" << endl;
		cout << "3. Wypisz liste lekow" << endl;
		cout << "4. Zarzadzanie lekarstwami" << endl;
		cout << "0. Wyjscie z programu" << endl;
		cout << "Wybor: ";
		int num1 = ilosc_psow();
	    int num2 = ilosc_kotow();
		cin >> wybor;
		if (wybor == 1)
		{
			cout << "1. Wypisanie listy wszystkich zwierzat" << endl << "2. Wypisanie zwierzat po konkretnym atrybucie" << endl;
			cout << "Wybor: ";
			int wybor1;
			cin >> wybor1;
			switch (wybor1)
			{
			case 1:
				cout << "1. Wszystkie informacje" << endl << "2. Tylko lista imion" << endl;
				int wybor2;
				cout << "Wybor: ";
				cin >> wybor2;
				if (wybor2 == 1)
				{
					cout << "Psy:" << endl << "----------------------------------" << endl;
					for (int i = 0; i < num1; i++)
					{
						tab1[i]->wypiszInfo();
					}
					cout << "Koty:" << endl << "----------------------------------" << endl;
					for (int i = 0; i < num2; i++)
					{
						tab2[i]->wypiszInfo();
					}
				}
				if (wybor2 == 2)
				{
					cout << "Psy:" << endl;
					for (int i = 0; i < num1; i++)
					{
						cout << tab1[i]->imie << endl;
					}
					cout << "----------------------------------" << endl;
					cout << "Koty: " << endl;
					for (int i = 0; i < num2; i++)
					{
						cout << tab2[i]->imie << endl;
					}
				}
				//else throw "Blad! Nie ma innej opcji";
				break;

			case 2:
				cout << "Po czym wyszukiwac zwierzeta?" << endl;
				cout << "1. Po gatunku" << endl << "2. Po wieku" << endl << "3. Po ubarwieniu" << endl << "4. Czy do zwierzecia sa przypisane lekarstwa" << endl << "5. Czy jest wytresowany (tylko psy)" << endl << "6. Po cechach charakteru (tylko koty)" << endl;
				int wybor3;
				string wyb_g;
				string odp, odp1;
				cin >> wybor3;
				switch (wybor3)
				{
				case 1:
					cout << "Psy czy koty?" << endl << "Wpisz swoj wybor: ";
					cin >> wyb_g;
					if (wyb_g == "psy")
					{
						for (int i = 0; i < num1; i++)
						{
							cout << tab1[i]->imie << endl;
						}
					}
					if (wyb_g == "koty")
					{
						for (int i = 0; i < num2; i++)
						{
							cout << tab2[i]->imie << endl;
						}
					}
					if (wyb_g != "psy" && wyb_g != "koty")
					{
						cout << "Blad! Sprobuj jeszcze.";
					}
					break;

				case 2:
					wy_wiek(tab1, tab2, num1, num2);
					break;

				case 3:
					cout << "Chcesz wypisac ubarwienie psow(1), kotow(2) czy wszystkich zwierzat(3)?" << endl;
					int wybor;
					cout << "Wybor: ";
					cin >> wybor;
					tworzenie_tab_ubarw_p(num1, num2, tab1, tab2, wybor);
					wypisz_barwa(wybor, odp, num1, num2, tab1, tab2);
					break;

				case 4:
					wypiszZwierzetaZLekarstwami(tab1, tab2, num1, num2);
					break;

				case 5:
					wypisz_tres(num1, tab1);
					break;

				case 6:
					tworzenie_tab_charakt(num2, tab2);
					wypisz_cecha(num2, tab2);
				}
			}
		}
		if (wybor == 2)
		{
			dopisywanie_do_pliku();
		}
		if (wybor == 3)
		{
			cout << "Leki:" << endl << "----------------------------------" << endl;
			for (int i = 0; i < num3; i++)
			{
				tab3[i]->wypiszDostepneLeki();
			}
		}
		////////FUNKCJE DO LEKARSTW I TAKICH TAM////////
		if (wybor == 4)
		{
			int id1, wyb;
			wypiszZwierzetaZLekarstwami(tab1, tab2, num1, num2);
			cout << "Chcesz wypisac dane pacjenta(1), przypisac nowe leki(2), zaktualizowac baze danych(3)?" << endl << "Wybor: ";
			cin >> wyb;
			int p1 = ile_pacjentow_psy(tab1, num1);
			int p2 = ile_pacjentow_koty(tab2, num2);
			int p = p1 + p2;	
			if (wyb == 1)
			{
				cout << "Podaj ID pacjenta: ";
				cin >> id1;
				for (int z = 0; z < p; z++)
				{
					tab4[z]->koszt_utrzym = 0;
					if (tab4[z]->id_p == id1)
					{
						cout << "ID: " << tab4[z]->id_p << endl;
						cout << "Lekarstwa: " << endl;
						int n = tab4[z]->id_lek.size();
						for (int i = 0; i < n; i++)
						{
							for (int j = 0; j < num3; j++)
							{
								if (tab4[z]->id_lek[i] == tab3[j]->id)
								{
									cout << tab3[j]->nazwa << " ("<<tab3[j]->koszt<<" zl)"<<endl;
									tab4[z]->koszt_utrzym += tab3[j]->koszt;
								}
							}
						}
						cout << "Koszt utrzymania: " << tab4[z]->koszt_utrzym << " zl" << endl;
					}
				}
			}
			if (wyb == 2)
			{
				int nowe_l, id_zwierz;
				cout << "Prosze podac ID zwierzecia: ";
				cin >> id_zwierz;
				cout << endl << "Ile nowych lekow chcesz przypisac?" << endl;
				cin >> nowe_l;
				cout << "Prosze podac ID leku/ów:";
				for (int j = 0; j < p; j++)
				{
					tab4[j]->noweLeki(id_zwierz, nowe_l);
				}
			}
			if (wyb == 3)
			{
				int r = 0;
				tab4 = wypiszP(p, r, tab1, num1, tab2, num2);
			}	
		}
	}
	cout << "Do zobaczenia!";
	delete[] tab1;
	delete[] tab2;
	delete[] tab3;
	delete[] tab4;

}