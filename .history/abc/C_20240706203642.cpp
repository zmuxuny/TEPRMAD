#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
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
    if (k == n)
        ans = 0;

    cout << ans << endl;
    return 0;
}