/*˼·�� 
���ȶ�ʱ������ʱ����ͬ������·����ߵ�����
��ǰ���ʱ��<=�������еĵ��ʱ�䣬���Ժ������е㷲�ǳɼ�С�ڵ�ǰ��ģ�һ���Ǳ������ġ�
Ҳ��������Ҫ�ľ��Ǽ�¼��ǰ��ĳɼ���Ϊһ����ֵ��������������ĳɼ����ø���ĳɼ��滻�������ֵ������ÿ���㣬
��ֻ��Ҫ�Ƚ������ĳɼ��Ƿ�С����ֵ��С�ھ��Ǳ�������������ʱ�������Ҳ�Ǳ���������ʱ������򲻱����� 
������ǲ��������������Ų��Ұѵ�ǰ��ֵ����Ϊ�µ���ֵ
*/
#include<bits/stdc++.h>
using namespace std;
#define endl '\n' 
struct node{
	int id,t,score;
};
const int maxn=1000005;
node a[maxn];

bool mycmp(node x,node y)
{
	if(x.t!=y.t) return x.t<y.t; //warn: cmp�����ﲻҪ����return
	else return x.score>y.score;
}

set<int>ans;
void solve()
{
	int n; cin>>n;
	for(int i=0;i<n;i++) //warn: 0~n
	{
		cin>>a[i].t>>a[i].score;
		a[i].id=i+1;
	}
	sort(a,a+n,mycmp);
	int mx=0,nowt=0; //��ǰ��߷� 
	for(int i=0;i<n;i++) //���⣺������ҵ�����ʱ�����Ŀ�÷ֶ���ͬ����Ҷ������ܵ������� 
		if(a[i].score>mx||(a[i].t==nowt&&a[i].score==mx))
		{ 		  // > not >=
			ans.insert(a[i].id);
//			cout<<a[i].id<<endl;
//			cout<<mx<<" "<<a[i].score<<endl; ע�͵��� 
			mx=a[i].score;
			nowt=a[i].t;
		}
	for(auto u:ans) cout<<u<<endl;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	solve();
	return 0;
}
