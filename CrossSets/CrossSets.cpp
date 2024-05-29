#include <iostream>
#include <set>
#include "CrossSet.h"

using namespace std;

// Функция для вычисления суммы цифр числа
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Функция для заполнения множества чисел от 1 до N, делящихся без остатка на сумму своих цифр
set<int> fillSet(int N) {
    std::set<int> resultSet;
    for (int i = 1; i <= N; ++i) {
        int sumDigits = sumOfDigits(i);
        if (i % sumDigits == 0) {
            resultSet.insert(i);
        }
    }
    return resultSet;
}

set<int> fillSetWithEvenDigitSum(int N) {
    std::set<int> resultSet;
    for (int i = 1; i <= N; ++i) {
        int sumDigits = sumOfDigits(i);
        if (sumDigits % 2 == 0) {
            resultSet.insert(i);
        }
    }
    return resultSet;
}

int main()
{
	set<int> set1;
	set<int> set2;
    set<int> set3;

    int N = 0;
    cout << "Input N: ";
	try
	{
		cin >> N;
	}
	catch (...)
	{
		cout << "Error";
		return 1;
	}
    
    set1 = fillSet(N);
    set2 = fillSetWithEvenDigitSum(N);

    set3 = CrossSet(set1, set2);

    for (int i : set1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : set2)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : set3)
    {
        cout << i << " ";
    }


    return 0;
}

