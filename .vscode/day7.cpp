#include <iostream>  // 用于输入输出 (cout, endl)
#include <vector>    // 用于 vector 容器
#include <algorithm> // 用于 max 函数

using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int left = 0;
        int right = 0;
        int count = 0;
        int n = fruits.size();

        // 注意：如果在实际项目中栈空间较小，建议改用 vector<int> arr(100001, 0);
        // 这里为了保持你的原样，保留数组写法
        int arr[100001] = {0};

        int ret = 0;

        for (right; right < n; right++)
        {
            // 进窗口逻辑
            if (arr[fruits[right]] == 0)
            {
                count++;
                arr[fruits[right]]++;
            }
            else
            {
                arr[fruits[right]]++;
            }

            // 出窗口逻辑
            while (count > 2)
            {
                arr[fruits[left]]--;
                if (arr[fruits[left]] == 0)
                {
                    left++;
                    count--;
                    break;
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

    // 测试用例 1
    vector<int> fruits1 = {1, 2, 1};
    cout << "输入: [1, 2, 1]" << endl;
    cout << "输出: " << sol.totalFruit(fruits1) << endl; // 预期: 3
    cout << "-------------------" << endl;

    // 测试用例 2
    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "输入: [0, 1, 2, 2]" << endl;
    cout << "输出: " << sol.totalFruit(fruits2) << endl; // 预期: 3
    cout << "-------------------" << endl;

    // 测试用例 3
    vector<int> fruits3 = {1, 2, 3, 2, 2};
    cout << "输入: [1, 2, 3, 2, 2]" << endl;
    cout << "输出: " << sol.totalFruit(fruits3) << endl; // 预期: 4
    cout << "-------------------" << endl;

    return 0;
}