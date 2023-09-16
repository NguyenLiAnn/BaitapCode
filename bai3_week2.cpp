#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* pre;
		Node* next;
		Node(){
			this->data = 0;
			this->pre = nullptr;
			this->next = nullptr;
		}
		Node(int data){
			this->data = data;
			this->pre = nullptr;
			this->next = nullptr;
		}
};

int Size(Node* a){
	int cnt = 0;
	while (a != nullptr){
		cnt++;
		a = a->next ;
	}
	return cnt;
}

class LinkedList{
	public:
		Node* head;
		void insert_node(int data);
		int count_triplets();
};

void LinkedList::insert_node(int data){
	Node* tmp = new Node(data);
	if(head == nullptr){
		head = tmp;
	}
	else {
		Node* p = head;
		while (p->next != nullptr){
			p = p->next;
		}
		p->next = tmp;
		tmp->pre = p;
	}
} 

int LinkedList::count_triplets(){
	int n = Size(head); int cnt = 0;
	Node* tmp = head->next;
	for (int i = 0; i < n - 2; i++){
		if(tmp->pre->data + tmp->data + tmp->next->data == 0){
			cnt++;
		}
		tmp = tmp->next;
	}
	return cnt;
}

int main(){
	int n; cin >> n;
	LinkedList ls;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		ls.insert_node(x); 
	}
	cout << ls.count_triplets();
	return 0;
}
