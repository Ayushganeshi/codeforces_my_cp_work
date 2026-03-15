#include<bits/stdc++.h>
#define F(i,x,y) for (int i=(x);i<=(y);i++)
#define R(i,x,y) for (int i=(x);i>=(y);i--)

using namespace std;

const bool MT = 1;
int n,k,p,a[100005];
ll m;
void ygg(){
	cin>>n>>k>>p>>m;
	F(i,1,n) cin>>a[i];
	multiset<int> opt;
	F(i,1,k-1) opt.insert (a[i]);
	F(i,k,p-1) {
		opt.insert (a[i]);
		m-=*opt.begin ();
		opt.erase (opt.begin ());
	}
	m-=a[p];
	if (m<0) {
	    cout<<0<<"\n";
	    return;
	}
	ll sum=a[p];
	opt.clear ();
	F(i,1,n) {
		if (i!=p) opt.insert (a[i]);
	}
	F(i,1,n-k) {
		sum+=*opt.begin ();
		opt.erase (opt.begin ());
	}
	cout<<1+m/sum<<"\n";
}
void mark() {

}
int main (){
#ifdef ONLINE_JUDGE
	iosoptim
#endif
	int testcases=1;
	if(MT) cin>>testcases;
	while(testcases--){
		ygg();
		mark();
	}
	return 0;
}
