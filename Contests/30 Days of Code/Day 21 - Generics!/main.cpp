#include <iostream>
#include <vector>

using namespace std;

template <typename Type>
void printArray(vector<Type> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

int main()
{
    vector<int> vInt{1, 2, 3};
    vector<string> vString{"Hello", "World"};

    printArray<int>(vInt);
    printArray<string>(vString);

    return 0;
}
