#include <iostream>

using namespace std;

struct Node {
	int val = 0;
	Node* next = NULL;
};

int main()
{
	Node* p = new Node();
	p->val = 1;
	
	Node* cur = p;
	for (int i = 0; i < 2; i++) {
		Node* n = new Node();
		n->val = i + 2;
		
		cur->next = n;
		cur = n;
	}
	
	cur = p;
	cout << p->val << ' ';
	while (cur->next != NULL) {
		cur = cur->next;
		cout << cur->val << ' ';
	}
	
	return 0;
}
