/*
˼·
1.�ܾ���Ķ�̬�滮���⣬Ҳ���ǲ��ϵؼ�����ѽ�����Ӷ��õ���ǰ����ѽ����
2.��̬�滮����Ҫ�ľ����ҵ�״̬ת�Ʒ���dp[I]=max(dp[i],dp[j]+1)
3.��2�ķ������ǿ����ҵ���i+1ö����Ϊ���һ��������ܹ����ض��ٷ�����ô��i+2öͬ�������ֵ
4.������Ǳ����ҳ�dp�е����ֵ�Ϳ��Եõ����ǵ�������ص�������
�����⶯̬�滮�� 
����˵�����ǰѴ����⻯ΪС���⣬�ҵ�С����Ľ���������ϳɴ�����Ľ��������
��¼С��������Ž���������Ա��ڻ���Ѱ�ң�����ʱ�临�Ӷȡ�
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	int k; cin>>k;
	vector<int>h(k),dp(k); 
	for(int i=0;i<k;i++)
	{
		cin>>h[i];
		dp[i]=1;
	}
	for(int i=0;i<k;i++)
		for(int j=0;j<i;j++)
			if(h[j]>=h[i]) dp[i]=max(dp[i],dp[j]+1); 
	int mx=0; 
	for(int i=0;i<k;i++) mx=max(dp[i],mx);  //warn��dp��i���Ǳ�����i�ģ������̫��Ͳ�һ�������Ž� 
	cout<<mx;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
