#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int vi;
    vector<int> v;
    while (N--) {
        cin >> vi;
        v.push_back(vi);
    }

    sort(v.begin(), v.end());

    int lastElement = v.size() - 1;
    for (int i = 0; i < lastElement; i++) {
        cout << v[i] << " ";
    }

    cout << v[lastElement];

    return 0;
}
