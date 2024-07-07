#ifndef vectoref_h
#define vectoref_h 
#include <iostream>
using namespace std;
template<class T>
class vectoref {
public:
    vectoref();
    vectoref(int size_);
    vectoref(int s, T* a);
    vectoref(const vectoref& other);
    vectoref(std::initializer_list<T> list);
    vectoref(const vectoref&& other);
     // operators
    vectoref& operator=(const vectoref& other);
    T& operator[](int value);
    vectoref  operator+(const vectoref& gg);
    // methods
    vectoref& push_back(T newger);
    vectoref& pop_back();
    void getFull();
    void resize(int value);
    bool empty();
    int gsize();
    vectoref& insert(T empl, int index2);
    vectoref& erase(int index2);
    vectoref& push_front(T newger);
    vectoref& pop_front();
    vectoref& assign(int value, int ga);
    vectoref& sort();
    vectoref& Resort();
    void clear();
    // Destructor
    ~vectoref();
private:
    int index_push;
    int size;
    T* arr;
};
//constructors release
template<class T>
vectoref<T>::vectoref() : arr(nullptr), size(0), index_push(0) {}
template <class T>
vectoref<T>::vectoref(int size_)
{
    this->size = size_;
    arr = new T[size];
    this->index_push = 0 ;
}
template <class T>
vectoref<T>::vectoref(int s,T*a) :size (s),arr(new T[size])
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = a[i];
    }
}
template <class T>
vectoref<T>::vectoref(const vectoref& other)
{
    this->size = other.size;
    arr = new T[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = other.arr[i];
    }
}
template <class T>
vectoref<T>::vectoref(std::initializer_list<T> list):size(list.size()),arr ( new T[size]){
   
    int i = 0;
    for (const T& element : list) {
        arr[i++] = element;
    }
}
template <class T>
vectoref<T>::vectoref(const vectoref&& other):size(other.size), arr (other.arr)
{
    if(this!=other)
    other.arr = nullptr;
}
// operators
template <class T>
vectoref<T>& vectoref<T>::operator=(const vectoref&other )
{
    if (this != &other)
    {
        delete[] arr;
        size = other.size;
        arr = new T[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}
template<class T>
T& vectoref<T>:: operator[](int value)
{
    return arr[value];
}
template <class T>
vectoref<T> vectoref<T>::operator+(const vectoref& gg)
{
    int sizefull = this->size + gg.size;
    T* go = new T[sizefull];
    int s = 0;
    for (int i = 0; i < size; ++i)
    {
        go[s++] = arr[i];
    }
    for (int i = 0; i < gg.size; ++i)
    {
        go[s++] = gg.arr[i];
    }
    return vectoref(sizefull, go);
}
 //methods
template<class T>
vectoref<T>& vectoref<T>::push_back(T newger)
{
    if (size == 0)
    {
        arr = new int[5];
        arr[index_push++] = newger;
        size = 5;
    }
    else if (index_push < size )
    {
        arr[index_push++] = newger;
    }
    else  if (index_push == size)
    {
        T* temp = new int[size + 1];
        for (int i = 0; i < size; ++i)
        {
            temp[i] = arr[i];
        }
        temp[size++] = newger;
        delete[]arr;
        arr = temp;
        index_push++;
    }
    return *this;
}
template <class T>
vectoref<T>& vectoref<T>::pop_back()
{

    if (size > 0) {
        T* gg = new int[size - 1];
        int id = 0;
        for (int i = 0; i < size - 1; ++i)
        {
            gg[i] = arr[id++];
        }
        delete[]arr;
        arr = gg;
        size--;
    }
    else {
        cout << "ERROR"<<endl;
        size = 0;
        index_push = 0;
    }
    return *this;
}
template <class T>
void vectoref<T>::getFull()
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
}
template <class T>
void vectoref<T>::resize(int value)
{
    if (size == 0)
    {
        arr = new T[value];
        size = value;
    }
    else {
        T* temp = new T[value];
        for (int i = 0; i < value; ++i)
        {
            temp[i] = arr[i];
        }
        delete[]arr;
        arr = temp;
        size = value;
    }
}
template<class T>
bool vectoref<T>::empty()
{
    return size == 0 ;
}
template<class T>
vectoref<T>& vectoref<T>::insert(T empl, int index2)
{
    int index_insert = 0;
    T* fd = new T[size + 1];
    for (int i = 0; i < size; ++i)
    {
        if (index2 != index_insert)
        {
            fd[index_insert++] = arr[i];
        }
        else if (index2 == i) {
            fd[index_insert++] = empl;
            fd[index_insert++] = arr[i];
        }
        if (index2 == size)
        {
            fd[index_insert] = empl;
        }
        else {
            cout << "ERROR";
        }
    }
    delete[]arr;
    arr = fd;
    size++;
    return *this;
}
template <class T>
vectoref<T>& vectoref<T>::erase(int index2)
{
    if (index2 < 0 || index2 >= size) {
        cout << "ERROR" << endl;
        return *this;
    }
    int j = 0;
    T* fd = new T[size - 1];
    for (int i = 0; i < size; ++i)
    {
        if (index2 != i)
        {
            fd[j++] = arr[i];
        }
    }
    delete[]arr;
    arr = fd;
    size--;
    return *this;
}
template <class T>
vectoref<T>& vectoref<T>::push_front(T newger)
{
    if (size == 0)
    {
        arr = new int[5];
        arr[index_push++] = newger;
        size = 5;
    }
    else  if (index_push >= 0)
    {
        int id = 0;
        T* temp = new int[size + 1];
        size++;
        for (int i = 1; i < size; ++i)
        {
            temp[i] = arr[id++];
        }
        temp[0] = newger;
        delete[]arr;
        arr = temp;
        index_push++;
    }
    return *this;
}
template<class T>
vectoref<T>& vectoref<T>::assign(int value,int ga)
{
    T* temp = new T[value];
    size=value;
    for (int i = 0; i < value; ++i)
    {
        temp[i] = ga;
    }
    delete[]arr;
    arr = temp;
    return *this;
}
template<class T>
 vectoref<T>& vectoref<T>::pop_front()
{
     if (size > 0) {
         T* gg = new int[size - 1];
         int id = 1;
         for (int i = 0; i < size - 1; ++i)
         {
             gg[i] = arr[id++];
         }
         delete[]arr;
         arr = gg;
         size--;
     }
     else {
         cout << "ERROR" << endl;
         size = 0;
         index_push = 0;
     }
     return *this;
}
 template<class T>
 vectoref<T>& vectoref<T>::sort()
 {
         for (int i = 0; i < size; ++i)
         {
             for (int j = i + 1; j < size; ++j)
             {
                 if (arr[i] > arr[j])
                 {
                     swap(arr[i], arr[j]);
                 }
             }
         }
     return  *this;     
 }
 template<class T>
 vectoref<T>& vectoref<T>::Resort()
 {
     for (int i = 0; i < size; ++i)
     {
         for (int j = i + 1; j < size; ++j)
         {
             if (arr[i] < arr[j])
             {
                 swap(arr[i], arr[j]);
             }
         }
     }
     return  *this;
 }
 template<class T>
 void vectoref<T>::clear()
 {
     delete[]arr;
     arr = nullptr;
     size = 0;
 }
 template <class T>
 int vectoref<T>::gsize()
 {
     return size;
 }
template <class T>
vectoref<T>::~vectoref()
{
    if(arr != nullptr) {
        delete[] arr;
    }
}
#endif
