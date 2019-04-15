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
    int **a = new int *[n];

    int q, k;
    cin >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> k;

        int *ai = new int[k];
        for (int j = 0; j < k; j++)
        {
            int ki;
            cin >> ki;
            ai[j] = ki;
        }

        a[i] = ai;
    }

    while (q--)
    {
        int i, j;

        cin >> i;
        cin >> j;

        cout << a[i][j] << endl;
    }

    return 0;
}