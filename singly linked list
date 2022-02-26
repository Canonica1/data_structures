#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

template<class T>
class List
{
public:
	List();
	~List();
	void push_front(T data);
	void clear();
	void pop_front();
	void pop_back();
	void push_back(T data);
	void insert(T value, int index);
	void removeAt(int index);
	int getSize() {
		return Size;
	}
	T& operator[] (const int index);

private:
	template<class T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}

	};
	int Size;
	Node<T> *head;
};
template<class T>
List<T>::List()
{
	Size = 0;
	this->head = nullptr;
}
template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<class T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<class T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;

	delete temp;
	Size--;
}

template<class T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<class T>
void List<T>::push_back(T data)
{
	if (this->head == nullptr)
	{
		this->head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}
template<class T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{	
		push_front(data);
	}
	else {

		Node<T> *previous = this->head;
		for (int i = 0; i < index-1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

template<class T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else {

		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toRemove = previous->pNext;
		previous->pNext = toRemove->pNext;
		delete toRemove;
		Size--;
	}
}

template<class T>
T & List<T>::operator[](const int index)
{
	Node<T> *current = this->head;
	int counter = 0;
	while (current != nullptr)
	{
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	List<int> lst;
	int arr[] = {1,4,4,5,3,5};
	lst.push_back(100);
	lst.push_back(2);
	lst.push_back(1);
	lst.push_back(44);
	lst.push_back(2222);
	lst.pop_front();
	lst.push_front(123123);
	lst.insert(1000100100, 1);
	lst.removeAt(2);
	for (int i = 0; i < lst.getSize(); i++)
	{
		cout << lst[i] << ' ';
	}
	


}
