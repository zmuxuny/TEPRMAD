#include <bits/stdc++.h>
using namespace std;

bool range_merge(int x1, int x2, int x3, int x4)
{
    return !(x1 >= x4 || x2 <= x3);
}

int main()
{
    int x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;

    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;

    if (range_merge(x1, x2, x3, x4) && range_merge(y1, y2, y3, y4) && range_merge(z1, z2, z3, z4))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
