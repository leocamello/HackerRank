#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> a(N, 0);

	for (unsigned int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int min = 0;
	for (unsigned int i = 0; i < N; i++)
	{
		if (a[i] - min > 0)
		{
			min = a[i];

			cout << N - i << endl;
		}
	}

	return 0;
}
