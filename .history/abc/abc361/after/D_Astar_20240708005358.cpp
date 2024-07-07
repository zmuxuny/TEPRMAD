#include <bits/stdc++.h>
using namespace std;
struct state
{
    string s;
    int cost;
    int heur; // 估价函数值
};

int fun(string &s, string t)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
        {
            count++;
        }
    }
    return count;
}

int Astar(const string &s, const string &t)
{
    // Your implementation of the A* algorithm here
    // ...
    return 0; // Placeholder return value
}

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
