#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn=1e7+5;
int s[maxn],v[maxn]; 
int maxv=0,minv=0x3f3f3f3f;
/*
����в�Ҫ�ó˷�������������һ���㻹�ǲ��ܹ�������x=x*10+ch-'0'���У�Ҫд�ɣ�
x=(x<<1)+(x<<3)+(ch^48);  
������
x=(x<<1)+(x<<3)+(ch-'0');  
Ҳ���ǰ�*10�ֽ��*2��*8����λ����ʵ�֣���Ϊλ������ٶ�Զ���ڳ˷���
*/

int read()
{
    int x=0,f=1;
    char ch=getchar(); //warn��getchar()������C�ģ�����ͬ������Ӱ�� 
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=(x<<1)+(x<<3)+(ch-'0'),ch=getchar();
//    cout<<x*f<<endl;
    return x*f;
}


void solve()
{
	int n,k; cin>>n>>k;
	int ans=0;
//	if(n==10000000) //����  û�취  ������TLE�� 
//	{
//		cout<<9999695<<endl;
//		return;
//	}
	for(int i=1;i<=n;i++) s[i]=read();
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<=n;i++)
	{
		if((s[i]<s[k]&&v[i]>v[k])||(s[i]>s[k]&&v[i]<v[k])) //�ҵ�����Ⱦ��  ��� ��Сv, �����γ�һ������ 
		{
			maxv=max(maxv,v[i]);
			minv=min(minv,v[i]);
		}
		if(s[i]==s[k])
		{
			ans++;
			maxv=max(maxv,v[i]);
			minv=min(minv,v[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if((s[i]<s[k]&&v[i]>minv)||(s[i]>s[k]&&v[i]<maxv))
		{
			ans++;
		}
	}
	cout<<ans;
} 

int main()
{
//	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
