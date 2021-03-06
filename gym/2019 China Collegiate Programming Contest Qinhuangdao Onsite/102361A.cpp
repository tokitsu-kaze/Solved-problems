#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
	//inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
	inline char nc(){
		static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
		if(p1==pend){
			p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);
			if(pend==p1){IOerror=1;return -1;}
		}
		return *p1++;
	}
	inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
	template<class T> inline bool read(T &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(sign)x=-x;
		return true;
	}
	inline bool read(double &x){
		bool sign=0;char ch=nc();x=0;
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		if(ch=='-')sign=1,ch=nc();
		for(;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0';
		if(ch=='.'){
			double tmp=1; ch=nc();
			for(;ch>='0'&&ch<='9';ch=nc())tmp/=10.0,x+=tmp*(ch-'0');
		}
		if(sign)x=-x;
		return true;
	}
	inline bool read(char *s){
		char ch=nc();
		for(;blank(ch);ch=nc());
		if(IOerror)return false;
		for(;!blank(ch)&&!IOerror;ch=nc())*s++=ch;
		*s=0;
		return true;
	}
	inline bool read(char &c){
		for(c=nc();blank(c);c=nc());
		if(IOerror){c=-1;return false;}
		return true; 
	}
	template<class T,class... U>bool read(T& h,U&... t){return read(h)&&read(t...);}
	#undef OUT_SIZE
	#undef BUF_SIZE
};
using namespace fastIO;
/************* debug begin *************/
string to_string(string s){return '"'+s+'"';}
string to_string(const char* s){return to_string((string)s);}
string to_string(const bool& b){return(b?"true":"false");}
template<class T>string to_string(T x){ostringstream sout;sout<<x;return sout.str();}
template<class A,class B>string to_string(pair<A,B> p){return "("+to_string(p.first)+", "+to_string(p.second)+")";}
template<class A>string to_string(const vector<A> v){
	int f=1;string res="{";for(const auto x:v){if(!f)res+= ", ";f=0;res+=to_string(x);}res+="}";
	return res;
}
void debug_out(){puts("");}
template<class T,class... U>void debug_out(const T& h,const U&... t){cout<<" "<<to_string(h);debug_out(t...);}
#ifdef tokitsukaze 
#define debug(...) cout<<"["<<#__VA_ARGS__<<"]:",debug_out(__VA_ARGS__);
#else
#define debug(...) 233;
#endif
/*************  debug end  *************/
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define sqr(x) (x)*(x)
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef pair<int,ll> PIL;
typedef pair<ll,int> PLI;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<PII > VPII;
/************* define end  *************/
void read(int *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(ll *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void read(double *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
void println(int *x,int l,int r){for(int i=l;i<=r;i++) printf("%d%c",x[i]," \n"[i==r]);}
void println(ll *x,int l,int r){for(int i=l;i<=r;i++) printf("%lld%c",x[i]," \n"[i==r]);}
/*************** IO end  ***************/
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3fLL;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
VPII mp[2020],mp2;
int x[MAX],y[MAX];
int gcd(int a,int b)
{
	int res=0;
	if(a<0) a=-a;
	if(b<0) b=-b;
	if(!a||!b) return a+b;
	while(a)
	{
		for(;!(a&1)&&!(b&1);res++,a>>=1,b>>=1);
		for(;!(a&1);a>>=1);
		for(;!(b&1);b>>=1);
		if(a<b) swap(a,b);
		a-=b;
	}
	return b<<res;
}
void go()
{
	int n,q,i,j,g,xx,yy,ans1,ans2;
	PII tmp,tmp2[2020];
	while(read(n,q))
	{
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			read(x[i],y[i]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				tmp.fi=x[i]-x[j];
				tmp.se=y[i]-y[j];
				g=gcd(tmp.fi,tmp.se);
				tmp.fi/=g;
				tmp.se/=g;
				mp[i].pb(tmp);
				tmp.fi=-tmp.fi;
				tmp.se=-tmp.se;
				mp[j].pb(tmp);
			}
			sort(all(mp[i]));
		}
		while(q--)
		{
			read(xx,yy);
			ans1=ans2=0;
			mp2.clear();
			for(i=1;i<=n;i++)
			{
				tmp.fi=xx-x[i];
				tmp.se=yy-y[i];
				g=gcd(tmp.fi,tmp.se);
				tmp.fi/=g;
				tmp.se/=g;
				mp2.pb(tmp);
				tmp2[i]=tmp;
			}
			sort(all(mp2));
			for(i=1;i<=n;i++)
			{
				tmp=tmp2[i];
				swap(tmp.fi,tmp.se);
				tmp.fi=-tmp.fi;
				ans1+=upper_bound(all(mp2),tmp)-lower_bound(all(mp2),tmp);
				ans2+=upper_bound(all(mp[i]),tmp)-lower_bound(all(mp[i]),tmp);
				tmp.fi=-tmp.fi;
				tmp.se=-tmp.se;
				ans1+=upper_bound(all(mp2),tmp)-lower_bound(all(mp2),tmp);
				ans2+=upper_bound(all(mp[i]),tmp)-lower_bound(all(mp[i]),tmp);
			}
			printf("%d\n",ans1/2+ans2);
		}
	}
}
