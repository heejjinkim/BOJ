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
	int size = 0;
	StackNode<DT>* temp = top;
	while (temp != NULL) {
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

	while (1) {
		char str[256];
		cin.getline(str, 256);
		Stack<char> testStack;
		char cmd;
		bool check = true;

		if (str[0] == '.') {
			break;
		}
		for (int i = 0; i < 256; i++) {
			cmd = str[i];
			if (cmd == '.') {
				break;
			}
			if (!check) {
				break;
			}
			if (cmd == '(' || cmd == '[') {
				testStack.push(cmd);
			}
			else if (cmd == ')') {
				if (testStack.isEmpty()) {
					check = false;
				}
					check = (testStack.pop() == '(');
			}
			else if (cmd == ']') {
				if (testStack.isEmpty()) {
					check = false;
				}
				check = (testStack.pop() == '[');
			}
			
		}

		if (testStack.isEmpty() && check) {
			cout << "yes" << endl;
		}
		else
			cout << "no" << endl;

	}

	return 0;
}