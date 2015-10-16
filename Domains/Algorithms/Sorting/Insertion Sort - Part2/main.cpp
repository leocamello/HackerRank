#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

void printArray(int ar_size, int *ar)
{
	for (size_t i = 0; i < ar_size; i++)
	{
		cout << ar[i] << " ";
	}

	cout << endl;
}

/* Head ends here */
void insertionSort(int ar_size, int *ar)
{
	if (ar_size <= 0)
		return;

	if (ar_size == 1)
	{
		printArray(ar_size, ar);
		return;
	}

	for (int i = 1; i < ar_size; i++)
	{
		int j = i;
		for (int k = j; k >= 0; k--)
		{
			if (ar[j] < ar[k])
			{
				int tmp = ar[j];
				ar[j] = ar[k];
				ar[k] = tmp;

				j = k;
			}
		}

		printArray(ar_size, ar);
	}
}

/* Tail starts here */
int main(void)
{
	int _ar_size;
	cin >> _ar_size;
	//scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for (_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
		cin >> _ar[_ar_i];
		//scanf("%d", &_ar[_ar_i]); 
	}

	insertionSort(_ar_size, _ar);

	return 0;
}