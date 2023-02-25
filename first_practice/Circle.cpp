#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

void Circle::set_circle(float r, float x, float y) {
    radius = r;
    x_center = x;
    y_center = y;
}
float Circle::square() {
    return acos(-1) * pow(radius, 2);
}
bool Circle::triangle_around (float a, float b, float c){
    float p = (a + b + c) / 2;
    return (abs(a * b * c / (4 * sqrt(p*(p-a)*(p-b)*(p-c))) - radius) < 0.0001);
}
bool Circle::triangle_in (float a, float b, float c){
    float p = (a + b + c) / 2;
    return (abs(sqrt((p-a)*(p-b)*(p-c)/p) - radius) < 0.0001);
}
bool Circle::check_circle (float r, float x_cntr, float y_cntr){
    float dist = sqrt(pow(abs(x_center - x_cntr),2) + pow(abs(y_center - y_cntr),2));
    return (dist < radius + r) and (dist > abs(radius - r));
}