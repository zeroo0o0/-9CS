/*
��˼·�� 
һ�������Ķ�̬�滮�⡣���õ��ǵݹ���⣬û�н���ά���飨���Ա���·�����ڵ���鷳��
�е����������������Ĵ��淽������һ��һά���鴢������������������Ϊ0������Ϊ1��
�����ӣ�ÿ����������ӽڵ��������������+���������ߣ�������+����+1��
��¼·����path�����ڵݹ�ʱ���桾���ֵ·������ÿ����ѡ����ӽ�㣬һ����һ�������������~
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
int a[100000],path[100000], size, n;

int dfs(int now, int floor) //����  ����   �����ӽڵ��������������+���������ߣ�������+����+1��
{
	if(floor==n) return a[now];
	int left=a[now]+dfs(now+floor,floor+1);
	int right=a[now]+dfs(now+floor+1,floor+1);
	if(left>right) path[now]=now+floor;
	else path[now]=now+floor+1;
	return max(left,right);
}


void solve()
{
	cin>>n;
	size=n*(n+1)/2;
	for(int i=0;i<size;i++) cin>>a[i]; //warn**<size
	int ans=dfs(0,1);
	cout<<ans<<endl;
	int cnt=0, now=0;
	while(cnt<n)
	{
		cout<<a[now]<<" ";
		now=path[now];
		cnt++;
	}
}


signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
