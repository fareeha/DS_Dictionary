#ifndef __APP3_CPP
#define APP3_CPP
#include "queue.cpp"
#include <iostream>
#include <fstream>

using namespace std;

List<string> Dictionary()
{
//read into linked list
//sort insert as the new word come
//ends when lists ends
//string compare

	List<string> list;
	list.insertAtTail("a");
	list.insertAtTail("b");
	list.insertAtTail("c");
	list.insertAtTail("d");
	list.insertAtTail("e");
	list.insertAtTail("f");
	list.insertAtTail("g");
	list.insertAtTail("h");
	list.insertAtTail("i");
	list.insertAtTail("j");
	list.insertAtTail("k");
	list.insertAtTail("l");
	list.insertAtTail("m");
	list.insertAtTail("n");
	list.insertAtTail("o");
	list.insertAtTail("p");
	list.insertAtTail("q");
	list.insertAtTail("r");
	list.insertAtTail("s");
	list.insertAtTail("t");
	list.insertAtTail("u");
	list.insertAtTail("v");
	list.insertAtTail("w");
	list.insertAtTail("x");
	list.insertAtTail("y");
	list.insertAtTail("z");

	cout<<list.length()<<endl;

	ifstream myfile;
	myfile.open("words.txt");

	string word;


	while(!myfile.eof())
	{
		getline(myfile,word);
		ListItem<string> *tmp = list.searchFor(string(1,word[0]));
		if(tmp!=NULL)
		{
			tmp->wordList.insertSorted(word);
		}
	}

	myfile.close();
	return list;
}

Queue<string> FindWords(string sub_str)
{
	List<string> sortedlist = Dictionary();
	Queue<string> queue;

	ListItem<string>* sortedtemp = sortedlist.getHead();

	while(sortedtemp!=NULL)
	{
		ListItem<string>* insideTemp = sortedtemp->wordList.getHead();
		while(insideTemp!=NULL)
		{
			unsigned found = insideTemp->value.find(sub_str);
			if(std::string::npos != insideTemp->value.find(sub_str))//Taken from cplusplus reference. npos indicated end of string it no match is founf it will equal to npos
			{
				queue.enqueue(insideTemp->value);
			}
			insideTemp=insideTemp->next;
		}
		sortedtemp=sortedtemp->next;
	}

	return queue;
}

int main()
{
	Queue<string> q = FindWords("lol");
	for(int i=0; i<q.length(); i++)
	{
		cout<<q.dequeue()<<endl;
	}
}

#endif
