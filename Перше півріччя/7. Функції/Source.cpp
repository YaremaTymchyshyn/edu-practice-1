
// Описати функцію, яка впорядковує стрічки цілоисельної прямокутної матриці
// по зростанню кількості однакових елементів у кожній стрічці.
// Дано дві прямокутні матриці різної розмірності.
//Впорядкувати їх стрічки.

#include <iostream>
using namespace std;

void printArr(int** arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}



int function(int** arr, int n, int m)
{
    int* count = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (arr[i][j] != arr[i][k] || j == k)
                    continue;
                if (count[i] < 0)
                    count[i] = 0;
                if (count[i] == 0 || count[i] > 0)
                    count[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++) {
            if (count[i] < count[j]) {
                for (int k = 0; k < m; k++) {
                    arr[i][k] += arr[j][k];
                    arr[j][k] = arr[i][k] - arr[j][k];
                    arr[i][k] -= arr[j][k];
                }
            }
        }
    }
    printArr(arr, n, m);
    return 1;
}



int main()
{
    int n, m;
    cout << "Enter dimension of the first array:\n";
    cin >> n >> m;
    int** arr = new int* [n];
    for (int i = 0; i < n; ++i)
        arr[i] = new int[m];

    cout << "\nInput elements of the first array:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int l, f;
    cout << "\nEnter dimension of the second array:\n";
    cin >> l >> f;
    int** err = new int* [l];
    for (int i = 0; i < l; ++i)
        err[i] = new int[f];

    cout << "\nInput elements of the second array:\n";

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < f; j++)
        {
            cin >> err[i][j];
        }
    }

    cout << "\n";
    cout << "Matrix 1:\n\n";
    printArr(arr, n, m);
    cout << "\n";
    cout << "Matrix 2:\n\n";
    printArr(err, l, f);
    cout << "\n\n\n";
    cout << "Matrix 1 sorted:\n\n";
    function(arr, n, m);
    cout << "\n";
    cout << "Matrix 2 sorted:\n\n";
    function(err, l, f);
    return 0;
}