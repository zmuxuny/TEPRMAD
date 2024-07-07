#include <bits/stdc++.h>

using namespace std;

long long fun1(vector<long long> &a, int n, int k)
{
    long long ans = 1e12;

    for (int i = 1, j = n - k; i <= k; i++, j++)
    {
        ans = min(a[j] - a[i], ans);
    }
    if (k == n)
        ans = 0;
    cout << ans << endl;
}
long long fun2(vector<long long> &a, int n, int k)
{
    long long ans = a[n - 1] - a[0];

    for (long long i = 0, j = a.size() - 1; i < j && j - i + 1 > n - k;)
    {
        long long temp = 1e12;
        if (a[j] - a[i + 1] < a[j - 1] - a[i])
        {

            temp = a[j] - a[i + 1];
            i++;
        }
        else
        {
            temp = a[j - 1] - a[i];
            j--;
        }
        ans = temp;
        // cout << "now:" << endl;
        // for (long long ii = i; ii <= j; ii++)
        // {
        //     cout << a[ii] << " ";
        // }
        // cout << endl;
    }
    ans = min(fun1(a, n, k), fun2(a, n, k));
}

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);

    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    if (n > 5)
    {
        fun1(a, n, k);
    }
    else
    {
        fun2(a, n, k);
    }

    return 0;
}