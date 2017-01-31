#ifndef ___Class_Color
#define ___Class_Color

#include <iostream>

class Color {
private:
	float r, g, b;

public:
	Color();
	Color(float r, float g, float b);
	~Color();

	void operator=(const Color& color);

	float getR(void) const;
	float getG(void) const;
	float getB(void) const;
	void setR(float r);
	void setG(float g);
	void setB(float b);
	void setRGB(float r, float g, float b);
	void print(void) const;
	void print(int x, int y) const;
};

inline void Color::operator=(const Color& color)
{
	r = color.r;
	g = color.g;
	b = color.b;
}

inline float Color::getR(void) const
{
	return r;
}

inline float Color::getG(void) const
{
	return g;
}

inline float Color::getB(void) const
{
	return b;
}

inline void Color::setR(float r)
{
	this->r = r;
}

inline void Color::setG(float g)
{
	this->g = g;
}

inline void Color::setB(float b)
{
	this->b = b;
}

inline void Color::setRGB(float r, float g, float b)
{
	this->r = r;
	this->g = g;
	this->b = b;
}

#endif

