#include <stdexcept>
#include <cmath>
#include "pch.h"

double cone::Cone::GetRadius() const
{
	return radius;
}

double cone::Cone::GetHeight() const
{
	return height;
}

double cone::Cone::GetSurfaceArea() const
{
	const double PI = 3.1415926535;
	double slantHeight = std::sqrt(std::pow(radius, 2) + std::pow(height, 2));
	return PI * radius * (radius + slantHeight);
}

double cone::Cone::GetVolume() const
{
	const double PI = 3.1415926535;
	return (PI * std::pow(radius, 2) * height) / 3;
}

cone::Cone::Cone(const double radius, const double height)
{
	if (radius <= 0 || height <= 0)
	{
		throw std::invalid_argument("Радиус и высота должны быть положительными числами.");
	}

	this->radius = radius;
	this->height = height;
}

std::ostream& cone::operator<<(std::ostream& output, const Cone& object)
{
	output << "Радиус основания конуса: " << object.GetRadius() << "\n";
	output << "Высота конуса: " << object.GetHeight() << "\n";
	output << "Площадь поверхности конуса: " << object.GetSurfaceArea() << "\n";
	output << "Объём конуса: " << object.GetVolume() << "\n";

	return output;
}
