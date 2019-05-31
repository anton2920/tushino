#include <iostream>

struct Matrix
{
	double matrix[100][100];
	int row;
	int column;
};

void read(Matrix& a)
{
	do
	{
		std::cout << "Enter M: ";
		std::cin >> a.row;
		if (std::cin)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}

	} while (a.row <= 0 || a.row > 100);

	do
	{
		std::cout << "Enter N: ";
		std::cin >> a.column;
		if (std::cin)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}

	} while (a.column <= 0 || a.column > 100);


	std::Cout << "Enter the matrix: \n";
	for (int i = 0; i < a.row; ++i)
	{
		for (int j = 0; j < a.column; ++j)
		{
			std::cin >> a.matrix[i][j];
		}
	}
}

void result(Matrix& a)
{
	std::cout << "\n\n";

	// Предполагается, что нумерация начиется с нуля.
	for (int i = 0; i < a.row; i += 2)
	{
		for (int j = 0; j < a.column; ++j)
		{
			std::cout << a.matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int main(void)
{
	Matrix matrix;
	read(matrix);
	result(matrix);

	return 0;
}
