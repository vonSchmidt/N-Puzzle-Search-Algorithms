#ifndef S_ADA
#define S_ADA
#include "container.h"
#include <stack>

template <class T>
class stack_adaptor
	: public container<T> {
private:
	std::stack<T> *s;
public:
	stack_adaptor();
	~stack_adaptor();
    void pop();
    void push(T);
    T top() const;
    unsigned int size();
};

template <class T>
stack_adaptor<T>::stack_adaptor() {
	this->s = new std::stack<T>();
}

template <class T>
stack_adaptor<T>::~stack_adaptor() {
	delete this->s;
}

template <class T>
void stack_adaptor<T>::pop() {
	this->s->pop();
}

template <class T>
void stack_adaptor<T>::push(T element) {
	this->s->push(element);
}

template <class T>
T stack_adaptor<T>::top() const{
	return this->s->top();
}

template <class T>
unsigned int stack_adaptor<T>::size() {
	return this->s->size();
}
#endif /* S_ADA */
