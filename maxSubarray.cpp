#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int l, int r)
{

    if (l == r)
        return nums[l];

    int m = l + (r - l) / 2;
    int esq = solve(nums, l, m);
    int dir = solve(nums, m + 1, r);
    int merged, esq_max_sum = INT_MIN, dir_max_sum = INT_MIN;

    merged = 0;
    for (int i = m; i >= l; i--)
    {
        merged += nums[i];
        if (merged > esq_max_sum)
            esq_max_sum = merged;
    }

    merged = 0;
    for (int i = m + 1; i <= r; i++)
    {
        merged += nums[i];
        if (merged > dir_max_sum)
            dir_max_sum = merged;
    }

    merged = dir_max_sum + esq_max_sum;

    if (esq >= dir && esq >= merged)
        return esq;
    else if (dir >= esq && dir >= merged)
        return dir;
    else
        return merged;
}

int maxSubArray(vector<int> &nums)
{

    int res = solve(nums, 0, nums.size() - 1);
    return res;
}

int main()
{
    vector<int> nums = {-1,-1,-2,-2};
    int res = maxSubArray(nums);

    cout << "Result: " << res << endl;

    return 0;
}