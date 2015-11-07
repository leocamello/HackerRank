#include <vector>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int vi;
    vector<int> v;
    while(N--) {
        cin >> vi;
        v.push_back(vi);
    }

    int x;
    cin >> x;
    v.erase(v.begin() + x - 1);

    int a, b;
    cin >> a >> b;
    v.erase(v.begin() + a - 1, v.begin() + b - 1);

    cout << v.size() << endl;

    int lastElement = v.size() - 1;
    for (int i = 0; i < lastElement; i++) {
        cout << v[i] << " ";
    }

    if (lastElement >= 0) {
        cout << v[lastElement];
    }

    return 0;
}
