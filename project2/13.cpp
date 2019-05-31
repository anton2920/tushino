#include <iostream>

struct Matrix
{
	double matrix[100][100];
	int M;
};

void read(Matrix& a)
{
	do
	{
		std::cout << "Enter M: ";
		std::cin >> a.M;
		if (std::cin)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}

	} while (a.M <= 0 || a.M > 100);

	std::cout << "Enter the matrix: \n";
	for (int i = 0; i < a.M; ++i)
	{
		for (int j = 0; j < a.M; ++j)
		{
			std::cin >> a.matrix[i][j];
		}
	}
}
void result(Matrix& a)
{
	std::cout << "\n\n";
	for (int i = 0; i < a.M; ++i)
	{
		for (int j = 0; j < a.M; ++j)
		{
			std::cout << a.matrix[a.M - j - 1][i] << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	Matrix matrix;

	read(matrix);
	result(matrix);

	return 0;
}
