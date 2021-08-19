#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Node {
	char c;
	Node* next;
};

void reverse(Node* cur) {
	stack<char> s;
	while (cur != NULL) {
		s.push(cur->c);
		cur = cur->next;
	}
	
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

void remove(Node* cur, char c) {
	Node* pre;
	while (cur != NULL) {
		if (cur->c == c) {
			pre->next = cur->next;
			cur->next = NULL;
		} else {
			pre = cur;
			cur = cur->next;
		}
		
	}
	
	while(cur!=NULL) {
		cout << cur->c;
		cur = cur->next;
	} 
}

int main()
{
	string s = "abcdefg";
	Node* head = new Node();
	head->c = s[0];
	head->next = NULL;
	
	Node* tail = head;
	
	for (int i = 1; i < s.size(); i++) {
		Node* cur = new Node();
		cur->c = s[i];
		cur->next = NULL;
		
		tail->next = cur;
		tail = cur;
	}
	
	Node* cur = head;
//	reverse(cur);	
	remove(cur, 'b');
	
	cout << endl;
	
	return 0;
}
