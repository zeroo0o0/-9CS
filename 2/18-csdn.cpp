#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<int> > map(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char ch;
			cin>>ch;
			map[i].push_back(ch-'0');
		}
	}
	int ans=1;//�������ٰ���һ��1�ַ�; 
	int cnt=1;//����һ�� 
	for(int size=1;size<=n;size++){ //���ߴ�ı��� 
		int temp_cnt=0;
		for(int i=0;i<=n-size;i++){
			for(int j=0;j<=n-size;j++){ //i,j ��� 
				/*************��������forѭ�������������еĸ�size����*******************/
				/************************��ÿ�����̽���check****************************/
				int k,l;
				for(k=0;k<size;k++){
					int flag=0;
					for(l=0;l<size;l++){
						if((l+k)%2==0){
							if(map[i+k][j+l]==1) continue;
							else {
								flag=1;break;
							}
						}else{
							if(map[i+k][j+l]==0) continue;
							else {
								flag=1;break;
							}
						}
					}
					if(flag) break;
				} 
				/**************�������˵�����̷���Ҫ��*********************************/
				if(k==size&&l==size){
						ans=size;
						temp_cnt++;
				}
			}
		}
		if(ans!=size) break; //��ǰsizeû���ҵ�ans�����Ը����sizeҲ�Ҳ���������Ͳ�����
		if(ans==size) cnt=temp_cnt;//����ҵ���ans�����Ǹ����ҵ��ĸ��� 
		
	} 
	cout<<ans<<" "<<cnt<<endl; 
	return 0;
} 


