#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn=1e5+5;
int a[maxn];

void solve()
{
	int n,m; cin>>n>>m;
	int cnt=0,r=0;
	while(n--)
	{
		string s; cin>>s;
		if(s=="alloc") //warn ѡ�뿪ͷ����ķ��� 
		{
			int x; cin>>x;
			int l=0,temp=0,flag=0;
			for(int i=1;i<=m;i++)
			{
				if(a[i]==0&&l==0) l=i,temp++;
				else if(a[i]==0) temp++;
				else l=0,temp=0;
				if(temp>=x)
				{
					cnt++;
					for(int j=l;j<l+x;j++) //warn Ҫ��r�ı� ֮ǰ 
						a[j]=cnt;
					cout<<cnt<<endl;
					r=max(l+x,r);
					flag=1;
					break;
				}
					
			 } 
			if(!flag) cout<<"NULL"<<endl; 
		}
		if(s=="erase") 
		{
			int x; cin>>x;
			if(x<0||x>cnt) 
			{
				cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;  //warn : ereaseʧ��Ҫcout 
				continue;//warn :continue ǰ����ֱ�ӽӣ�
			}
			bool flag=0;
			for(int i=0;i<=m;i++)
			{
				if(a[i]==x) {
					a[i]=0; flag=true;
					if(x==cnt) r--;
				}
			}
			if(!flag) cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
		}
		if(s=="defragment")
		{
			for(int i=0;i<m-1;i++) //���ð������ 
			{
				bool flag=0;
				for(int i=1;i<=m-1;i++)
					if(a[i]==0){
						swap(a[i],a[i+1]); flag=1;
					}
				if(flag)r--; 
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
