
// ������ ����� a ����� ����� ��������� n.
// �� ��'��� �������� ������ �������� � ����� � ���������� �������, � ���� �������� ��� ���.

#include <iostream>
using namespace std;

void main()
{
	int n;
	cout << "Input n: ";
	cin >> n;
	int* arr = new int(n);
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] < 0 && arr[j] < 0)
			{
				swap(arr[i], arr[j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}