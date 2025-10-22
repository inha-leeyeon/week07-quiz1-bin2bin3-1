#include <iostream>
#include "Point.h"
#include "Square.h"
#include <vector>

using namespace std;

Square::Square(const std::string n, int _x, int _y, unsigned int s)
{
	setName(n);
	setX(_x);
	setY(_y);
	setSide(s);
	setArea(s);
}

unsigned int Square::getSide() const
{
	return side;
}

unsigned int Square::getArea() const
{
	return area;
}

std::string Square::getName() const
{
	return name;
}

void Square::setSide(unsigned int s)
{
	side = s;
}

void Square::setArea(unsigned int s)
{
	area = s * s;
}

void Square::setName(std::string n)
{
	name = n;
}

Point::Point(int px, int py)
{
	setX(px);
	setY(py);
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::setX(int _x)
{
	x = _x;
}

void Point::setY(int _y)
{
	y = _y;
}


void swapSquare(Square& a, Square& b)
{
	Square tmp = a;
	a = b;
	b = tmp;
}

void sortByarea(vector<Square>& v)
{
	int n = v.size();

	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0;j < n - 1 - i;j++)
		{
			if (v[j].getArea() > v[j + 1].getArea())
			{
				swapSquare(v[j], v[j + 1]);
			}
		}
	}
}

void sortByMaxX(vector<Square>& v)
{
	int n = v.size();
	for (int i = 0;i < n-1;i++)
	{
		for (int j = 0;j < n - 1 - i;j++)
		{
			int maxX1 = v[j].getX() + v[j].getSide();
			int maxX2 = v[j + 1].getX() + v[j + 1].getSide();
			if (maxX1 > maxX2) {
				swapSquare(v[j], v[j + 1]);
			}
		}
	}
}

void sortByMaxY(vector<Square>& v)
{
	int n = v.size();
	for (int i = 0;i < n - 1;i++)
	{
		for (int j = 0;j < n - 1 - i;j++)
		{
			int maxY1 = v[j].getY() + v[j].getSide();
			int maxY2 = v[j + 1].getY() + v[j + 1].getSide();
			if(maxY1 > maxY2) {
				swapSquare(v[j], v[j + 1]);
			}
		}
	}
}

int main()
{
	int num = 0;
	cin >> num;
	vector<Square> squares;
	for (int i = 0;i < num;i++)
	{
		string name;
		int px = 0, py = 0;
		unsigned int pside = 0;
		cin >> name >> px >> py >> pside;
		Square s(name, px, py, pside);
		squares.push_back(s);
	}

	cout << "\nSquares in increasing order of area" << endl;
	sortByarea(squares);
	for (int i = 0; i < num; i++) {
		cout << squares[i].getName() << "(" << squares[i].getX() << ", " << squares[i].getY()
			<< ") side=" << squares[i].getSide() << ", area=" << squares[i].getArea() << endl;
	}

	cout << "\nSquares in increasing order of max x-coordinate" << endl;
	sortByMaxX(squares);
	for (int i = 0; i < num; i++) {
		int maxX1 = squares[i].getX() + squares[i].getSide();
		cout << squares[i].getName() << "(" << maxX1 << ", " << squares[i].getY()
			<< ") side=" << squares[i].getSide() << ", area=" << squares[i].getArea() << endl;
	}

	cout << "\nSquares in increasing order of max y-coordinate" << endl;
	sortByMaxY(squares);
	for (int i = 0; i < num; i++) {
		int maxY1 = squares[i].getY() + squares[i].getSide();
		cout << squares[i].getName() << "(" << squares[i].getX() << ", " << maxY1
			<< ") side=" << squares[i].getSide() << ", area=" << squares[i].getArea() << endl;
	}

	return 0;
}