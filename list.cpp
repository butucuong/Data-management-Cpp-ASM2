#include "list.h"

template <class T>
List<T>::List()
{
    capacity = 10;  //default
    size = 0;
    h = new T[capacity];

}

template <class T>
List<T>::List(int n) {
    if (n <= 0) {
        capacity = 10;
    }
    
    capacity = n;
    size = 0;
    h = new T[capacity];
    
}


template <typename T>
List<T>::~List()
{
    size = 0;
    capacity = 0;
    delete []h;
    h = nullptr;  
    
   
}

template<class T>
void List<T>::add(T c,int indx)
{
    if (size + 1 <= capacity)
        newAlloc();
    for (int i = indx; i < size; i++) {
        h[i + 1] = h[i];
    }
    h[indx]=c;
}

template<class T>
T& List<T>::get(int pos)
{
    if (pos >= size) cerr<< "Out of range";
    else
    return h [pos];
}

template <typename T>
bool List<T>::PushBack( T& Tval)
// grow by doubling capacity
{
    if (size >= capacity)
    {
        if (capacity== 0)
        {
            if (!SetCapacity(1))
                return 0;
        }
        else if (!SetCapacity(2 * capacity))
            return 0;
    }
    h[size] = Tval;
    ++size;
    return 1;
}
template <class  T>
void List<T>::newAlloc() {
    capacity = 2 * size;
    T* temp = new T[capacity];
    for (int i = 0; i < size; i++)
    {
        temp[i] = h[i];
    }
    // delete old array and have new array take the place of old array
    delete[] h;
    h = temp;
}


template<class T>
void List<T>::Swap(T &i, T &j)
{
    T temp ;

    temp = i;
    i = j;
    j = temp;
    
}

template <class T>
int List<T>::Size() const {
    return size;
}
template <class T>
int List<T>::Capacity() const {
    return capacity;
}

template <class T>
T& List<T>::operator [](int k) {
    
    if (k > size)
    {
        cerr << "** Vector<T> Error: vector index out of range!\n";
        if (k >= capacity)
            exit(EXIT_FAILURE);
    }
    return h[k];
}
template <class T>
T& List<T>::operator = (const T& p) {
    if (this == p)
         return *this;
    else {
        deepCopy(p);
        return *this; 
    }
       

}

template <class T>
void List<T>::deepCopy(const T& source) {
   
    if (capacity != source.capacity)
    
    

    this->capacity = source.capacity;
    this->size = source.size;
    delete[]h;
    if (source.h) {
        h = new T[capacity];
        for (int i = 0; i < size; i++) {
            h[size] = source.h[size];
        }
    }
    else {
        h = nullptr;

    }

}
template <class T>
List<T>::List(const List& g) {
    deepCopy(g);
}

template <class T>
bool List<T>::SetCapacity(int newcapacity ) {
    if (newcapacity == 0)
    {
        delete[] h;
        h= nullptr;
        size = capacity= 0;
        return 1;
    }
    if (newcapacity != capacity)
    {
        T* newcontent = new T[newcapacity];
        if (newcontent == nullptr)
            return 0;
        if (size > newcapacity)
            size= newcapacity;
        for (int i = 0; i < size; ++i)
        {
            newcontent[i] =h[i];
        }
        capacity = newcapacity;
        delete[] h;
        h = newcontent;
    }

    return 1;
}
template <typename T>
bool List<T>::SetSize(int newsize)
// (re)set size
{
    if (newsize > capacity)
        if (!SetCapacity(newsize))
            return 0;
    size = newsize;
    return 1;
}
template <class T>
void List<T>::Sort() {
    for (int i = 0; i < size-1 ; i++) {
        for (int j = 0; j < size -i -1; j++) {
            if (h[j] > h[j + 1]) {
                Swap(h[j], h[j +1]);
            }
        }
    }
}


//Specialize template for pointer type


