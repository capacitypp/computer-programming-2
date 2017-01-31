#include "Color.h"

using namespace std;

Color::Color()
	: r(0.0F), g(0.0F), b(0.0F)
{

}

Color::Color(float r, float g, float b)
	: r(r), g(g), b(b)
{

}

Color::~Color()
{

}

void Color::print(void) const
{
	cout << "(r,g,b) = (" << r << "," << g << "," << b << ")" << endl;
}

void Color::print(int x, int y) const
{
	cout << "[" << x << "," << y << "]: (r,g,b) = (" << r << "," << g << "," << b << ")" << endl;
}

