#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
struct node{
	int l,r; //���� 
};
map<int,node>mp;

void solve()
{
	int n,m,k; cin>>n>>m>>k;
	int a[n*n]={0}; //warn 0
	for(int i=0;i<k;i++)
	{
		string s; 
		cin>>s;
		if(s=="in")
		{
			int id,num; cin>>id>>num;
//			if(mp.find(id)!=node()) //���� 
			if(mp.find(id)!=mp.end()) 
			{
				cout<<"no"<<endl; continue;
			}
			int l=0,cnt=0,flag=0;
			for(int j=0;j<n*n;j++) //<n*n //warn��i������ 
			{
				if(a[j]==0&&cnt==0) l=j,cnt++; //warn��***l==0��������� 
				else if(a[j]==0) cnt++;
				else l=0,cnt=0;
				if(cnt>=num)
				{
					for(int z=l;z<l+num;z++) //warn Ҫ��r�ı� ֮ǰ 
						a[z]=1;
					cout<<"yes"<<endl;
					node t; 
					t.l=l, t.r=l+num-1;
					mp[id]=t;
					flag=1;
					break;
				}		
			 } 
//			if(id==4) for(int i=0;i<9;i++) cout<<a[i]<<" "; //***������  ��ע�͵� 
			if(!flag) cout<<"no"<<endl; 
		}
		else 
		{
			int id; cin>>id;
			if(mp.find(id)==mp.end()) 
			{
				cout<<"no"<<endl;
				continue;
			}
			else 
			{
				for(int j=mp[id].l;j<=mp[id].r;j++) a[j]=0;
				cout<<"yes"<<endl; 
				mp.erase(mp.find(id)); //warn***���δ���� 
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
