#include<bits/stdc++.h> //DP �������� 
using namespace std;
double q; int n;
int flag[35];
const int times=100; //time ������������  //***warn ֻ����100���ᶪʧ���ȣ���Ҫ����ĿҪ���һλ 

void solve()
{
	q*=1000;
	vector<int>v; //warn Ƕ�� vector<double>
	memset(flag,-1,sizeof(flag)); //***Ҫ�жϷ�Ʊ�Ƿ�ɱ��� 
	for(int i=0;i<n;i++)
	{
		int num; cin>>num;
		double sum=0;
		while(num--)
		{
			char a,b; double c; //��Щ��Ʊ���ɱ��� 
			cin>>a>>b>>c;
			sum+=c;
			if(a!='A'&&a!='B'&&a!='C') flag[i]=0; 
			if(c>600) flag[i]=0;
		}
		if(sum>1000) flag[i]=0;
		if(flag[i]) v.push_back(sum*1000);
	}
	sort(v.begin(),v.end());
	int dp[(int)q+5]; //warn q
	memset(dp,0,sizeof(dp));
	int ans=0;
	for(int i=0;i<v.size();i++)
		for(int j=q;j>=v[i];j--) //warn j--
		{
			if(v[i]>j) break;
			dp[j]=max(dp[j],dp[j-v[i]]+v[i]);  //dp 
			ans=max(ans,dp[j]);
		}
	cout<<fixed<<setprecision(2)<<(double)ans/1000<<endl;  //ǿת 
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	while(cin>>q>>n&&n) solve();
	return 0;
}
