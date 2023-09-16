#include <iostream>
#include <vector>
using namespace std;

class stack{
	private:
		vector<int> v;
	public:
		void push(int x){
			v.push_back(x); 
		}	
		void pop(){
			v.pop_back();
		}
		void print(){
			for(int x : v){
				cout << x << " ";
			}
		}
};

int main(){
	stack ls;
	int n; cin >> n;
	string s;
	int x;
	while (n--){
		cin >> s;
		if (s == "push"){
			cin >> x;
			ls.push(x);
		}
		else if (s == "pop"){
			ls.pop();
		}
	}
	ls.print() ;
	
	return 0;
}
