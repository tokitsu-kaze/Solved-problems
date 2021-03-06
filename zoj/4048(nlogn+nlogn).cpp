#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
	#define BUF_SIZE 100000
	#define OUT_SIZE 100000
	//fread->read
	bool IOerror=0;
//	inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
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
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
using namespace __gnu_cxx;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VL;
void go();
int main(){
	#ifdef tokitsukaze
		freopen("TEST.txt","r",stdin);
	#endif
	go();return 0;
}
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
struct node
{
	int to;
	ll w;
	node(){}
	node(int _to,ll _w) :to(_to),w(_w){}
};
ll dis[MAX],disred[MAX];
int path[2*MAX],deep[2*MAX],first[MAX],tot;
int dp[2*MAX][20];
bool flag[MAX];
vector<node> mp[MAX];
void dfs(int x,int pre,int h)
{
	int i;
	path[++tot]=x;
	first[x]=tot;
	deep[tot]=h;
	for(i=0;i<mp[x].size();i++)
	{
		int to=mp[x][i].to;
		if(to==pre) continue;
		disred[to]=min(disred[to],disred[x]+mp[x][i].w);
		dis[to]=dis[x]+mp[x][i].w;
		dfs(to,x,h+1);
		path[++tot]=x;
		deep[tot]=h;
	}
}
void ST(int n)
{
	int i,j,x,y;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=i;
	}
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			x=dp[i][j-1];
			y=dp[i+(1<<(j-1))][j-1];
			dp[i][j]=deep[x]<deep[y]?x:y;
		}
	}
}
int query(int l,int r)
{
	int len,x,y;
	len=(int)log2(r-l+1); 
	x=dp[l][len];
	y=dp[r-(1<<len)+1][len];
	return deep[x]<deep[y]?x:y;
}
int LCA(int x,int y)
{
	int l,r,pos;
	l=first[x];
	r=first[y];
	if(l>r) swap(l,r);
	pos=query(l,r);
	return path[pos];
} 
int getdist(int a,int b)
{
	return dis[a]+dis[b]-2*dis[LCA(a,b)];
}
void work(int n)
{
	int i;
	for(i=1;i<=n;i++) dis[i]=0;
	tot=0;
	dfs(1,0,0);
	ST(2*n-1);
}
int tmp[MAX];
void go()
{
	int t,n,m,q,i,a,b,w,k;
	ll l,r,mid;
	read(t);
	while(t--)
	{
		read(n,m,q);
		for(i=1;i<=n;i++)
		{
			mp[i].clear();
			disred[i]=LLINF;
		}
		while(m--)
		{
			read(a);
			disred[a]=0;
		}
		for(i=1;i<n;i++)
		{
			read(a,b,w);
			mp[a].pb(node(b,w));
			mp[b].pb(node(a,w));
		}
		work(n);
		while(q--)
		{
			read(k);
			l=r=0;
			for(i=1;i<=k;i++)
			{
				read(tmp[i]);
				r=max(r,dis[tmp[i]]);
			}
			VI res;
			auto check=[&](ll x)->int
			{
				res.clear();
				for(i=1;i<=k;i++)
				{
					if(disred[tmp[i]]>x) res.pb(tmp[i]);
				}
				if(sz(res)<=1) return 1;
				int lca=res[0];
				for(i=1;i<sz(res);i++) lca=LCA(lca,res[i]);
				for(i=0;i<sz(res);i++)
				{
					if(dis[res[i]]-dis[lca]>x) return 0;
				}
				return 1;
			};
			while(l<r)
			{
				mid=(l+r)>>1;
				if(check(mid)) r=mid;
				else l=mid+1;
			}
			printf("%lld\n",l);
		}
	}
}