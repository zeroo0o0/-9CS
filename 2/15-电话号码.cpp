#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
map<string,set<string>>m;
map<string,vector<string>>ans;

bool check(string str, string suffix) { //***�жϺ�׺
    if (suffix.length() > str.length()) return false; 
    return (str.rfind(suffix) == (str.length() - suffix.length()));
}

bool cmp(string a, string b)
{
	if(a.size()!=b.size()) return a.size()<b.size(); 
	return a<b;
}

void solve()
{
	int n; cin>>n;
	cin.get(); //warn�� getline֮�䲻��Ҫget���� 
	for(int i=0;i<n;i++) //warn ���� �ڶ��������Ǹ��� 
	{
		string name; cin>>name;
		int x; cin>>x;
		for(int i=0;i<x;i++) 
		{
			string s; cin>>s;
			m[name].insert(s);
		}
	} 
	for(auto u:m)
	{
		vector<string>temp;
//		if(u.second.size()!=0)  //���ܵ���0  
		for(auto v:u.second) //temp.push_back(v);
		{
			bool flag=1;
			for(auto t:u.second) 
			  if(t!=v&&check(t,v)) flag=0; //warn: f(check(t,v))��������һ����������ͬ�� 
			if(flag) temp.push_back(v);
		}
		sort(temp.begin(),temp.end(),cmp);
		ans[u.first]=temp;	
	}
	cout<<ans.size()<<endl;
	for(auto u:ans)
	{
		cout<<u.first<<" ";
		auto v=u.second;
		cout<<u.second.size()<<" "; 
		for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
		cout<<endl; 
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
