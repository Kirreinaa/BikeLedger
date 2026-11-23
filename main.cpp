#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

const char CDfr[] = "uzsakymas.txt";
const char RFfr[] = "ataskaita.txt";

using namespace std;

bool duomenuNuskaitymas(string Kategorija[], string Pavadinimas[], double Kaina[], int Kiekis[], int &n);
int KategorijosPasirinkimas(string Kategorija[], string Pavadinimas[], double Kaina[], int Kiekis[], int n, int pasirinktaKategorija);
void KategorijosVienetai(string Kategorija[], int Kiekis[], int n);
double eilutesSuma(double kaina, int kiekis);
double eilutesNuolaida(double suma, int kiekis);
double bendraSumaPriesNuolaidas(double Kaina[], int Kiekis[], int n);
double bendraNuolaida(double Kaina[], int Kiekis[], int n);

double KategorijosSuma(string Kategorija[], int n, double Kaina[], int Kiekis[], string kategorija);

bool tinkamaKategorija(string kategorija);
void lenteleAntraste(ostream &out);
void eilutesIsvedimas(ostream &out, string kategorija, string pavadinimas, double kaina, int kiekis);
void ataskaita(ostream &out, string Kategorija[], string Pavadinimas[], double Kaina[], int Kiekis[], int n);

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
if (!(cin >> meniuPasirinkimas)) {
    cin.clear();
    cin.ignore(1000, '\n');
    meniuPasirinkimas = 0;
}

switch (meniuPasirinkimas) {

    case 1: {
        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "UZSAKYMO PREKIU PERZIUREJIMAS" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        lenteleAntraste(cout);
        for (int i = 0; i < n; i++){
            eilutesIsvedimas(cout, Kategorija[i], Pavadinimas[i], Kaina[i], Kiekis[i]);
        }

        break;
    }

    case 2: {

        int pasirinktaKategorija;
        string kategorijosPavadinimas;

        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "PREKIU PERZIUREJIMAS PAGAL KATEGORIJA" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        cout << "Pasirinkite kategorija:" << endl;
        cout << "==============================" << endl;
        cout << "1. Dviraciai" << endl;
        cout << "2. Dalys" << endl;
        cout << "3. Aksesuarai" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        do {
            cout << "Iveskite skaiciu: ";

            if (!(cin >> pasirinktaKategorija)) {
                cin.clear();
                cin.ignore(1000, '\n');
                pasirinktaKategorija = 0;
            }

            if (pasirinktaKategorija < 1 || pasirinktaKategorija > 3) {
                cout << "Neteisingas kategorijos pasirinkimas. Bandykite dar karta." << endl;
                cout << " " << endl;
            }

        } while (pasirinktaKategorija < 1 || pasirinktaKategorija > 3);

        if (pasirinktaKategorija == 1){
            kategorijosPavadinimas = "Dviraciai";
        } else if (pasirinktaKategorija == 2){
            kategorijosPavadinimas = "Dalys";
        } else {
            kategorijosPavadinimas = "Aksesuarai";
        }

        int rasta = KategorijosPasirinkimas(Kategorija, Pavadinimas, Kaina, Kiekis, n, pasirinktaKategorija);

        if (rasta == 0) {
            cout << "Atsiprasome, bet sios kategorijos prekiu nerasta." << endl;
        } else {

        cout << fixed << setprecision(2);
        cout << "==============================" << endl;
        cout << "Moketina suma uz kategorija " << kategorijosPavadinimas<< ": "
             << KategorijosSuma(Kategorija, n, Kaina, Kiekis, kategorijosPavadinimas) << " EUR" << endl;
        }

        break;
    }

    case 3: {
        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "VISO UZSAKYMO SUMU PERZIUREJIMAS" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        double suma = bendraSumaPriesNuolaidas(Kaina, Kiekis, n);
        double nuolaida = bendraNuolaida(Kaina, Kiekis, n);
        double galutine = suma - nuolaida;

        cout << fixed << setprecision(2);
        cout << "Suma pries nuolaidas:   " << suma << " EUR" << endl;
        cout << "Bendra nuolaida:        " << nuolaida << " EUR" << endl;
        cout << "Galutine moketina suma: " << galutine << " EUR" << endl;

        break;
    }

    case 4: {
        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "SUMU PERZIUREJIMAS PAGAL KATEGORIJAS" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        cout << fixed << setprecision(2);

        cout << "Dviraciai:  " << KategorijosSuma(Kategorija, n, Kaina, Kiekis, "Dviraciai") << " EUR"<< endl;
        cout << "Dalys:      " <<KategorijosSuma(Kategorija, n, Kaina, Kiekis, "Dalys") << " EUR"<< endl;
        cout << "Aksesuarai: " <<KategorijosSuma(Kategorija, n, Kaina, Kiekis, "Aksesuarai") << " EUR" << endl;

        break;
    }

    case 5: {
        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "VISO UZSAKYMO ATASKAITA" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        ataskaita(cout, Kategorija, Pavadinimas, Kaina, Kiekis, n);

        break;
    }

    case 6: {
        cout << " " << endl;
        cout << "==============================" << endl;
        cout << "ATASKAITOS ISSAUGOJIMAS I FAILA" << endl;
        cout << "==============================" << endl;
        cout << " " << endl;

        ofstream fr(RFfr);

        if (!fr) {
            cout << "Nepavyko atidaryti failo " << RFfr << " irasymui." << endl;
        } else {
            ataskaita(fr, Kategorija, Pavadinimas, Kaina, Kiekis, n);
            fr.close();

            if (fr.fail()) {
                cout << "Klaida irasant ataskaita i faila." << endl;
            } else {
                cout << "Ataskaita sekmingai issaugota faile " << RFfr << "." << endl;
            }
        }

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

    if (!cd || n < 1 || n > 100) {
        cout << "Neteisingas irasu kiekis. Turi buti nuo 1 iki 100." << endl;
        return false;
    }

    for (int i = 0; i < n; i++) {
        cd >> ws;
        getline(cd, Kategorija[i], ';');
        getline(cd, Pavadinimas[i], ';');
        cd >> Kaina[i];
        cd.ignore();
        cd >> Kiekis[i];

        if (!cd) {
            cout << "Klaida nuskaitant irasa Nr. " << i + 1 << "." << endl;
            return false;
        }

        if (!tinkamaKategorija(Kategorija[i]) || Kaina[i] <= 0 || Kiekis[i] <= 0) {
            cout << "Netinkami duomenys irase Nr. " << i + 1 << "." << endl;
            return false;
        }
    }

    return true;
}

int KategorijosPasirinkimas(string Kategorija[], string Pavadinimas[], double Kaina[], int Kiekis[], int n, int pasirinktaKategorija){
    int rasta = 0;
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
    if ((pasirinktaKategorija == 1 && Kategorija[i] == "Dviraciai") ||
        (pasirinktaKategorija == 2 && Kategorija[i] == "Dalys") ||
        (pasirinktaKategorija == 3 && Kategorija[i] == "Aksesuarai")) {

        if (rasta == 0) {
            lenteleAntraste(cout);
        }

        eilutesIsvedimas(cout, Kategorija[i], Pavadinimas[i], Kaina[i], Kiekis[i]);

        rasta++;
    }
}

    return rasta;
}

void KategorijosVienetai(string Kategorija[], int Kiekis[], int n){
    int VienetaiNuolaidai = 0;

    for (int i=0; i < n; i++){
        for (int j=0; j < i; j++){
        if (Kategorija[i] == Kategorija[j])
            VienetaiNuolaidai++;
        }
    }
}

// Vienos eilutes suma pries nuolaida: kaina * kiekis
double eilutesSuma(double kaina, int kiekis) {
    return kaina * kiekis;
}

// Vienos eilutes nuolaida: 10 % jei kiekis >= 10, kitaip 0
double eilutesNuolaida(double suma, int kiekis) {
    if (kiekis >= 10) {
        return suma * 0.10;
    }
    return 0.0;
}

// Viso uzsakymo suma pries nuolaidas
double bendraSumaPriesNuolaidas(double Kaina[], int Kiekis[], int n) {
    double bendra = 0.0;
    for (int i = 0; i < n; i++) {
        bendra += eilutesSuma(Kaina[i], Kiekis[i]);
    }
    return bendra;
}

// Bendra visu eiluciu nuolaidu suma
double bendraNuolaida(double Kaina[], int Kiekis[], int n) {
    double nuolaida = 0.0;
    for (int i = 0; i < n; i++) {
        double suma = eilutesSuma(Kaina[i], Kiekis[i]);
        nuolaida += eilutesNuolaida(suma, Kiekis[i]);
    }
    return nuolaida;
}


double KategorijosSuma(string Kategorija[], int n, double Kaina[], int Kiekis[], string kategorija){
    double bendra = 0.0;

    for (int i = 0; i<n; i++){
        if (Kategorija[i] == kategorija){
            double suma = eilutesSuma(Kaina[i], Kiekis[i]);
            double nuolaida = eilutesNuolaida(suma, Kiekis[i]);

            bendra += suma - nuolaida;
        }
    }
    return bendra;
}

bool tinkamaKategorija(string kategorija) {
    return kategorija == "Dviraciai" || kategorija == "Dalys" || kategorija == "Aksesuarai";
}

void lenteleAntraste(ostream &out) {
    out << left << setw(12) << "Kategorija" << setw(50) << "Pavadinimas"
        << right << setw(10) << "Kaina" << setw(8) << "Kiekis"
        << setw(14) << "Suma" << setw(14) << "Nuolaida" << setw(14) << "Moketina" << endl;
    out << string(122, '-') << endl;
}

void eilutesIsvedimas(ostream &out, string kategorija, string pavadinimas, double kaina, int kiekis) {
    double suma = eilutesSuma(kaina, kiekis);
    double nuolaida = eilutesNuolaida(suma, kiekis);

    out << fixed << setprecision(2);
    out << left << setw(12) << kategorija << setw(50) << pavadinimas
        << right << setw(10) << kaina << setw(8) << kiekis
        << setw(14) << suma << setw(14) << nuolaida << setw(14) << suma - nuolaida << endl;
}

void ataskaita(ostream &out, string Kategorija[], string Pavadinimas[], double Kaina[], int Kiekis[], int n) {
    out << fixed << setprecision(2);

    out << "DVIRACIU PARDUOTUVES UZSAKYMO ATASKAITA" << endl;
    out << endl;

    lenteleAntraste(out);
    for (int i = 0; i < n; i++) {
        eilutesIsvedimas(out, Kategorija[i], Pavadinimas[i], Kaina[i], Kiekis[i]);
    }
    out << string(122, '-') << endl;
    out << endl;

    double suma = bendraSumaPriesNuolaidas(Kaina, Kiekis, n);
    double nuolaida = bendraNuolaida(Kaina, Kiekis, n);

    out << "Viso uzsakymo sumos:" << endl;
    out << "Suma pries nuolaidas:   " << suma << " EUR" << endl;
    out << "Bendra nuolaida:        " << nuolaida << " EUR" << endl;
    out << "Galutine moketina suma: " << suma - nuolaida << " EUR" << endl;
    out << endl;

    out << "Sumos pagal kategorijas (po nuolaidu):" << endl;
    out << "Dviraciai:  " << KategorijosSuma(Kategorija, n, Kaina, Kiekis, "Dviraciai") << " EUR" << endl;
    out << "Dalys:      " << KategorijosSuma(Kategorija, n, Kaina, Kiekis, "Dalys") << " EUR" << endl;
    out << "Aksesuarai: " << KategorijosSuma(Kategorija, n, Kaina, Kiekis, "Aksesuarai") << " EUR" << endl;
}