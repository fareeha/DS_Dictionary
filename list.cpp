#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "list.h"
#include <iostream>
using namespace std;

template <class T>
List<T>::List()
{
	head=NULL; //initialize
}

template <class T>
List<T>::List(const List<T>& otherList)
{

	head=NULL;
	ListItem<T>* dummy=otherList.head;

	while(dummy!=NULL)
	{
		insertAtTail(dummy->value); //???
		dummy=dummy->next;
	}

//put NULL at end?
//return;
}

template <class T>
List<T>::~List() //done
{
	while(head!=NULL)
	{
		deleteHead();
	}
}

template <class T>
void List<T>::insertAtHead(T item)
{

	ListItem<T>* New= new ListItem<T>(item);

	if(head==NULL)
	{
	head=New;
	New->next=NULL;
	New->prev=NULL;
	}

	else
	{
	ListItem<T>* New= new ListItem<T>(item);
	ListItem<T>* temp;
	temp=head;
	New->next=temp;
	temp->prev=New;
	head=New; //updating head
	New->prev=NULL;
	}
}

template <class T>
void List<T>::insertAtTail(T item)
{
//traverse to find end
        ListItem<T>* New= new ListItem<T>(item);

        if(head==NULL)
        {
 	       head=New;
	   	    New->next=NULL;
			New->prev=NULL;
			return;
        }

	else
	{
		ListItem<T>* tail = head;
		while(tail->next != NULL)
		{
			tail = tail->next;
		}
//	ListItem<T>* tail=getTail();
//		New->next=NULL;
		tail->next=New;
		New->prev=tail;
		New->next=NULL;
	}
}

template <class T>
void List<T>::insertAfter(T toInsert, T afterWhat)
{
		ListItem<T>* afterWhatNode=searchFor(afterWhat);

		if(afterWhatNode==NULL)
		{
		//ListItem<T>* result=searchFor(item);
		cout<<"Item not found"<<endl;
		return;
		}
		
		else
		{
			if(afterWhatNode->next==NULL)
			{
			insertAtTail(toInsert);
			}
			
			else
			{
			ListItem<T>* New= new ListItem<T>(toInsert);
			ListItem<T>* temp=afterWhatNode->next;

			afterWhatNode->next=New;
			New->next=temp;
			New->prev=afterWhatNode;
			temp->prev=New;
			}
		}

}

template <class T>
void List<T>::insertSorted(T item)
{
	ListItem<T>* check = head;
	if(head==NULL)
	{
		insertAtHead(item);
		return;
	}
	if(head->next==NULL)
	{
		if(item < head->value)
		{
			insertAtHead(item);
		}
		else
		{
			insertAtTail(item);
		}
		return;
	}


	while(check->next!=NULL)
	{
		if(check->value > item)
		{
//			if(check==head)
//			{
//				insertAtHead(item);
//				return;
//			}
			if(check==head)
			{
				insertAtHead(item);
				return;
			}
			else
			{
					ListItem<T>* temp = check->prev;
					ListItem<T>* tempNew = new ListItem<T>(item);
					temp->next = tempNew;
					tempNew->prev=temp;
					tempNew->next=check;
					check->prev=tempNew;
					return;
			}
		}
		check = check->next;
	}
	if(check->next == NULL)
	{
		if(item < check->value)
		{
			ListItem<T>* temp = check->prev;
			ListItem<T>* tempNew = new ListItem<T>(item);
			temp->next = tempNew;
			tempNew->prev=temp;
			tempNew->next=check;
			check->prev=tempNew;
			return;
		}
		else
		{
			insertAtTail(item);
		}
	}
//sort insert
/*
                ListItem<T>* temp1;
				ListItem<T>* temp2;

                temp1=ead;
				temp2=temp1->next;


		if(head==NULL)
		{
        ListItem<T>* New= new ListItem<T>(item);
		head=New;
		New->next=NULL;  //or New = tail
		return;
		}


	if(head->next==NULL)
	{
		if((head->value)>item)
		{
		insertAtHead(item);
		return;
		}

		if((head->value)<item)
		{
		insertAtTail(item);
		return;
		}
	}

                        while(temp2!=NULL)
                        {
                                if((temp2->value)>item)
                                {
                                        insertAfter(item,temp1);
                                        break;
                                }

                        temp1=temp1->next;
						temp2=temp2->next;
                        }

return;
*/
}


template <class T>
ListItem<T>* List<T>::getHead()
{
	return head;
}

template <class T>
ListItem<T>* List<T>::getTail()
{
	ListItem<T>* temp1;
	ListItem<T>* temp2;

	if(head==NULL){
	//cout<<"List empty"<<endl;
	return NULL;
	}

	temp1=head;
	temp2=temp1->next;

	while(temp2!=NULL)
	{
		temp1=temp1->next;
		temp2=temp2->next;
	}

	return temp1;
}


template <class T>
ListItem<T> *List<T>::searchFor(T item)
{

	ListItem<T>* temp1;

	if(head==NULL)
	return NULL;

	temp1=head;

	while(temp1!=NULL)
	{
		if(temp1->value==item)
		return temp1;

	temp1=temp1->next;
	}

//	cout<<"Item not found"<<endl;
	return NULL;

}


template <class T>
void List<T>::deleteElement(T item)
{
//traverse to find elt
//delete it

	if(head==NULL)
	{
	return;
	}

	ListItem<T>* result=searchFor(item);

if(result==NULL)
{
return;
}

	if(result==head)
	{
		deleteHead();
	}

	else if(result==getTail())
	{
		deleteTail();
	}

	else
	{

	ListItem<T>* temp1=head;
	ListItem<T>* temp2=temp1->next;
	ListItem<T>* temp3=temp2->next;

	while(temp2!=NULL)
	{
		if(temp2==result)
		{
		temp1->next=temp3;
		temp3->prev=temp1;
		temp2->next=NULL;
		temp2->prev=NULL;
		delete temp2;
		}

		temp1=temp1->next;
		temp2=temp2->next;
		temp3=temp3->next;
    }//while
	}//else

}

template <class T>
void List<T>::deleteHead()
{
	ListItem<T>* temp1=head;

	if(head==NULL)
	{
		return;
	}

	//ListItem<T>* temp2=temp1->next;
	head=head->next;
	if(temp1->next!=NULL)
	{
		head->prev=NULL;
//		delete temp1;
//		return;
	}
	else
	{
		head=NULL;
	}
//	head=head->next;
//	temp2->prev=NULL;
	temp1->next=NULL;
	delete temp1;
}

template <class T>
void List<T>::deleteTail()
{
 ListItem<T>* result=getTail();
 
	if(result==NULL)
	{
	return;
	}
 
	else if(result==getHead())
	{
	deleteHead();
	}
	
	else
	{
	ListItem<T>* temp=result->prev;

	temp->next=NULL;
	result->prev=NULL;
	delete result;
	}

}


template <class T>
int List<T>::length()
{
	ListItem<T>* temp=head;
	int count=0;

	while(temp!=NULL)
	{
	temp=temp->next;
	count++;
	}

	return count;
}

#endif
