#include <iostream>
using namespace std;

// 函数用于检查两个区间是否有交集
bool hasIntersection(int l1, int r1, int l2, int r2)
{
    return !(r1 < l2 || r2 < l1);
}

// 函数用于检查两个立方体是否相交
bool cuboidsIntersect(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
    // 检查在每个维度上的投影是否相交
    bool intersectX = hasIntersection(a, d, g, j);
    bool intersectY = hasIntersection(b, e, h, k);
    bool intersectZ = hasIntersection(c, f, i, l);

    // 如果在所有三个维度上的投影都有交集，则两个立方体相交
    return intersectX && intersectY && intersectZ;
}

int main()
{
    int a, b, c, d, e, f, g, h, i, j, k, l;
    // 读取两个立方体的坐标
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    // 检查立方体是否相交，并输出结果
    if (cuboidsIntersect(a, b, c, d, e, f, g, h, i, j, k, l))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}