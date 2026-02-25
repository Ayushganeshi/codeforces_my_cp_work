#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
struct Quad{ll a,b,c;}; 
 

bool comp(Quad f,Quad g)
{
  if(f.a>g.a)return false;
  else if(f.a==g.a)return f.b==g.b&&f.c<g.c;
  else
  {
    Quad Q{g.a-f.a,g.b-f.b,g.c-f.c};
    return Q.b*Q.b-4*Q.a*Q.c<0;
  }
}
 
int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    vector<Quad>vec(n);
    for(Quad&Q:vec)cin>>Q.a>>Q.b>>Q.c;
    vector<vector<int>>adj1(n),adj2(n);
    vector<int>id1(n),id2(n),dp1(n,1),dp2(n,1);
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(comp(vec[i],vec[j]))
        {
          adj1[i].push_back(j);
          id1[j]++;
          adj2[j].push_back(i);
          id2[i]++;
        }
      }
    }
    queue<int>Q;
    for(int i=0;i<n;i++)if(id1[i]==0)Q.push(i);
    while(!Q.empty())
    {
      int a=Q.front();Q.pop();
      for(int i:adj1[a])
      {
        id1[i]--;dp1[i]=max(dp1[i],dp1[a]+1);
        if(id1[i]==0)Q.push(i);
      }
    }
    for(int i=0;i<n;i++)if(id2[i]==0)Q.push(i);
    while(!Q.empty())
    {
      int a=Q.front();Q.pop();
      for(int i:adj2[a])
      {
        id2[i]--;dp2[i]=max(dp2[i],dp2[a]+1);
        if(id2[i]==0)Q.push(i);
      }
    }
    for(int i=0;i<n;i++)cout<<dp1[i]+dp2[i]-1<<" \n"[i+1==n];
  }
}
