#include "Triangle.h"
#include "Circle.h"
#include "Figure.h"
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

void Figur(){
    Figure mas[3];
    float x1, x2, x3, x4, y1, y2, y3, y4;
    for (int i = 0; i < 3; i++){
        cout << "Введите x1, x2, x3, x4, y1, y2, y3, y4 для четырёхугольника № " << i+1 << " через пробел: " << endl;
        cin >> x1 >> x2 >> x3 >> x4 >> y1 >> y2 >> y3 >> y4;
        mas[i] = Figure(x1,x2,x3,x4,y1,y2,y3,y4);
    }
    // Первая фигура:
    cout << "Информация о первой фигуре: \n";
    mas[0].show();
    // Вторая фигура:
    if (mas[1].is_square()){
        cout << "Вторая фигура - квадрат\n";
    } else if (mas[1].is_prug()){
        cout << "Вторая фигура - прямоугольник\n";
    } else if (mas[1].is_romb()){
        cout << "Вторая фигура - ромб\n";
    } else{
        cout << "Вторая фигура - четырёхугольник\n";
    }
    // Третья фигура:
    if (mas[2].is_in_circle()){
        cout << "Третий четырёхугольник можно вписать в окружность \n";
    }
    if (mas[2].is_out_circle()){
        cout << "Третий четырёхугольник можно описать около окружности \n";
    }
    if (!mas[2].is_in_circle() and !mas[2].is_out_circle()){
        cout << "Третий четырёхугольник нельзя не вписать, не описать около окружности \n";
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Triangl();
    Circl();
    Figur();
    bool temp;
    cin >> temp;
    return 0;
}
