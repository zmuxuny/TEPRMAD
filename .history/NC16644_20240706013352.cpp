#include <bits/stdc++.h>
using namespace std;
int p1, p2, p3;

char trans(char c)
{
    if (p1 == 1)
    {
        if (isdigit(c))
            return c;
        else
            return _tolower(c);
    }
    if (p1 == 2)
    {
        if (isdigit(c))
            return c;
        else
            return _toupper(c);
    }
    if (p1 == 3)
    {
        return '*';
    }
    return '*';
}

string expand(char a, char b)
{
    if (isdigit(a) != isdigit(b))
    {
        return "-";
    }
    string res = "";
    for (char c = a + 1; c < b; c++)
    {
        string temp = "";
        for (int i = 0; i < p2; i++)
        {
            temp += trans(c);
        }
        res += temp;
    }
    if (a == b)
    {
        return "-";
    }
    if (b - a == 1)
    {
        return "";
    }
    if (a > b)
    {
        return "-";
    }
    return res;
}

void myreverse(string &s)
{

    if (p3 == 1)
    {
        return;
    }
    else if (p3 == 2)
    {
        std::reverse(s.begin(), s.end());
        return;
    }
    else
    {
        cout << string("cao") << endl;
        exit(0);
    }
}

string option(char a, char b)
{
    string res = expand(a, b);
    myreverse(res);
    return res;
}
string fun(char b, char e, int p1, int p2, int p3)
{
    if (e - b == 1)
    {
        return "";
    }
    if (!((isalpha(b) && isalpha(e) && b < e) ||
          (isdigit(b) && isdigit(e) && b < e)))
    {
        return "-";
    }
    string ans = "";
    for (char t = b + 1; t < e; t++)
    {
        for (int i = 0; i < p2; i++)
        {
            ans += t;
        }
    }
    if (p1 == 2 && isalpha(b))
    {
        for (int i = 0; i < ans.length(); i++)
        {
            ans[i] = ans[i] - 'a' + 'A';
        }
    }
    if (p1 == 3)
    {
        for (int i = 0; i < ans.length(); i++)
        {
            ans[i] = '*';
        }
    }
    if (p3 == 2)
    {
        reverse(ans.begin(), ans.end());
    }
    return ans;
}
int main()
{
    for (int tt = 0; tt < 1000; tt++)
    {
        srand(time(0)); // 使用当前时间作为随机数生成的种子

        // 随机生成p1, p2, p3的值
        int p1 = rand() % 3 + 1; // 生成1到3之间的随机数
        int p2 = rand() % 8 + 1; // 生成1到8之间的随机数
        int p3 = rand() % 2 + 1; // 生成1到2之间的随机数

        // 随机生成字符串s的长度，长度范围1到100
        int length = rand() % 100 + 1;

        // 初始化字符串s为空字符串
        string s = "";

        // 定义字符集，包括小写字母和数字
        string charSet = "abcdefghijklmnopqrstuvwxyz0123456789";

        // 随机生成字符串s
        for (int i = 0; i < length; i++)
        {
            int charIndex = rand() % charSet.length(); // 生成随机索引
            s += charSet[charIndex];                   // 从字符集中选取字符，添加到字符串s
        }
    }
    // cin >> p1 >> p2 >> p3;

    string s;
    cin >> s;

    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '-' && (i == 0 || i == s.size() - 1))
        {
            ans += s[i];
            continue;
        }
        if (s[i] != '-')
        {
            ans += s[i];
        }
        else if (s[i] == '-')
        {
            auto temp = option(s[i - 1], s[i + 1]);
            auto temp2 = fun(s[i - 1], s[i + 1], p1, p2, p3);
            if (temp != temp2)
            {
                cout << "Error: Invalid range" << endl;
                cout << "Print: " << s[i - 1] << " " << s[i + 1] << endl;
                exit(0);
            }
            ans += temp;
        }
    }
    cout << ans << endl;

    return 0;
}