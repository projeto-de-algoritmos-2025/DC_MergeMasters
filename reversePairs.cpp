#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int inv = 0;
    vector<int> lv(n1), rv(n2);

    for (i = 0; i < n1; i++)
        lv[i] = nums[l + i];
    for (j = 0; j < n2; j++)
        rv[j] = nums[m + 1 + j];

    i = 0;
    j = 0;
    while (i < n1 && j < n2)
    {
        if (lv[i] > (long)2 * rv[j])
        {
            inv += (n1 - i);
            j++;
        }
        else
            i++;
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (lv[i] <= rv[j])
        {
            nums[k] = lv[i++];
        }
        else
        {
            nums[k] = rv[j++];
        }
        k++;
    }

    while (i < n1)
    {
        nums[k++] = lv[i++];
    }

    while (j < n2)
    {
        nums[k++] = rv[j++];
    }

    return inv;
}

int solve(vector<int> &nums, int l, int r)
{

    int m, inv = 0;
    if (l < r)
    {

        m = l + (r - l) / 2;
        inv += solve(nums, l, m);
        inv += solve(nums, m + 1, r);
        inv += merge(nums, l, m, r);
    }

    return inv;
}

int reversePairs(vector<int> &nums)
{

    return solve(nums, 0, nums.size() - 1);
}

int main()
{

    vector<int> nums = {2, 4, 3, 5, 1};
    int res = reversePairs(nums);

    cout << "Result: " << res << endl;

    return 0;
}