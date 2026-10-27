#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayQueue {
private:
    int* q_array;
    int q_capacity;
    int q_size;
    int q_front;
    int q_back;

public:
    ArrayQueue(int capacity = 8) : q_capacity(capacity), q_size(0), q_front(0), q_back(-1) {
        q_array = new int[q_capacity];
    }

    ArrayQueue(const ArrayQueue& other) 
        : q_capacity(other.q_capacity), q_size(other.q_size), q_front(other.q_front), q_back(other.q_back) {
        q_array = new int[q_capacity];
        for (int i = 0; i < q_capacity; ++i) {
            q_array[i] = other.q_array[i];
        }
    }

    ArrayQueue& operator=(const ArrayQueue& other) {
        if (this != &other) {
            delete[] q_array;
            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;
            q_array = new int[q_capacity];
            for (int i = 0; i < q_capacity; ++i) {
                q_array[i] = other.q_array[i];
            }
        }
        return *this;
    }

    ~ArrayQueue() {
        delete[] q_array;
    }

    bool Empty() const { return q_size == 0; }
    int Size() const { return q_size; }
    void Clear() { q_size = 0; q_front = 0; q_back = -1; }

    int Front() const {
        if (Empty()) throw runtime_error("Queue is empty");
        return q_array[q_front];
    }

    int Back() const {
        if (Empty()) throw runtime_error("Queue is empty");
        return q_array[q_back];
    }

    void Enqueue(int val) {
        if (q_size == q_capacity) {
            cout << "Queue is full!\n";
            return;
        }
        q_back = (q_back + 1) % q_capacity;
        q_array[q_back] = val;
        q_size++;
    }

    void Dequeue() {
        if (Empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        q_front = (q_front + 1) % q_capacity;
        q_size--;
        if (q_size == 0) {
            q_front = 0;
            q_back = -1;
        }
    }

    void Display() const {
        if (Empty()) {
            cout << "[ Empty Queue ]\n";
            return;
        }
        for (int i = 0; i < q_size; ++i) {
            int index = (q_front + i) % q_capacity;
            cout << q_array[index] << " ";
        }
        cout << "\n";
    }
};

int main() {
    cout << "=================================================\n";
    cout << "   ILO B.2: ARRAY CIRCULAR QUEUE DEMONSTRATION   \n";
    cout << "=================================================\n";

    ArrayQueue aq(8);

    cout << "1. Enqueue operations (10, 20, 30, 40, 50):\nQueue: ";
    aq.Enqueue(10);
    aq.Enqueue(20);
    aq.Enqueue(30);
    aq.Enqueue(40);
    aq.Enqueue(50);
    aq.Display();
    cout << "Size: " << aq.Size() << "\n";
    cout << "Front: " << aq.Front() << "\n";
    cout << "Back: " << aq.Back() << "\n";

    cout << "\n2. Dequeue operation:\nQueue after Dequeue: ";
    aq.Dequeue();
    aq.Display();

    cout << "\n3. Copy Constructor:\nCopied Queue: ";
    ArrayQueue aqCopy = aq;
    aqCopy.Display();

    cout << "\n4. Copy Assignment Operator:\nAssigned Queue: ";
    ArrayQueue aqAssign(5);
    aqAssign = aq;
    aqAssign.Display();

    cout << "\n5. Clear operation:\n";
    aq.Clear();
    cout << "Is Empty after Clear? " << (aq.Empty() ? "True" : "False") << "\n";

    return 0;
}