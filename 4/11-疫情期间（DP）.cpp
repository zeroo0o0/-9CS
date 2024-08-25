/*
dp[i][j] ��ʾ��i�����˻j���õ�����С��Ϣ����
0��Ϣ��1��̣�2����, ��ȫ����ʼ��Ϊ�ܴ������
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 0x3f3f3f3f

void solve()
{
	int n; cin>>n;
	int day[n];
	for(int i=0;i<n;i++) cin>>day[i];
	int dp[n][3];
//	memset(dp,0x3f,sizeof(dp));//warn ��ά���鲻����ô��ʼ�� //dp[i][j] 0��Ϣ��1��̣�2���� 
	for(int i=0;i<n;i++) //warn*** i<n
		for(int j=0;j<3;j++) dp[i][j]=INF;

	if(day[0]==1) dp[0][1]=0;
	if(day[0]==2) dp[0][2]=0;
	if(day[0]==3)
	{
		dp[0][1]=0;
		dp[0][2]=0;
	}
	dp[0][0]=1;
	
	for(int i=1;i<n;i++) //0��  1����  2����  3���� 
	{
		if(day[i]==1) dp[i][1]=min(dp[i-1][2],dp[i-1][0]); //warn ���¾��� 
		if(day[i]==2) dp[i][2]=min(dp[i-1][1],dp[i-1][0]);
		if(day[i]==3)
		{
			dp[i][1]=min(dp[i-1][2],dp[i-1][0]);
			dp[i][2]=min(dp[i-1][1],dp[i-1][0]);
		}
		dp[i][0]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+1;
	}
	int ans=min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
	cout<<ans<<endl;
}

int main() 
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
