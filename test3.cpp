#include <iostream>
#include <cmath>
#include <iomanip>

double task(double* arr, int n)
{
	double t = 1;

	for (int i = 0; i < n; i++)
		t *= arr[i];

	t = pow(t, 1 / 3.0);

	return t;

}

double checkelem(int n)
{
	double elem;

	std::cout << "Type element: ";

	while (true)
	{
		try
		{
			if (!(std::cin >> elem))
			{
				std::cin.clear();

				while (std::cin.get() != '\n');

				throw "element is non digit!";
			}
			else
				break;
		}

		catch (const char* exception)
		{
			std::cout << exception << '\n';

			std::cout << "Type new element: ";
		}
	}
	return elem;
}


int sizechecker(int n)
{
	while (true)
	{
		try
		{
			if (!(std::cin >> n)) // проверка на букву или спец.символы
			{
				std::cin.clear();

				while (std::cin.get() != '\n');

				throw "Size is non digit!";
			}
			else
				if (n <= 0 || n > 10)
					throw "Size is out of range!";
				else
					break;

		}

		catch (const char* exception)
		{
			std::cout << exception << '\n';

			std::cout << "Type new size: ";
		}
	}
	return n;
}

int main()
{
	int n = 0;

	double t;

	std::cout << "Type size of the array: ";

	n = sizechecker(n);

	double* arr = new double[n];

	for (int i = 0; i < n; i++)
		arr[i] = checkelem(n);

	t = task(arr, n);

	std::cout << "Geometric mean: " << t;
	delete[] arr;
	return 0;
}
