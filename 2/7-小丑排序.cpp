#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
/*
1.����⿴�Ÿ��ӣ���ʵ�ܼ򵥰���������vector��¼����ż����Ϳ�����
2.������ֱ�������ż���ε������
*/

void solve()
{
	int n; int cnt=1;
	while(cin>>n&&n)
	{
		vector<string>va,vb;
		for(int i=1;i<=n;i++)
		{
			string s; cin>>s;
			if(i%2!=0) va.push_back(s); //warn ������ �ߴ������� 
			else vb.push_back(s);
		}
		cout<<"set-"<<cnt<<endl;
		for(int i=0;i<va.size();i++) cout<<va[i]<<endl;  //NB ż��λ������� 
		for(int i=vb.size()-1;i>=0;i--) cout<<vb[i]<<endl;
		cnt++;		
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
