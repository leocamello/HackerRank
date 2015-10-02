#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, K;
		cin >> N >> K;

		int a, count = 0;

		while (N--)
		{
			cin >> a;

			if (a <= 0)
			{
				count++;
			}
		}

		if (count < K)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}