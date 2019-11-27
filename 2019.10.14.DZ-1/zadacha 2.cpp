/* Напишите функцию вычисляющую праймориал числа. Программа должна работать не более чем за O(n*log log n) шагов.
*/
#include <iostream>
#include <vector>

using namespace std;

void plndrm(int n, int m, vector<int>& A)
{
	if (n % 2 == 0)
	{
		if (m >= n / 2)
		{
			return;
		}
		if (m == n / 2 - 1)
		{
			for (int j = 0; j < 10; ++j)
			{
				A[m] = j;
				A[m + 1] = j;
				for (int g = 0; g < n; ++g)
				{
					cout << A[g];
				}
				cout << endl;
			}
		}
		else
		{
			for (int j = 0; j < 10; ++j)
			{
				A[m] = j;
				A[n - m - 1] = j;
				plndrm(n, m + 1, A);
			}
		}
	}
	else
	{
		if (m > n / 2)
		{
			return;
		}
		if (m == n / 2)
		{
			for (int j = 0; j < 10; ++j)
			{
				A[m] = j;
				for (int g = 0; g < n; ++g)
				{
					cout << A[g];
				}
				cout << endl;
			}
		}
		else
		{
			for (int j = 0; j < 10; ++j)
			{
				A[m] = j;
				A[n - m - 1] = j;
				plndrm(n, m + 1, A);
			}
		}
	}
}


int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 1; i < 10; ++i)
	{
		A[0] = i;
		A[n - 1] = i;
		plndrm(n, 1, A);
	}
}
/*
Перебор эффективен, потому что при каждом шаге рекурсии ищется новый палиндром.
*/