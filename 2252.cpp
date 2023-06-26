#include <iostream>
using namespace std;


template <class DT>
class vector {
public:
    int size, max_size;
    DT* arr;
    vector() {
        size = 0;
        max_size = 4;
        arr = new DT[max_size];
    }
    ~vector() {
        delete[] arr;
    }
    void push_back(DT newdata) {
        if (size == max_size) {
            DT* tarr = new DT[max_size + max_size];
            max_size += max_size;
            for (int i = 0; i < size; i++) {
                tarr[i] = arr[i];
            }
            delete[] arr;
            arr = tarr;
        }
        arr[size++] = newdata;

    }
};

template <class DT>
class Queue;

template <class DT>
class Node {
private:
    DT item;
    Node* next;

    Node(const DT& data, Node* nextptr) {
        item = data;
        next = nextptr;
    }

    friend class Queue<DT>;

};

template <class DT>
class Queue {
private:
    Node<DT>* front;
    Node<DT>* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }
    ~Queue() {
        clear();
    }
    void clear() {
        rear = nullptr;
        while (front != nullptr) {
            Node<DT>* temp = front;
            front = front->next;
            delete temp;
        }
    }
    void enqueue(const DT newdata) {
        Node<DT>* newnode = new Node<DT>(newdata, nullptr);
        if (front == nullptr) {
            front = newnode;
            rear = newnode;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }
    }
    DT dequeue() {
        if (front == nullptr) {
            return ' ';
        }
        else {
            Node<DT>* temp = front;
            DT data = front->item;
            front = front->next;
            delete temp;
            return data;
        }
    }
    bool isEmpty() {
        return (front == nullptr);
    }
};

vector<int> graph[32001]; // 해당 번호의 뒤에 와야 할 번호 저장
int inDegree[32001]; // 해당 번호의 앞에 와야 할 번호가 몇 개 인지
int N, M;

void TopologicalSort(void) {
    Queue<int> q;

    for (int i = 1; i <= N; i++)
        if (!inDegree[i]) //0이면, 뭐 뒤에 와야 된다는 조건이 없을 때
            q.enqueue(i);

    while (!q.isEmpty()) {
        int cur = q.dequeue();

        cout << cur << ' ';
        for (int i = 0; i < graph[cur].size; i++) {
            inDegree[graph[cur].arr[i]]--;
            if (!inDegree[graph[cur].arr[i]]) //0이면, 더 이상 뭐 뒤에 와야 된다는 조건이 없을 때
                q.enqueue(graph[cur].arr[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        inDegree[b]++;
    }

    TopologicalSort();

    return 0;
}