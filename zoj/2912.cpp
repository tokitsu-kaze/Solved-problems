#include <bits/stdc++.h>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;
struct node
{
	ll to,v;
	node(){}
	node(ll a,ll b)
	{
		to=a;
		v=b;
	}
};
vector<node> mp[MAX];
ll dp[MAX],n;
double ans;
void dfs(ll x,ll pre)
{
	ll i,to;
	dp[x]=1;
	for(i=0;i<sz(mp[x]);i++)
	{
		to=mp[x][i].to;
		if(to==pre) continue;
		dfs(to,x);
		dp[x]+=dp[to];
		ans+=(double)dp[to]*(n-dp[to])*mp[x][i].v;
	}
}
int main()
{
	ll t,i,a,b,c;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			mp[i].clear();
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			mp[a].pb(node(b,c));
			mp[b].pb(node(a,c));
		}
		ans=0;
		mem(dp,0);
		dfs(0,-1);
		printf("%.6lf\n",ans/(n*(n-1)/2));
	}
	return 0;
}