#include<iostream>
using namespace std;

int a[30];//ai
int b[30];//bi,�±��Ӧ����
int aE[30];//ai��չ��ʽ,�±��Ӧ����
int main() {
	int n;
	while(cin>>n&&n>0) {

		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=n-1; i>=0; i--) {
			cin>>b[i];
		}
		b[n]=1;//x^n��ϵ��Ϊ1
		aE[0]=a[1];//����ֻ��һ��(x+a1),��x��0�η�ϵ��Ϊa1
		aE[1]=1;//����ֻ��һ��(x+a1),��x��1�η�ϵ��Ϊ1
		for(int i=2; i<=n; i++) {//i��2��ʼ��n,���Ǵ�(x+a2)��ʼ����ȥ,һֱ�˵�(x+an),ÿ�θ���չ��ʽÿһ��ϵ���ı仯
			aE[i]=1;//����˵�ai,��ôx^iΪ��������Ϊ1
			for(int j=i-1; j>0; j--)
				aE[j]=aE[j]*a[i]+aE[j-1];//����(x+ai)��x^j��ԭϵ��*ai����x^j-1��ϵ��(��x�˺������Ϊj��ϵ������)Ϊx^j����ϵ��
			aE[0]*=a[i];//������*ai
		}

		int flag = 0;
		for(int i=0; i<n; i++) {
			if(b[i]==aE[i])flag++;//�ж�bi�Ƿ��aiչ��ʽһһ��Ӧ
		}

		if(flag==n)cout<<'Y'<<endl;
		else cout<<'N'<<endl;
	}
}

