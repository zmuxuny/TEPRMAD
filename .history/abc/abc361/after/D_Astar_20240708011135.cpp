#include <bits/stdc++.h>
using namespace std;
struct state
{
    string s;
    int cost;
    int heur;                                // 估价函数值
    bool operator<(const state &other) const // 注意这里的改动
    {
        return cost + heur < other.cost + other.heur;
    }
    bool operator>(const state &other) const // 注意这里的改动
    {
        return cost + heur > other.cost + other.heur;
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
    map<string, int> mp;

    mp[s] = 0;
    int asdf = 0;
    while (heap.size())
    {
        asdf++;
        if (asdf > 10000)
        {
            cout << "no" << endl;
        }
        auto tt = heap.top();

        heap.pop();

        if (tt.s == t)
        {
            return tt.cost;
        }
        auto dot_index = tt.s.find('.');
        for (int i = 0; i < tt.s.size(); i++)
        {
            auto next = tt.s;

            if (next[i] != '.' && next[i + 1] != '.')
            {

                swap(next[i], next[dot_index]);
                swap(next[i + 1], next[dot_index + 1]);
                int new_cost = tt.cost + 1;
                if (mp.count(next) == 0 || new_cost < mp[next])
                {
                    heap.push({next, new_cost, fun(next, t)});
                    mp[next] = new_cost;
                }
            }
        }
    }

    return -1;
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
