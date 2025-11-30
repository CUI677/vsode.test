#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int count = 0;
        int ret = 0;

        for (int right = 0; right < n; right++)
        {
            // 进窗口
            if (nums[right] == 0)
                count++;

            // 出窗口
            while (count > k)
            {
                if (nums[left] == 0)
                {
                    count--;
                }
                left++;
            }

            // 更新结果
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};

int main()
{
    Solution sol;

    // 测试用例1
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    cout << "测试1: " << sol.longestOnes(nums1, k1) << " (预期: 6)" << endl;

    // 测试用例2
    vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;
    cout << "测试2: " << sol.longestOnes(nums2, k2) << " (预期: 10)" << endl;

    // 测试用例3: 全是1
    vector<int> nums3 = {1, 1, 1, 1, 1};
    int k3 = 2;
    cout << "测试3: " << sol.longestOnes(nums3, k3) << " (预期: 5)" << endl;

    // 测试用例4: 全是0
    vector<int> nums4 = {0, 0, 0, 0, 0};
    int k4 = 2;
    cout << "测试4: " << sol.longestOnes(nums4, k4) << " (预期: 2)" << endl;

    // 测试用例5: k=0
    vector<int> nums5 = {1, 1, 0, 1, 1, 1};
    int k5 = 0;
    cout << "测试5: " << sol.longestOnes(nums5, k5) << " (预期: 3)" << endl;

    // 测试用例6: 单个元素
    vector<int> nums6 = {0};
    int k6 = 1;
    cout << "测试6: " << sol.longestOnes(nums6, k6) << " (预期: 1)" << endl;

    return 0;
}