#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
    int n,a,b;
    scanf("%d %d %d", &n,&a,&b);
    string s;
    cin>>s;
    int dp[5001];
    dp[0]=0;dp[1]=a;
    for(int i=2;i<=n;i++)
        dp[i]=999999999;
    for(int l=2;l<=n;l++){
        string ss = s.substr(0,l);//����l���Ӵ�
        dp[l] = dp[l-1]+a;
        for(int mid=(l+1)/2;mid<l;mid++){//���һ���ǳ����Ұ�ģ�����mid��(l+1)/2��ʼ
            string left=ss.substr(0,mid);//�Ӵ����
            string right=ss.substr(mid,l);//�Ӵ��Ұ�
            if(left.find(right)!=left.npos)
                dp[l] = min(dp[l], dp[mid]+b);
        }
    }
    cout<<dp[n];
}
