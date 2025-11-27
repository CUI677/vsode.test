#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> sum;

        if (n < 4)
        {
            return {};
        }

        for (int i = 0; i < n; i++)
        {
            // 溢出保护：转换成 long long
            long long target2 = (long long)target - nums[i];

            // 去重：第一层循环
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < n; j++)
            {
                // 溢出保护
                long long target3 = target2 - nums[j];

                // 去重：第二层循环，注意是 j > i + 1
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while (left < right)
                {
                    // 溢出保护
                    long long currentSum = (long long)nums[left] + nums[right];

                    if (currentSum < target3)
                    {
                        left++;
                    }
                    else if (currentSum > target3)
                    {
                        right--;
                    }
                    else
                    {
                        sum.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // 去重：跳过相同的 left
                        while (right > left && nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                        // 去重：跳过相同的 right
                        while (right > left && nums[right] == nums[right + 1])
                        {
                            right--;
                        }
                    }
                }
            }
        }
        return sum;
    }
};

// 辅助函数：打印结果
void printResult(const vector<vector<int>> &result)
{
    cout << "[";
    for (size_t i = 0; i < result.size(); ++i)
    {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j];
            if (j < result[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1)
            cout << ",";
    }
    cout << "]" << endl;
}

int main()
{
    Solution sol;

    // 示例 1
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    cout << "示例 1 输入: nums = [1,0,-1,0,-2,2], target = 0" << endl;
    vector<vector<int>> res1 = sol.fourSum(nums1, target1);
    cout << "输出: ";
    printResult(res1);
    cout << endl;

    // 示例 2
    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;
    cout << "示例 2 输入: nums = [2,2,2,2,2], target = 8" << endl;
    vector<vector<int>> res2 = sol.fourSum(nums2, target2);
    cout << "输出: ";
    printResult(res2);
    cout << endl;

    // 溢出测试用例
    vector<int> nums3 = {1000000000, 1000000000, 1000000000, 1000000000};
    int target3 = -294967296;
    cout << "溢出测试 输入: nums = [1000000000,1000000000,1000000000,1000000000], target = -294967296" << endl;
    vector<vector<int>> res3 = sol.fourSum(nums3, target3);
    cout << "输出: ";
    printResult(res3); // 预期输出 [] 因为和太大

    return 0;
}