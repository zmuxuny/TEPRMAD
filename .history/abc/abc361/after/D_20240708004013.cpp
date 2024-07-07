#include <bits/stdc++.h>
using namespace std;

int bfs(string &s, string &t)
{
    map<string, int> mp;

    queue<string> q;

    q.push(s);
    mp[s] = 0;

    while (q.size())
    {
        auto tt = q.front();
        q.pop();

        if (tt == t)
        {
            return mp[tt];
        }
        auto dot_index = tt.find('.');
        for (int i = 0; i < tt.size() - 1; i++) // 遍历到倒数第二个位置
        {
            string next = tt;
            if (next[i] != '.' && next[i + 1] != '.')
            {

                swap(next[i], next[dot_index]);
                swap(next[i + 1], next[dot_index + 1]);
                int new_cost = mp[tt] + 1;
                if (mp.count(next) == 0 || new_cost < mp[next])
                {
                    cout << next << endl;
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
    auto ans = bfs(s, t);
    cout << ans << endl;
    return 0;
}
