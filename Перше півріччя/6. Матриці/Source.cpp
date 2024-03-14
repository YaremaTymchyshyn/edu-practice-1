
// Задана дійсна квадратна матриця порядку n ( n - непарне), всі елементи якої різні.
// Серед елементів, розміщених на головній і бічній діагоналях, знайти найбільший і поміняти його місцями з елементом, розміщеним на перетині цих діагоналей.

#include <iostream>
using namespace std;

void main()
{
	int n;
	cout << "n must be an odd number" << endl;
	cout << "Input n: ";
	cin >> n;

	while (n % 2 == 0)
	{
		cout << "n must be an odd number" << endl;
		cout << "Input n: ";
		cin >> n;
	}

	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
		matrix[i] = new int[n];

	cout << "All elements of matrix must be different" << endl << endl;
	cout << "Input elements of matrix: " << endl;

	for (int i = 0; i < n; i++) // fill matrix
	{  
		for (int j = 0; j < n; j++) 
		{
			cin >> matrix[i][j];
		}
	}

	cout << endl;

	int max_num = matrix[0][0];
	int t_x = 0;
	int t_y = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				if (max_num < matrix[i][j])
				{
					max_num = matrix[i][j];
					t_x = i; t_y = j;
				}
			}
			if ((i + j) == n - 1)
			{
				if (max_num < matrix[i][j])
				{
					max_num = matrix[i][j];
					t_x = i; t_y = j;
				}
			}
		}
	}

	int temp = matrix[n/2][n/2];
	matrix[t_x][t_y] = temp;
	matrix[n / 2][n / 2] = max_num;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}