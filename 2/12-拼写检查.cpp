//��ʱ������ؽ���ģ��  Ҳ�Ǻð취  //�ֵ�str����һ�ַ�==�Լ�ɾһ���ַ� 
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<string>v; //�ֵ�

bool erase_insert(string s1,string s2)
{
//	cout<<abs(int(s1.size()-s2.size()))<<endl; //warn***����ǿתint ����s1.size()-s2.size()����� 
	if(abs(int(s1.size()-s2.size()))!=1) return false;
	if(s1.size()<s2.size()) swap(s1,s2);
	for(int i=0;i<s1.size();i++)
	{
		string temp=s1;
		temp.erase(i,1); //***warn ������������������ʼ�±�   ���� 
		if(temp==s2) return true; //***warn ��һ�����㼴�� 
	} 
	return false;
}

bool replace(string s1,string s2)
{
	if(s1.size()!=s2.size()) return false;
	int cnt=0;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s2[i]) cnt++;
	}
	return cnt==1;
}

void solve()
{
	string s;
	while(cin>>s&&s!="#") v.push_back(s);
	while(cin>>s&&s!="#") //���� 
	{
		cout<<s;
		if(find(v.begin(),v.end(), s)!=v.end())
		{
			cout<<" is correct"<<endl;
			continue;
		}
		cout<<": "; //warn ����ȷ����"��" 
		for(auto u:v)
		{
			if(erase_insert(u,s)||replace(u,s))
				cout<<u<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
