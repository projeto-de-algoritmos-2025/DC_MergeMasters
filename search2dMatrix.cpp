#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        bool res = false;

        int sizej = matrix[0].size() - 1;
        int sizei = matrix.size() - 1;
        int i = 0, j = sizej, current;

        while (i <= sizei && j >= 0)
        {

            current = matrix[i][j];
            if (current == target)
            {
                res = true;
                break;
            }
            else if (current > target)
                j--;
            else
                i++;
        }

        return res;
    }

    int main()
    {

        int target = 5;
        vector<vector<int>> matrix = {
            {1, 4, 7, 11, 15},
            {2, 5, 8, 12, 19},
            {3, 6, 9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}};

        cout << searchMatrix(matrix, target) << endl;
        return 0;
    }
};