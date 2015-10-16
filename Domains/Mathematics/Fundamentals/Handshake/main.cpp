#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		if (N > 1) {
			long long int result = (N * (N - 1)) / 2;
			cout << result << endl;
		}
		else {
			cout << 0 << endl;
		}
	}

	return 0;
}