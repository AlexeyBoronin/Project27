#include <iostream>
using namespace std;
class Shape
{
	int x;
	int y;
public: 
	Shape(int x, int y) : x{x},y{y}
	{}
	virtual double getSquare() const = 0;
	virtual double getPerimeter() const = 0;
	void printCoords()const
	{
		cout << "X: " << x << "\tY: " << y << endl;
	}
};
class Rectangle :public Shape
{
	double width;
	double height;
public:
	Rectangle(int x, int y,double w, double h):width(w),height(h),Shape{x,y}
	{}
	double getSquare() const override
	{
		return width * height;
	}
	double getPerimeter()const override
	{
		return width * 2 + height * 2;
	}
};
class Circle :public Shape
{
	double radius;
public:
	Circle(int x, int y, double r): radius(r),Shape{x,y}
	{}
	double getSquare() const override
	{
		return radius * radius * 3.14;
	}
	double getPerimeter() const override
	{
		return 2 * 3.14 * radius;
	}
};

int main()
{
	Rectangle rect{0,0, 20,60 };
	Circle circle{20,30, 25 };
	rect.printCoords();
	cout << "Rectangle square: " << rect.getSquare() << endl;
	cout << "Rectangle perimeter: " << rect.getPerimeter() << endl;
	circle.printCoords();
	cout << "Circle square: " << circle.getSquare() << endl;
	cout << "Circle perimeter: " << circle.getPerimeter() << endl;

	return 0;
}