/*
˼·
1.�о��ͺͽ���ת������
2.�ȱ��ͳһ������������
3.�ٰ��չ���ת���Ϳ����ˣ�
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
string s0[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
string tdays[]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};		
map<string,int>hyues;

void solve()
{
	string s; int hyear; cin>>s>>hyear;
	int hday=stoi(s);
	string hyue=s.substr(s.find('.')+1); //ȡ��"." ֮��� 
	int hmonth=hyues[hyue];
	int sum=hyear*365+hmonth*20+hday; //�ڶ��� =1*20+����
	int tyear=sum/260; 
//	sum%=260; //���п��ޣ���Ϊ13��20Ҳ��260������ 
	int tday=sum%13+1;
	string td_name=tdays[sum%20];
	cout<<tday<<" "<<td_name<<" "<<tyear<<endl; 
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	for(int i=0;i<19;i++) hyues[s0[i]]=i; //huyues[]
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
