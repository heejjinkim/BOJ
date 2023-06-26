#include <iostream>


using namespace std;

template <class DT>
class Stack;

template <class DT>
class StackNode {
private:

	StackNode(const DT& nodeData, StackNode* nextPtr);

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
StackNode<DT>::StackNode(const DT& nodeData, StackNode* nextPtr) {
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
	int n;
	cin >> n;
	int item;
	int cnt = 1;
	Stack <int> testStack;
	string ans;

	for (int i = 0; i < n; i++) {
		cin >> item;
		if (testStack.getTop() < item) {
			while (cnt <= item) {
				testStack.push(cnt);
				cnt++;
				ans += '+';
			}
			testStack.pop();
			ans += '-';
		}
		else {
			if (testStack.getTop() == item) {
				testStack.pop();
				ans += '-';
			}
			else {
				cout << "NO" << '\n';
				return 0;
			}
		}

	}
	for (int i = 0; i < ans.length(); i++) {
		char c=ans[i];
		cout << c << '\n';
	}
	

	return 0;
}