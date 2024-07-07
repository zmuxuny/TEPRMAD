#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    int g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    // Check if the cuboids intersect along each dimension
    bool intersect_x = (d > g) && (a < j);
    bool intersect_y = (e > h) && (b < k);
    bool intersect_z = (f > i) && (c < l);

    if (intersect_x && intersect_y && intersect_z)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
