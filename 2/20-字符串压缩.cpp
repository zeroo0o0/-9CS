/*
����b��һ��С��a����Ҫ���������ַ���ɵ��Ӵ������������е����ַ���
Ҳ�п�������չ����Ŀǰ����Ӵ���ȴʹ�ú����޷���������ŵ��Ӵ������ֲ�����δ����ȫ�����š�
t1t2...ti-1ti�ĳ����ǹ̶��ģ�Ϊi��
t1t2...ti-1�ĳ���ֻ�д��ڵ���ti�ĳ��Ȳ��п��ܰ���ti���Ӵ���
��˼�Ϊÿ��һ���ַ�������������ַ���ǰ���ַ���һ��Ϊ����
������п�������Ӵ��������ֱ�Ӽ��ַ��Ĵ��۽��жԱȡ�
dp[0]=a
dp[i]=dp[j-1]+b(i>0,j<=i,j\geq\left \lceil (i+1)/2 \right \rceil,������j~iΪ0~j-1���Ӵ�)
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn=5005;
int dp[maxn];

void solve()
{
	int n, a, b; cin>>n>>a>>b;
	string s; cin>>s;
	dp[1]=a;
	for(int i=2;i<=s.size();i++) //len
	{
		dp[i]=dp[i-1]+a;
		string ss=s.substr(0,i);
		for(int j=(i+1)/2;j<i;j++) //�ָ�� 
		{
			string left=s.substr(0,j); //0~j-1
			string right=s.substr(j,i-j); //warn: ��j��ʼ  //j~i-1
			if(left.find(right)!=-1&&dp[j]+b<dp[i]) dp[i]=dp[j]+b; 	//warn dp[j] not dp[j-1] ��Ϊ����Ϊj
		}
	}
	cout<<dp[n]<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
