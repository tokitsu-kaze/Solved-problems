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
int main()
{
	int n,i,a,b,v[211],ans;
	while(~scanf("%d",&n))
	{
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d:%d",&a,&b);
			v[i]=a*60+b;
		}
		for(i=n+1;i<=2*n;i++)
		{
			v[i]=v[i-n]+24*60;
		}
		n*=2;
		sort(v+1,v+1+n);
		for(i=2;i<=n;i++) ans=max(ans,v[i]-v[i-1]);
		ans--;
		printf("%02d:%02d\n",ans/60,ans%60);
	}
	return 0;
}