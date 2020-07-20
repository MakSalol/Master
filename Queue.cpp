#include <iostream>
using namespace std;

class Queue {
public:
	struct node {
		int item;
		node* next;
	};

	Queue() {
		pFront = nullptr;
		pTail = nullptr;
	}

	void push(const int& a) {
		if (pFront == nullptr && pTail == nullptr) {
			node* newnode = new node;
			newnode->item = a;
			newnode->next = nullptr;
			pTail = newnode;
			pFront = newnode;
			count++;
		}
		else {
			node* newnode = new node;
			newnode->item = a;
			newnode->next = nullptr;
			pTail->next = newnode;
			pTail = newnode;
			count++;
		}
	}
		
	int back() const {
		if (count != 0) {
			return pTail->item;
		}
		 else return -100500;
	}

	int front() const {
		if (count != 0) {
			return pFront->item;
		}
		else return -100500;
	}

	bool Empty() const {
		if (count == 0) {
			return true;
		}
		return false;
	}

	void pop() {
		if (count != 0) {
			node* temp = pFront;
			pFront = pFront->next;
			delete temp;
			count--;
		}
		else cout << "ALARM!!!" << endl;
	}

	int counter() {
		return count;
	}
private:
	node* pFront;
	node* pTail;
	int count = 0;
};


int main() {
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.pop();
	cout << q.back() << endl;
	cout << q.front() << endl;
	cout << "Empty " << q.Empty() << endl;
	cout << "Counter " << q.counter() << endl;
}