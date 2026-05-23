#include<bits/stdc++.h>

using namespace std;

const int N = 200043;
const int K = 3;
const int LN = 20;

vector<int> g[N];
int p[N];
pair<int, int> dp_down[N][K];
int dp_up[N];
int q_index;
int ans[N];
int f[N];

void upd_down(int idx, pair<int, int> p)
{
    if(dp_down[idx][K - 1] < p)
    {
        dp_down[idx][K - 1] = p;
        int j = K - 1;
        while(j != 0)
        {
            if(dp_down[idx][j - 1] < dp_down[idx][j])
            {
                swap(dp_down[idx][j - 1], dp_down[idx][j]);
                j--;
            }
            else break;
        }
    }
}

void upd(pair<int, int>& p, int x)
{
    if(p.second < x) p.second = x;
    if(p.first < p.second) swap(p.first, p.second);
}

int get_cur(int x)
{
    pair<int, int> cur_ans = {0, 0};
    for(int i = 0; i < K; i++)
        if(dp_down[x][i].second != f[x])
            upd(cur_ans, dp_down[x][i].first);
    if(f[x] != -1)
        upd(cur_ans, dp_up[x]);
    return cur_ans.second + 1;        
}

int get_full(int x)
{
    pair<int, int> cur_ans = {0, 0};
    for(int i = 0; i < K; i++)
        upd(cur_ans, dp_down[x][i].first);
    upd(cur_ans, dp_up[x]);
    return cur_ans.second + 1;    
}

void dfs1(int x, int parent = -1)
{
    p[x] = parent;
    for(auto y : g[x])
    {
        if(y > q_index) continue;
        if(y != parent)
        {
            dfs1(y, x);
            upd_down(x, make_pair(get_cur(y), y));
        }
    }
}

void dfs2(int x)
{
    if(p[x] != -1)
        dp_up[x] = get_cur(p[x]);
    for(auto y : g[x])
    {
        if(y > q_index) continue;
        if(y != p[x])
        {
            f[x] = y;
            dfs2(y);
            f[x] = -1;
        }
    }
}

int get_ans(int x)
{
    q_index = x + 2;
    for(int i = 1; i <= q_index; i++)
    {
        dp_up[i] = 0;
        for(int j = 0; j < K; j++)
            dp_down[i][j] = {0, -1};
        p[i] = -1;
        f[i] = -1;
    }
    dfs1(1);
    dfs2(1);
    int ans = 1;
    for(int i = 1; i <= q_index; i++)
        ans = max(ans, get_full(i));
    return ans;
}

void rec(int l, int r, int L, int R)
{
    if(l >= r) return;
    if(L == R)
    {
        for(int i = l; i < r; i++)
            ans[i] = L;
        return;
    }
    int mid = (l + r) / 2;
    ans[mid] = get_ans(mid);
    rec(l, mid, L, ans[mid]);
    rec(mid + 1, r, ans[mid], R);
}

void solve()
{
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i + 2);
        g[i + 2].push_back(x);
    }
    rec(0, q, 1, LN);
    for(int i = 0; i < q; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    for(int i = 0; i < t; i++)
        solve();
    return 0;
}
