#include "Triangle.h"
#include "Circle.h"
#include <iostream>
#include <windows.h>

using namespace std;

void Triangl(){
    Triangle mas[3];
    double a, b, c;
    for (int i = 0; i < 3; i++){
        cout << "Введите a, b и c для треугольника № " << i+1 << " через пробел: " << endl;
        cin >> a >> b >> c;
        mas[i].set (a, b, c);
        if (!(mas[i].Triangle::exst_tr())){
            mas[i].show();
            cout << "Треугольника с такими сторонами не существует, попробуйте ещё раз" << endl;
            i--;
        }
    }
    for (int i=0; i<3; i++){
        mas[i].show();
        cout << "Периметр треугольника: " << mas[i].perimetr() << endl;
        cout << "Площадь треугольника: " << mas[i].square() << endl;
    }
}

void Circl(){
    Circle mas[3];
    float r, x, y;
    for (int i = 0; i < 3; i++){
        cout << "Введите r, x и y для окружности № " << i+1 << " через пробел: " << endl;
        cin >> r >> x >> y;
        mas[i].set_circle(r, x, y);
    }
    float a, b, c, r_n, x_n, y_n;
    for (int i = 0; i < 3; i++){
        cout << "Площадь окружности № " << i+1 << ": " << mas[i].square() << '\n';
        cout << "Введите стороны треугольника: ";
        cin >> a >> b >> c;
        if (mas[i].triangle_around(a, b, c)){
            cout << "Вокруг треугольника можно описать данную окружность" << '\n';
        } else if(mas[i].triangle_in(a, b, c)){
            cout << "В треугольник можно вписать данную окружность" << '\n';
        } else{
            cout << "Нельзя не вписать, не описать данную окружность около треугольника" << '\n';
        }
        cout << '\n' << "Введите радиус и координаты окружности: ";
        cin >> r_n >> x_n >> y_n;
        if (mas[i].check_circle(r_n, x_n, y_n)){
            cout << "Окружности пересекаются" << '\n';
        } else{
            cout << "Окружности не пересекаются" << '\n';
        }
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
//    Triangl();
    Circl();
    bool temp;
    cin >> temp;
    return 0;
}
