#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

template <class T>
Stack<T>::Stack()
{
}

template <class T>
Stack<T>::Stack(const Stack<T>& otherStack) : list(otherStack.list)
{
}

template <class T>
Stack<T>::~Stack()
{
	for(int i=0;i<length();i++)
	{
		list.deleteHead();
	}
}

template <class T>
void Stack<T>::push(T item)
{
	list.insertAtHead(item);
}

template <class T>
T Stack<T>::top()
{
	return (list.getHead())->value;
}

template <class T>
T Stack<T>::pop()
{
	T item = (list.getHead())->value;
	list.deleteHead();
	return item;
}

template <class T>
int Stack<T>::length()
{
	return list.length();
}

template <class T>
bool Stack<T>::isEmpty()
{
	if(length()==0)
		return true;
	else
		return false;
}

#endif
