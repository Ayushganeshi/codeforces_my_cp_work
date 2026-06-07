#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
vi a(20);
vvi op;

void moveall(int k, int s, int t)
{
    if(k <= 0) return;
    int u = 6 - s - t;

    if(a[k - 1] == 0)
    {
        moveall(k - 1, s, u);
        op.pb({k, s, t});
        moveall(k - 1, u, t);
    }
    else
    {
        moveall(k - 1 - a[k - 1], s, u);
        op.pb({k, s, t});
        moveall(k - 1 - a[k - 1], u, s);
        moveall(k - 1, s, t);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;

	while(t-->0)
    {
        cin >> n;

        for(int i=0; i<n; i++) cin >> a[i];

        bool ok = true;
        for(int i=0; i<n; i++) if(a[i] > i) ok = false;

        if(!ok)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        moveall(n, 1, 3);

        cout << op.size() << "\n";
        for(vi p: op) cout << p[0] << " " << p[1] << " " << p[2] << "\n";
        op.clear();
    }
}
