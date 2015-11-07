#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int Q;
    string X;
    int type, Y;

    map<string, int> m;
    map<string, int>::iterator it;

    cin >> Q;

    while (Q--) {
        cin >> type >> X;
        it = m.find(X);
        switch (type) {
            case 1:
            cin >> Y;
            if (it != m.end()) {
                m[X] += Y;
            }
            else {
                m.insert(make_pair(X, Y));
            }
            break;
            case 2:
            if (it != m.end()) {
                m.erase(it);
            }
            break;
            case 3:
            if (it != m.end()) {
                cout << it->second << endl;
            }
            else {
                cout << 0 << endl;
            }
            break;
        }
    }

    return 0;
}
