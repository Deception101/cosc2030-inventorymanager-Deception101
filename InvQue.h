template <class T>
class InvQue
{
	private:
		struct QueueNode
		{
			T value;
			QueueNode *next;
		};

		QueueNode *front;	
		QueueNode *rear;	

	public:
		InvQue()
			{ front = nullptr; rear = nullptr; }
		void enqueue(T);
		void dequeue(T &);
		bool isEmpty();
};


template <class T>
void InvQue<T>::enqueue(T item)
{
	QueueNode *newNode = new QueueNode;
	newNode->value = item;
	newNode->next = nullptr;

	if (isEmpty())
	{
		front = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
}


template <class T>
void InvQue<T>::dequeue(T &item)
{
	if (isEmpty())
	{
		cout << "The queue is empty.\n";
	}
	else
	{
		QueueNode *temp = front;
		item = front->value;
		front = front->next;
		delete temp;

		if (front == nullptr)	
			rear = nullptr;
	}
}


template <class T>
bool InvQue<T>::isEmpty()
{
	return front == nullptr;
}

