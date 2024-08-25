#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2010;
int l[N];
int n, m;

int main() {

	cin >> n >> m;
	
	char a[n][m];
	
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++) {
			cin >> a[i][j];
			// ��ǰλ��1��������� i ���ؿ��Կ� j �� 
			if (a[i][j] - '0') l[j] ++;
		} 
	
	bool flag = false;
	for (int i = 0; i < n; i ++) {
		int k = 0;
		for (int j = 0; j < m; j ++) 
			// ��ȥĳһ�����⣬ʣ�µĵƵ����鶼��Ϊ0����ʾ���������Ŀ��� 
			if (l[j] + '0' - a[i][j] > 0)  k ++;
		
		// �ҵ��˿���ȥ������һ������
		if (k == m) {
			flag = true;
			break;
		}
	}
	
	if (flag) puts("YES");
	else puts("NO"); 
	
	return 0;
}

