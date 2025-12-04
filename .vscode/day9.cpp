#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        if (s.empty() || words.empty())
            return res;

        int wordLen = words[0].size();
        int m = words.size();
        int n = (int)s.size();
        int totalLen = wordLen * m;
        if (n < totalLen)
            return res;

        // 统计 words 中每个单词需要出现的次数
        unordered_map<string, int> need;
        for (auto &w : words)
            need[w]++;

        // 枚举起点偏移：0 ~ wordLen-1 共 wordLen 条“赛道”
        for (int offset = 0; offset < wordLen; ++offset)
        {
            unordered_map<string, int> window; // 当前赛道上的窗口计数
            int left = offset;                 // 窗口左端
            int count = 0;                     // 已经匹配到的单词数

            // 右端按块（长度为 wordLen）向右滑
            for (int right = offset; right + wordLen <= n; right += wordLen)
            {
                string w = s.substr(right, wordLen);

                // 不在 words 里的单词，整窗清空，从下一个块重新开始
                if (!need.count(w))
                {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                // 把 w 加进窗口
                window[w]++;
                if (window[w] <= need[w])
                {
                    ++count; // 有效匹配
                }
                else
                {
                    // 某个单词出现次数超过 need，缩左直到不过量
                    while (window[w] > need[w])
                    {
                        string w2 = s.substr(left, wordLen);
                        window[w2]--;
                        if (window[w2] < need[w2])
                            --count;
                        left += wordLen;
                    }
                }

                // 如果已经匹配了 m 个单词，记录答案
                if (count == m)
                {
                    res.push_back(left);
                    // 弹出左端一个词，继续往后找下一个
                    string w2 = s.substr(left, wordLen);
                    window[w2]--;
                    --count;
                    left += wordLen;
                }
            }
        }
        return res;
    }
};

int main()
{
    // 示例：LeetCode 经典样例
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};

    Solution sol;
    vector<int> ans = sol.findSubstring(s, words);

    cout << "起始下标: ";
    for (int idx : ans)
    {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}