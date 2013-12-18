#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

template <class T>
Queue<T>::Queue()
{
}

template <class T>
Queue<T>::Queue(const Queue<T>& otherQueue) : list(otherQueue.list)
{
}

template <class T>
Queue<T>::~Queue()
{
	for(int i=0;i<list.length();i++)
	{
	list.deleteHead();
	}
}

template <class T>
void Queue<T>::enqueue(T item)
{
	list.insertAtTail(item);
}

template <class T>
T Queue<T>::front()
{
	return (list.getHead())->value;
}

template <class T>
T Queue<T>::dequeue()
{
//front();
	T item = (list.getHead())->value;
	list.deleteHead();
	return item;
}

template <class T>
int Queue<T>::length()
{
	return list.length();
}

template <class T>
bool Queue<T>::isEmpty()
{
	if(length()>0)
		return false;
	else
		return true;
}


#endif
