#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int m,n; cin>>m>>n;
	string s=to_string(n);
	for(int i=1;i<=m;i++)
	{
		if(i%n==0)
		{
			cout<<i<<" ";
			continue;
		}
		string temp=to_string(i);
		if(temp.find(s)!=-1) cout<<i<<" "; //warn �Ҳ�������-1 
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
