#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	// matrix creation
	char **square_map = new char*[n];

	for (unsigned int i = 0; i < n; i++)
	{
		square_map[i] = new char[n];
	}

	for (unsigned int row = 0; row < n; row++)
	{
		string entire_row;
		cin >> entire_row;
		for (unsigned int column = 0; column < n; column++)
		{
			square_map[column][row] = entire_row[column];
		}
	}

	for (unsigned int r = 1; r < n - 1; r++)
	{
		for (unsigned int c = 1; c < n - 1; c++)
		{
			if (square_map[c][r] > square_map[c - 1][r]
				&& square_map[c][r] > square_map[c + 1][r]
				&& square_map[c][r] > square_map[c][r - 1]
				&& square_map[c][r] > square_map[c][r + 1])
			{
				square_map[c][r] = 'X';
			}
		}
	}

	for (unsigned int row = 0; row < n; row++)
	{
		for (unsigned int column = 0; column < n; column++)
		{
			cout << square_map[column][row];
		}

		cout << endl;
	}

	// matrix deletion
	for (unsigned int i = 0; i < n; i++)
	{
		delete[] square_map[i];
	}

	delete[] square_map;

	return 0;
}