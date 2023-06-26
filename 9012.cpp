#include <iostream>


using namespace std;

template <class DT>
class Stack;

template <class DT>
class StackNode {
private:

	StackNode(DT& nodeData, StackNode* nextPtr);

	DT item;
	StackNode* link;

	friend class Stack<DT>;
};

template <class DT>
class Stack {

public:
	Stack();
	~Stack();

	void push(DT& item);
	DT getTop();
	int getSize();
	int isEmpty();
	DT pop();

private:
	StackNode<DT>* top;

};

template <class DT>
StackNode<DT>::StackNode(DT& nodeData, StackNode* nextPtr) {
	item = nodeData;
	link = nextPtr;
}

template <class DT>
Stack<DT>::Stack() {
	top = NULL;
}

template <class DT>
Stack<DT>::~Stack() {
	while (top != NULL) {
		StackNode<DT>* temp = top;
		top = top->link;
		delete temp;
	}
}

template <class DT>
void Stack<DT>::push(DT& item) {
	StackNode<DT>* newnode = new StackNode<DT>(item, NULL);
	newnode->link = top;
	top = newnode;
}

template <class DT>
DT Stack<DT>::getTop() {
	if (top == NULL)
		return -1;
	return top->item;
}

template <class DT>
int Stack<DT>::getSize() {
	int size=0;
	StackNode<DT>* temp = top;
	while (temp!=NULL) {
		temp = temp->link;
		size++;
	}
	return size;
}

template <class DT>
int Stack<DT>::isEmpty() {
	return (top == NULL);
}

template <class DT>
DT Stack<DT>::pop() {
	if (isEmpty()) {
		return -1;
	}
	else {
		StackNode<DT>* temp = top;
		DT result = temp->item;
		top = top->link;
		delete temp;
		return result;
	}
}

bool check(string str) {
	Stack<char> testStack;
	char cmd;
	for (int i = 0; i < str.length(); i++) {
		cmd = str[i];

		if (cmd == '(') {
			testStack.push(cmd);
		}
		else {
			if (testStack.isEmpty()) {
				return false;
			}
			else {
				testStack.pop();
			}
		}
	}
	return testStack.isEmpty();
}

int main(void)
{

	int n;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (check(str)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		
	}

	return 0;
}