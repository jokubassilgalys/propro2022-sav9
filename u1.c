
/*duomenų tipai ir funkcijos atstumui tarp dviejų taškų plokštumoje suskaičiuoti*/

#include <stdio.h>

typedef struct 
{
    double x;
    double y;
} Point;

void printPoint(Point p)
{
    printf("(%0.1lf, %0.1lf)\n", p.x, p.y);

}

Point createPoint(double x, double y)
{
    Point p;
    p.x = x;
    p.y = y;

    return p;
}

double getDistance(Point a, Point b)
{
    return sqrt(pow(b.x-a.x, 2) + pow(b.y-a.y, 2));
}

int main()
{

    double distance = getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0));

   Point p1 = createPoint(2.0, -3.0);
    Point p2 = createPoint(-4.0, 5.0);

    printPoint(p1);
    printPoint(p2);

    return 0;
}