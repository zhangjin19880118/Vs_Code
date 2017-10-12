#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define PI 3.14

class Shape
{
public:
	virtual double getPerimeter() = 0;
	virtual double getArea() = 0;
};

class Circle : public Shape
{
public:
	Circle(double radius)
	{
		this->mRadius = radius;
	}

	virtual double getPerimeter()
	{
		return 2 * PI*mRadius;
	}

	virtual double getArea()
	{
		return PI*mRadius*mRadius;
	}

private:
	double mRadius;
};

class Rectangle : public Shape
{
public:
	Rectangle(double length, double width)
	{
		mLength = length;
		mWidth = width;
	}

	virtual double getPerimeter()
	{
		return 2 * (mLength + mWidth);
	}

	virtual double getArea()
	{
		return mLength*mWidth;
	}

private:
	double mLength;
	double mWidth;
};

double getPerimeter(Shape *pShape)
{
	return pShape->getPerimeter();
}

double getArea(Shape *pShape)
{
	return pShape->getArea();
}

void getPerimeterAndArea(Shape *pShape)
{
	cout << pShape->getPerimeter() <<" , "<< pShape->getArea()<<endl;
	delete pShape;
}

int main(void)
{
	cout << "圆形周长和面积分别为:";
	getPerimeterAndArea(new Circle(5.5));

	cout << "矩形周长和面积分别为:";
	getPerimeterAndArea(new Rectangle(2.5, 3.5));

	system("pause");
	return 0;
}
