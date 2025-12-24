#include <vector>
#include <iostream> // 必须包含iostream头文件才能用cout/cin
using namespace std;

class Solution
{
public:
    vector<int> missingTwo(vector<int> &nums)
    {
        // 步骤1：整体异或，得到两个缺失数的异或结果 sum = a ^ b
        int sum = 0;
        for (auto e : nums)
        {
            sum ^= e;
        }
        int n = nums.size();
        for (int i = 1; i <= n + 2; ++i)
        {
            sum ^= i;
        }

        // 步骤2：提取sum最右侧的1（核心：sum & (-sum)）
        int mask = sum & (-sum);

        // 步骤3：分组异或，拆分出两个缺失数a和b
        int a = 0, b = 0;
        // 先异或数组中的元素
        for (auto e : nums)
        {
            if (e & mask)
            {
                a ^= e;
            }
            else
            {
                b ^= e;
            }
        }
        // 再异或1~n+2的完整序列（重复数抵消，剩余a和b）
        for (int i = 1; i <= n + 2; ++i)
        {
            if (i & mask)
            {
                a ^= i;
            }
            else
            {
                b ^= i;
            }
        }

        return {a, b};
    }
};

// 完整的main函数：测试代码逻辑
int main()
{
    // 测试用例1：nums=[1]，缺失2和3
    vector<int> nums1 = {1};
    Solution s;
    vector<int> res1 = s.missingTwo(nums1);
    cout << "测试用例1结果：" << res1[0] << ", " << res1[1] << endl;

    // 测试用例2：nums=[2,3]，缺失1和4
    vector<int> nums2 = {2, 3};
    vector<int> res2 = s.missingTwo(nums2);
    cout << "测试用例2结果：" << res2[0] << ", " << res2[1] << endl;

    // 测试用例3：nums=[1,2,4]，缺失3和5
    vector<int> nums3 = {1, 2, 4};
    vector<int> res3 = s.missingTwo(nums3);
    cout << "测试用例3结果：" << res3[0] << ", " << res3[1] << endl;

    return 0;
}