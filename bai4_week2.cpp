#include <iostream>
#include <vector>
using namespace std;

class queue{
	private:
		vector<int> v;
	public:
		void enqueue(int x){
			v.push_back(x); 
		}	
		void dequeue(){
			v.erase(v.begin());
		}
		void print(){
			for(int x : v){
				cout << x << " ";
			}
		}
};

int main(){
	queue ls;
	int n; cin >> n;
	string s;
	int x;
	while (n--){
		cin >> s;
		if (s == "enqueue"){
			cin >> x;
			ls.enqueue(x);
		}
		else if (s == "dequeue"){
			ls.dequeue();
		}
	}
	ls.print() ;
	
	return 0;
}
