#pragma once
#include <iostream>
using namespace std;



template <typename T>
class LinkedList {
	struct Node;
public:
	// Behaviors
	void printForward() const {
		const Node* currentNode = head;
		while (currentNode->next) {
			std::cout << currentNode->data << std::endl;
			currentNode=*(currentNode->next());
		}
	}
	void printReverse() const {
		const Node* currentNode = tail;
		while (currentNode->prev) {
			std::cout << currentNode->data << std::endl;
			currentNode=*(currentNode->prev());
		}
	}

	// Accessors
	[[nodiscard]] unsigned int getCount() const {
		return count;
	}
	Node* getHead() {return head;}
	const Node* getHead() const {return head;}
	Node* getTail(){return tail;}
	const Node* getTail() const {return tail;}

	// Insertion
	void addHead(const T& data) {
		head = new Node(T(data), nullptr, head);
		count++;
	}
	void addTail(const T& data) {
		tail = new Node(T(data), tail,nullptr);
		count++;
	}

	// Removal
	bool removeHead() {
		if (count==0)
			return false;
		Node* temp = head;
		head = head->next;
		delete temp;
		head->prev = nullptr;
		count--;
		return true;
	}
	bool removeTail() {
		if (count==0)
			return false;
		Node* temp = tail;
		tail = tail->prev;
		delete temp;
		tail->next = nullptr;
		count--;
		return true;
	}
	void Clear() {
		if (count==0) {
			return;
		}
		Node* current=head;
		while (current->next) {
			Node* temp=current;
			current=temp->next;
			delete temp;
		}
		delete current;
		head=nullptr;
		tail=nullptr;
		count=0;
	}

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept {
		if (this==&other) {
			return *this;
		}
		Clear();
		head=other.head;
		tail=other.tail;
		other.head=nullptr;
		other.tail=nullptr;
		return *this;

	}
	LinkedList<T>& operator=(const LinkedList<T>& rhs) {
		if (&rhs==this) {
			return *this;
		}
		Node* current = rhs.head;
		while (current->next) {
			addHead(current);
			current=current->next;
		}
		return *this;
	}

	// Construction/Destruction
	LinkedList() : head(nullptr), tail(nullptr), count(0) {}
	LinkedList(const LinkedList<T>& list) : head(nullptr), tail(nullptr), count(list.count) {
		Node* current=list.head;
		while (current->next) {
			addTail(current->next.data);
		}
	}
	LinkedList(LinkedList<T>&& other) noexcept {
		head=other.head;
		tail=other.tail;
		other.head=nullptr;
		other.tail=nullptr;
		count=other.count;
	}
	~LinkedList() {
		Clear();
	}

private:
	struct Node {
		T data;
		Node* prev;
		Node* next;
	};
	// Stores pointers to first and last nodes and count
	Node* head;
	Node* tail;
	unsigned int count;

};


