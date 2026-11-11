
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

const char CDfr[] = "uzsakymas.txt";

using namespace std;

bool duomenuNuskaitymas(string Kategorija[], string Pavadinimas[], double Kaina[], int Kiekis[], int &n);

int main() {

const int MAX = 100;
int n; // irasu kiekis

string Kategorija[MAX];
string Pavadinimas[MAX];
double Kaina[MAX];
int Kiekis[MAX];

int meniuPasirinkimas;

if (duomenuNuskaitymas(Kategorija, Pavadinimas, Kaina, Kiekis, n)) {

do {
cout << " " << endl;
cout << "==============================" << endl;
cout << "DVIRACIU PARDUOTUVE" << endl;
cout << "==============================" << endl;
cout << " " << endl;
cout << "1. Perziureti visas uzsakymo prekes" << endl;
cout << "2. Perziureti prekes pagal kategorija" << endl;
cout << "3. Perziureti viso uzsakymo sumas" << endl;
cout << "4. Perziureti sumas pagal kategorijas" << endl;
cout << "5. Parodyti visa uzsakymo ataskaita" << endl;
cout << "6. Issaugoti ataskaita i faila" << endl;
cout << "7. Iseiti" << endl;

cout << "Pasirinkite veiksma: ";
cin >> meniuPasirinkimas;

switch (meniuPasirinkimas) {

    case 1: {
        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "UZSAKYMO PREKIU PERZIUREJIMAS" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        break;
    }

    case 2: {
        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "PREKIU PERZIUREJIMAS PAGAL KATEGORIJA" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        break;
    }

    case 3: {
        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "VISO UZSAKYMO SUMU PERZIUREJIMAS" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        break;
    }

    case 4: {
        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "SUMU PERZIUREJIMAS PAGAL KATEGORIJAS" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        break;
    }

    case 5: {
        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "VISO UZSAKYMO ATASKAITA" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        break;
    }

    case 6: {
        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "ATASKAITOS ISSAUGOJIMAS I FAILA" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        break;
    }

    case 7: {
        cout << "Iseinama is savitarnos..." << endl;

        break;
    }

    default: {
        cout << "Neteisingas ivedimas. Bandykite dar karta." << endl;
        break;
    }
}

} while (meniuPasirinkimas != 7);

}

return 0;
}

bool duomenuNuskaitymas(string Kategorija[], string Pavadinimas[], double Kaina[], int Kiekis[], int &n) {

    ifstream cd(CDfr);

    if (!cd) {
        cout << "Nepavyko atidaryti failo. Bandykite is naujo." << endl;
        return false;
    }

    cd >> n;
    cd.ignore();

    if (n < 1 || n > 100) {
        cout << "Neteisingas irasu kiekis. Turi buti nuo 1 iki 100." << endl;
        return false;
    }

    for (int i = 0; i < n; i++) {
        getline(cd, Kategorija[i], ';');
        getline(cd, Pavadinimas[i], ';');
        cd >> Kaina[i] >> Kiekis[i];
        cd.ignore();

        if (!cd) {
            cout << "Klaida nuskaitant irasa. Bandykite is naujo." << i + 1 << "." << endl;
            return false;
        }
    }

    return true;
}
