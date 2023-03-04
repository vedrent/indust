#include "eq2.h"
#include "iostream"
#include "cmath"
using namespace std;


eq2::eq2(double a1, double b1, double c1) {
    a = a1; b = b1; c = c1;
    D = b*b - 4*a*c;
}
void eq2::set(double a1, double b1, double c1) {
    a = a1; b = b1; c = c1;
    D = b*b - 4*a*c;
}
double eq2::find_X() {
    if (D<0){
        cout << "Корней нет\n";
        return 0;
    } else if (D==0){
        cout << "Один корень: ";
        double x = -b/(2*a);
        cout << x << '\n';
        return x;
    } else{
        cout << "Два корня, наибольший: ";
        double x = max((-b - sqrt(D)) / (2*a), (-b + sqrt(D)) / (2*a));
        cout << x << '\n';
        return x;
    }
}
double eq2::find_Y(double x1) {
    return a*x1*x1 + b*x1 + c;
}