#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main()
{
    vector<vector<int>> testCases = {
        {1},
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5},
        {1, 3, 2, 1},
        {2, 1},
        {1, 2, 1, 3, 5, 6, 4}};

    Solution solution;
    for (int i = 0; i < testCases.size(); ++i)
    {
        vector<int> &nums = testCases[i];
        int peakIndex = solution.findPeakElement(nums);

        cout << "测试用例 " << i + 1 << "：[";
        for (int j = 0; j < nums.size(); ++j)
        {
            cout << nums[j];
            if (j != nums.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;

        cout << "峰值索引：" << peakIndex << "，峰值数值：" << nums[peakIndex] << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}