#ifndef __APP2_CPP
#define APP2_CPP
#include "stack.cpp"

int Find_F_N(int n)
{
	Stack<int> stack;

	if(n!=0 && n!=1)
	{
		stack.push(0);
		stack.push(1);

		for(int i=1;i<n;i++)
		{
			int temp1=stack.pop();
			int temp2=stack.pop();

			stack.push(temp1);
			stack.push(temp2+temp1);

		}
		return stack.top();
	}
	else
	{
		return n;
	}
}

int main()
{
	cout<<Find_F_N(46)<<endl;
}

#endif
