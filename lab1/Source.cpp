#include <iostream>
#include <cmath>
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

int main() {
    int No = 1;   

    MyFunc obj;             
    obj.x = 0.48 * No;      
    obj.y = 0.47 * No;
    obj.z = -1.32 * No;

    double b = obj.calcB();      
    double a = obj.calcA(b);     

    cout << "b = " << b << endl;
    cout << "a = " << a << endl;

    return 0;
}