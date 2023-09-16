#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node(int data);
};

Node::Node(int data){
	this->data = data;
	this->next = nullptr;
} 

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
		Node* head = nullptr;
		void insert_node(int data, int pos);
		void delete_node(int pos);
};

void LinkedList::insert_node(int data, int pos){
	Node* tmp = new Node(data);
	int n = Size(head);
	if (n == 0){
		head = tmp;
		return;
	}
	else {
		if (pos == 0){
			tmp->next = head;
			head = tmp;
		}
		else if (pos == n + 1){
			Node* p = head;
			while (p->next != nullptr){
				p = p->next;
			}
			p->next = tmp;
		}
		else {
			Node* p = head;
			for (int i = 0; i < pos - 1; i++){
				p = p->next ;
			}
			tmp->next = p->next ;
			p->next = tmp;
		}
	}
} 

void LinkedList::delete_node(int pos){
	int n = Size(head);
	if (n == 0){
		return;
	}
	else {
		if (pos == 0){
			head = head->next ;
		}
		else if (pos == n){
			Node* p = head;
			for (int i = 0; i < pos - 1; i++){
				p = p->next ;
			}
			p->next = nullptr;
		}
		else {
			Node* p = head;
			for (int i = 0; i < pos - 1; i++){
				p = p->next ;
			}
			p->next = p->next->next;
		}
	}
} 

void xuat(LinkedList ls){
	//cout << "size cua ll: " << Size(ls.head) << endl;
	Node* p = ls.head ;
	while (p != nullptr){
		cout << p->data << " ";
		p = p->next ;
	}
}

int main()
{
	LinkedList ls;
	
	int n; cin >> n;
	while (n--){
		string s; cin >> s;
		if (s == "insert"){
			int p, x; cin >> p >> x;
			ls.insert_node(x, p); 
		}
		else if (s == "delete"){
			int p; cin >> p;
			ls.delete_node(p); 
		}
		else cout << "cu phap khong hop le!";
	}
	
	xuat(ls);
	  
	return 0;
}
