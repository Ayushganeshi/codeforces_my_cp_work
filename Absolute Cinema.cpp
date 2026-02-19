#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
vector<ll>solve(ll n,vector<ll>f)
{
  vector<ll>vec(n);
  for(int i=1;i+1<n;i++)
  {
    if((f[i+1]+f[i-1]-2*f[i])%2!=0)return {};
    vec[i]=(f[i+1]+f[i-1]-2*f[i])/2;
    if(abs(vec[i])>1000)return {};
  }
  auto g=[&](ll j)
  {
    ll w=f[j];
    for(int i=1;i+1<n;i++)
    {
      w-=vec[i]*abs(i-j);
    }
    return w;
  };
  ll g1=g(0),gn=g(n-1);
  if(gn%(n-1)!=0)return {};
  if(g1%(n-1)!=0)return {};
  vec[0]=gn/(n-1);
  vec[n-1]=g1/(n-1);
  if(abs(vec[0])>1000||abs(vec[n-1])>1000)return {};
  return vec;
}

int main()
{
  int t;cin>>t;
  while(t--)
  {
    ll n;cin>>n;
    vector<ll>f(n);
    for(ll&i:f)cin>>i;
    auto a=solve(n,f);
    assert(a.size()==n);
    for(int i=0;i<n;i++)cout<<a[i]<<" \n"[i+1==n];
  }
}
