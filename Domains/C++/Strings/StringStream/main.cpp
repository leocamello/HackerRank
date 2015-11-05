#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);

    int a; char c;
    vector<int> res;
    while (!ss.eof()) {
        ss >> a >> c;
        res.push_back(a);
    }

    return res;
}

int main() {
    string str;
    cin >> str;

    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
