// Vector.h
#ifndef VECTOR_H
#define VECTOR_H
#define DEFAULT_SIZE 3
#define MAX_SIZE 100000

//-------------------------------------------------------------------------
// include
#include <iostream>

/**
 * @class Vector
 * @brief handle vector
 * 
 * @tparam T 
 */
template <class T>
class Vector
{
public:
    /**
	 * @brief Construct a new Vector object
	 * 
	 * @param length 
	 */
    Vector(int length = DEFAULT_SIZE);

    /**
	 * @brief Destroy the Vector object
	 * 
	 */
    ~Vector();

    /**
	 * @brief handle size
	 * @return int 
	 */
    int Size() { return len; };

    /**
	 * @brief check if the data is empty
	 * 
	 * @return int 
	 */
    int isEmpty() { return len == 0; };

    /**
	 * @brief sets push back
	 * 
	 * @param item 
	 * @return void
	 */
    void push_back(T item);

    /**
	 * @brief added minimum
	 * 
	 * @param i 
	 * @return T& 
	 */
    T &at(int i);

    /**
	 * @brief resize newSize;
	 * @return void
	 */
    void pop();

    /**
	 * @brief Get the Max Len object
	 * 
	 * @return int 
	 */
    int getMaxLen() { return maxLen; };

private:
    /**
	 * @brief resize data
	 * 
	 * @param newSize 
	 */
    void resize(int newSize);

    T *list;
    int len;
    int maxLen;
};

/**
 * @brief Construct a new Vector< T>:: Vector object
 * 
 * set vector empty at first
 * @tparam T 
 * @param length 
 */
template <class T>
Vector<T>::Vector(int length)
{
    if (length <= 0)
    {
        std::cout << "Vector size must be positive" << std::endl;
        maxLen = DEFAULT_SIZE;
    }
    else
    {
        maxLen = length;
    }
    len = 0;
    list = new T[maxLen];
}

/**
 * @brief Destroy the Vector< T>:: Vector object
 * 
 * @tparam T 
 */
template <class T>
Vector<T>::~Vector()
{
    if (list != nullptr)
    {
        delete[] list;
        list = nullptr;
    }
}

/**
 * @brief resize the vector
 * delets the list after storing data
 * 
 * @tparam T 
 * @param newSize 
 * @return void
 */
template <class T>
void Vector<T>::resize(int newSize)
{
    T *newList = new T[maxLen];
    T *newListP = newList;
    T *oldListP = list;
    while (oldListP != (list + len))
    {
        *(newListP) = *(oldListP);

        //move to next location/address
        newListP++;
        oldListP++;
    } //this loop swap value until the last location of list

    maxLen = newSize;
    delete[] list;
    list = newList;
}

/**
 * @brief push back the element in a vector
 * 
 * @tparam T 
 * @param item 
 * @return void
 */
template <class T>
void Vector<T>::push_back(T item)
{
    if (len >= maxLen / 2)
    {
        //resize();
        Vector::resize(maxLen * 2);
    }
    list[len++] = item;
}

/**
 * @brief resize the vector 
 * 
 * @tparam T 
 * @return void
 */
template <class T>
void Vector<T>::pop()
{
    if (len < maxLen / 2)
    {
        Vector::resize(maxLen / 2);
    }
    len--;
}

/**
 * @brief return the list as requested
 * 
 * @tparam T 
 * @param i 
 * @return T& - data of that position
 * @return default is 1st element from the list
 */
template <class T>
T &Vector<T>::at(int i)
{
    if ((i >= 0) && (i < len))
    {
        return list[i];
    }
    return list[0];
}

#endif
