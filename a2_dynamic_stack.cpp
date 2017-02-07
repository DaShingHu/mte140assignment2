#include <iostream>
#include "a2_dynamic_stack.hpp"

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
	this->items_ = new StackItem[16];
	this->capacity_ = 16;
	this->size_ = 0;
	this->init_capacity_ = 0;
}

DynamicStack::DynamicStack(unsigned int size_)
{
	this->items_ = new StackItem[16];
	this->capacity_ = size_;
	this->size_ = 0;
	this->init_capacity_ = 0;
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
		this->items_[size_ + 1] = value;
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
}

StackItem DynamicStack::peek() const
{
}

void DynamicStack::print() const
{
}

