#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    long long ans = 1e12;
    for (int i = k, j = n - 1; i >= 0; i--, j--)
    {
        ans = min(ans, a[j] - a[i]);
    }
    cout << ans << endl;

    return 0;
}
