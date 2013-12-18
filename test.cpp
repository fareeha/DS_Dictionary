#include "list.cpp"

int main()
{
	List<int> l;
	for(int i=10; i>0; i--)
	{
		cout<<i<<endl;
		l.insertSorted(i);
	}
}
