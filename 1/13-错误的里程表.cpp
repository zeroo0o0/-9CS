#include<bits/stdc++.h>  //warn �ⲻ����һ���˽����� 
using namespace std;	//������������Ҫ��ϸ����Ŀ��Ѱ����ʾ 
#define endl '\n'
#define int long long 
/*
1.��̱�����3��8�޷���ʾ��Ҳ����˵������һ��λ��ֻ����0 1 2 4 5 6 7 9�˸����֡��ⲻ����һ���˽���������
2.�������Ȱ������ת��Ϊ�����İ˽�����(���� 19��ʵ��17)
3.Ȼ�����ǰ�����˽�����ת��Ϊ10�������͵õ���ȷ��������ˣ�
*/

void solve()
{
	int t; cin>>t;
	while(t--)
	{
		int x; cin>>x;
		int ans=0;
		string s=to_string(x);
		reverse(s.begin(),s.end());
		for(int i=0;i<s.size();i++)	
		{
			if(s[i]>='3'&&s[i]<'8') s[i]--; //warn -- not ++
			if(s[i]>'8') s[i]-=2;
			ans+=(s[i]-'0')*pow(8,i);
		}
		cout<<ans<<endl; 
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	solve();
	return 0;
}
