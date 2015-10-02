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
		long long int B, W;
		cin >> B >> W;

		long long int X, Y, Z;
		cin >> X >> Y >> Z;

		if (X > Y + Z)
		{
			cout << B * (Y + Z) + W * Y << endl;
		}
		else if (Y > X + Z)
		{
			cout << B * X + W * (X + Z) << endl;
		}
		else
		{
			cout << B * X + W * Y << endl;
		}
	}

	return 0;
}