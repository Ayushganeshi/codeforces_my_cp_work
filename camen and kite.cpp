#include <bits/stdc++.h>
using namespace std;

long long s, t;

long long eval(string &str, int mid)
{
    long long teacher = 0, ans = 0;

    for(char ch : str)
    {
        if(ch == 'I')
        {
            if(teacher < t)
            {
                teacher++;
                ans++;
            }
        }
        else if(ch == 'E')
        {
            if(ans < teacher * s)
                ans++;
        }
        else
        {
            if(mid-- > 0)
            {
                if(teacher < t)
                {
                    teacher++;
                    ans++;
                }
            }
            else
            {
                if(ans < teacher * s)
                    ans++;
            }
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while(tc--)
    {
        int n;
        cin >> n >> t >> s;

        string str;
        cin >> str;

        int left = 0, right = 0;

        for(char ch : str)
        {
            if(ch == 'A')
                right++;
        }

        while(left < right)
        {
            int mid = (left + right) / 2;

            long long x = eval(str, mid);
            long long y = eval(str, mid + 1);

            if(x < y)
                left = mid + 1;
            else
                right = mid;
        }

        cout << eval(str, left) << '\n';
    }

    return 0;
}
