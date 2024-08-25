#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn=100000+5;
vector<vector<int>>e(maxn);

double Expect(int u=1, int p=-1) //Ĭ��ֵ  //����  ���ڵ� 
{				//***warn  uӦ�ô�1��ʼ����0��ʼ��û�� 
	double expect=0;
	for(auto v:e[u])
		if(v!=p) expect+=Expect(v,u)+1;
	if(expect) return expect/(e[u].size()-(p!=-1)); //***warn: +1 //���ڴ˴��ż�1��Ҷ�ӵĸ��ڵ�expect��Ϊ0 
	else return 0;
} 

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	double ans=Expect();
	cout<<fixed<<setprecision(7)<<ans;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
