#pragma once
#include <iostream>
#include <cmath>

namespace cone
{
	/**
	* @brief Класс Конус
	*/
	class Cone
	{
	private:
		/**
		* @brief Радиус основания
		*/
		double radius;

		/**
		* @brief Высота конуса
		*/
		double height;

	public:
		/*
		* @brief Вернуть радиус основания
		* @return Радиус
		*/
		double GetRadius() const;

		/*
		* @brief Вернуть высоту конуса
		* @return Высота
		*/
		double GetHeight() const;

		/*
		* @brief Рассчитать площадь поверхности конуса
		* @return Площадь поверхности
		*/
		double GetSurfaceArea() const;

		/*
		* @brief Рассчитать объём конуса
		* @return Объём
		*/
		double GetVolume() const;

		/*
		* @brief Инициализирует новый объект класса Cone
		* @param radius Радиус основания
		* @param height Высота конуса
		*/
		explicit Cone(const double radius, const double height);
	};

	/*
	* @brief Выводит в поток информацию о конусе
	* @param output Поток вывода
	* @param object Конус
	*/
	std::ostream& operator<<(std::ostream& output, const Cone& object);
}
