#include <bits/stdc++.h>

using namespace std;

long long fun1(vector<long long> &a, int n, int k)
{
    long long ans = 1e15;
    if (n == k)
        return 0;
    for (int i = 0, j = n - k - 1; i < k; i++, j++)
    {
        ans = min(a[j] - a[i], ans);
    }

    return ans;
}
long long fun2(vector<long long> &a, int n, int k)
{
    long long ans = 1e16;

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
    if (k == n)
        ans = 0;

    return ans;
}
3 1 5 4 9

    1 3 4 5 9 int
    main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    cout << min(fun1(a, n, k), fun2(a, n, k));

    return 0;
}