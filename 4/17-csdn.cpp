 #include<string>
 #include<iostream>
 #include<sstream>
 #include<stack>
 using namespace std;
 
 int a[100010];
 int path[100010];  //ǰ�����飬����Ѱ���·�� 
  int n; //������ 
  
 int dp(int now,int now_floor,int fa){
 	
	 if(now_floor==n) {  //������ײ� 
 		return a[now];
	 }
	 
	  int left=a[now] + dp( now+now_floor,now_floor+1, now);
	  int right=a[now]+ dp(now+now_floor+1, now_floor+1, now);
	  path[now]=left>right?now+now_floor:now+now_floor+1;
	  return max(left,right);   
	 //�Ա����������ߣ��ı߸�����ߣ����+����    �ұߣ����+����+1 
 }
 
 
 int main(){
 	
	 cin>>n;
	 int num=((n+1)*n)/2; //�ܵĽ������ 
	 
	 for(int i=0;i<num;i++) cin>>a[i];
	 
	  cout<<dp(0 , 1 , -1)<<'\n';    //��ǰ�ܺ�Ϊa[0]����ʼ���Ϊ0����ʼ����Ϊ1 
	
	int k=0;
	int f=1;
	while(f<=n){
		cout<<a[k]<<" ";
		k=path[k];
		f++;
	}
 } 
