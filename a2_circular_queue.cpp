#include <iostream>
#include "a2_circular_queue.hpp"


using namespace std;
typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
	items_ = new QueueItem[16];
	this->head_ = 0;
	this->tail_ = 0;
	this->size_ = 0;
	this->capacity_ = 16;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
	items_ = new QueueItem[capacity];
	this->head_ = 0;
	this->tail_ = 0;
	this->size_ = 0;
	this->capacity_ = capacity;
}

CircularQueue::~CircularQueue()
{
	delete [] this->items_;
}

bool CircularQueue::empty() const
{    
	return this->size_ == 0;
}

bool CircularQueue::full() const
{
	return this->size_ == this->capacity_;
}

int CircularQueue::size() const
{  
	return this->size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
	if (!this->full())
	{
		items_[tail_] = value;
		this->tail_ = (this->tail_+ 1) % this->capacity_;
		this->size_++;
		return true;
	}
	return false;
}

QueueItem CircularQueue::dequeue()
{
	if (!empty())
	{
		QueueItem lastItem = items_[head_];
		this->head_ = (this->head_ + 1) % this->capacity_;
		this->size_--;
		return lastItem;
	}
	return EMPTY_QUEUE;
}

QueueItem CircularQueue::peek() const
{
	if (!empty())
	{
		return items_[head_];
	}
	return EMPTY_QUEUE;
}

void CircularQueue::print() const
{
	if(empty())
		cout << "Circular Queue is empty!" << endl;
	else
	{
		// Tail > head
		if (tail_ > head_)
		{
			for (int i = head_; i < tail_; i++)
			{
				cout << i << ": " << items_[i] << endl; 
			}
		}
		// Tail == head and size != 0
		else if (tail_ == head_ && size_ != 0)
		{
			int counter = 0;
			for (int i = head_; i < size_; i++)
			{
				cout << counter << ": " << items_[i] << endl;
				counter++;
			}
			for (int i = 0; i < tail_; i++)
			{
				cout << counter << ": " << items_[i] << endl;
				counter++;
			}
		}
		// Head > tail
		else
		{
			int counter = 0;
			for (int i = head_; i < size_; i++)
			{
				cout << counter << ": " << items_[i] << endl;
				counter++;
			}
			for (int i = 0; i < tail_; i++)
			{
				cout << counter << ": " << items_[i] << endl;
				counter++;
			}
		}
}
}

