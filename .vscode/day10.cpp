#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) 
    {
        int hash1[128] = {0};
        int hash2[128] = {0};
        int count = 0;
        int n = s.size();
        int len = INT_MAX;
        int begin = -1;

        for (char e : t)
        {
            if (hash1[e] == 0)
                count++;
            hash1[e]++;
        }

        int left = 0, right = 0;
        int count2 = 0;

        for (; right < n; right++)
        {
            char in = s[right];
            hash2[in]++;
            if (hash1[in] == hash2[in])
                count2++;

            while (count == count2)
            {
                if (right - left + 1 < len)
                {
                    len = right - left + 1;
                    begin = left;
                }
                char out = s[left];
                if (hash1[out] == hash2[out])
                    count2--;
                hash2[out]--;
                left++;
            }
        }
        return begin == -1 ? "" : s.substr(begin, len);
    }
};

int main() {
    string s = "cabwefgewcwaefgcf";
    string t = "cae";
    Solution sol;
    cout << sol.minWindow(s, t) << endl;  // 应输出 cwae
    return 0;
}