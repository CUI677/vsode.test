#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string ret = "1";
        for (int i = 1; i < n; i++)
        {
            string tmp;
            int len = ret.size();
            for (int left = 0, right = 0; right < len;)
            {
                while (right < len && ret[left] == ret[right])
                    right++;
                tmp += to_string(right - left) + ret[left];
                left = right;
            }
            ret = tmp;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    for (int i = 1; i <= 6; i++)
    {
        cout << "n=" << i << ": " << sol.countAndSay(i) << endl;
    }
    return 0;
}
