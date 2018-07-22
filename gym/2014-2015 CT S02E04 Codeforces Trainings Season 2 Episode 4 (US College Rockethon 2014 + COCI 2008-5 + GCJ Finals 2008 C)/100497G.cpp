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
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e4+10;
const ll mod=1e9+7;
ll a[MAX];
int main()
{
	ll n,k,i,flag,now,temp;
	while(~scanf("%lld%lld",&n,&k))
	{
		now=n*(n-1)/2;
		flag=now%2;
		if(flag!=abs(k)%2||now<abs(k))
		{
			puts("-1");
			continue;
		}
		for(i=2;i<=n;i++) a[i]=i-1;
		now-=k;
		now/=2;
		ll cnt=1;
		for(i=2;i<=n;i++)
		{
			if(now>=(n-i+1))
			{
				a[i]-=2*min(cnt,now/(n-i+1));
				now-=min(cnt,now/(n-i+1));
			}
			cnt++;
//			cout<<now<<endl;
		}
		printf("%d",a[1]);
		for(i=2;i<=n;i++) printf(" %d",a[i]);
		puts("");
	}
	return 0;
}