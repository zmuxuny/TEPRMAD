#include <iostream>
#include <cmath> // 包含sqrt函数
using namespace std;

// 函数用于计算两点之间的距离
double distance(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

// 函数用于计算立方体的外接球半径
double radius(double a, double b, double c, double d, double e, double f)
{
    return distance(a, b, c, d, e, f) / 2.0;
}

// 函数用于判断两个立方体的外接球是否相交
bool spheresIntersect(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
    // 计算两个立方体的外接球中心
    double centerX1 = (a + d) / 2.0;
    double centerY1 = (b + e) / 2.0;
    double centerZ1 = (c + f) / 2.0;
    double centerX2 = (g + j) / 2.0;
    double centerY2 = (h + k) / 2.0;
    double centerZ2 = (i + l) / 2.0;

    // 计算两个立方体的外接球半径
    double radius1 = radius(a, b, c, d, e, f);
    double radius2 = radius(g, h, i, j, k, l);

    // 计算两个外接球中心之间的距离
    double dist = distance(centerX1, centerY1, centerZ1, centerX2, centerY2, centerZ2);

    // 如果中心之间的距离小于或等于半径之和，则外接球相交
    return dist <= (radius1 + radius2);
}

int main()
{
    int a, b, c, d, e, f, g, h, i, j, k, l;
    // 读取两个立方体的坐标
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    // 判断立方体的外接球是否相交，并输出结果
    if (spheresIntersect(a, b, c, d, e, f, g, h, i, j, k, l))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}