#include<bits/stdc++.h>
using namespace std;
int n,p[200005],q[200005];
vector<int>g[200005];
int dfs(int x,int y,int las)
{
	p[x]=y;
	int tt=0;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==las)continue;
		if(p[cu]&&!tt)tt=y+1-p[cu];
		else if(p[cu]&&tt)continue;
		else
		{
			int ans=dfs(cu,y+1,x);
			if(ans)tt=ans;
		}
	}
	return tt;
}
int powdv(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1)ans=1ll*ans*x%1000000007;
		y>>=1;
		x=1ll*x*x%100000007;
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==i)assert(0);
		g[i].push_back(x);
		g[x].push_back(i);
	}
	int tot=0;
	for(int i=1;i<=n;i++)if(!p[i])
	{
		int tt=dfs(i,1,0);
		if(tt<=1)tt=2;
		q[++tot]=tt;
	}
	int ll=n,ff=1;
	for(int i=1;i<=tot;i++)ll-=q[i];
	for(int i=1;i<=tot;i++)ff=1ll*ff*(powdv(2,q[i])-2)%1000000007;
	cout<<1ll*ff*powdv(2,ll)%1000000007<<endl;
	return 0;
}
