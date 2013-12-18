#ifndef __APP1_CPP
#define APP1_CPP
#include "list.cpp"
#include <fstream>
#include <ostream>


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



int main()
{
	List<string> l = Dictionary();
	ListItem<string>* t = l.getHead();
	t = t->next;
	ListItem<string>* h = t->wordList.getHead();
	while(h!=NULL)
	{
		cout<<h->value<<endl;
		h=h->next;
	}

}


#endif




