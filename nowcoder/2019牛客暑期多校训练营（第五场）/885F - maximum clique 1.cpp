#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
//  inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;}
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
const int MAX=5000+10;
const ll mod=998244353;
/*********************************  head  *********************************/
struct Bipartite_Matching
{
	static const int N=5e3+10;
	int n,m;
	VI mp[N];
	int link[N],s[N];
	bool used[N],flag[N];
	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		for(int i=0;i<=n;i++) mp[i].clear();
	}
	void add_edge(int a,int b){mp[a].pb(b);}
	bool dfs(int x)
	{
		int i,to;
		flag[x]=1;
		for(i=0;i<sz(mp[x]);i++)
		{
			to=mp[x][i];
			if(used[to]) continue;
			used[to]=1;
			if(link[to]==-1||dfs(link[to]))
			{
				link[to]=x;
				s[x]=to;
				return 1;
			}
		}
		return 0;
	}
	int max_match()
	{
		int i,res;
		mem(link,-1);
		mem(s,-1);
		res=0;
		for(i=1;i<=n;i++)
		{
			if(!sz(mp[i])) continue;
			mem(used,0);
			if(dfs(i)) res++;
		}
		return res;
	}
	int min_cover(VI &x,VI &y)
	{
		int i,res;
		res=max_match();
		mem(flag,0);
		mem(used,0);
		x.clear();
		y.clear();
		for(i=1;i<=n;i++)
		{
			if(s[i]==-1) dfs(i);
		}
		for(i=1;i<=n;i++)
		{
			if(!flag[i]) x.pb(i);
		}
		for(i=1;i<=m;i++)
		{
			if(used[i]) y.pb(i);
		}
		return res;
	}
}bpm;
int a[MAX],can[MAX];
VI res[2];
void go()
{
	int n,i,cnt;
	while(read(n))
	{
		bpm.init(n,n);
		res[0].clear();
		res[1].clear();
		for(i=1;i<=n;i++)
		{
			read(a[i]);
			res[__builtin_popcount(a[i])&1].pb(i);
		}
		for(auto even:res[0])
		{
			for(auto odd:res[1])
			{
				if(__builtin_popcount(a[even]^a[odd])==1) bpm.add_edge(odd,even);
			}
		}
		res[0].clear();
		res[1].clear();
		cnt=bpm.min_cover(res[0],res[1]);
		VI ans;
		for(i=1;i<=n;i++) can[i]=1;
		for(auto it:res[0]) can[it]=0;
		for(auto it:res[1]) can[it]=0;
		for(i=1;i<=n;i++)
		{
			if(can[i]) ans.pb(a[i]);
		}
		assert(sz(ans)==n-cnt);
		printf("%d\n",sz(ans));
		println(ans);
	}
}
