#include<string>
#include<iostream>
#include <stack>
using namespace std;

template<typename T>

class Steak
{
    T* arr;
    int size;
    unsigned amount;
public:
    Steak(int s, int q)
    {
        size = s;
        amount = q;
        arr = new T[size];
    }

    ~Steak()
    {
        delete[]arr;
    }

    void push(T valur)
    {
        if (size == amount)
        {
            T* tempArr = new T[size];
            for (size_t i = 0; i < size; i++)
            {
                tempArr[i] = arr[i];
            }
            size += 10;
            arr = new T[size];
            for (size_t i = 0; i < amount; i++)
            {
                arr[i] = tempArr[i];
            }
            delete[] tempArr;
        }
        arr[amount] = valur;
        amount++;
    }

    void pop()
    {
        if (amount == 0)
        {
            cout << "amount = 0";
            return;
        }
        else if (size - amount == 15)
        {
            T* tempArr = new T[amount];
            for (size_t i = 0; i < amount; i++)
            {
                tempArr[i] = arr[i];
            }
            size -= 10;
            arr = new T[size];
            for (size_t i = 0; i < amount; i++)
            {
                arr[i] = tempArr[i];
            }
            delete[] tempArr;
        }
        amount--;
        return;
    }

    T top()
    {
        if (amount == 0)
        {
            cout << "amount = 0";
            return NULL;
        }
        return arr[amount - 1];
    }

    bool isEmpty()
    {
        return amount == 0;
    }

    unsigned getAmount()
    {
        return amount;
    }

    int getSize()
    {
        return size;
    }

};


int main()
{
    cout << "Input your word: ";
    string input;
    cin >> input;

    Steak<char> char_steak(10, input.length());
    for (int i = 0; i < input.size(); i++)
    {
        char_steak.push(input[i]);
    }

    string output = "";
    for (int i = 0; i < char_steak.getAmount(); i++)
    {
        output += char_steak.top();
        char_steak.pop();
    }
    cout << "Your inversed word: " << output << endl;

    cout << endl;

    cout << "input array size: ";
    int n;
    cin >> n;
    cout << "Enter elements of the array: ";
    int* arr = new  int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Steak<int> int_steak(n, n);
    for (int i = 0; i < n; i++)
    {
        int_steak.push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = int_steak.top();
        int_steak.pop();
    }
    cout << "Your inversed array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}