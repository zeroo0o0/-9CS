#include<string>
#include<iostream>
#include<sstream>
#include<string.h>
using namespace std;
 
/*
���������ͦ��  ��Ҫ��֪��a1+a2,a1+a3  ������ô�ҵ�a2+a3�أ�
�����-->����������Ѱ����֤����Ψһ���ҵ�������ȷ�� 
�����������ǲ���ģ�N < 100 
*/
 
int sum[10200]; //�� ���� 
int vis[10200]; //���ʺ͵����� 
int num[110];   // ԭ���� 
 
 int main(){
 	int n;
 	while(cin>>n&&n){
 		int size=(n*(n-1))/2;
		 for(int i=1;i<=size;i++){  //�±��1��ʼ 
		 	cin>>sum[i];
		 }	
 
		 for(int i=3;i<=size;i++) {     //ѭ���ܶ�Σ�������٣� ����sum��i����a2+a3��
		 								//�����sumȫ�������ˣ�˵��sum��i������a2+a3������������� 
		 	//num[1]+num[2]=sum[1];
			//num[1]+num[3]=sum[2];
			//num[2]+num[3]=sum[i];   �������sum[i]��a2+a3,�Ƴ�a4��a5��an������ȫ���Ƴ��������Ǵ� 
		 	
		 	num[1]=(sum[1]+sum[2]-sum[i])/2;
		 	num[2]=sum[1]-num[1];
			num[3]=sum[2]-num[1]; 
			
			if (( sum[1]+ sum[2] - sum[i]) % 2 || (sum[1] + sum[2] - sum[i] <= 0)) 
                continue; // 2*a1�϶���������   a1һ����������....��Ȼ�ó���һ��������� 
			
			memset(vis,0,sizeof(vis));//ÿ�ζ�Ҫ��mark������0�����鵱ǰ��sum[i]�ǲ���a2+a3
			
			vis[1]=vis[2]=vis[i]=1;  //��� ��1��2��i���Ѿ������ʹ�
			
			//���ʱ��û�б����ʵĺ��У���С�ľ���a1+a4,Ȼ�����a4,���a1+a4,a2+a4,a3+a4;���ʱ����С�ľ���a1+a5���� 
		 	int know=3; //Ŀǰ�Ѿ�֪������
			int flag=1;
			while(know!=n){
			 	int mini=-1;//��û�����ʵ��������ҵ���Сֵ����������û�����ʵĵ�һ��������Сֵ 
				 for(int j=1;j<=size;j++){
				 	if(vis[j]==0){
				 		mini=sum[j];
				 		vis[j]=1;//��Ƿ��ʣ�������Сֵʵ���Ͼ���a1+a4,a1+a5...�� 
				 		break; 
					 }
				 }
			 	
			 	num[know+1]=mini-num[1];
			 	know++; 
			 	
			 	//������2~(know-1)  ��Ϊa1+aj�Ѿ�����ǹ���
			 	for(int k=2;k<=know-1;k++) { //�ҵ����µ����֣���֮ǰ�ҵ������ֺ���������ӣ���sum��ȥȥ�� 
			 		int temp=num[k]+num[know];
			 		flag=0;
					 for(int p=1;p<=size;p++){
			 			if(vis[p]==0 && sum[p]==temp){
			 				flag=1;
			 				vis[p]=1;
			 				break;
						 }
					 }
					 if(flag==0) break;  //�����ӳ�����ֵ�Ҳ�������˵��һ��ʼa2+a3�Ҵ��� 
				 }
			 	if(flag==0) break;
			 } 	
			 //whileѭ���������߲�����������...
			 if(know!=n) continue;   //���sum[i]���ԣ�����forѭ������һ��
			 
			 for(int h=1;h<=n;h++){  //�ҵ��� 
			 	cout<<num[h]<<" ";
			 }
			 cout<<'\n';
			 break;  
		} 	 	
	} 	
}
	
