#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;


struct studentas {
	string vardas = "", pav = "";
	float paz[10], vid, egz, gal;
};

studentas sukurimas() {
	studentas zmogus;
	cout << "iveskite varda: "; zmogus.vardas = vardo_imimas();
	//paprasome pazymiu(iskvieciama demonstracine funkcija):


	return zmogus;
};



float pazymiu_imimas() {
	float pazymys;
	cin >> pazymys;

	//Error check
	while ((cin.good() == false) && (pazymys<=10 && 0<=pazymys) ) {
		cout << "neteisinga ivestis." << '\n';

		cin.clear();
		cin.ignore(999, '\n');

		//is naujo paparaso:
		cout << "Bandykite dar karta: "; cin >> pazymys;
	}
	return pazymys;
};

string vardo_imimas() {
	string vard;
	cin >> vard;

	//Error check
	while (cin.good() == false) {
		cout << "neteisinga ivestis." << '\n';

		cin.clear();
		cin.ignore(999, '\n');

		//is naujo paparaso:
		cout << "Bandykite dar karta: "; cin >> vard;
	}
	return vard;
}

int main() {
	//studentas Grupe[10];
	int n = 0;
	cout << "Iveskite studentu skaiciu: ";
	cin >> n;

	studentas* grupe = new studentas[n];
	for (int i = 0; i < n; i++) { cout << "Iveskite " << i + 1 << "-aji vada: "; cin >> grupe[i].vardas; }
	for (int i = 0; i < n; i++) { cout << grupe[i].vardas << " : "; }
	cout << endl;

	studentas* temp = new studentas[n + 1];
	for (int i = 0; i < n; i++) temp[i] = grupe[i];
	for (int i = 0; i < n; i++) { cout << temp[i].vardas << " : "; }
	cout << endl;

	cout << "Iveskite " << n + 1 << "-aji vada: ";
	cin >> temp[n].vardas;
	for (int i = 0; i < n + 1; i++) { cout << temp[i].vardas << " : "; }
	cout << endl;

	delete[] grupe;
	n++;
	grupe = new studentas[n];
	for (int i = 0; i < n; i++) grupe[i] = temp[i];
	delete[] temp;
	cout << "grupe" << endl;
	for (int i = 0; i < n; i++) { cout << grupe[i].vardas << " : "; }
	cout << endl;
}