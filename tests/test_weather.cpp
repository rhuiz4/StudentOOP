#include <cassert>
#include <iostream>
#include <fstream>
#include "../my_code/weather.h"

using namespace std;

int main() {
    GPS loc = GPS(46.3, 67.2);
    Weather irkutsk = Weather("Irkutsk", loc);
    cout << irkutsk << endl;
    
    ifstream ifs("r.txt");
    double i;
    while (ifs >> i) {
        cout << i << endl;;
    }
    
    ifs.close();
    
}
