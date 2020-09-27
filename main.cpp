#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using std::sort;
using std::string;
using std::cout;
using std::cin;
using std::endl;


struct studentas {
	string vardas = "", pav = "";
	float paz[10], vid, med, egz, gal;
};


void spausdinimas(studentas stud) {
	cout << "vardas         Pavarde         galutinis(vid)"<< "\n";
	cout << "---------------------------------------------"<< "\n";
	cout << stud.vardas << "      " << stud.pav << "      ";
	cout << std::fixed;
	cout << std::setprecision(2);
	cout << stud.med <<"\n";

}

int int_imimas() {
	int pazymys;
	cin >> pazymys;

	//Error check
	while ((cin.good() == false) && (0 <= pazymys)) {
		cout << "neteisinga ivestis." << '\n';

		cin.clear();
		cin.ignore(999, '\n');

		//is naujo paparaso:
		cout << "Bandykite dar karta: "; cin >> pazymys;
	}
	return pazymys;
};

int ndskaiciaus_imimas() {
	int nskaicius;
	cin >> nskaicius;

	//Error check
	while ((cin.good() == false) && (nskaicius <= 10 && 0 <= nskaicius)) {
		cout << "neteisinga ivestis." << '\n';

		cin.clear();
		cin.ignore(999, '\n');

		//is naujo paparaso:
		cout << "Bandykite dar karta: "; cin >> nskaicius;
	}
	return nskaicius;
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

studentas sukurimas() {
	studentas zmogus;
	cout << "iveskite varda:   "; zmogus.vardas = vardo_imimas();
	cout << "iveskite pavarde: "; zmogus.pav = vardo_imimas();
	//paprasome pazymiu(demonstracine funkcijos vieta):
	int nd = 0;
	cout << "kiek ND pazymiu?(iki 10): "; nd = ndskaiciaus_imimas();
	zmogus.vid = 0;
		for (int i = 0; i < nd; i++)
		{
			cout << "Iveskite " << i + 1 << "-aji pazymi: "; zmogus.paz[i] = pazymiu_imimas();
	//suskaiciuojame vidurki ir mediana:
			zmogus.vid += zmogus.paz[i];

		};

	// demonstracijos pabaiga.
	zmogus.vid = zmogus.vid / nd;
	sort(zmogus.paz, zmogus.paz+nd);
	if (nd % 2 != 0) { zmogus.med = (float)zmogus.paz[nd / 2]; }
	else { zmogus.med=(float)((zmogus.paz[(nd - 1) / 2] + zmogus.paz[nd / 2])) / 2.0; };

	cout << "Iveskite egzamino rezultata: "; zmogus.egz = pazymiu_imimas();
	cout << endl;

	zmogus.gal = 0.4 * zmogus.vid + 0.6 * zmogus.egz;
	return zmogus;
};
/*
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
*/
int main() {
	int n = 0;
	cout << "kiek studentu bus?:  "; n = int_imimas();
	studentas* grupe = new studentas[n];
	for (int i = 0; i < n; i++) { grupe[i] = sukurimas(); };
	//spausdinimas
	for (int i = 0; i < n; i++) { spausdinimas(grupe[i]); };
	cout << endl;

	delete[] grupe;
}