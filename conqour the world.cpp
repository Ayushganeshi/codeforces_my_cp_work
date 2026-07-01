//~ mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;

int n;
int a[nax];
int b[nax];
int oa[nax];
int ob[nax];

int wyn[nax];

int dlu[nax];
int bylo[nax];

void ans(int v)
{
	if (v)
	{
		printf("YES\n");
		for (int i=1; i<=n; i++)
			printf("%d ", b[i]);
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
}

queue<int> kol;

bool relax()
{
	while(!kol.empty())
	{
		int i=kol.front();
		kol.pop();
		
		int sr=i;
		int zew=b[i];
		zew=a[zew];
		sr=a[sr];
		if (b[sr]>=0 || ob[zew]>=0)
		{
			if (b[sr]==zew)
			{
			}
			else
			{
				return false;
			}
		}
		else
		{
			b[sr]=zew;
			ob[zew]=sr;
			kol.push(sr);
		}
	}
	return true;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &a[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &b[i]);
	
	for (int i=1; i<=n; i++)
		oa[a[i]]=i;
	for (int i=1; i<=n; i++)
		ob[i]=-1;
	for (int i=1; i<=n; i++)
		if (b[i]>=0)
			ob[b[i]]=i;
	
	while(!kol.empty())
		kol.pop();
	
	for (int i=1; i<=n; i++)
		if (b[i]>=0)
			kol.push(i);
	//~ debug() << range(b+1, b+1+n);
	if (!relax())
	{
		ans(0);
		return;
	}
	
	for (int i=1; i<=n; i++)
	{
		bylo[i]=0;
		dlu[i]=0;
	}
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		int v=i;
		int ile=0;
		while(v!=i || !ile)
		{
			ile++;
			v=a[v];
		}
		while(!dlu[v])
		{
			dlu[v]=ile;
			v=a[v];
		}
	}
	vector<vi> zbi(n+1);
	for (int i=n; i; i--)
		zbi[dlu[i]].push_back(i);
	
	for (int i=1; i<=n; i++)
	{
		if (b[i]==-1)
		{
			int x=dlu[i];
			while(ob[zbi[x].back()]>=0)
				zbi[x].pop_back();
			int y=zbi[x].back();
			kol.push(i);
			b[i]=y;
			ob[y]=i;
			assert(relax());
		}
	}
	ans(1);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
