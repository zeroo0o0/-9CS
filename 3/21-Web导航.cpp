#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
stack<string>s1,s2; //ǰ��  ���� 

void solve()
{
	string s;
	string url="http://www.game.org/";
	while(cin>>s&&s!="QUIT")
	{
		if(s=="BACK")
		{
			if(s2.empty()) 
			{
				cout<<"Ignored"<<endl;
				continue;
			}
			s1.push(url);
			url=s2.top();
			s2.pop();
		}
		if(s=="FORWARD")
		{
			if(s1.empty()) 
			{
				cout<<"Ignored"<<endl;
				continue;
			}
			s2.push(url);
			url=s1.top();
			s1.pop();
		}
		if(s=="VISIT")
		{
			s2.push(url); //warn*** ��ѹ�뵱ǰҳ�� 
			string u; cin>>u;
			url=u;
			s1=stack<string>(); //���ջ 
		}
		cout<<url<<endl;
	} 
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
