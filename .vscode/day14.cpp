#include <iostream>
#include <vector>
#include <algorithm> // 包含max/min函数
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        if (n == 0)
            return {}; // 处理空矩阵边界
        int m = mat[0].size();

        // 1. 初始化二维前缀和数组（n+1行m+1列，默认值0）
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                // 前缀和递推公式：上 + 左 - 左上（去重） + 原矩阵当前值
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        // 2. 初始化结果数组
        vector<vector<int>> ret(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                // 计算以(i,j)为中心、k为半径的子矩阵边界（原矩阵0起点）
                int x1 = max(0, i - k);     // 子矩阵左上边界（行）
                int y1 = max(0, j - k);     // 子矩阵左上边界（列）
                int x2 = min(n - 1, i + k); // 子矩阵右下边界（行）
                int y2 = min(m - 1, j + k); // 子矩阵右下边界（列）

                // 二维前缀和求子矩阵和（核心公式）
                ret[i][j] = dp[x2 + 1][y2 + 1] - dp[x1][y2 + 1] - dp[x2 + 1][y1] + dp[x1][y1];
            }
        }
        return ret;
    }
};

// 辅助函数：打印二维数组
void printMatrix(const vector<vector<int>> &mat)
{
    for (const auto &row : mat)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

// 测试用例
int main()
{
    // 示例1：基础测试用例
    vector<vector<int>> mat1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int k1 = 1;
    Solution sol;
    vector<vector<int>> res1 = sol.matrixBlockSum(mat1, k1);

    cout << "原矩阵：" << endl;
    printMatrix(mat1);
    cout << "k=" << k1 << " 时的矩阵块和：" << endl;
    printMatrix(res1);
    cout << "-------------------------" << endl;

    // 示例2：k=0（仅自身）
    int k2 = 0;
    vector<vector<int>> res2 = sol.matrixBlockSum(mat1, k2);
    cout << "k=" << k2 << " 时的矩阵块和：" << endl;
    printMatrix(res2);
    cout << "-------------------------" << endl;

    // 示例3：空矩阵边界测试
    vector<vector<int>> mat2 = {};
    vector<vector<int>> res3 = sol.matrixBlockSum(mat2, 2);
    cout << "空矩阵的结果：" << (res3.empty() ? "空数组" : "非空") << endl;

    return 0;
}