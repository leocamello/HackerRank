#include <iostream>

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if (1 <= i && i <= 9) {
            if (i == 1) {
                cout << "one";
            }
            else if (i == 2) {
                cout << "two";
            }
            else if (i == 3) {
                cout << "three";
            }
            else if (i == 4) {
                cout << "four";
            }
            else if (i == 5) {
                cout << "five";
            }
            else if (i == 6) {
                cout << "six";
            }
            else if (i == 7) {
                cout << "seven";
            }
            else if (i == 8) {
                cout << "eight";
            }
            else if (i == 9) {
                cout << "nine";
            }
        }
        else if (i > 9) {
            if (i % 2 == 0) {
                cout << "even";
            }
            else {
                cout << "odd";
            }
        }

        cout << "\n";
    }

    return 0;
}
