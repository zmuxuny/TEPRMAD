#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    string s, t;

    cin >> s >> t;

    s += "..";
    t += "..";

    auto ans = Astar(s, t);
    cout << ans << endl;
    return 0;
}
