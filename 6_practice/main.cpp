#include "iostream"
#include <windows.h>
//#include "cone.h"
#include "us_cone.h"
using namespace std;

ostream &operator<<(ostream &stream, cone obj){
    stream << "(" << obj.x << "; ";
    stream << obj.y << "; ";
    stream << obj.z << ") ";
    stream << "r=" << obj.radius << " ";
    stream << "h=" << obj.height << "\n";
}
ostream &operator<<(ostream &stream, us_cone obj){
    stream << "(" << obj.x << "; ";
    stream << obj.y << "; ";
    stream << obj.z << ") ";
    stream << "h=" << obj.height << " ";
    stream << "r=" << obj.radius << " ";
    stream << "r_u=" << obj.radius_us << "\n";
    stream << "Площадь поверхности: " << obj.area() << '\n';
    stream << "Объём: " << obj.volume() << '\n' << '\n';
}
istream &operator>>(istream &stream, us_cone& obj){
    cout << "Введите координаты, радиус, высоту конуса и радиус усечения: ";
    stream >> obj.x >> obj.y >> obj.z >> obj.radius >> obj.height >> obj.radius_us;
    cout << '\n';
    return stream;
}

void conus(){
    cone* arr = new cone[3];
    for (int i = 0; i < 3; i++){
        cout << "Введите координаты, радиус и высоту конуса " << i+1 << ": ";
        double x, y, z, r, h;
        cin >> x >> y >> z >> r >> h;
        arr[i].setCoordinate(x, y, z);
        arr[i].setRadius(r);
        arr[i].setHeight(h);
    }

    for (int i = 0; i < 3; i++){
        cout << "Конус " << i+1 << ": " << arr[i];
        cout << "Площадь поверхности: " << arr[i].area() << '\n';
        cout << "Объём: " << arr[i].volume() << '\n';
    }
}

void us_conus(){
    us_cone cn1(2, 1, 1);
    us_cone cn2, cn3;
    cout << "Статический конус: " << cn1;
    cin >> cn2 >> cn3;
    cout << cn2 << cn3;
}


int main(){
    SetConsoleOutputCP(CP_UTF8);

//    conus();
    us_conus();

    bool temp;
    cin >> temp;
    return 0;
}