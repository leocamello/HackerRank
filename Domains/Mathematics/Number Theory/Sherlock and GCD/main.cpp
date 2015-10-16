#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int GDC(int a, int b) {
	int c = max(a, b) % min(a, b);

	if (c == 0)
		return min(a, b);
	else
		return GDC(min(a, b), c);
}

bool checkVector(const vector<int>& v) {
	if (v.size() == 1)
		return false;

	int next = v[0];
	for (int i = 1; i < v.size(); i++) {
		next = GDC(next, v[i]);

		if (next == 1)
			return true;
	}

	return false;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<int> v(N);
		bool numberOneExists = false;
		for (int i = 0; i < N; i++) {
			cin >> v[i];
			if (v[i] == 1) {
				numberOneExists = true;
			}
		}

		if (numberOneExists) {
			cout << "YES" << endl;
		}
		else {
			if (checkVector(v))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}
