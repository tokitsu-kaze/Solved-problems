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
const int MAX=1e6+10;
//const ll mod=998244353;
/*********************************  head  *********************************/
ll mod;
struct Matrix
{
	ll c[4][4],n;
	Matrix(){}
	Matrix(ll a,ll v=0)
	{
		int i,j;
		n=a;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=v;
			}
		}
	}
	Matrix operator *(const Matrix &b)const
	{
		int i,j,k;
		Matrix res(n);
		for(k=0;k<n;k++)
		{
			for(i=0;i<n;i++)
			{
				if(!c[i][k]) continue;
				for(j=0;j<n;j++)
				{
					res.c[i][j]+=c[i][k]*b.c[k][j];
					if(res.c[i][j]>=mod) res.c[i][j]%=mod;
				}
			}
		}
		return res;
	}
};
Matrix matpow10(Matrix a,int *b,int n)
{
	Matrix res(a.n);
	for(int i=0;i<a.n;i++)
	{
		res.c[i][i]=1;
	}
	for(int i=n;i>=1;i--)
	{
        for(int j=1;j<=b[i];j++) res=res*a;
        Matrix tmp=a;
        a=a*a;
		a=a*a;
		a=a*a;
		a=a*tmp*tmp;
    }
	return res;
}
int trans(char *s,int n,int *res)
{
    for(int i=1;i<=n;i++) res[i]=s[i]-'0';
    res[n]--;
    for(int i=n;i>=1;i--)
    {
        if(res[i]<0)
        {
			res[i-1]+=res[i];
			res[i]=10+res[i];
		}
        else break;
	}
    return n;
}
char s[MAX];
int t[MAX];
void go()
{
	ll a,b,x0,x1,i;
	int len;
	while(read(x0,x1,a,b))
	{
		read(s+1);
		read(mod);
		Matrix tmp(2),res(2);
		tmp.c[0][0]=a;
		tmp.c[0][1]=b;
		tmp.c[1][0]=1;
		res.c[0][0]=x1;
		res.c[1][0]=x0;
		len=strlen(s+1);
		len=trans(s,len,t);
		res=matpow10(tmp,t,len)*res;
		printf("%lld\n",res.c[0][0]);
	}
}
