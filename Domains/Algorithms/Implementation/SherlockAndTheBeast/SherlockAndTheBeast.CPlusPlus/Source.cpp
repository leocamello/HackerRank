#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print(int N, int t) {
	for (int i = 0; i < t; i++) {
		cout << N;
	}
}

void findTheKey(int N) {
	int div = N / 3;

	while (div >= 0) {
		int mod = N - (div * 3);

		if (mod == 0 || mod % 5 == 0) {
			print(5, div * 3);
			print(3, mod);
			cout << endl;
			return;
		}

		div--;
	}

	cout << -1 << endl;
}


int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		findTheKey(N);
	}

	return 0;
}
