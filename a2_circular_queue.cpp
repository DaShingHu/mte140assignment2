#include <iostream>
#include "a2_circular_queue.hpp"

using namespace std;
typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue(): items_(NULL), capacity_(16), head_(0), tail_(0), size_(0) 
{
	items_ = new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity): items_(NULL), capacity_(capacity), head_(0), tail_(0), size_(0)
{
	items_ = new QueueItem[capacity_];
}

CircularQueue::~CircularQueue()
{
	delete [] items_;
	items_ = NULL;
}

bool CircularQueue::empty() const
{    
	return size_ == 0;
}

bool CircularQueue::full() const
{
	return size_ == capacity_;
}

int CircularQueue::size() const
{  
	return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
}

QueueItem CircularQueue::dequeue()
{
	if(empty())
		return EMPTY_QUEUE;
	QueueItem LastItem = items_[head_];
	for(int i = head_; i < tail_; i++)
	{
		items_[i] = items_[i + 1];
	}
	return LastItem;	
}

QueueItem CircularQueue::peek() const
{
	if(empty())
		return EMPTY_QUEUE;
	return items_[head_];
}

void CircularQueue::print() const
{
	if(empty())
		cout << "Circular Queue is empty!" << endl;
	else
	{
		for(int i = head_; i < tail_; i++)
		{
			cout << cout << i << ": " << items_[i] << endl;
		}
	}
}
