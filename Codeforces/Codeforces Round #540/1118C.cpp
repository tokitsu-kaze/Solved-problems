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
void println(VI x){for(int i=0;i<sz(x);i++) printf("%d%c",x[i]," \n"[i==sz(x)-1]);}
void println(VL x){for(int i=0;i<sz(x);i++) printf("%lld%c",x[i]," \n"[i==sz(x)-1]);}
template<class T> void read(T *x,int l,int r){for(int i=l;i<=r;i++) read(x[i]);}
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
const int MAX=2e5+10;
const ll mod=998244353;
/*********************************  head  *********************************/
int mp[22][22];
void go()
{
	int n,i,j,cnt[1010],x,y,flag,tmp,odd,xx,yy;
	while(read(n))
	{
		mem(cnt,0);
		for(i=0;i<n*n;i++)
		{
			read(x);
			cnt[x]++;
		}
		flag=1;
		tmp=0;
		odd=0;
		for(i=1;i<=1000;i++)
		{
			if(cnt[i])
			{
				if(n&1)
				{
					if(cnt[i]%4==2)
					{
						if(tmp<n-1) tmp++;
						else flag=0;
					}
					else if(cnt[i]%4==1)
					{
						if(!odd) odd++;
						else flag=0;
					}
					else if(cnt[i]%4==3)
					{
						if(!odd) odd++;
						else flag=0;
						if(tmp<n-1) tmp++;
						else flag=0;
					}
					else flag&=(cnt[i]%4==0);
				}
				else flag&=(cnt[i]%4==0);
			}
		}
		mem(mp,-1);
		if(n&1)
		{
			for(i=0;i<n;i++) mp[i][n/2]=mp[n/2][i]=-2;
		}
		if(n&1)
		{
			if((n-1-tmp)%2!=0||odd!=1||!flag)
			{
				puts("NO");
				continue;
			}
			puts("YES");
			x=y=0;
			xx=0;
			yy=n/2;
			tmp=n-1-tmp;
			for(i=1;i<=1000;i++)
			{
				if(!cnt[i]) continue;
				if(cnt[i]%4==1||cnt[i]%4==3)
				{
					cnt[i]--;
					mp[n/2][n/2]=i;
				}
				if(cnt[i]%4==2)
				{
					cnt[i]-=2;
					if(xx==n-1-xx)
					{
						if(yy==n/2) yy=0;
						mp[xx][yy]=mp[n-1-xx][n-1-yy]=i;
						yy++;
					}
					else
					{
						mp[xx][yy]=mp[n-1-xx][yy]=i;
						xx++;
					}
				}
				while(tmp>0&&cnt[i]%4==0&&cnt[i]>0)
				{
					tmp-=2;
					cnt[i]-=4;
					if(xx==n-1-xx)
					{
						if(yy==n/2) yy=0;
						mp[xx][yy]=mp[n-1-xx][n-1-yy]=i;
						yy++;
					}
					else
					{
						mp[xx][yy]=mp[n-1-xx][yy]=i;
						xx++;
					}
					if(xx==n-1-xx)
					{
						if(yy==n/2) yy=0;
						mp[xx][yy]=mp[xx][n-1-yy]=i;
						yy++;
					}
					else
					{
						mp[xx][yy]=mp[n-1-xx][yy]=i;
						xx++;
					}
				}
				while(cnt[i]>0)
				{
					cnt[i]-=4;
					while(mp[x][y]!=-1)
					{
						y++;
						if(y==n)
						{
							y=0;
							x++;
						}
					}
					mp[x][y]=mp[n-x-1][n-y-1]=mp[x][n-y-1]=mp[n-x-1][y]=i;
				}
			}
		}
		else
		{
			if(!flag)
			{
				puts("NO");
				continue;
			}
			puts("YES");
			x=y=0;
			for(i=1;i<=1000;i++)
			{
				while(cnt[i]>0)
				{
					cnt[i]-=4;
					while(mp[x][y]!=-1)
					{
						y++;
						if(y==n)
						{
							y=0;
							x++;
						}
					}
					mp[x][y]=mp[n-x-1][n-y-1]=mp[x][n-y-1]=mp[n-x-1][y]=i;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				printf("%d%c",mp[i][j]," \n"[j==n-1]);
			}
		}
	}
}
