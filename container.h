#ifndef CONTAINER_H
#define CONTAINER_H
template <class T>
class container {
public:
    virtual void pop() = 0;
    virtual void push(T) = 0;
    virtual T top() const = 0;
    virtual unsigned int size() = 0;
    virtual ~container() {};
};
#endif /* CONTAINER_H */
