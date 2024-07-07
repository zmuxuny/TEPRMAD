#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
using namespace std;

// 定义状态
struct State
{
    string s;      // 当前状态
    int cost;      // 到达当前状态的代价
    int heuristic; // 启发式函数的值
};

// 启发式函数：计算当前状态到目标状态的差异
int heuristic(const string &s, const string &t)
{
    int diff = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != t[i])
        {
            ++diff;
        }
    }
    return diff;
}

// A* 算法
int solve(const string &S, const string &T)
{
    priority_queue<State> pq;
    map<string, int> cost;

    pq.push({S, 0, heuristic(S, T)});
    cost[S] = 0;

    while (!pq.empty())
    {
        State cur = pq.top();
        pq.pop();

        if (cur.s == T)
        {
            return cur.cost;
        }

        // 枚举相邻状态
        for (int i = 0; i < cur.s.size() - 1; ++i)
        {
            string next = cur.s;
            swap(next[i], next[i + 1]);
            int new_cost = cur.cost + 1;

            if (!cost.count(next) || new_cost < cost[next])
            {
                cost[next] = new_cost;
                pq.push({next, new_cost, new_cost + heuristic(next, T)});
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

    int result = solve(S, T);
    cout << result << endl;

    return 0;
}
