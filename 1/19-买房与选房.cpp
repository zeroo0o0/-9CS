#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int m; 
int n;                            /* nΪ����������ͨ�����ú���getMess��ȡ */
map<string,int>mp;
struct people
{
	char id[19];                  /* ���֤���� */
	int social;                     /* �籣�������� */
	int area;                       /* ����ס����� */
	char date[11];              /* �걨���� */
	
	//***����< 
	bool operator<(const people b)const  //�ײ�Ҫ�� ��const �ң�������const���η� 
	{
		if(area==0&&social<=24) return false;
		if(b.area==0&&b.social<=24) return true;
		if(area!=b.area) return area<b.area;
		if(area==0&&social!=b.social) return social>b.social;
		for(int i=6;i<=9;i++)
			if(date[i]!=b.date[i]) return date[i]<b.date[i];
		for(int i=0;i<=1;i++)   //warn  ע�����ڸ�ʽ  ��--��--��
			if(date[i]!=b.date[i]) return date[i]<b.date[i];
		for(int i=3;i<=4;i++)    
			if(date[i]!=b.date[i]) return date[i]<b.date[i];
		return 0; //warn ����return true ����WA 
	}
};
people *p;          /* ָ�����б����˵Ļ��������׵�ַ��ͨ�����ú���getMess��ȡ */

people* getMess(int &n)            /* ���ļ����ݶ����ڴ� */
{									//��ȡ�Ѿ���� 
	FILE *fp;
	fp=fopen("house.bin","rb");
	fseek(fp,-1*(long)sizeof(int), 2);
	fread(&n, sizeof(int),1, fp);
	rewind(fp);
	people *tmp=new people[n];
	fread(tmp, sizeof(people), n, fp);
	fclose(fp);
	return tmp;
}

void solve()
{
	string s; cin>>s;
	int id=mp[s];
	int l=lower_bound(p,p+n,p[id])-p+1; //==�� ��һ�� ����
	int r=upper_bound(p,p+n,p[id])-p; //==�� ���һ������
	if((p[id].area==0&&p[id].social<=24)||l>m) cout<<"Sorry"<<endl;
	else if(l==r) cout<<l<<endl;
	else if(r>m) cout<<m-l+1<<"/"<<r-l+1<<endl; //warn r-l not r-m
	else cout<<l<<" "<<r<<endl; 
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	p=getMess(n);
	// ...
	sort(p,p+n);
	for(int i=0;i<n;i++)
	{
		string s=p[i].id;
		mp[s]=i;  
	}
	int t; cin>>m>>t;
	while(t--) solve(); 
	return 0;
}
