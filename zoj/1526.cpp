#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#define INF 0x3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define MAX 100000+10
using namespace std;
typedef long long ll;
int main()
{
    int t,n,i;
    double s;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>n;
			s=0;
			for(i=2;i<=n;i++)
			{
				s+=log10(i*1.0);
			}
			cout<<int(s)+1<<endl;
		}
	} 
    return 0;
}