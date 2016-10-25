#ifndef Q_ADA
#define Q_ADA
#include "container.h"
#include <queue>

template <class T>
class queue_adaptor
	: public container<T> {
private:
	std::queue<T> *s;
public:
	queue_adaptor();
	~queue_adaptor();
    void pop();
    void push(T);
    T top() const;
    unsigned int size();
};

template <class T>
queue_adaptor<T>::queue_adaptor() {
	this->s = new std::queue<T>();
}

template <class T>
queue_adaptor<T>::~queue_adaptor() {
	delete this->s;
}

template <class T>
void queue_adaptor<T>::pop() {
	this->s->pop();
}

template <class T>
void queue_adaptor<T>::push(T element) {
	this->s->push(element);
}

template <class T>
T queue_adaptor<T>::top() const{
	return this->s->front();
}

template <class T>
unsigned int queue_adaptor<T>::size() {
	return this->s->size();
}
#endif /* Q_ADA */
