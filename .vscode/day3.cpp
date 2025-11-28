#include <iostream>
#include <vector>
#include <algorithm> // 用于 min 函数
#include <climits>   // 用于 INT_MAX

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        // 初始化为一个最大整数，用来找最小值
        int len = INT_MAX;

        // 外层循环：right 主动向右走，扩大窗口
        for (int right = 0; right < n; right++)
        {
            sum += nums[right]; // 进窗口

            // 内层循环：当满足条件时，尝试缩小窗口 (left 向右走)
            while (sum >= target)
            {
                // 更新最小长度 (注意这里是 right - left + 1)
                len = min(len, right - left + 1);

                // 出窗口：减去左边的值，并右移左指针
                sum -= nums[left];
                left++;
            }
        }

        // 如果 len 还是初始值，说明从未找到过满足条件的子数组，返回 0
        return (len == INT_MAX) ? 0 : len;
    }
};

// 这是一个辅助函数，用来打印测试结果，方便观看
void runTestCase(int target, vector<int> nums)
{
    Solution sol;

    cout << "输入 Target: " << target << endl;
    cout << "输入 Nums: [";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << (i < nums.size() - 1 ? "," : "");
    }
    cout << "]" << endl;

    int result = sol.minSubArrayLen(target, nums);

    cout << "输出结果: " << result << endl;
    cout << "----------------------------------" << endl;
}

int main()
{
    // 示例 1
    // 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    runTestCase(7, nums1);

    // 示例 2
    // 解释：子数组 [4] 满足条件，长度为 1。
    vector<int> nums2 = {1, 4, 4};
    runTestCase(4, nums2);

    // 示例 3
    // 解释：总和为 8，小于 target 11，不存在符合条件的子数组，返回 0。
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    runTestCase(11, nums3);

    // 可以自己添加更多测试用例
    // vector<int> nums4 = {10, 2, 3};
    // runTestCase(6, nums4);

    return 0;
}