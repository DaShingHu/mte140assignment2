#include <iostream>
#include "a2_dynamic_stack.hpp"

using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	this->items_ = new StackItem[16];
	this->capacity_ = 16;
	this->size_ = 0;
	this->init_capacity_ = 16;
}

DynamicStack::DynamicStack(unsigned int size_)
{
	this->items_ = new StackItem[size_];
	this->capacity_ = size_;
	this->size_ = 0;
	this->init_capacity_ = size_;
}

DynamicStack::~DynamicStack()
{
	delete [] items_;
}

bool DynamicStack::empty() const
{
	return this->size_ == 0;
}

int DynamicStack::size() const
{
	return this->size_;
}

void DynamicStack::push(StackItem value)
{
	if (this->size_ < this->capacity_)
	{
		this->items_[size_] = value;
		this->size_++;
	}
	else
	{
		StackItem* temp = new StackItem[this->capacity_ * 2];
		for (int i = 0; i < this->capacity_ * 2; i++)
		{
			temp[i] = this->items_[i];
		}
		delete[] this->items_;
		this->items_ = temp;
		this->capacity_ = this->capacity_ * 2;
		this->push(value);
	}
	
}

StackItem DynamicStack::pop()
{
		if(!empty())
	{
		StackItem LastItem = items_[size_ - 1];
		items_[size_ - 1] = 0;
		size_--;
		
		if(size_ <= (capacity_/4) && (capacity_/2) >= init_capacity_)   
		{
			StackItem* temp = new StackItem[capacity_/2];
			for(int i = 0; i < size_; i++)
			{
				temp[i] = items_[i];
			}
			delete [] items_;
			this->capacity_ = this->capacity_ / 2;
			items_ = temp;
			temp = NULL;
		}
		return LastItem;
	}
	return EMPTY_STACK;
}

StackItem DynamicStack::peek() const
{
	if(!empty())
	{
		return items_[size_ - 1];
	}
	return EMPTY_STACK;
}

void DynamicStack::print() const
{
	if(!empty())
	{
		for(int i = 0; i < size_; i++)
		{
			cout << i << ": " << items_[i] << endl;
		}
	}
	else
		cout << "The Stack is empty!" << endl;
}

