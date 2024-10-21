#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
void solve()
{
	cin>>n;
	if(n==1)cout<<"7 6\n";
	if(n==2)cout<<"11 9\n";
	if(n==3)cout<<"7 4\n";
	if(n>3)
	{
		if(n%2)cout<<3<<" "<<(n^(ll)3)<<"\n";
		else cout<<2<<" "<<(n^(ll)2)<<"\n";
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
	return 0;
} 
