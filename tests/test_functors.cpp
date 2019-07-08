//
//#include <iostream>
//#include <functional>
//#include <cmath>
//
//using namespace std;
//
//const double PI = 3.14159265358979323846;
//
//class Sin {
//    public:
//        double operator()(double r) {
//            return sin(r);
//        }
//};
//
//class Fib {
//    public:
//        Fib() {
//        }
//
//        long long int operator()(long long int n) {
//            if (n <= 1) return 1;
//            else return operator()(n - 1) + operator()(n - 2);
//        }
//
//        const int MAX_FIB = 100;
//        const int NOT_CALCED = -1;
//    private:
//};
//
//
//double square_func(double d, function<double(double)> f) {
//    return f(d) * f(d);
//}
//
//
//int main() {
//    const long long int FIB_NUM = 46;
//
//    // first functors:
//    Sin sine = Sin();
//    double d = sine(PI / 2);
//    cout << "sin pi / 2 == " << d << endl;
//    d = sine(0);
//    cout << "sin 0 == " << d << endl;
//    Fib fib = Fib();
//    long long int f = fib(FIB_NUM);
//    cout << "fib(" << FIB_NUM << ") == " << f << endl;
//
//    // then lambdas -- use several functions from cmath here:
//    d = square_func(0, [](double arg) { return sin(arg); });
//    cout << "Square of sin 0 = " << d << endl;
//    d = square_func(1, [](double arg) { return sin(arg); });
//    cout << "Square of sin 1 = " << d << endl;
//    /*
//    // you're call here!
//    cout << "Square of cos 1 = " << d << endl;
//    // you're call here!
//    cout << "Square of tan 0 = " << d << endl;
//    // you're call here!
//    */
//}

#include <iostream>
#include <functional>
#include <cmath>
#include <string>

using namespace std;

const double PI = 3.14159265358979323846;

/*
 * An exception to throw when we get a number too big.
 * */
class NoNegative : public exception {
public:
    NoNegative(int n)
    : badnum(n)
    {
    }
    
    const char* what() const throw() {
        string s = "Argument canot be negative: " + to_string(badnum);
        return s.c_str();
    }
    
private:
    int badnum;
};


class Sin {
public:
    double operator()(double r) {
        return sin(r);
    }
};


class Cos {
public:
    double operator()(double r) {
        return cos(r);
    }
};


class Tan {
public:
    double operator()(double r) {
        return tan(r);
    }
};


class Fib {
public:
    Fib() {
        for (int i = 0; i < MAX_FIB; i++) {
            f_arr[i] = NOT_CALCED;
        }
    }
    
    long long int operator()(long long int n) {
        if (n < 0) { throw (NoNegative(n)); }
        if (f_arr[n] != NOT_CALCED) { return f_arr[n]; }
        
        long long int res = 0;
        if (n <= 1) { res = 1; }
        else { res = (operator()(n - 1) + operator()(n - 2)); }
        
        
        f_arr[n] = res;
        return res;
    }
    
    const int MAX_FIB = 100;
    const int NOT_CALCED = -1;
private:
    long long int* f_arr = new long long int[MAX_FIB];
};


double your_func(double d, function<double(double)> f) {
    return 0.0;
}

double square_func(double d, function<double(double)> f) {
    return f(d) * f(d);
}

double cubed_func(double d, function<double(double)> f) {
    return f(d) * f(d) * f(d);
}

int main() {
    const long long int FIB_NUM = 46;
    
    // first functors:
    Sin sine = Sin();
    double d = sine(PI / 2);
    cout << "sin pi / 2 == " << d << endl;
    d = sine(0);
    cout << "sin 0 == " << d << endl;
    Fib fib = Fib();
    
    try {
        
        long long int f = fib(FIB_NUM);
        cout << "fib(" << FIB_NUM << ") == " << f << endl;
        
    }
    catch (NoNegative& e) {
        cerr << "Got a negative argument for fib: " << e.what() << endl;
    }
    
    // then lambdas -- use several functions from cmath here:
    d = square_func(0, [](double arg) { return sin(arg); });
    cout << "Square of sin 0 = " << d << endl;
    d = square_func(1, [](double arg) { return sin(arg); });
    cout << "Square of sin 1 = " << d << endl;
    d = square_func(1, [](double arg) { return cos(arg); });
    cout << "Square of cos 1 = " << d << endl;
    d = square_func(0, [](double arg) { return tan(arg); });
    cout << "Square of tan 0 = " << d << endl;
    
    d = cubed_func(0, [](double arg) { return sin(arg); });
    cout << "Cube of sin 0 = " << d << endl;
    d = cubed_func(1, [](double arg) { return sin(arg); });
    cout << "Cube of sin 1 = " << d << endl;
    d = cubed_func(1, [](double arg) { return cos(arg); });
    cout << "Cube of cos 1 = " << d << endl;
    d = cubed_func(0, [](double arg) { return tan(arg); });
    cout << "Cube of tan 0 = " << d << endl;
}
