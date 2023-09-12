#include <iostream>
#include <algorithm>
using namespace std;

#define N 5

int main(){
	
	int a[5];
	for (int i = 0; i < N; i++){
		cin >> a[i];
	}
	sort(a, a + N);
	cout << a[0] + a[N - 1];
	
	return 0;
}
