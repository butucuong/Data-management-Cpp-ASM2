#ifndef LIST_H_
#define LIST_H_
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "Setting.h"
using namespace std;
//page 342bjarnstrououp


template<class T>
class List:public Setting{
private:
	T*h ;
	int capacity;
	int size;
	
public:
	List(int n);
	List(const List& g);
	List();
	void newAlloc();
	void Sort();
	T& operator [](int k);
	T& operator = (const T& p);
	void deepCopy(const T& source);
	~List();
	bool SetSize(int);    // force capacity change (up or down)
	bool SetCapacity(int);    // force capacity change (up or down)
	int  Size() const;    // return size
	int  Capacity() const;    // return capacity
	bool PushBack(T& Tval);
	void add(T c,int indx);
	T& get(int pos);
	void Swap(T& i, T& j);
	
	
};


#endif /* LIST_H_ */