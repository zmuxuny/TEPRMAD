#include <bits/stdc++.h>
using namespace std;
struct state
{
    string s;
    int cost;
    int heur; // 估价函数值
    bool operator<(state &other)
    {
        return cost + heur < other.cost + other.heur;
    }
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

int Astar(string &s, string &t)
{
    priority_queue<state, vector<state>, greater<state>> heap;

    heap.push({s, 0, fun(s, t)});

    return 0;
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
