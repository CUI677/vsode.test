#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int hash[128] = {0}; // 数组模拟哈希表，记录每个字符出现次数
        int left = 0;        // 窗口左边界
        int maxLen = 0;      // 记录最大长度
        int n = s.size();

        // right 是窗口右边界
        for (int right = 0; right < n; right++)
        {
            // 1. 当前字符进入窗口，计数+1
            hash[s[right]]++;

            // 2. 如果当前字符重复了（次数>1），收缩左边界
            while (hash[s[right]] > 1)
            {
                hash[s[left]]--; // 左边字符离开窗口，计数-1
                left++;          // 左边界右移
            }

            // 3. 此时窗口内无重复，更新最大长度
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// ==================== 测试代码 ====================
int main()
{
    Solution sol;

    // 测试用例1: 基本情况
    string s1 = "abcabcbb";
    cout << "输入: \"" << s1 << "\"" << endl;
    cout << "输出: " << sol.lengthOfLongestSubstring(s1) << endl;
    cout << "解释: 最长子串是 \"abc\"，长度为 3" << endl;
    cout << "-------------------" << endl;

    // 测试用例2: 全部重复
    string s2 = "bbbbb";
    cout << "输入: \"" << s2 << "\"" << endl;
    cout << "输出: " << sol.lengthOfLongestSubstring(s2) << endl;
    cout << "解释: 最长子串是 \"b\"，长度为 1" << endl;
    cout << "-------------------" << endl;

    // 测试用例3: 中间有重复
    string s3 = "pwwkew";
    cout << "输入: \"" << s3 << "\"" << endl;
    cout << "输出: " << sol.lengthOfLongestSubstring(s3) << endl;
    cout << "解释: 最长子串是 \"wke\"，长度为 3" << endl;
    cout << "-------------------" << endl;

    // 测试用例4: 空字符串
    string s4 = "";
    cout << "输入: \"" << s4 << "\"" << endl;
    cout << "输出: " << sol.lengthOfLongestSubstring(s4) << endl;
    cout << "解释: 空字符串，长度为 0" << endl;
    cout << "-------------------" << endl;

    // 测试用例5: 无重复
    string s5 = "abcdef";
    cout << "输入: \"" << s5 << "\"" << endl;
    cout << "输出: " << sol.lengthOfLongestSubstring(s5) << endl;
    cout << "解释: 整个字符串无重复，长度为 6" << endl;
    cout << "-------------------" << endl;

    // 测试用例6: 含空格和特殊字符
    string s6 = "a b c";
    cout << "输入: \"" << s6 << "\"" << endl;
    cout << "输出: " << sol.lengthOfLongestSubstring(s6) << endl;
    cout << "解释: 最长子串是 \"a b c\"（含空格），长度为 5" << endl;

    return 0;
}