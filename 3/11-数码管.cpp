/*��һ 
1.�������¼������ܵ��������ǽ�����������������������ͬ��˵��ֻ��ӻ��߼�
2.���˼·�ǲ���ͦ�����
*/
/*
������ת������ 
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int m[15][15]={
{0,1,0,0,0,0,0,1,1,0},//0
{1,0,0,1,1,0,0,1,1,1},//1
{0,0,0,0,0,0,0,0,1,0},//2
{0,1,0,0,0,0,0,1,1,1},//3
{0,1,0,0,0,0,0,0,1,1},//4
{0,0,0,0,0,0,1,0,1,1},//5
{0,0,0,0,0,1,0,0,1,0},//6 //ע������д�� 
{1,1,0,1,0,0,0,0,1,1},//7
{1,1,1,1,1,1,1,1,0,1},//8
{0,1,0,1,1,1,0,1,1,0} //9
};

void solve()
{
	while(1){
		int last=0,now=0,flag=1;
		for(int i=0;i<10;i++)
		{
			cin>>now;
			if(i==0&&now==-1) return; //warn��i==0 ���ǵ�һ�� 
			if(i==0) last=now; //������vector��v[i-1],v[i] 
//			cout<<last<<" "<<now<<endl;
			if(m[last][now]||last==now) 
			{
				last=now; //������һ�� 
				continue; //last==now:��һ�� 
			}
			else 
			{
				flag=0;
//				break;  warn: ����δ��ɣ�����break 
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

signed main()
{
	
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
