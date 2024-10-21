#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define ull unsigned long long

ll n;

void solve()
{
	cin>>n;
	ll a,b;
	if(n==1)a=7,b=6;
	if(n==2)a=11,b=9;
	if(n==3)a=7,b=4;
	if(n>3)
	{
		if(n%2)a=3,b=n^(ll)3;
		else a=2,b=n^(ll)2;
	}
	cout<<a<<" "<<b<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	freopen("D:\\1.in","r",stdin); //输入重定向，输入数据将从D盘根目录下的in.txt文件中读取 
	int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
} 
