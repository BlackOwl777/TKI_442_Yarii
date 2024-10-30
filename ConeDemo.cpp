#include <iostream>
#include <clocale>
#include "pch.h"

#include "../Cone/pch.h"

int main()
{
	setlocale(LC_ALL, "RUS");

	using namespace cone;

	try
	{
		double radius, height;

		std::cout << "Введите радиус основания конуса: ";
		std::cin >> radius;

		std::cout << "Введите высоту конуса: ";
		std::cin >> height;

		Cone first(radius, height);

		std::cout << "Введенный радиус основания: " << first.GetRadius() << "\n";
		std::cout << "Введенная высота: " << first.GetHeight() << "\n";
		std::cout << "Площадь поверхности конуса: " << first.GetSurfaceArea() << "\n";
		std::cout << "Объем конуса: " << first.GetVolume() << "\n";

		std::cout << "\nДемонстрация перегрузки оператора вывода в поток:\n";
		std::cout << first << "\n";

		return 0;
	}
	catch (const std::exception& error)
	{
		std::cout << "ОШИБКА: " << error.what() << "\n";
	}

	return -1;
}
