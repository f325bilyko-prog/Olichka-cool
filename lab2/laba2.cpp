#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Spivrobitnyk {
public:
    int tabNomer;          
    string prizvyshche;    
    string imya;           
    string poBatkovi;      
    double oklad;          
    int stazh;             
    int vidpratsovaniDni;  
    int robochiDni;        
    double narahuvannya;   
    double utrymannya;     
    double alimentyOdsotok; 

    
    Spivrobitnyk() {
        tabNomer = 0;
        oklad = 0;
        stazh = 0;
        vidpratsovaniDni = 0;
        robochiDni = 1;
        narahuvannya = 0;
        utrymannya = 0;
        alimentyOdsotok = 0;
    }

    
    void rahuvatyZarplatu() {
        
        double zaDni = oklad / robochiDni * vidpratsovaniDni;
       
        double nadbavka = oklad * stazh / 100;
        
        narahuvannya = zaDni + nadbavka;

        
        double pensiya = narahuvannya * 2 / 100;
        
        double alimenty = narahuvannya * alimentyOdsotok / 100;
        
        utrymannya = pensiya + alimenty;
    }

    
    double naRuky() {
        return narahuvannya - utrymannya;
    }

    
    void pokazaty() {
        cout << "Number: " << tabNomer << endl;
        cout << "Name: " << prizvyshche << " " << imya << " " << poBatkovi << endl;
        cout << "Base salary: " << oklad << endl;
        cout << "Work experience: " << stazh << endl;
        cout << "Days worked: " << vidpratsovaniDni << " ç " << robochiDni << endl;
        cout << "Gross earnings: " << narahuvannya << endl;
        cout << "Deductions: " << utrymannya << endl;
        cout << "Net pay: " << naRuky() << endl;
        cout << "-------------------------" << endl;
    }
};


class Zarplata {
private:
    vector<Spivrobitnyk> spysok; 

    
    int znayty(int nomer) {
        for (int i = 0; i < spysok.size(); i++) {
            if (spysok[i].tabNomer == nomer) {
                return i;
            }
        }
        return -1;
    }

    
    void vvestyDani(Spivrobitnyk& s) {
        cout << "surname: ";
        cin >> s.prizvyshche;
        cout << "Name: ";
        cin >> s.imya;
        cout << "Po batkovi: ";
        cin >> s.poBatkovi;
        cout << "Work experience: ";
        cin >> s.oklad;
        cout << "Work experience (years): ";
        cin >> s.stazh;
        cout << "Days worked: ";
        cin >> s.vidpratsovaniDni;
        cout << "Working days in a mounth: ";
        cin >> s.robochiDni;
        cout << "Child support percentage (0 if none): ";
        cin >> s.alimentyOdsotok;
    }

public:
    
    void dodaty() {
        Spivrobitnyk s;
        cout << "Employee number: ";
        cin >> s.tabNomer;

        
        if (znayty(s.tabNomer) != -1) {
            cout << "This number already taken!" << endl;
            return;
        }

        vvestyDani(s);
        spysok.push_back(s); 
        cout << "Employee added." << endl;
    }

    
    void redaguvaty() {
        int nomer;
        cout << "Enter employee number: ";
        cin >> nomer;

        int m = znayty(nomer);
        if (m == -1) {
            cout << "No results found." << endl;
            return;
        }

        cout << "Enter new data:" << endl;
        vvestyDani(spysok[m]); 
        cout << "Data  updated" << endl;
    }

    
    void vydalyty() {
        int nomer;
        cout << "Enter employee number: ";
        cin >> nomer;

        int m = znayty(nomer);
        if (m == -1) {
            cout << "No results found." << endl;
            return;
        }

        spysok.erase(spysok.begin() + m); 
        cout << "Entry deleted." << endl;
    }


    void narahuvatyVsim() {
        if (spysok.size() == 0) {
            cout << "The list is empty." << endl;
            return;
        }
        for (int i = 0; i < spysok.size(); i++) {
            spysok[i].rahuvatyZarplatu();
        }
        cout << "Salary calculated for all." << endl;
    }

    
    void poshuk() {
        int nomer;
        cout << "Enter employee number: ";
        cin >> nomer;

        int m = znayty(nomer);
        if (m == -1) {
            cout << "No results found." << endl;
            return;
        }
        spysok[m].pokazaty();
    }

    
    void pokazatyVsih() {
        if (spysok.size() == 0) {
            cout << "The list is empty." << endl;
            return;
        }
        for (int i = 0; i < spysok.size(); i++) {
            spysok[i].pokazaty();
        }
    }
};

int main() {
    Zarplata z;
    int vybir = -1;

    
    while (vybir != 0) {
        cout << endl;
        cout << "===== Menu =====" << endl;
        cout << "1 - Add employee" << endl;
        cout << "2 - Edit employee" << endl;
        cout << "3 - Delete employee" << endl;
        cout << "4 - Clculate salary" << endl;
        cout << "5 - Find employee salary" << endl;
        cout << "6 - Show all" << endl;
        cout << "0 - Exit" << endl;
        cout << "Your choice: ";
        cin >> vybir;

        if (vybir == 1) {
            z.dodaty();
        }
        else if (vybir == 2) {
            z.redaguvaty();
        }
        else if (vybir == 3) {
            z.vydalyty();
        }
        else if (vybir == 4) {
            z.narahuvatyVsim();
        }
        else if (vybir == 5) {
            z.poshuk();
        }
        else if (vybir == 6) {
            z.pokazatyVsih();
        }
        else if (vybir == 0) {
            cout << "The end." << endl;
        }
        else {
            cout << "No such item!" << endl;
        }
    }

    return 0;
}