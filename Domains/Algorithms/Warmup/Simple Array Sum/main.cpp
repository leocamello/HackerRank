#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> arr(n);

    for (int arr_i = 0; arr_i < n; arr_i++) {
       cin >> arr[arr_i];
    }

    cout << accumulate(arr.begin(), arr.end(), 0);

    return 0;
}
