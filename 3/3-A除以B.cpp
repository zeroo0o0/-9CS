#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
/*
˼·
1.Сѧ�ĳ����㷨
2.�ύ���и����⣬����������û����֮������һλ�����������⣬��������һ�����У���ȫ����
*/

void solve()
{
	string a; int b; cin>>a>>b;
	vector<int> ans;
	int r=0; //���� 
	for(int i=0;i<a.size();i++)
	{
		r=r*10+a[i]-'0';
		ans.push_back(r/b);
		r%=b;
	}
	int i=0;
	while(ans[i]==0&&i<ans.size()) i++;
	if(i==ans.size()) cout<<0;
	else while(i<ans.size()) cout<<ans[i++];
	cout<<" "<<r<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
