#include <bits/stdc++.h>
using namespace std;
namespace fastIO{
    #define BUF_SIZE 100000
    #define OUT_SIZE 100000
    #define ll long long
    //fread->read
    bool IOerror=0;
//    inline char nc(){char ch=getchar();if(ch==-1)IOerror=1;return ch;} 
    inline char nc(){
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if(p1==pend){
            p1=buf;pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if(pend==p1){IOerror=1;return -1;}
        }
        return *p1++;
    }
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';}
    template <class T> inline bool read(T &x){
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
    template<typename T,typename... U>inline bool read(T& head,U&... tail){return read(head)&&read(tail...);}
    //fwrite->print
    struct Ostream_fwrite{
        char *buf,*p1,*pend;
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;}
    //    void out(char ch){putchar(ch);}
        void out(char ch){if(p1==pend){fwrite(buf,1,BUF_SIZE,stdout);p1=buf;}*p1++=ch;}
        template <class T>void print(T x){
            static char s[33],*s1;s1=s;
            if(!x)*s1++='0';if(x<0)out('-'),x=-x;
            while(x)*s1++=x%10+'0',x/=10;
            while(s1--!=s)out(*s1);
        }
        void print(double x,int y){
            static ll mul[]=
            {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,
            10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,
            100000000000000LL,1000000000000000LL,10000000000000000LL,100000000000000000LL};
            if(x<-1e-12)out('-'),x=-x;
            ll x2=(ll)floor(x);if(!y&&x-x2>=0.5)++x2;x-=x2;x*=mul[y];
            ll x3=(ll)floor(x);if(y&&x-x3>=0.5)++x3;print(x2);
            if(y>0){out('.');for(size_t i=1;i<y&&x3*mul[i]<mul[y];out('0'),++i);print(x3);}
        }
        void print(char *s){while(*s)out(*s++);}
        void print(const char *s){while(*s)out(*s++);}
        void flush(){if(p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}}
        ~Ostream_fwrite(){flush();}
    }Ostream;
    template <class T>void print(T x){Ostream.print(x);}
    inline void print(char x){Ostream.out(x);}
    inline void print(char *s){Ostream.print(s);}
    inline void print(const char *s){Ostream.print(s);}
    inline void print(double x,int y){Ostream.print(x,y);}
    template<typename T,typename... U>inline void print(const T& head,const U&... tail){print(head);print(tail...);}
    inline void flush(){Ostream.flush();}
    #undef ll
    #undef OUT_SIZE
    #undef BUF_SIZE
};
using namespace fastIO;
void Main();
int main(){
    #ifdef tokitsukaze
        freopen("TEST.txt","r",stdin);
    #endif
    Main();return 0;
}
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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
/*********************************  head  *********************************/
char mp[222][222];
void Main()
{
	int t,a,b,c,n,m,i,j;
	read(t);
	while(t--)
	{
		read(a,b,c);
		n=b*2+c*2+1;
		m=a*2+b*2+1;
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)mp[i][j]='.';
		for(i=1;i<=b;i++)
		{
			for(j=1;j<=a;j++)
			{
				mp[i*2-1][j*2+1+b*2-i*2]='+';
				mp[i*2-1][j*2+2+b*2-i*2]='-';
				mp[i*2-1][j*2+3+b*2-i*2]='+';
				mp[i*2][j*2+b*2-i*2]='/';
				mp[i*2][j*2+2+b*2-i*2]='/';
			}
		}
		for(i=1;i<=c;i++)
		{
			for(j=1;j<=a;j++)
			{
				mp[i*2+b*2-1][j*2-1]='+';
				mp[i*2+b*2-1][j*2]='-';
				mp[i*2+b*2-1][j*2+1]='+';
				mp[i*2+b*2][j*2-1]='|';
				mp[i*2+b*2][j*2+1]='|';
				mp[i*2+b*2+1][j*2-1]='+';
				mp[i*2+b*2+1][j*2]='-';
				mp[i*2+b*2+1][j*2+1]='+';
			}
		}
		for(i=1;i<=c;i++)
		{
			for(j=1;j<=b;j++)
			{
				mp[i*2+b*2-j*2][a*2+j*2+1]='|';
				mp[i*2+b*2-j*2+1][a*2+j*2+1]='+';
				mp[i*2+b*2-j*2+2][a*2+j*2]='/';
			}
		}
		for(i=1;i<=n;i++)
		{
			mp[i][m+1]='\0';
			print(mp[i]+1,'\n');
		}
	}
}
