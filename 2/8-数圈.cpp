#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
/*
1.����������Һù���Ȼ��ģ��Ϳ����� 
ע�⣺�������д�����飬����˼·�����ַ������
*/
int dx[]={0,1,0,-1};//ESWN //��
int dy[]={1,0,-1,0};	   //�� 

void solve()
{
	int n; cin>>n;
	int mp[n][n];
	int dir=0; //��¼����
	int buchang=1; //�´���Ҫ��dir�߼���
	int cnt=0;//***�ֲ����� һ��Ҫ��ʼ��*** //��������ͬ���� ���򲽳�+1
	int i=1;
	int x,y; x=y=(n-1)/2; //�����ʼλ�� 
	mp[x][y]=i;
	while(i<n*n) //warn: < not <=
	{
		for(int j=1;j<=buchang;j++) //warn i������ ֻ��j 
		{
			mp[x+j*dx[dir]][y+j*dy[dir]]=++i; //ģ���ֶ�����  //warn: j*dx[dir] not buchang
			if(i==n*n) break; //��ֹ Խ�� 
		}
		//warn ����x,y
		x+=buchang*dx[dir];
		y+=buchang*dy[dir];
		cnt++;
		if(cnt==2)
		{
			buchang++,cnt=0;
		}
		dir++;
		if(dir==4) dir=0; 
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<mp[i][j]<<" ";
		cout<<endl;		
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
