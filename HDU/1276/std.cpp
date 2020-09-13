#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 100010;
const int MAXL = 100010;
 
 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
    
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		bool flag = 0;
		queue<int> q;
		for(int i = 1; i <= n; i++){
			q.push(i);
		}
		while(q.size() > 3){
			int len = q.size();
			for(int i = 1; i <= len ; i++){
				int temp = q.front();
				q.pop();
				if(i % 2 != 0)
					q.push(temp);
			}
			if(q.size() <= 3) 
				break;
			len = q.size();
			for(int i = 1 ;i <= len; i++){
				int temp = q.front();
				q.pop();
				if(i % 3 != 0)
					q.push(temp);
			}
		}
		while(q.size() > 1){
			cout << q.front() << " ";
			q.pop();
		}
		cout << q.front() << endl;
	}
	return 0;
}