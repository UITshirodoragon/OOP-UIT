#include <iostream>

using namespace std;

class Point
{
    private:
    int x, y;

    public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int sx, int sy = 0)
    {
        x = sx;
        y = sy;
    }
    void set();
    void display();
    void move(int ax, int ay);
    int check1(Point pt)
    {
        return (x == pt.x && y == pt.y);
    }
    int check2(Point *pt)
    {
        return (x == pt->x && y == pt->y);
    }
    int check3(Point &pt)
    {
        return (x == pt.x && y == pt.y);
    }
    int check4(Point pt)
    {
        return (this -> x == pt.x && this -> y == pt.y); // point *this = &pt;
    }

};



void Point::set()
{
    cout << "Cai dat toa do: ";
    cin >> x >> y;
}

void Point::display()
{
    cout << "Toa do {" << x << ", "<< y << "}\n";

}

void Point::move(int ax, int ay)
{
    x += ax;
    y += ay;
}

class Rec
{
    private:
    int a, b, c;

    public:
    void Rset();
    void Rdisplay();
};



void Rec::Rdisplay()
{
    cout << "Do dai tam giac canh a, b, c: " << a << " " << b << " " << c << endl;
}
void Rec::Rset()
{
    cout << "Nhap 3 canh tam giac: ";
    cin >> a >> b >> c;
}

int main()
{
    Point a(1,2);
    Point b;
    Point c;

    a.display();
    

    return 0;
}