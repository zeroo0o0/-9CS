/*
����˼·
��(x+a1)��ʼ��ÿ�γ���(x+ai)��ֱ��(x+an)��ÿ�θ���չ��ʽ��ϵ��������biһһ�Ƚϡ�
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
int a[25], b[25], c[25];

void solve()
{
	int n;
	while(cin>>n&&n)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=n-1;i>=0;i--) cin>>b[i];
		b[n]=1;
		c[0]=a[1],c[1]=1; //��ʼ����һ�� (x+a1)
		for(int i=2;i<=n;i++) //һ��һ���������� 
		{
			c[i]=1; //warn��������ߴ��� 
			for(int j=i-1;j>0;j--) //***warn: i-1 not n-1 ����i�η�֮ǰ�����дη�  ��Ϊn-1����=i 
				c[j]=c[j]*a[i]+c[j-1];
			c[0]*=a[i];
		}
		int cnt=0;
		for(int i=0;i<=n-1;i++) if(b[i]==c[i]) cnt++;
		if(cnt==n) cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
