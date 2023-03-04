#include "iostream"
#include <windows.h>
#include "eq2.h"
#include "rational.h"
using namespace std;

eq2 operator + (eq2 e1, eq2 e2){
    eq2 temp = eq2(e1.a + e2.a, e1.b + e2.b, e1.c + e2.c);
    return temp;
}

rational operator - (rational r1, rational r2){
    rational temp;
    temp = rational(r1.a * r2.b - r2.a * r1.b, r1.b * r2.b);
    return temp;
}

void eq_2(){
    double a, b, c, a1, b1, c1;
    cin >> a >> b >> c >> a1 >> b1 >> c1;
    eq2 ex1(a, b, c), ex2(a1, b1, c1);
    ex1.find_X();
    cout << ex2.find_Y(6) << '\n';
    eq2 ex3 = ex1 + ex2;
    ex3.find_X();
}

void ration(){
    int n;
    cin >> n;
    rational *arr = new rational[n];
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr[i].set(a, b);
    }
    for (int i = 0; i < n; i++){
        cout << "Дробь " << i+1 << ": ";
        arr[i].show();
    }
    cout << "Сумма 1 и 2 дробей: ";
    (arr[0] + arr[1]).show();
    cout << "Разница 2 и 3 дробей: ";
    (arr[1] - arr[2]).show();
    cout << "Инкремент к 1 дроби: ";
    ++arr[0];
    arr[0].show();
    if (arr[0] > arr[2]){
        cout << "1 дробь больше 3\n";
    } else if (arr[0] == arr[2]){
        cout << "1 и 3 дроби равны\n";
    } else{
        cout << "1 дробь меньше 3\n";
    }
    cout << "Присваиваем первой дроби значение третьей:\n";
    arr[0] = arr[2];
    arr[0].show();

    delete[] arr;
}

int main(){
    SetConsoleOutputCP(CP_UTF8);
//    eq_2();
    ration();
    bool temp;
    cin >> temp;
    return 0;
}