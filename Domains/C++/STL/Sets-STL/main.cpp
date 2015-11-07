#include <iostream>
#include <set>

using namespace std;

int main() {
    int Q, y, x;
    cin >> Q;

    set<int> s;

    while (Q--) {
        cin >> y >> x;

        switch (y) {
            case 1:
            s.insert(x);
            break;
            case 2:
            s.erase(x);
            break;
            case 3:
            if (s.find(x) != s.end()) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
