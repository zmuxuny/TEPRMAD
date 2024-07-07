#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    int ans = a[n - 1] - a[0];

    for (int i = 0, j = a.size() - 1; i < j && j - i + 1 > n - k;)
    {
        int temp = 1e9;
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
        ans = min(temp, ans);
        // cout << "now:" << endl;
        // for (int ii = i; ii <= j; ii++)
        // {
        //     cout << a[ii] << " ";
        // }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}