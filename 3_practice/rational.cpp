#include "rational.h"
#include "iostream"
using namespace std;

void rational::set(int a1, int b1) {
    int A1 = a1, B1 = b1;
    while (B1 == 0){
        cout << "Введите b, не равный 0\n";
        cin >> B1;
    }
    A1 = A1 % B1;
    for (int i = A1; i > 1; i--){
        if (A1%i == 0 and B1%i == 0){
            A1 /= i;
            B1 /= i;
        }
    }
    a = A1; b = B1;
}

rational::rational() {}
rational::rational(int a1, int b1) {
    this->set(a1, b1);
}

void rational::show() {
    cout << a << "/" << b << '\n';
}
rational rational::operator+(rational r) {
    rational temp;
    temp = rational(this->a * r.b + r.a * this->b, this->b * r.b);
    return temp;
}
void rational::operator++() {
    this->a++;
}
bool rational::operator==(rational r) {
    return this->a == r.a and this->b == r.b;
}
bool rational::operator>(rational r) {
    return this->a * r.b > this->b * r.a;
}
void rational::operator=(rational r) {
    this->a = r.a;
    this->b = r.b;
}