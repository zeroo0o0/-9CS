/*
���Ƽӷ��Ľ�λԭ���жϺ�ʱ��Ҫ��λ��׼ȷ���ƾ�ȷ���
˼·��
���Ȱٶ�һ��2001��1��1���������� ������֮��Ҫȷ����һ�������ڼ����У�Ҳ��һЩ��Ĺ�ʽ
���ϵ���n��ȥ365����366��ֱ����С�ڵ������������ʱ�����ȷ������ˣ�
�·����Ƶĵ�����ȥһ���£���ȥ�����£�ֱ��nС�ڵ��£�ȷ�����·ݣ�
ʣ�µ�nֵ��Ȼ���������������˵���λ��ǰ�油�ϡ�0����
���ڵĻ��ܼ򵥣�ֱ����(6+n) % 7 ���� ~ 
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int month[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},
				  {31,29,31,30,31,30,31,31,30,31,30,31}};
int year[]={365,366};
string week[]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};

bool check(int x)
{
	if(x%4!=0||(x%100==0&&x%400!=0)) return 0;
	return 1;
}

void solve()
{
	int days;
	while(cin>>days&&days!=-1)
	{
		int dayofweek=days%7; //���ڼ� 
		int i=2000, j=0;
		for(;days>=year[check(i)];i++) //warn num>=
			days-=year[check(i)];
		for(j=0;days>=month[check(i)][j];j++)
			days-=month[check(i)][j];
		string ans_month=to_string(j+1);
		if(j+1<10) ans_month="0"+ans_month;
		string day=to_string(days+1); //warn  days+1  ��1�ſ�ʼ 
		if(days+1<10) day="0"+day;
		cout<<i<<"-"<<ans_month<<"-"<<day<<" "<<week[dayofweek]<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
