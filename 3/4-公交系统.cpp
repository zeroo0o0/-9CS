/*
˼·����
���ϳ��Ĺ����У��ϳ������������ֵ�����ϵ�ԭʼ�������ϸ����ֵ���ᳬ����������ؿ�����
�³������������ֵ�����ϵ�ԭʼ��������С�ڸ����ֵ
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
	int n,w; cin>>n>>w;
	int sum=0,mn=0,mx=0; 
	for(int i=0;i<n;i++)
	{
		int x; cin>>x;
		sum+=x;
		if(sum>mx) mx=sum;
		if(sum<mn) mn=sum;
	}
	/*
	����������ʽ (ע�⣺min<0)
	0<= min+i <=w ,0<= max+i <=w
	==>-min<= i <=w-max
	+1 because: 0<=i<=2 0,1,2 ==3
	*/
	int ans=w-mx+mn+1;
	if(ans>0) cout<<ans<<endl;
	else cout<<0<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
