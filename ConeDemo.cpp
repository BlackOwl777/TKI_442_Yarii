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

		std::cout << "������� ������ ��������� ������: ";
		std::cin >> radius;

		std::cout << "������� ������ ������: ";
		std::cin >> height;

		Cone first(radius, height);

		std::cout << "��������� ������ ���������: " << first.GetRadius() << "\n";
		std::cout << "��������� ������: " << first.GetHeight() << "\n";
		std::cout << "������� ����������� ������: " << first.GetSurfaceArea() << "\n";
		std::cout << "����� ������: " << first.GetVolume() << "\n";

		std::cout << "\n������������ ���������� ��������� ������ � �����:\n";
		std::cout << first << "\n";

		return 0;
	}
	catch (const std::exception& error)
	{
		std::cout << "������: " << error.what() << "\n";
	}

	return -1;
}
