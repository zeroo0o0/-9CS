#include<bits/stdc++.h>
using namespace std;
/*
˼·
1.��vector��¼���룬ע���ַ�ת���֡�
2.�������е�size���ҳ���Ӧ���������̵���ʼ�㡣
3.check��Ӧ�������Ƿ�����Ҫ�󼴿�
ע�⣺�����ǰ������sizeû�и��£���ô�����size�Ͳ�������
*/
const int maxn=2000+5;
char m[maxn][maxn];
int ans,cnt;

void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>m[i][j];
	for(int size=1;size<=n;size++)
	{
		int temp=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int x,y;
				bool flag=0;
				for(x=0;x<size;x++) //�ƶ�x�� 
				{
					for(y=0;y<size;y++)
					{
						int nx=i+x, ny=j+y;
						if((x+y)%2==0) //warn: x+y not nx+ny 
						{
							if(m[nx][ny]=='1') continue; //warn �Ѿ���Ϊ��0 1 
							else flag=1;
							break;
						}
						else {
							if(m[nx][ny]=='0') continue;
							else flag=1;
							break;
						}
					}
					if(flag) break;
				}
				if(x==size&&y==size) //��������
				{
					ans=size;
					temp++;
				} 
			}
		if(ans!=size) break;
		else cnt=temp;
	}
	cout<<ans<<" "<<cnt<<endl;
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
} 
