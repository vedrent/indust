#include "Figure.h"
#include <iostream>
#include <cmath>

using namespace std;

Figure::Figure(){
    x1 = 0; x2 = 0; x3 = 0; x4 = 0;
    y1 = 0; y2 = 0; y3 = 0; y4 = 0;
    S = (abs((x1-x2)*(y1+y2) + (x2-x3)*(y2+y3) + (x3-x4)*(y3+y4) + (x4-x1)*(y4+y1)))/2;
    P = sqrt(pow((x1 - x2),2) + pow((y1 - y2),2)) + sqrt(pow((x2 - x3),2) + pow((y2 - y3),2)) + sqrt(pow((x3 - x4),2) +
            pow((y3 - y4),2)) + sqrt(pow((x4 - x1),2) + pow((y4 - y1),2));
}
Figure::Figure(float X1, float X2, float X3, float X4, float Y1, float Y2, float Y3, float Y4){
    x1 = X1; x2 = X2; x3 = X3; x4 = X4;
    y1 = Y1; y2 = Y2; y3 = Y3; y4 = Y4;
    S = (abs((x1-x2)*(y1+y2) + (x2-x3)*(y2+y3) + (x3-x4)*(y3+y4) + (x4-x1)*(y4+y1)))/2;
    P = sqrt(pow((x1 - x2),2) + pow((y1 - y2),2)) + sqrt(pow((x2 - x3),2) + pow((y2 - y3),2)) + sqrt(pow((x3 - x4),2) +
            pow((y3 - y4),2)) + sqrt(pow((x4 - x1),2) + pow((y4 - y1),2));
}
void Figure::show() {
    cout << "Координаты точек: \n";
    cout << "(" << x1 << "," << y1 << ") " << "(" << x2 << "," << y2 << ") " << "(" << x3 << "," << y3 << ") " << "(" << x4 << "," << y4 << ") ";
    cout << "\nПлощадь: " << S;
    cout << "\nПериметр: " << P << '\n';
}
bool Figure::is_prug() {   // ��������� ������������ ����� 0
    return (abs(((x2-x1)*(x3-x2)) + ((y2-y1)*(y3-y2))) < 0.0001) and (abs(((x3-x2)*(x4-x3)) + ((y3-y2)*(y4-y3))) < 0.0001) and (abs(((x4-x3)*(x1-x4)) + ((y4-y3)*(y1-y4))) < 0.0001);
}
bool Figure::is_romb() {   // ��� ������� �����
    return (abs(P/4 - sqrt(pow((x1 - x2),2) + pow((y1 - y2),2))) < 0.0001) and (abs(P/4 - sqrt(pow((x2 - x3),2) + pow((y2 - y3),2))) < 0.0001) and (abs(P/4 - sqrt(pow((x3 - x4),2) + pow((y3 - y4),2))) < 0.0001) and (abs(P/4 - sqrt(pow((x4 - x1),2) + pow((y4 - y1),2))) < 0.0001);
}
bool Figure::is_square() {
    return this->is_prug() and this->is_romb();
}
bool Figure::is_in_circle() {   // �������� ������� ��������
    return abs(sqrt(pow((x1 - x2),2) + pow((y1 - y2),2)) * sqrt(pow((x3 - x4),2) + pow((y3 - y4),2)) + sqrt(pow((x2 - x3),2) + pow((y2 - y3),2)) * sqrt(pow((x4 - x1),2) + pow((y4 - y1),2)) - sqrt(pow((x1 - x3),2) + pow((y1 - y3),2)) * sqrt(pow((x2 - x4),2) + pow((y2 - y4),2))) < 0.0001;
}
bool Figure::is_out_circle() {   // ����� ��������������� ������ �����
    return abs(sqrt(pow((x1 - x2),2) + pow((y1 - y2),2)) - sqrt(pow((x2 - x3),2) + pow((y2 - y3),2)) + sqrt(pow((x3 - x4),2) + pow((y3 - y4),2)) - sqrt(pow((x4 - x1),2) + pow((y4 - y1),2))) < 0.0001;
}