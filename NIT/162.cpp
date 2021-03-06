#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-8;
const int MAX=1e5+10;
const ll mod=1e9+7;
int f[105],sg[MAX],m;
int dfs(int x)
{
	int i,j,flag[105];
	if(sg[x]!=-1) return sg[x];
	mem(flag,0);
	for(i=1;i<=m;i++)
	{
		if(x>=f[i])
		{
			dfs(x-f[i]);
			flag[sg[x-f[i]]]=1;
		}
	}
	for(i=0;;i++)
	{
		if(!flag[i])
		{
			j=i;
			break;
		}
	}
	return sg[x]=j;
}
int a[MAX];
int main()
{
	int n,ans,i;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=m;i++) scanf("%d",&f[i]);
		sort(f,f+m);
		mem(sg,-1);
		ans=0;
		for(i=1;i<=n;i++)
		{
			dfs(a[i]);
			ans^=sg[a[i]];
		}
		if(ans) puts("ZSQ");
		else puts("BJH");
	}
	return 0;
}