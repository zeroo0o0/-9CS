/*
˼·
1.����⿪ʼ�����е��ɣ���ʵ�ܼ򵥵ģ����ǿ����������֣�ǰ����a���м���b��������a�������Ϳ�����������ѭ��Ȼ������������֣�Ȼ���������a��b�Ϳ�����
2.���Ǳ����ⷨ���޷�ͨ��ȫ��������
3.������������ǰ׺�ͣ�����ͺ�ǰn�����һ���ģ�����һ˵����ҿ϶������ˣ���Ҹ߿���ѧ������Ŀ�У���֪ǰn��ͱ��ʽ����an�ı��ʽ��Щ��
4.���������Ǽ���ĳ�������a��b�Ϳ��Լ��ˣ������ǵ�һ�����ֵ�a����һ����ȥ���ˣ�����ֱ�ӵ���
5.�ڶ������ֵ�b���ԣ����������b����õ��м������b
6.���������ڵ㣬�õ�����������������֣�Ȼ�����Ǽ����������ֵ�ֵ��ӣ�������ֵ����
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
const int maxn=5005; //warn���5000 
vector<int>a(maxn),b(maxn);
int mx,a1,b0,a2;

void solve()
{
	string s; cin>>s;
	if(s[0]=='a') a[0]=1,b[0]=0; //warn b[0]=0
	else b[0]=1, a[0]=0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='a') a[i]=a[i-1]+1, b[i]=b[i-1];
		else a[i]=a[i-1], b[i]=b[i-1]+1;
	}
//	cout<<b[2]<<endl; cout<<b[5]<<endl; 
	for(int i=0;i<s.size();i++)
		for(int j=i;j<s.size();j++) //����ö�� �����ָ�� 
		{//warn����i=0��a[i-1]��Խ�� //���У�����0��ʼ�ò������Ž� 
			if(i==0) a1=a[0],b0=b[j]-0; //warn ��ʼ��ʱb��=0 
			else a1=a[i],b0=b[j]-b[i]; //warn -b[i-1]  //0~i:a  i+1~j:b j+1~end:a  //warn b[j] not b[j-i]
			a2=a[s.size()-1]-a[j];
			int sum=a1+b0+a2;
//			cout<<i<<" "<<j<<":";
//			cout<<a1<<" "<<b0<<" "<<a2<<endl;
			if(sum>mx) mx=sum;
		}
	cout<<mx<<endl;
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	solve();
	return 0;
}
