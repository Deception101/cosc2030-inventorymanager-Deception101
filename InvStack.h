// DynStack template

template <class T>
class InvStack
{
	private:
		struct StackNode
		{
			T value;
			StackNode *next;
		};

		StackNode *top;

	public:
		InvStack()
			{ top = nullptr; }
		void push(T);
		void pop(T &);
		bool isEmpty();
};

//*********************************************************
// Member function push pushes the argument onto          *
// the stack.                                             *
//*********************************************************

template <class T>
void InvStack<T>::push(T num)
{
	StackNode *newNode = nullptr;

	// Allocate a new node & store Num
	newNode = new StackNode;
	newNode->value = num;
	
	// If there are no nodes in the list
	// make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else		// Otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
}

//*********************************************************
// Member function pop pops the value at the top          *
// of the stack off, and copies it into the variable      *
// passed as an argument.                                 *
//*********************************************************

template <class T>
void InvStack<T>::pop(T &num)
{
	StackNode *temp = nullptr;
	
	if (isEmpty())
	{
		cout << "The stack is empty.\n";
	}
	else   // pop value off top of stack
	{
		num = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}
 
//*********************************************************
// Member funciton isEmpty returns true if the stack      *
// is empty, or false otherwise.                          *
//*********************************************************

template <class T>
bool InvStack<T>::isEmpty()
{
	bool status = false;

	if (!top)
	{
		status = true;
	}
		
	return status;
}