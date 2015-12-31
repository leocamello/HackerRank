#include <vector>
#include <iostream>

using namespace std;

int largestHourglassesSum(const vector<vector<int>> &array)
{
    int largestSum = -100;
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            int sum = 0;
            
            sum += array[i + 0][j + 0];
            sum += array[i + 0][j + 1];
            sum += array[i + 0][j + 2];
            sum += array[i + 1][j + 1];
            sum += array[i + 2][j + 0];
            sum += array[i + 2][j + 1];
            sum += array[i + 2][j + 2];
            
            largestSum = max(largestSum, sum);
        }
    }
    
    return largestSum;
}

int main()
{
    vector<vector<int>> array(6, vector<int>(6));
    
    for(int i = 0; i < 6; i++)
    {
       for(int j = 0; j < 6; j++)
       {
          cin >> array[i][j];
       }
    }
    
    cout << largestHourglassesSum(array) << endl;
    
    return 0;
}
