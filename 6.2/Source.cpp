#include <iostream>
using namespace std;
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

void Create(int* a, int size)
{
	for (int i = 0; i < size; i++)
		a[i] = rand();
}
void Print(int* a, int size)
{
	for (int i = 0; i < size; i++)
		cout << a[i] << "   ";
	cout << endl;
}

void Sum(int* a, int size, int max, int min, int*s) {
	int num = a[size-2];
	if (size > 1)
	{
		if (num > max)
		{
			max = num;
		}
		if (num < min)
		{
			min = num;
		}
		*s = (min + max) / 2;
		Sum(a, size - 1, max, min, s);
	}
	return;
}


int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	int n;
	cout << "n=";cin >> n;
	int* a;
	int s;
	a = new int[n];

	Create(a, n);
	Print(a, n);
	Sum(a, n, a[n - 1], a[n - 1], &s);
	cout << "sum="<<s;
	delete[]a;
	return 0;

}
