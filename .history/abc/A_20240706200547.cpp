#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, K, X;
    cin >> N >> K >> X;  // 读取长度N，位置K和插入的整数X
    vector<int> A(N), B; // 定义原始序列A和结果序列B

    // 读取序列A
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    // 将X插入到序列A的第K个元素之后
    for (int i = 0; i < N; ++i)
    {
        B.push_back(A[i]); // 将A的元素添加到B
        if (i == K - 1)
        {                   // 检查是否到达K的位置
            B.push_back(X); // 在K的位置后插入X
        }
    }

    // 输出结果序列B
    for (int i = 0; i < B.size(); ++i)
    {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}