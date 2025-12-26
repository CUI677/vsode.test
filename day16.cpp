#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        int d = 2 * numRows - 2;
        string ret;
        int n = s.size();

        for (int i = 0; i < n; i += d)
        {
            ret += s[i];
        }

        for (int l = 1; l < numRows - 1; l++)
        {
            for (int i = l, j = d - l; i < n || j < n; i += d, j += d)
            {
                if (i < n)
                    ret += s[i];
                if (j < n)
                    ret += s[j];
            }
        }

        for (int i = numRows - 1; i < n; i += d)
        {
            ret += s[i];
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    cout << sol.convert("PAYPALISHIRING", 3) << endl;
    cout << sol.convert("PAYPALISHIRING", 4) << endl;
    cout << sol.convert("A", 1) << endl;
    cout << sol.convert("AB", 1) << endl;
    return 0;
}
