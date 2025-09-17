#include <iostream>
#include <vector>

// 函数功能：将数组中所有0移动到末尾，保持非零元素的相对顺序
void moveZeroes(std::vector<int> &nums)
{
    int n = nums.size();
    int nonZeroIndex = 0; // 用于跟踪下一个非零元素应该存放的位置

    // 第一步：将所有非零元素移到前面
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[nonZeroIndex++] = nums[i];
        }
    }

    // 第二步：将剩余位置填充为0
    for (int i = nonZeroIndex; i < n; i++)
    {
        nums[i] = 0;
    }
}

// 打印数组
void printArray(const std::vector<int> &nums)
{
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // 测试用例
    std::vector<int> test1 = {0, 1, 0, 3, 12};
    std::vector<int> test2 = {0, 0, 0, 1};
    std::vector<int> test3 = {1, 2, 3, 4};
    std::vector<int> test4 = {0};

    // 处理并输出结果
    std::cout << "原数组: ";
    printArray(test1);
    moveZeroes(test1);
    std::cout << "处理后: ";
    printArray(test1);
    std::cout << std::endl;

    std::cout << "原数组: ";
    printArray(test2);
    moveZeroes(test2);
    std::cout << "处理后: ";
    printArray(test2);
    std::cout << std::endl;

    std::cout << "原数组: ";
    printArray(test3);
    moveZeroes(test3);
    std::cout << "处理后: ";
    printArray(test3);
    std::cout << std::endl;

    std::cout << "原数组: ";
    printArray(test4);
    moveZeroes(test4);
    std::cout << "处理后: ";
    printArray(test4);

    return 0;
}
