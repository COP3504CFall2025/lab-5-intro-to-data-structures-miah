#pragma once
#include <iostream>
using namespace std;



template <typename T>
class LinkedList {
	struct Node;
public:
	// Behaviors
	void printForward() const {
		if (count==0)
			throw std::runtime_error("tried to print an empty linked list");
		const Node* currentNode = head;
		while (currentNode) {
			std::cout << currentNode->data << std::endl;
			currentNode = currentNode->next;
		}
	}
	void printReverse() const {
		if (count==0)
			throw std::runtime_error("tried to print an empty linked list");
		const Node* currentNode = tail;
		while (currentNode) {
			std::cout << currentNode->data << std::endl;
			currentNode = currentNode->prev;
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
		if (count==0)
			tail = head;
		else
			head->next->prev=head;
		count++;
	}
	void addTail(const T& data) {
		tail = new Node(T(data), tail,nullptr);
		if (count==0)
			head=tail;
		else
			tail->prev->next=tail;
		count++;
	}

	// Removal
	bool removeHead() {
		if (count==0)
			return false;
		Node* temp = head;
		head = head->next;
		delete temp;
		if (count!=1)
			head->prev = nullptr;
		else
			tail=nullptr;
		count--;
		return true;
	}
	bool removeTail() {
		if (count==0)
			return false;
		Node* temp = tail;
		tail = tail->prev;
		delete temp;
		if (count!=1)
			tail->next = nullptr;
		else
			head=nullptr;
		count--;
		return true;
	}
	void clear() {
		if (count==0) {
			return;
		}
		Node* current=head;
		while (current) {
			Node* temp=current;
			current=temp->next;
			delete temp;
		}
		head=nullptr;
		tail=nullptr;
		count=0;
	}

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept {
		if (this==&other) {
			return *this;
		}
		clear();
		head=other.head;
		tail=other.tail;
		count=other.count;
		other.count=0;
		other.head=nullptr;
		other.tail=nullptr;
		return *this;

	}
	LinkedList<T>& operator=(const LinkedList<T>& rhs) {
		if (&rhs==this) {
			return *this;
		}
		clear();
		Node* current = rhs.head;
		while (current) {
			addTail(current->data);
			current=current->next;
		}
		return *this;
	}

	// Construction/Destruction
	LinkedList() : head(nullptr), tail(nullptr), count(0) {}
	LinkedList(const LinkedList<T>& list) : head(nullptr), tail(nullptr), count(0) {
		Node* current=list.head;
		while (current) {
			addTail(current->data);
			current=current->next;
		}

	}
	LinkedList(LinkedList<T>&& other) noexcept {
		head=other.head;
		tail=other.tail;
		other.head=nullptr;
		other.tail=nullptr;
		count=other.count;
		other.count=0;
	}
	~LinkedList() {
		clear();
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


