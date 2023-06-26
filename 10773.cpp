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

int main(void)
{
	Stack<int> testStack;
	int n, sum=0;
	cin >> n;
	int cmd;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == 0) {
			sum-=testStack.pop();
		}
		else {
			testStack.push(cmd);
			sum += cmd;
		}
	}
	cout << sum;

	return 0;
}