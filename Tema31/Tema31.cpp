#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int positions = 0;
string listOfMenus[100];

class Menu {

private:

    string name;
    int position;
    vector<string> options;
public:
    Menu() {
        this->name = "";
        int position = 0;
    }

    Menu(string _name) {
        this->name = _name;
        this->position = positions;
        positions++;
        listOfMenus[positions] = _name;
    }

    void showMenu() {
    
        cout << name << endl << endl;

        for (int i = 0; i < this->options.size(); i++) {
            /*if (this->options[i] != "")*/ {
                cout << i << " " << this->options[i] << endl;
                cout << "------------------------------------------------------------------------------" << endl;
            }
        }
    }

    Menu operator*(const string& newName){
        Menu menu;
        menu.name = newName;
        menu.position = this->position;
        menu.options = this->options;
        return menu;
    }

    Menu operator+(const string& newOption) {
        Menu menu;
        menu.name = this->name;
        menu.position = this->position;
        menu.options = this->options;
        menu.options.push_back(newOption);
        return menu;
    }

    Menu operator!() {
        Menu menu;
        menu.name = this->name;
        menu.position = this->position;
        menu.options = this->options;
        sort(menu.options.begin(), menu.options.end());
        return menu;
    }

    Menu operator+(const Menu& secondMenu) {
        Menu menu;
        menu.name = this->name;
        menu.position = this->position;
        menu.options = this->options;
        for (int i = 0; i < secondMenu.options.size(); i++) {
            menu.options.push_back(secondMenu.options[i]);
        }
        return menu;
    }

    Menu operator/(const int& n) {
        Menu menu;
        menu.name = this->name;
        menu.position = this->position;
        for (int i = 0; i < n; i++) {
            menu.options.push_back(this->options[i]);
        }
        return menu;
    }

    int numberOfOptions() {
        return options.size();
    }
    ~Menu() {};
};


int main()
{
    Menu meniu1("meniu1");
    Menu meniu2("meniu2");
    Menu meniu3("meniu3");
    bool exist = true;
    int choice;
    int menuNumber = 0;
    string menuName;
    string menuOption;
    int nmbrOfOptions;

    while (exist) {
        cout << "Selectati una dintre optiuni:" << endl;
        cout << "1.Vizualizati unul dintre meniuri." << endl;
        cout << "2.Schimbati numele unui meniu." << endl;
        cout << "3.Adaugati o optiune unui meniu." << endl;
        cout << "4.Sortati alfabetic un meniu." << endl;
        cout << "5.Concatenati cele 2 meniuri." << endl;
        cout << "6.Extrageti un submeniu dintr-un meniu." << endl;
        cout << "7.Iesire." << endl;
        cin >> choice;
        while (choice < 1 || choice > 7) {
            cout << "Optiunea nu este valida, va rog sa alegeti alta optiune." << endl;
        }
        switch (choice) {
        case 1:
            while (menuNumber != 1 && menuNumber != 2) {
                cout << "Ce meniu doriti sa vizualizati?(1 sau 2)" << endl;
                cin >> menuNumber;
            }
            if (menuNumber == 1) {
                meniu1.showMenu();
            }
            else {
                meniu2.showMenu();
            }
            menuNumber = 0;
            break;
        case 2:
            while (menuNumber != 1 && menuNumber != 2) {
                cout << "Carui meniu doriti sa ii schimbati numele?(1 sau 2)" << endl;
                cin >> menuNumber;
            }
            cout << "Introduceti numele pe care doriti sa il atribuiti meniului:"; cin >> menuName;
            cout << endl;
            if (menuNumber == 1) {
                meniu1 = meniu1 * menuName;
            }
            else {
                meniu2 = meniu2 * menuName;
            }
            menuNumber = 0;
            break;
        case 3:
            while (menuNumber != 1 && menuNumber != 2) {
                cout << "Carui meniu doriti sa ii atribuiti o optiune?(1 sau 2)" << endl;
                cin >> menuNumber;
            }
            cout << "Introduceti optiunea pe care doriti sa o atribuiti meniului:"; cin >> menuOption;
            cout << endl;
            if (menuNumber == 1) {
                meniu1 = meniu1 + menuOption;
            }
            else {
                meniu2 = meniu2 + menuOption;
            }
            menuNumber = 0;
            break;
        case 4:
            while (menuNumber != 1 && menuNumber != 2) {
                cout << "Ce meniu doriti sa sortati alfabetic?(1 sau 2)" << endl;
                cin >> menuNumber;
            }
            cout << endl;
            if (menuNumber == 1) {
                meniu1 = !meniu1;
            }
            else {
                meniu2 = !meniu2;
            }
            menuNumber = 0;
            break;
        case 5:
            meniu1 = meniu1 + meniu2;
            cout << "Cele 2 meniuri au fost concatenate." << endl;
            break;
            menuNumber = 0;
        case 6:
            while (menuNumber != 1 && menuNumber != 2) {
                cout << "Din care meniu doriti sa extrageti un submeniu?(1 sau 2)" << endl;
                cin >> menuNumber;
            }
            if (menuNumber == 1) {
                cout << "Meniul contine " << meniu1.numberOfOptions() << " optiuni. Alegeti un numar de optiuni mai mic decat acesta." << endl;
                cin >> nmbrOfOptions;
                while (nmbrOfOptions > meniu1.numberOfOptions()) {
                    cout << "Meniul contine " << meniu1.numberOfOptions() << " optiuni. Alegeti un numar de optiuni mai mic decat acesta." << endl;
                    cin >> nmbrOfOptions;
                }
                meniu3 = meniu1 / nmbrOfOptions;
                meniu3.showMenu();
            }
            else {
                cout << "Meniul contine " << meniu2.numberOfOptions() << " optiuni. Alegeti un numar de optiuni mai mic decat acesta." << endl;
                cin >> nmbrOfOptions;
                while (nmbrOfOptions > meniu2.numberOfOptions()) {
                    cout << "Meniul contine " << meniu2.numberOfOptions() << " optiuni. Alegeti un numar de optiuni mai mic decat acesta." << endl;
                    cin >> nmbrOfOptions;
                }
                meniu3 = meniu2 / nmbrOfOptions;
                meniu3.showMenu();
            }
            menuNumber = 0;
            break;
        case 7:
            exist = false;
            break;
        default:
            break;
            exit(0);
        }
    }

}
