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
        cout << endl;
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
    ~Menu() {};
};


int main()
{
    Menu meniu1("menu1");
    meniu1 = meniu1 + "optiune1";
    meniu1 = meniu1 + "optiune2";
    meniu1 = meniu1 + "optiune3";
    meniu1.showMenu();

    Menu meniu2("menu2");
    meniu2 = meniu2 + "optiune4";
    meniu2 = meniu2 + "optiune5";
    meniu2 = meniu2 + "optiune6";
    meniu2.showMenu();

    meniu1 = meniu1 + meniu2;
    meniu1.showMenu();

    Menu meniu3("menu3");
    meniu3 = meniu1 / 3;
    meniu3.showMenu();
}
