#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {-1, -1};

        int left = 0;
        int right = (int)nums.size() - 1;
        int begin = 0;

        // 找左边界：第一个 >= target 的位置
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }

        if (nums[left] != target)
            return {-1, -1};
        begin = left;

        // 找右边界：最后一个 <= target 的位置
        right = (int)nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left + 1) / 2; // 偏右
            if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }

        return {begin, right};
    }
};

int main()
{
    int n;
    cin >> n; // 数组长度
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    { // 读入数组元素（有序）
        cin >> nums[i];
    }
    int target;
    cin >> target; // 读入要查找的目标值

    Solution sol;
    vector<int> ans = sol.searchRange(nums, target);

    cout << ans[0] << " " << ans[1] << endl; // 输出左右边界下标
    return 0;
}