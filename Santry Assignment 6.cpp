/*
	Author: Arin Santry
	Course: ECCS 2671 Data Structures and Algorithms 1
	Date: November 2019
*/


#include <iostream>
#include <string>

using namespace std;

class QueueList {

private:
	struct node {
		string data;
		node* next;
	};

	int capacity;
	int currentSize;
	node* head;
	node* tail;

public:
	QueueList(int c = 5);
	~QueueList();
	bool enqueue(const string addData);
	string dequeue();
	string peek();
	bool isEmpty();
	bool isFull();
	int size();
	void displayQueue();
};

// all proper initializations should be done here
QueueList::QueueList(int c) {
	capacity = c;
	head = nullptr;
	tail = nullptr;
	currentSize = 0;
}

// deallocate any reserved memory
QueueList::~QueueList() {
	delete head;
	delete tail;
}

// check if the queue is empty or not
// return true if queue is empty and false otherwise
bool QueueList::isEmpty() {
	if (head == nullptr)
		return true;
	else
		return false;
}

// check if the queue is full or not
// return true if queue is full and false otherwise
bool QueueList::isFull() {
	if (size() >= capacity)
		return true;
	else
		return false;
}

// insert an element into the Queue
// return true if element is inserted, false otherwise
bool QueueList::enqueue(const string addData) {
	if (isFull())
		return false;
	else
	{
		node* newNode = new node;
		newNode->data = addData;
		newNode->next = nullptr;
		if (isEmpty())
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		currentSize++;
		return true;
	}
}

// remove the element at the front of the queue
string QueueList::dequeue() {
	if (isEmpty())
		return false;
	else
	{
		node* delPtr = head;
		string data;
		if (head == tail)
		{
			data = head->data;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			data = head->data;
			head = head->next;
		}
		currentSize--;
		delete delPtr;
		return data;
	}
}

// show the element at the front of the queue
string QueueList::peek() {
	return head->data;
}

// return the current size of the Queue
int QueueList::size() {
	return currentSize;
}

// show the content of the queue.
// this function is for debugging purposes only
void QueueList::displayQueue() {
	node* curr = head;
	while (curr != nullptr)
	{
		cout << "(" << curr->data << ")->";
		curr = curr->next;
	}
	cout << "00" << endl;

}

int main() {

	QueueList myQueue;

	string inputName;
	int choice;
	cout << "1 -- enqueue" << endl;
	cout << "2 -- dequeue" << endl;
	cout << "3 -- peek" << endl;
	cout << "4 -- display" << endl;
	cout << "5 -- size" << endl;
	cout << "6 -- EXIT." << endl;

	do {
		cout << "Enter your choice ... " << endl;
		cin >> choice;
		cout << endl;

		switch (choice) {

		case 1:
			cout << "Enter a name:" << endl;
			cin >> inputName;
			cout << endl;
			myQueue.enqueue(inputName);
			break;
		case 2:
			if (!myQueue.isEmpty())
				cout << "Dequeue: " << myQueue.dequeue() << endl;
			else
				cout << "Queue is EMPTY" << endl;
			break;
		case 3:
			if (!myQueue.isEmpty())
				cout << "The element at the front is: " << myQueue.peek() << endl;
			else
				cout << "Queue is EMPTY" << endl;
			break;
		case 4:
			myQueue.displayQueue();
			break;
		case 5:
			cout << "Queue size is: " << myQueue.size() << endl;

		}

	} while (choice != 6);



	return 0;
}
