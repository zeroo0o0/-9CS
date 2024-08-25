/*
��dis[v]��ʾv���ϵĵ㵽�����������Ȩֵ(�϶������������е�ĳ���㵽�����) ��������������ۼӺ� 
��������(x,y)�����ߵ�ʱ��,����ȨֵΪw,�Լ���ĿǰΪֹ�߹������Ȩֵ��cur ���cur<0,��ô��
��Ҫ֮ǰ��·����,ֱ�Ӽ���cur��***because aһ����>=1�ģ��� ��������֮ǰ��·������ȥ�ͺá� ��������̰�ĵ������dis[v]�� 
���dis[x]>a[x]��ô���Լ�����������нڵ㶼Ҫɾ��(��ΪҪ��Ҷ�ӽڵ㿪ʼɾ) 
���dis[x]<=a[x]��ô�Ϳ��Ա���������ˡ���������ȥ�����Ա����ĵ�ĸ���������������Ҫɾ���ĸ����ˡ�
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
const int maxn=1e5+5;
//int vis[maxn]; �����ò��ϣ���pre��¼�����͹��� 
vector<vector<pii>>e(maxn);
int cnt, a[maxn];

void dfs(int u, int now, int pre)
{
	if(now>a[u]) return;
	cnt++;
	for(auto t:e[u])
	{
		int v=t.first, w=t.second;
		if(v==pre) continue;
		dfs(v,max(0LL,now+w),u);//[Error] no matching function for call to 'max(int, long long int)'
	}
}

void solve()
{
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-1;i++) 
	{
		int u=i+1, v, w; cin>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dfs(1,0,-1);
	cout<<n-cnt;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
