#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template <class T>
class Vector
{
private:
	T* values;
	int size;
	int maxSize;

	bool isFull() const;
	void resize();
public:
	Vector();
	Vector(const Vector&);
	Vector<T>& operator=(const Vector&);

	void push_back(const T&);
	void remove(const int&);

	const int getSize() const;

	T& operator[](const int&) const;

	~Vector();
};

template <class T>
Vector<T>::Vector() : size(0), maxSize(10)
{
	values = new T[maxSize];
}

template <class T>
Vector<T>::Vector(const Vector& rhs) : size(rhs.size), maxSize(rhs.maxSize)
{
	values = new T[maxSize];
	for (int i = 0; i < size; i++)
	{
		values[i] = rhs.values[i];
	}
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
	if (this != &rhs)
	{
		delete[] values;

		maxSize = rhs.maxSize;
		size = rhs.size;

		values = new T[maxSize];

		for (int i = 0; i < size; i++)
		{
			values[i] = rhs.values[i];
		}
	}
	return *this;
}

template <class T>
bool Vector<T>::isFull() const
{
	return size == maxSize;
}

template <class T>
void Vector<T>::resize()
{
	maxSize *= 2;
	T* newValues = new T[maxSize];

	for (int i = 0; i < size; i++)
	{
		newValues[i] = values[i];
	}
	delete[] values;
	values = newValues;
}

template <class T>
void Vector<T>::push_back(const T& newValue)
{
	if (isFull())
	{
		resize();
	}
	values[size++] = newValue;
}

template <class T>
void Vector<T>::remove(const int& pos)
{
	if (pos >= 0 && pos < size)
	{
		for (int i = pos; i < size - 1; i++)
		{
			values[i] = values[i + 1];
		}
		size--;
	}
	else {
		std::cout << "Wrong position \n";
	}
}

template <class T>
const int Vector<T>::getSize() const
{
	return size;
}

template <class T>
T& Vector<T>::operator[](const int& pos) const
{
	if (pos < 0 || pos >= size)
	{
		T* arr = new T();
		return *arr;
	}
	else
	{
		return values[pos];
	}
}

template <class T>
Vector<T>::~Vector()
{
	delete[] values;
}

template <class T>
std::ostream& operator << (std::ostream& out, const Vector<T*>& v)
{
	for (int i = 0; i < v.getSize(); i++)
	{
		out << i << "\t" << *v[i];
	}
	return out;
}

#endif