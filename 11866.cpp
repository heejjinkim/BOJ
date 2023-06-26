#include <iostream>


using namespace std;

template <class DT>
class Queue {
public:
	Queue(int maxNumber);
	~Queue();
	void enqueue(const DT& newdata);
	DT dequeue();
	bool isEmpty();
	bool isFull();
	void clear();
	int getLength();

private:
	int front;
	int rear;
	int maxSize;
	DT* dataItems;
};

template <class DT> 
Queue<DT>::Queue(int maxNumber) {
	maxSize = maxNumber+1;
	front = maxNumber;
	rear = maxNumber;
	dataItems = new DT[maxSize];
}

template <class DT>
Queue<DT>::~Queue()
{
	clear();
}

//원형큐로 만들기
template <class DT>
void Queue<DT>::enqueue(const DT& newdata) {
	if (isFull()) {
		cout << "Queue is Full" << endl;
		return;
	}
	else {
		rear = (rear + 1) % maxSize;
		dataItems[rear] = newdata;
	}
}

template <class DT>
DT Queue<DT> :: dequeue() {
	if (isEmpty()) {
		cout << "Queue is Empty" << endl;
		return ' ';
	}
	else {
		front = (front + 1) % maxSize;
		DT item = dataItems[front];
		return item;
	}
}

template <class DT>
bool Queue<DT>::isEmpty() {
	return(rear == front);
}

template <class DT>
bool Queue<DT>::isFull() {
	return((rear + 1) % maxSize == front);
}

template <class DT>
void Queue<DT>::clear() {
	rear = maxSize - 1;
	front = maxSize - 1;
}

template <class DT>
int Queue<DT>::getLength() {
	int temp = front;
	int num = 0;
	while (temp != rear)
	{
		num++;
		temp = (temp + 1) % maxSize; 
	}
	return num;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	Queue<int> testQueue(n);
	for (int i = 1; i <= n; i++) {
		testQueue.enqueue(i);
	}
	cout << "<";

	while (testQueue.getLength() > 1) {
		for (int i = 0; i < k - 1; i++) {
			int temp = testQueue.dequeue();
			testQueue.enqueue(temp);		
		}
		cout << testQueue.dequeue() << ", ";
	}
	cout << testQueue.dequeue() << ">";
	return 0;
	
}