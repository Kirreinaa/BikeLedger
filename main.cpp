
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

int meniuPasirinkimas;

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

} while (meniuPasirinkimas > 7 || meniuPasirinkimas < 1);

}
