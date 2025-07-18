#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0);

//  AUTHOR:->Ayush Kumar Gupta 
//       !! CHESS & CODE!! 

struct X93 {
    int l, r, x;
};

bool ayu(const X93 &a1, const X93 &a2) {
    return a1.l < a2.l;
}

void pr1(priority_queue<int> *q, int *v) {
    while (!q->empty() && q->top() <= *v) q->pop();
}

int fx99(X93 *a, int n, int k) {
    sort(a, a + n,ayu);
    int p1 = k, j = 0;
    priority_queue<int> q;

    while (1) {
        while (j < n && a[j].l <= p1) q.push(a[j++].x);
        pr1(&q, &p1);
        if (q.empty()) break;
        p1 = q.top();
        q.pop();
    }
    return p1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    X93 *a = new X93[n];
    for (int i = 0; i < n; ++i) cin >> a[i].l >> a[i].r >> a[i].x;
    cout << fx99(a, n, k) <<endl;
    delete[] a;
}

int32_t main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
