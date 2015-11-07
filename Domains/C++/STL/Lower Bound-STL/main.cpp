#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, Q, Y;
    vector<int> v;

    cin >> N;

    int vi;
    while(N--) {
        cin >> vi;
        v.push_back(vi);
    }

    cin >> Q;

    vector<int>::iterator it;
    while (Q--) {
        cin >> Y;
        it = lower_bound(v.begin(), v.end(), Y);

        if (*it == Y) {
            cout << "Yes ";
        }
        else {
            cout << "No ";
        }

        cout << it - v.begin() + 1 << endl;
    }

    return 0;
}
