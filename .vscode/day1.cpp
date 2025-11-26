#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        if (n < 3)
            return res; // 长度不足 3，直接返回空

        sort(nums.begin(), nums.end());

        set<vector<int>> st; // 用来去重

        for (int i = 0; i < n - 2; ++i)
        {
            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0)
                {
                    ++left;
                }
                else if (sum > 0)
                {
                    --right;
                }
                else
                {
                    // 找到一个三元组，丢进 set 里去重
                    st.insert({nums[i], nums[left], nums[right]});

                    // 指针至少要动一次，防止卡住
                    ++left;
                    --right;
                }
            }
        }

        // 把 set 中的结果拷贝到 vector 里返回
        for (const auto &triplet : st)
        {
            res.push_back(triplet);
        }

        return res;
    }
};

int main()
{
    int n;
    // 输入格式：先输入 n，再输入 n 个整数
    // 例如：6 -1 0 1 2 -1 -4
    if (!(cin >> n))
    {
        return 0;
    }

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);

    // 按 [[a,b,c],[...]] 的形式输出
    cout << "[";
    for (size_t i = 0; i < ans.size(); ++i)
    {
        cout << "[";
        for (int j = 0; j < 3; ++j)
        {
            cout << ans[i][j];
            if (j < 2)
                cout << ",";
        }
        cout << "]";
        if (i + 1 < ans.size())
            cout << ",";
    }
    cout << "]" << endl;

    return 0;
}