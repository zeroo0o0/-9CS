#include<bits/stdc++.h>
using namespace std;
#define pii pair<char,char>
map<pii,int>m;
/*
˼·
1.����ܼ򵥣���B��ߵ������žͿ�����
2.��߳���������Ҫ--����Ϊ������Ӵ��ǿյ�
3.�ܶ���֮��������ߵ������ż�ȥ��ߵ������žͿ�����
*/
/*
������ ���������ɾ���պ��� 
*/

void solve()
{
	string s;
	string s0="()";
	while(cin>>s)
	{
//		cout<<s<<endl;  //warn��ע�Ͳ��Դ��� 
		while(s.find(s0)!=-1) s.erase(s.find(s0),2);
		int ans=s.find('B');
		cout<<ans<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	m[{'(',')'}]=1;
	solve();
	return 0;
}
