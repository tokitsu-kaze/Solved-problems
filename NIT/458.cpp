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
	int n,i,x,now,pre,t;
	ll ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		pre=-1;
		now=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x>pre) now++;
			else now=1;
			pre=x;
			ans+=now;
	//		cout<<now<<endl;
		}
		printf("%lld\n",ans);
	} 
	return 0;
}
/*
2
6
1 2 3 4 3 5
6
1 2 3 3 2 1

*/