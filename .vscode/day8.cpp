#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::vector<int> findAnagrams(std::string s, std::string p)
    {
        int n = static_cast<int>(s.size());
        int m = static_cast<int>(p.size());
        std::vector<int> res;
        if (m > n)
            return res;

        int cntP[26] = {0};
        int cntW[26] = {0};

        for (char c : p)
            cntP[c - 'a']++;

        int left = 0;
        for (int right = 0; right < n; ++right)
        {
            cntW[s[right] - 'a']++; // 扩张右边界

            if (right - left + 1 > m)
            { // 超长则收缩左边界
                cntW[s[left] - 'a']--;
                ++left;
            }

            if (right - left + 1 == m && std::equal(cntP, cntP + 26, cntW))
            {
                res.push_back(left);
            }
        }
        return res;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, p;
    if (!(std::cin >> s >> p))
        return 0;

    Solution sol;
    std::vector<int> ans = sol.findAnagrams(s, p);

    std::cout << "[";
    for (size_t i = 0; i < ans.size(); ++i)
    {
        if (i)
            std::cout << ",";
        std::cout << ans[i];
    }
    std::cout << "]\n";
    return 0;
}