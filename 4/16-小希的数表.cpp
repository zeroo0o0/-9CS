/*
1. �۲�һ�¿��Է���, ���a1 - an�ǵ�����n����, ��ô���ǵĺ�s1, s2, s3��(Ҳ�ǵ���), s1 = a1 + a2, s2 = a1 + a3, ��ôֻҪ�ҳ�a2 + a3, �Ϳ������a1��
2. ����ҳ�a2 + a3��, ��Ȼ������s3. �������ǿ��Ա���s3ֱ��s(n*(n+1)/2), �������s��a2 + a3, �Ӷ�����a1
3. OK, ��ô���������Ѿ������a1, ��ʲô��? ���ǿ������a2, ��Ϊs1��a1��a2�ĺ�, ���������к����޳���֪������֮��(a1, a2), 
ʣ�µ���Сs����a1+a3, ��ô�����a3, ������a3�����������s�޳���, ʣ�µ�s����С����a1+a4, ͬ��, ���������������������е�a
4�������˲�����������, �ͻ�һ��a2+a3, �ҵ��˵�һ���Ϳ����˳���, ��Ϊ��Ŀ������������Ψһ�Ķ����н��
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
//***warn ��������ͬ��sum������set������̫���� ,multiset���� 
int s[10000], num[105], vis[10000];
multiset<int>ms;

void solve()
{
	int n;
	while(cin>>n&&n)
	{
		int size=n*(n-1)/2;
		int num[size]={0};
		ms.clear(); //warn  ��ʼ�� 
		for(int i=1;i<=size;i++) 
		{
			cin>>s[i];
			ms.insert(s[i]);
		}

		for(int i=3;i<=size;i++)
		{
			if((s[1]+s[2]-s[i])%2==1||(s[1]+s[2]-s[i]<=0)) continue; //������ ****warn��|| not && 
			num[1]=(s[1]+s[2]-s[i])/2;
			num[2]=s[1]-num[1];
			num[3]=s[2]-num[1];
			multiset<int>t=ms;
			vector<int>ans;
			ans.push_back(0);
			for(int j=1;j<=3;j++) ans.push_back(num[j]); //***warn*** j
			for(int j=1;j<=2;j++) t.erase(s[j]);
			t.erase(t.find(s[i]));
			int flag=1; //��֪
			while(ans.size()<n+1) //warn <
			{
				int mn=*t.begin();  //������Сֵʵ���Ͼ���a1+a4,a1+a5...�� 
				ans.push_back(mn-num[1]);
				t.erase(t.begin()); //warn
				//��s[]��ɾȥ���ǵĺ�
				for(int j=2;j<=ans.size()-2;j++) //warn: ��֪��==ans.size()-1
				{			//<=size-2
					int temp=ans[j]+ans[ans.size()-1];

					if(t.find(temp)==t.end()) //û�ҵ� 
					{
						flag=0;
						break;
					}
					else t.erase(t.find(temp));  //ֻɾһ�� 
//					else t.erase(temp); //warn****��ôֱ�Ӱ�2��987һ��ɾ�� 
				} 
				if(!flag) break;
			}
			if(ans.size()!=n+1&&!flag) continue; //ǰ������һ��0 
			for(int j=1;j<=n;j++) cout<<ans[j]<<" "; //j
			cout<<endl;
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
} 
