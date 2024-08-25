/*
��������·����������һ�Ҫ����ֵ�����С��·�����ҵĽ��������Ϊÿ��������һ�� vector��
�洢�� 1 �ŵ㵽����������ֵ�����С��·��������⵽���̵�·��ʱ
һ���滻Ϊ���̵�·�������� dist ���飬������⵽ͬ�����ȵ�·��ʱ������ֵ����С�����滻·����
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
const int maxn=1e5+5;
struct node{
	int v,dis; //���㣬���� 
	bool operator<(node b) const  //warn***const ������ //***������bool 
	{
		return dis>b.dis;
	}
};

int dis[maxn], vis[maxn];
vector<vector<node>>e(maxn);
vector<set<int>>s(maxn);
map<pii,int>d;
int cnt, n,m;
vector<vector<int>>ans(100);

void dfs(int v)
{
	if(v==0)
	{
		reverse(ans[cnt].begin(),ans[cnt].end()); //���յ㿪ʼ���	
		return;
	}
	for(auto u:s[v])
	{
		if(dis[u]+d[{u,v}]!=dis[v])  //***warn:dis[0]  ����� 
			continue;
		if(u!=0) ans[cnt].push_back(u);
		dfs(u);
		cnt++;
		ans[cnt].push_back(n); //warn***
	}
} 

bool cmp(vector<int> a, vector<int> b)
{
	for(int i=0;i<min(a.size(),b.size());i++)
		if(a[i]<b[i]) return true;
	return false;
}

void solve()
{
	cin>>n>>m;
	for(int i=0;i<m;i++) 
	{
		int u,v,w; cin>>u>>v>>w;
		e[u].push_back(node{v,w}); //warn***ȨֵҲҪ��ѽ 
		e[v].push_back(node{u,w}); //***warn {u,w}
		d[{u,v}]=d[{v,u}]=w;
	} 
	memset(dis,0x3f3f,sizeof(dis));
	dis[1]=0; //warn***��ʼ�� 
	dis[0]=0; //***warn
	priority_queue<node>q;
	q.push(node{1,0});
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		int u=t.v;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto temp:e[u])
		{
			int v=temp.v;
			if(!vis[v]&&dis[v]>=dis[u]+temp.dis)
			{
				dis[v]=dis[u]+temp.dis; //***warn ���°� 
				q.push(node{v,dis[v]});
				s[v].insert(u);
			}
		}
	}
	if(dis[n]==INF) cout<<-1<<endl;
	else{
		ans[0].push_back(n); //warn***
		s[1].insert(0); //warn insert0
		dfs(n); //˳�����ϣ��ҳ����д� 
		sort(ans.begin(),ans.begin()+cnt,cmp);
		for(auto u:ans[0]) cout<<u<<" ";
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
