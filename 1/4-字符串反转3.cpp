#include<bits/stdc++.h>
using namespace std;

void solve()
{
//	cin.ignore(); //warn�� ������Ի��з� 
	string s;
	getline(cin,s);
	stringstream ss(s);
	string buf;
	while(ss>>buf)
	{
		reverse(buf.begin(),buf.end());
		cout<<buf<<" ";
	}
	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0); //warn ������ͬ��  ��һ�㳬ʱ 
	int t; cin>>t; 
	cin.ignore();  //warn��cin��getline֮�������Ի��з� 
	while(t--) solve();
	return 0;
}
