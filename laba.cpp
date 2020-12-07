#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int viborM();
string onlyWords();
string viborKomandi();

class FootballTeams {
protected:
	string trener;
	string country;
public:
	FootballTeams(string a, string a1) {
		trener = a;
		country = a1;
	}
	virtual void showData() = 0;
};

class RealMadrid :public FootballTeams {
private:
	string liga;
	string trofey;
public:
	RealMadrid(string a, string a1, string a2, string a3) :FootballTeams(a, a1) {
		liga = a2;
		trofey = a3;
	}
	void showData() {
		cout << " Название команды" << endl;
		cout << " Лига: " << liga << endl;
		cout << " Страна: " << country << endl;
		cout << " Тренер: " << trener << endl;
		cout << " Количество трофей: " << trofey << endl;
	}
};

class Barcelona :public FootballTeams {
private:
	string liga;
	string trofey;
public:
	Barcelona(string a, string a1, string a2, string a3) :FootballTeams(a, a1) {
		liga = a2;
		trofey = a3;
	}
	void showData() {
		cout << "Название команды" << endl;
		cout << " Лига: " << liga << endl;
		cout << " Страна: " << country << endl;
		cout << " Тренер: " << trener << endl;
		cout << " Количество трофей: " << trofey << endl;
	}
};

class Chelsea :public FootballTeams {
private:
	string liga;
	string trener;
	string trofey;
public:
	Chelsea(string a, string a1, string a2, string a3) :FootballTeams(a, a1) {
		trener = a2;
		trofey = a3;
	}
	void showData() {
		cout << "Название команды" << endl;
		cout << " Лига: " << liga << endl;
		cout << " Страна: " << country << endl;
		cout << " Тренер: " << trener << endl;
		cout << " Количество трофей: " << trofey << endl;
	}
};
string onlyWords() {
	string slovo;
	while (true) {
		int Knopka;
		char symbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					symbol = (char)Knopka;
					if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z')) {
						slovo = slovo + symbol;
						cout << symbol;
					}
				}
	}
	return slovo;
}

int inNum(int lr, int rr);
bool isNumNumeric();
bool isNumRangeCorrect(int num, int lr, int rr);

const int NUM_S = 0;
const int NUM_F = 2147483647;

int main() {
	setlocale(0, "rus");
	int n = 1;
	FootballTeams** mas = new FootballTeams * [n];
	n--;
	while (true) {
		int choose = viborM();
		if (choose == 0) {
			string name, country, liga, trofey;
			cout << "Название команды: ";
			name = onlyWords();
			system("cls");
			cout << "Страна: ";
			country = onlyWords();

			system("cls");
			cout << "Лига: ";
			liga = onlyWords();
			system("cls");
			cout << "Количество трофей: ";
			trofey = inNum(NUM_S, NUM_F);
			system("cls");
			mas[n] = new RealMadrid(name, country, liga, trofey);
			mas[n]->showData();
			n++;
			n++;
			FootballTeams** ptr = new FootballTeams * [n];
			n--;
			copy(mas, mas + n, ptr);
			mas = ptr;
			ptr = NULL;
			delete[]ptr;
			system("pause");
			system("cls");
		}
		else
			if (choose == 1) {
				string name, country, trener, trofey;
				cout << "Название команды: ";
				name = onlyWords();
				system("cls");
				cout << "Страна: ";
				country = onlyWords();

				system("cls");
				cout << "Тренер: ";
				trener = onlyWords();
				system("cls");
				cout << "Количество трофей: ";
				trofey = inNum(NUM_S, NUM_F);

				mas[n] = new Barcelona(name, country, trener, trofey);
				mas[n]->showData();
				n++;
				n++;
				FootballTeams** ptr = new FootballTeams * [n];
				n--;
				copy(mas, mas + n, ptr);
				mas = ptr;
				ptr = NULL;
				delete[]ptr;
				system("pause");
				system("cls");
			}
			else
				if (choose == 2) {
					string name, country, trofey, liga;
					cout << "Название команды: ";
					name = onlyWords();
					system("cls");
					cout << "Страна: ";
					country = onlyWords();

					system("cls");
					liga = viborKomandi();
					system("cls");
					cout << "Количество трофей: ";
					trofey = inNum(NUM_S, NUM_F);

					system("cls");
					mas[n] = new Chelsea(name, country, liga, trofey);
					mas[n]->showData();
					n++;
					n++;
					FootballTeams** ptr = new FootballTeams * [n];
					n--;
					copy(mas, mas + n, ptr);
					mas = ptr;
					ptr = NULL;
					delete[]ptr;
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) {
						for (int i = 0; i < n; i++)
							mas[i]->showData();
						system("pause");
						system("cls");
					}
					else break;
	}
	delete[] mas;
	return 0;
}
int inNum(int lr, int rr)
{
	int num;
	int vol = 1;

	while (true)
	{
		cin >> num;
		if (isNumNumeric() && isNumRangeCorrect(num, lr, rr)) return num;
		cout << "Некорректный ввод! Введите числа в дипазоне от " << lr << " по " << rr << ": ";
	}
}
bool isNumNumeric()
{
	if (cin.get() == '\n') return true;
	else
	{
		cin.clear();
		cin.ignore(256, '\n');
		return false;
	}
}
bool isNumRangeCorrect(int num, int lr, int rr) { return (lr <= num && num <= rr); }







int viborM() {
	int viborM = 0, knopka = 0;
	while (true) {
		cout << "select menu item " << endl;
		viborM = (viborM + 5) % 5;

		if (viborM == 0) { cout << " -> RealMadrid" << endl; }
		else { cout << " RealMadrid" << endl; }

		if (viborM == 1) { cout << " -> Barcelona" << endl; }
		else { cout << " Barcelona" << endl; }

		if (viborM == 2) { cout << " -> Chelsea" << endl; }
		else { cout << " Chelsea" << endl; }

		if (viborM == 3) { cout << " -> All information" << endl; }
		else { cout << " All information" << endl; }

		if (viborM == 4) { cout << " -> To finish the program" << endl; }
		else { cout << " To finish the program" << endl; }

		knopka = _getch();
		if (knopka == 224) {
			knopka = _getch();
			if (knopka == 72) viborM--;
			if (knopka == 80) viborM++;
		}
		if (knopka == 13) { system("cls"); return viborM; }
		system("cls");
	}
}

string viborKomandi() {
	int viborM = 0, knopka = 0;
	while (true) {
		cout << "select menu item: " << endl;
		viborM = (viborM + 5) % 5;

		if (viborM == 0) { cout << " -> RealMadrid" << endl; }
		else { cout << "RealMadrid" << endl; }

		if (viborM == 1) { cout << " -> Barcelona" << endl; }
		else { cout << "Barcelona" << endl; }

		knopka = _getch();
		if (knopka == 224) {
			knopka = _getch();
			if (knopka == 72) viborM--;
			if (knopka == 80) viborM++;
		}
		if (knopka == 13) {
			system("cls");
			if (viborM == 0) return "RealMadrid";
			else
				return "Barcelona";
		}
		system("cls");
	}
}
