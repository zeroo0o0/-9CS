#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	string s1,s2; cin>>s1>>s2;
	int l1=s1.size(),l2=s2.size();
	string t=s1;
	int cnt=0;
	for(int i=0;i<s2.size();i++)
	{
		int pos=t.find(s2[i]);
		if(pos!=-1)
		{
			cnt++; t.erase(pos,1);
		}
	}								//warn��s1.size-s2.size 
	if(cnt==s2.size()) cout<<"Yes"<<" "<<s1.size()-s2.size()<<endl; //warn��s2.size()-s1.size()����ֱ�����  ���Ǹ��������з������λ1�ᱻ���� 
	else cout<<"No"<<" "<<s2.size()-cnt<<endl;
//	cout<<(int)(s2.size()-s1.size())<<endl; //(int) ǿתint���Ծ������������Ĵ��� 
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
