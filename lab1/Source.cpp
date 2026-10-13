#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class MyFunc {
public:
    double x, y, z;

    double calcB() {
        double verh = y + atan(pow(fabs(x * x + z), 0.1));
        double nyz = 3 / x + pow(sin(pow(y + z, 3)), 2);
        double dodatok = y * exp(-(x + z) / (y + z));
        return x * (verh / nyz + dodatok);
    }

    double calcA(double b) {
        double verh = sqrt(pow(fabs(x * x - z), 0.3)) - cbrt(fabs(y + 2 * b));
        double nyz = 1 + x / 1 + (y * y) / 2 + (z * z * z) / 6;
        return verh / nyz;
    }
};


void task1() {
    int No = 1;

    MyFunc obj;
    obj.x = 0.48 * No;     
    obj.y = 0.47 * No;
    obj.z = -1.32 * No;

    double b = obj.calcB();    
    double a = obj.calcA(b);   

    cout << "task1" << endl;
    cout << "b = " << b << endl;
    cout << "a = " << a << endl;
}


void task2() {
    int No = 1;

    MyFunc obj;
    obj.y = 0.47 * No;     
    obj.z = -1.32 * No;

    double xp = -1;        
    double xk = 1;         
    double dx = 0.2;       

    cout << "task 2" << endl;
    cout << setw(8) << "x" << setw(12) << "b" << setw(12) << "a" << endl;

    
    for (double i = -1; i <= 1; i+= 0.2) {
        obj.x = i;

        
        //if (fabs(obj.x) < 0.0001) {
          //  cout << setw(8) << 0 << "   function does not exist (division by zero)" << endl;
            //continue;
        //}

        double b = obj.calcB();    
        double a = obj.calcA(b);   

        cout << setw(8) << obj.x << setw(12) << b << setw(12) << a << endl;
    }
}


int main() {
    task1();
    cout << endl;      
    task2();

    return 0;
}