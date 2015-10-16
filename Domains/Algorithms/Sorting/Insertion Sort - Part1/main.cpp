#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

void printVector(vector <int> ar)
{
	for (unsigned int i = 0; i < ar.size(); i++)
		cout << ar.at(i) << " ";

	cout << endl;
	return;
}

void insertionSort(vector <int>  ar)
{
	size_t size = ar.size();

	if (size == 0)
		return;

	if (size == 1)
	{
		cout << ar.at(0);
		return;
	}

	int n = ar.at(size - 1);
	for (size_t i = size - 1; i > 0; i--)
	{
		int c = ar.at(i - 1);

		if (c > n)
		{
			ar[i] = c;
			printVector(ar);
		}
		else
		{
			ar[i] = n;
			printVector(ar);
			return;
		}
	}

	ar[0] = n;
	printVector(ar);
}

/* Tail starts here */
int main(void)
{
	vector <int>  _ar;
	int _ar_size;
	cin >> _ar_size;
	for (int _ar_i = 0; _ar_i < _ar_size; _ar_i++)
	{
		int _ar_tmp;
		cin >> _ar_tmp;
		_ar.push_back(_ar_tmp);
	}

	insertionSort(_ar);

	return 0;
}