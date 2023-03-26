#include "cone.h"

class us_cone: public cone{
protected:
    double radius_us;
public:
    us_cone();
    us_cone(double r, double h, double r_u);
    us_cone(double a, double b, double c, double r, double h, double r_u);
    void setRadius_us(double r_u);
    double getRadius_us();
    double area();
    double volume();
    friend ostream &operator<<(ostream &stream, us_cone obj);
    friend istream &operator>>(istream &stream, us_cone& obj);
};