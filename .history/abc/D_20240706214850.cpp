#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
using namespace std;

// 定义状态
struct State
{
    string s; // 当前状态
    int cost; // 到达当前状态的代价
};

// 宽搜算法
int solve(const string &S, const string &T)
{
    queue<State> q;
    map<string, int> cost;

    q.push({S, 0});
    cost[S] = 0;

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        if (cur.s == T)
        {
            return cur.cost;
        }

        // 枚举相邻状态
        int dot_index = cur.s.find('.');
        for (int i = 0; i < cur.s.size() - 1; ++i)
        {
            string next = cur.s;
            if (next[i] == '.' || next[i + 1] == '.')
                continue;
            swap(next[i], next[dot_index]);
            swap(next[i + 1], next[dot_index + 1]);

            int new_cost = cur.cost + 1;
            if (!cost.count(next) || new_cost < cost[next])
            {
                cost[next] = new_cost;
                q.push({next, new_cost});
            }
        }
    }

    return -1; // 无解
}

int main()
{
    int N;
    string S, T;

    cin >> N >> S >> T;
    S += "..";
    T += "..";
    int result = solve(S, T);
    cout << result << endl;

    return 0;
}
