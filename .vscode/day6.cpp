#include <iostream>
#include <vector>
#include <numeric>   // 用于 accumulate 计算和
#include <algorithm> // 用于 min, max

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();

        // 1. 计算数组总和
        long long total_sum = 0;
        for (int e : nums)
            total_sum += e;

        // 2. 计算中间子数组的目标和
        int target = total_sum - x;

        // 特殊情况处理
        if (target < 0)
            return -1; // 全部减完都不够 x
        if (target == 0)
            return n; // 恰好需要减去全部元素

        int left = 0;
        int current_sum = 0;

        // 【技巧】初始化为一个不可能的大数值 (n + 1)
        // 因为最大操作数也就是 n，如果最后结果还是 n+1，说明没找到
        int min_ops = n + 1;

        // 3. 滑动窗口
        for (int right = 0; right < n; right++)
        {
            current_sum += nums[right];

            // 窗口过大，左边收缩
            while (current_sum > target && left <= right)
            {
                current_sum -= nums[left];
                left++;
            }

            // 刚好满足条件，更新最小操作数
            if (current_sum == target)
            {
                // 移除的个数 = 总长度 - 中间保留的长度
                int ops = n - (right - left + 1);
                // 直接用 min，不需要判断是否是第一次
                min_ops = min(min_ops, ops);
            }
        }

        // 如果 min_ops 还是初始值 n+1，说明循环里从未找到解，返回 -1
        // 否则返回计算出的最小值
        return (min_ops > n) ? -1 : min_ops;
    }
};

// --- 以下是测试辅助代码 ---

void runTestCase(vector<int> nums, int x, int expectedId)
{
    Solution sol;
    cout << "示例 " << expectedId << ":" << endl;
    cout << "输入: nums = [";
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << (i < nums.size() - 1 ? "," : "");
    }
    cout << "], x = " << x << endl;

    int result = sol.minOperations(nums, x);
    cout << "输出: " << result << endl;
    cout << "------------------------" << endl;
}

int main()
{
    // 示例 1
    // 解释：最佳解决方案是移除后两个元素 [2,3]，将 x 减到 0 (5-2-3=0)。操作数 2。
    vector<int> nums1 = {1, 1, 4, 2, 3};
    runTestCase(nums1, 5, 1);

    // 示例 2
    // 解释：无法将 x 减到 0。
    vector<int> nums2 = {5, 6, 7, 8, 9};
    runTestCase(nums2, 4, 2);

    // 示例 3
    // 解释：移除后三个 [1,1,3] 和前两个 [3,2]，总共 5 次。
    vector<int> nums3 = {3, 2, 20, 1, 1, 3};
    runTestCase(nums3, 10, 3);

    return 0;
}