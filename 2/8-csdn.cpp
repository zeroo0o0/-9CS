#include<iostream>
using namespace std;
int dir_x[4]={0,1,0,-1};
int dir_y[4]={1,0,-1,0};
int main(){
	int n;
	cin>>n;
	int x=(n-1)/2,y=(n-1)/2;//�������ʼλ�� 
	int map[n][n];//��ͼ 
	int dir_flag=0;//���Ʒ��� 
	int buchang=1;//�÷����ܼ��� 
	int buchang_cnt=0;//buchang ��������������һ�� 
	int i=1;//��ֵ������ 
	map[x][y]=1;
	while(i<n*n){

		for(int j=1;j<=buchang;j++){
			map[x+j*dir_x[dir_flag]][y+j*dir_y[dir_flag]]=++i;
			if(i==n*n) break;
		}
		x=x+buchang*dir_x[dir_flag];//���µ���������յ����� 
		y=y+buchang*dir_y[dir_flag];//���µ���������յ�����
		buchang_cnt++;
		if(buchang_cnt==2){//�ҹ��ɣ�ĳһ��buchang�����ξ������� 
			buchang_cnt=0;
			buchang++;
		} 
		dir_flag++;//�÷�����������һ������ 
		if(dir_flag==4) dir_flag=0;//����ѭ���� 
	}
	for(int i=0;i<n;i++ ){
		for(int j=0;j<n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 

