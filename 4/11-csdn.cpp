#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	int day[n];//ai
	for(int i=0; i<n; i++) {
		cin>>day[i];
	}
	int dp[n][3];//0��� 1�˶� 2��Ϣ,dp[i][j]��ʾ��i+1��(dp[0]��ʾ��1��)Ϊj״̬,��ʱ��Ϣ����������
	for(int i=0; i<n; i++)
		for(int j=0; j<3; j++)dp[i][j]=INT_MAX;

	if(day[0]==1)dp[0][0]=0;//����1���̣���Ϣ0��
	if(day[0]==2)dp[0][1]=0;//����1���˶�����Ϣ0��
	if(day[0]==3) {//����1���̻��˶�
		dp[0][1]=0;//ѡ��̣���Ϣ0��
		dp[0][0]=0;//ѡ�˶�����Ϣ0��
	}
	dp[0][2]=1;//����1����Ϣ����Ϣ1��

	for(int i=1; i<n; i++) {
		if(day[i]==1)dp[i][0]=min(dp[i-1][1],dp[i-1][2]);//����̣�����һ��ֻ���˶�����Ϣ
		if(day[i]==2)dp[i][1]=min(dp[i-1][0],dp[i-1][2]);//���˶�������һ��ֻ�ܱ�̻���Ϣ
		if(day[i]==3) {//����̻��˶�
			dp[i][0]=min(dp[i-1][1],dp[i-1][2]);//ѡ���
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);//ѡ�˶�
		}
		dp[i][2]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;//����Ϣ������һ�����߾���
	}
	int result=min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));//���Ϊ���һ������״̬����Сֵ
	cout<<result;
}

