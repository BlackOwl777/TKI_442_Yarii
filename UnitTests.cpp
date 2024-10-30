#include "pch.h"
#include "CppUnitTest.h"

#include "../Cone/pch.h"
#include "../Cone/pch.h"

#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(ConeTests)
	{
	public:

		TEST_METHOD(Constructor_NegativeRadiusOrHeight_ExpectedException)
		{
			// Assert: проверка исключения при отрицательном радиусе или высоте
			Assert::ExpectException<std::invalid_argument>([]() { cone::Cone obj(-5.6, 5.0); });
			Assert::ExpectException<std::invalid_argument>([]() { cone::Cone obj(5.6, -5.0); });
		}


		TEST_METHOD(GetRadius_ValidData_Success)
		{
			// Arrange
			const double Radius = 5.6;
			const double Height = 5.0;
			cone::Cone obj{ Radius, Height };
			const double expected = Radius;
			const double epsilon = 0.001;

			// Act
			const double actual = obj.GetRadius();

			// Assert
			Assert::IsTrue(std::abs(expected - actual) <= epsilon);
		}

		TEST_METHOD(GetHeight_ValidData_Success)
		{
			// Arrange
			const double Radius = 5.6;
			const double Height = 5.0;
			cone::Cone obj{ Radius, Height };
			const double expected = Height;
			const double epsilon = 0.001;

			// Act
			const double actual = obj.GetHeight();

			// Assert
			Assert::IsTrue(std::abs(expected - actual) <= epsilon);
		}

		TEST_METHOD(GetSurfaceArea_ValidData_Success)
		{
			// Arrange
			const double Radius = 5.6;
			const double Height = 5.0;
			cone::Cone obj{ Radius, Height };
			const double PI = 3.1415926535;
			const double slantHeight = std::sqrt(Radius * Radius + Height * Height);
			const double expected = PI * Radius * (Radius + slantHeight);
			const double epsilon = 0.1;

			// Act
			const double actual = obj.GetSurfaceArea();

			// Assert
			Assert::IsTrue(std::abs(expected - actual) <= epsilon);
		}

		TEST_METHOD(GetVolume_ValidData_Success)
		{
			// Arrange
			const double Radius = 5.6;
			const double Height = 5.0;
			cone::Cone obj{ Radius, Height };
			const double PI = 3.1415926535;
			const double expected = (PI * Radius * Radius * Height) / 3;
			const double epsilon = 0.1;

			// Act
			const double actual = obj.GetVolume();

			// Assert
			Assert::IsTrue(std::abs(expected - actual) <= epsilon);
		}

		TEST_METHOD(OperatorLeftShift_ValidData_Success)
		{
			// Arrange
			const double Radius = 5.6;
			const double Height = 5.0;
			cone::Cone obj{ Radius, Height };
			const double PI = 3.1415926535;
			const double slantHeight = std::sqrt(Radius * Radius + Height * Height);
			const double surfaceArea = PI * Radius * (Radius + slantHeight);
			const double volume = (PI * Radius * Radius * Height) / 3;

			std::stringstream buffer;
			buffer << std::fixed << std::setprecision(2);
			buffer << "Радиус основания конуса: " << obj.GetRadius() << "\n"
				<< "Высота конуса: " << obj.GetHeight() << "\n"
				<< "Площадь поверхности конуса: " << surfaceArea << "\n"
				<< "Объём конуса: " << volume << "\n";
			const std::string expected = buffer.str();

			// Act
			std::stringstream actualBuffer;
			actualBuffer << std::fixed << std::setprecision(2) << obj;
			std::string actual = actualBuffer.str();

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};
}
