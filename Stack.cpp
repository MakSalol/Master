#include <iostream>
using namespace std;

class Stack {
public:
	struct node {
		int a;
		node* next;
	};
	
	Stack() {
		pTop = nullptr;
	}
	void push(const int& b) {
		node* newnode = new node;
		newnode->a = b;
		newnode->next = pTop;
		pTop = newnode;
	}

	void  Top() const {
		if (pTop != nullptr) {
			cout << pTop->a << endl;
		}
		else cout << "IDI OTSUDA ONO TEBYA UB'ET !!!" << endl;
	}

	bool Empty() const {
		if (pTop == nullptr) {
			return true;
		}
		return false;
	}

	void Pop() {
		if (pTop != nullptr) {
			node* temp;
			temp = pTop;
			pTop = pTop->next;
			delete temp;
		}
		else cout << "IDI OTSUDA ONO TEBYA UB'ET !!!" << endl;
	}

	void Print() const {
		node* temp = pTop;
		while (temp != nullptr) {
			cout << temp->a <<" ";
			temp = temp->next;
		}
	}

	int Peek(const int& b) {
		node* temp;
		temp = pTop;
		int i = 0;
		while ((temp->next != nullptr) && (i < b)) {
			temp = temp->next;
			i++;
		}
		return temp->a;
	}
private:
	node* pTop;
};



int main() {
	Stack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.Pop();
	stack.Top();
	cout << "Empty " << stack.Empty() << endl;
	cout << "Peek " << stack.Peek(1) << endl;
	stack.Print();
}