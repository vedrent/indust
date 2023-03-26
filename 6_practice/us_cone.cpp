#include "us_cone.h"
#include "cmath"
using namespace std;
const double pi = 3.14159265;

us_cone::us_cone(){radius_us = 0;}
us_cone::us_cone(double r, double h, double r_u):cone(r, h) {
    radius_us = r_u;
}
us_cone::us_cone(double a, double b, double c, double r, double h, double r_u):cone(a, b, c, r, h) {
    radius_us = r_u;
}

void us_cone::setRadius_us(double r_u){
    radius_us = r_u;
}

double us_cone::getRadius_us(){
    return radius_us;
}

double us_cone::area() {
    double l = sqrt(height*height + (radius-radius_us)*(radius-radius_us));
    return pi*(radius*radius + radius_us*radius_us + (radius_us + radius)*l);
}

double us_cone::volume() {
    return pi*height*(radius*radius + radius_us*radius + radius_us*radius_us)/3;
}