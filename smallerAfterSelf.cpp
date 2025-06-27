#include <bits/stdc++.h>
using namespace std;

void merge(vector<vector<int>> &numbers, vector<int>& res, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int inv = 0;
    vector<vector<int>> lv(n1), rv(n2);

    for (i = 0; i < n1; i++)
        lv[i] = numbers[l + i];
    for (j = 0; j < n2; j++)
        rv[j] = numbers[m + 1 + j];

    i = n1-1;
    j = n2-1;
    while(i >= 0 && j >= 0){
        if(lv[i][0] > rv[j][0]){
            res[lv[i][1]] += (j+1);
            i--;
        }
        else{
            j--;
        }
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (lv[i] <= rv[j])
        {
            numbers[k] = lv[i++];
        }
        else
        {
            numbers[k] = rv[j++];
        }
        k++;
    }

    while (i < n1)
    {
        numbers[k++] = lv[i++];
    }

    while (j < n2)
    {
        numbers[k++] = rv[j++];
    }
}

void solve(vector<vector<int>> &numbers, vector<int>& res, int l, int r)
{
    if (l < r)
    {

        int m = l + (r - l) / 2;
        solve(numbers, res, l, m);
        solve(numbers, res, m + 1, r);
        merge(numbers, res, l, m, r);
    }
}

vector<int> countSmaller(vector<int> &nums)
{
    vector<int> res(nums.size(), 0);
    vector<vector<int>> numbers(nums.size(), vector<int>(2));
    for(int i = 0; i < nums.size(); i++){
        numbers[i] = {nums[i], i};
    }
    solve(numbers, res, 0, nums.size()-1);
    return res;
}

int main()
{

    vector<int> nums = {4, 3, 5};
    vector<int> res = countSmaller(nums);

    for (auto &e : nums)
        cout << e << " ";
    cout << endl;

    for (auto &e : res)
        cout << e << " ";
    cout << endl;

    return 0;
}