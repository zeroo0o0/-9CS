#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct node{
	int left;//ռ����� 
	int right;//ռ���յ� 
}temp;
int main(){
	int n,m;
	vector<int> position;
	map<int,node> map;
	while(cin>>n>>m){	
		for(int i=0;i<n*n;i++){
			position.push_back(0);//0��ʾ��λû�� 
		}
		int k;//������� 
		int id,num;//��¼id����Ҫ��num��λ��
		cin>>k;
		while(k--){
			string order;
			cin>>order;
			int flag=0;//�������yes no 
			if(order[0]=='i'){
				cin>>id>>num;
				if(map.find(id)==map.end()){//֮ǰûռ���ſ���ռ�� 
					for(int i=0;i<=n*n-num;i++){
						int j;
						for(j=i;j<i+num;j++){
							if(position[i]==0) continue;
							else break;
						}
						if(j==i+num&&!position[i+num-1]){//�ҵ������� 
							temp.left=i;
							temp.right=i+num-1;
							map[id]=temp; 
							cout<<"yes"<<endl;
							flag=1;
							/************����ռ��***************/
							for(int k=temp.left;k<=temp.right;k++){
								position[k]=1;
							} 
							break;
						}
					}					
				}
			}else{
				cin>>id;
				if(map.find(id)!=map.end()){
					for(int i=map[id].left;i<=map[id].right;i++){
						position[i]=0;//��λ�ڿ� 
					}
					map.erase(map.find(id));
					cout<<"yes"<<endl;
					flag=1;
				}
			}
			if(!flag) cout<<"no"<<endl;
		} 
	}
	return 0;
} 
