#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int>> &numbers, vector<int> &res, int l, int m, int r)
{
    int i, j, k;
    vector<pair<int, int>> temp(r - l + 1);

    i = l;
    j = m+1;
    k = 0;
    while (i <= m && j <= r)
    {
        if (numbers[i].first <= numbers[j].first)
        {
            temp[k] = numbers[j++];
        }
        else
        {
            res[numbers[i].second] += r - j + 1;
            temp[k] = numbers[i++];
        }
        k++;
    }

    while (i <= m)
    {
        temp[k++] = numbers[i++];
    }

    while (j <= r)
    {
        temp[k++] = numbers[j++];
    }

    for(int i = l; i <= r; i++){
        numbers[i] = temp[i-l];
    }
}

void solve(vector<pair<int, int>> &numbers, vector<int> &res, int l, int r)
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
    vector<pair<int, int>> numbers(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        numbers[i] = make_pair(nums[i], i);
    }
    solve(numbers, res, 0, nums.size() - 1);
    return res;
}

int main()
{

    vector<int> nums = {5, 2, 6, 1};
    vector<int> res = countSmaller(nums);

    for (auto &e : nums)
        cout << e << " ";
    cout << endl;

    for (auto &e : res)
        cout << e << " ";
    cout << endl;

    return 0;
}