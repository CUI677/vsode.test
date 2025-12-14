#include <iostream>
#include <vector>
using namespace std;

class NumMatrix
{
public:
    // 前缀和数组（成员变量，存储预处理结果）
    vector<vector<long long>> preSum;

    // 构造函数：初始化并预处理二维前缀和
    NumMatrix(vector<vector<int>> &matrix)
    {
        // 处理空矩阵边界情况
        if (matrix.empty() || matrix[0].empty())
        {
            return;
        }

        int rows = matrix.size();    // 矩阵行数
        int cols = matrix[0].size(); // 矩阵列数

        // 前缀和数组多开一行一列，避免边界越界判断
        preSum.resize(rows + 1, vector<long long>(cols + 1, 0));

        // 预处理前缀和数组
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                // 二维前缀和核心公式：当前值 = 左 + 上 - 左上（去重） + 原矩阵值
                preSum[i + 1][j + 1] = preSum[i][j + 1] + preSum[i + 1][j] - preSum[i][j] + matrix[i][j];
            }
        }
    }

    // 查询函数：计算 (row1,col1) 到 (row2,col2) 子矩阵的和
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        // 查询核心公式：右下角 - 上方区域 - 左方区域 + 重复扣除的左上角区域
        return preSum[row2 + 1][col2 + 1] - preSum[row1][col2 + 1] - preSum[row2 + 1][col1] + preSum[row1][col1];
    }
};

// 测试用例（主函数，可直接运行验证）
int main()
{
    // 示例矩阵（LeetCode 官方测试用例）
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};

    // 初始化 NumMatrix 对象
    NumMatrix numMatrix(matrix);

    // 测试查询1：(2,1) 到 (4,3)，预期输出 8
    cout << "sumRegion(2,1,4,3) = " << numMatrix.sumRegion(2, 1, 4, 3) << endl;

    // 测试查询2：(1,1) 到 (2,2)，预期输出 11
    cout << "sumRegion(1,1,2,2) = " << numMatrix.sumRegion(1, 1, 2, 2) << endl;

    // 测试查询3：(0,0) 到 (4,4)，预期输出 58
    cout << "sumRegion(0,0,4,4) = " << numMatrix.sumRegion(0, 0, 4, 4) << endl;

    return 0;
}