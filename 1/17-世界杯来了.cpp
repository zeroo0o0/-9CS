#include<bits/stdc++.h> //���㣺 �ṹ�� 
using namespace std;
#define endl '\n'
struct node{
	int score,win,ball;
};
#define pii pair<string,node>
bool cmp(pii a,pii b)
{
	if(a.second.score>b.second.score) return true; //Ϊ���� a��bǰ�� 
	if(a.second.score==b.second.score&&a.second.win>b.second.win) return true;
	if(a.second.score==b.second.score&&a.second.win==b.second.win&&a.second.ball>b.second.ball) return true; //ball not win
	else return false;
}

void solve()
{
	map<string,node>m;
	int n; cin>>n;
	for(int i=0;i<n;i++) 
	{
		string s;cin>>s;  //warn ��������string��������char�� 
	}
	for(int i=0;i<n*(n-1)/2;i++)
	{
		string s; int x,y; char d; cin>>s>>x>>d>>y;
		string a,c;
		int pos=s.find('-');
		a=s.substr(0,pos);
		c=s.substr(pos+1,s.size()-pos);
		if(y!=x)
		{
			if(y>x) swap(a,c),swap(x,y); //�����Ӯ 
			if(m.find(a)==m.end()) m[a].score=3; //!m[a] map<string,int>m; ������ 
			else m[a].score+=3;
			m[a].win+=x-y; //warn +=not = 
			m[c].win+=y-x; //warn  a,c ���� 
		}
		else
		{
			if(m.find(a)==m.end()) m[a].score=1;
			else m[a].score+=1;
//			m[a].win+=x-y; //��0���ø��� 
			if(m.find(c)==m.end()) m[c].score=1;
			else m[c].score+=1;
		}
		m[a].ball+=x;
		m[c].ball+=y;
	}

	vector<pii>v;
	set<string>s;
	for(auto u:m)	v.push_back({u.first,u.second});
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n/2;i++) s.insert(v[i].first); //warn ���ֵ����������
	for(auto u: s) cout<<u<<endl; 
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int t=1;
	while(t--) solve();
	return 0;
}
