#include<bits/stdc++.h>   //����ṹ�� 
using namespace std;
#define endl '\n'
struct node{ 
	vector<int>v;  //���У�����ȥ����  // 
	//�Ż�������Ͱ����
	int rank[105]; 
	int score;
};
map<string,node>m;
#define pii pair<string,node> //warn pair<string,node>
vector<pii>v;   
int scores[]={0,25,18,15,12,10,8,6,4,2,1};

bool cmp1(pii a,pii b)
{
	if(a.second.score!=b.second.score) return a.second.score>b.second.score; //warn �Ż� 
	for(int i=1;i<=100;i++)
	{
		if(a.second.rank[i]!=b.second.rank[i]) 
			return a.second.rank[i]>b.second.rank[i];
	}
}

bool cmp2(pii a,pii b)
{
	//����copy�㷨�ڿ���ʱ��Ŀ�������ǵ���ǰ���ٿռ�
	vector<int>vt;
//	vt.resize(a.second.v.size());
	copy(a.second.v.begin(),a.second.v.end(),vt.begin());
//	vt.assign(a.second.v.begin(),a.second.v.end());
//	vt=a.second.v;
//	vt.clear();
//	vector<int>va(a.second.v); vector<int>vb(b.second.v); 
	if(a.second.rank[1]!=b.second.rank[1]) 
		return a.second.rank[1]>b.second.rank[1];
	if(a.second.score!=b.second.score) return a.second.score>b.second.score; //warn �Ż� 
	for(int i=2;i<=100;i++) 
	{
		if(a.second.rank[i]!=b.second.rank[i]) 
			return a.second.rank[i]>b.second.rank[i];
	}
}

void solve()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		for(int i=1;i<=n;i++)
		{
			string s; cin>>s;
			m[s].rank[i]++;
			if(i<=10) m[s].score+=scores[i];
		}
	}
//	cout<<endl;
	for(auto u:m) v.push_back({u.first,u.second});
	sort(v.begin(),v.end(),cmp1);
//	for(auto u:v)
//	{
//		cout<<u.first<<" "<<u.second.score<<endl;
//		auto vtemp=u.second.v;
//		for(int i=0;i<vtemp.size();i++) cout<<vtemp[i]<<" ";
//		cout<<endl;
//	}
	cout<<v[0].first<<endl;
	//2
//	cout<<endl;
	sort(v.begin(),v.end(),cmp2);
//	for(auto u:v)
//	{
//		cout<<u.first<<" "<<u.second.score<<endl;
//		auto vtemp=u.second.v;
//		for(int i=0;i<vtemp.size();i++) cout<<vtemp[i]<<" ";
//		cout<<endl;
//	}
	cout<<v[0].first<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int t=1; 
	while(t--) solve();
	return 0;
}
