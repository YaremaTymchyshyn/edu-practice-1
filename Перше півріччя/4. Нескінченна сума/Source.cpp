
// Обчислити для заданого x з точністю е > 0 суму

#include <iostream>
using namespace std;

void main()
{
	int n = 0;
	float eps, x, sum = 1, a=1.0;

	cout << "Input x: ";
	cin >> x;
	cout << "Input e: ";
	cin >> eps;

	while (abs(a) > eps)
	{
		n++;
		a *= (-1.0) * pow(x, 2) / (2 * n * (2 * n + 1));
		sum += a;
	} 
	cout << "Sum = " << sum;
}