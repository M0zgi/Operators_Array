#include "Array.h"

MyArray::MyArray(int _size)
{	
	if (_size > 0)
	{
		size = _size;
		array = new int[size];
	}
}

MyArray::MyArray(const MyArray& obj)
{
     size = obj.size;
	 array = new int[size];

	 for (size_t i = 0; i < size; i++)
	 {
		 array[i] = obj.array[i];
	 }
}

bool MyArray::operator==(const MyArray& obj)
{
	if (size != obj.size)
		return false;

	else
	{
		int count = 0;

		for (size_t i = 0; i < size; i++)
		{
			if (array[i] == obj.array[i])
				count++;
		}
		
		return count == size;
	}
}

bool MyArray::operator!=(const MyArray& obj)
{
	if (size != obj.size)
		return true;

	else
	{
		int count = 0;

		for (size_t i = 0; i < size; i++)
		{
			if (array[i] == obj.array[i])
				count++;
		}

		return !(count == size);
	}
}

bool MyArray::operator>(const MyArray& obj)
{
	int sum1 = 0, sum2 = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum1 += array[i];
		sum2 += obj.array[i];
	}

	return sum1 > sum2;
}

bool MyArray::operator<(const MyArray& obj)
{
	int sum1 = 0, sum2 = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum1 += array[i];
		sum2 += obj.array[i];
	}

	return sum1 < sum2;
}

MyArray& MyArray::operator=(const MyArray& obj)
{	
	size = obj.size;

	if (array != nullptr)
	{
		delete[] array;
	}	
	
	array = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		array[i] = obj.array[i];
	}
	return *this;
}

int& MyArray::operator[](int index)
{
	if (index < 0 || index >= size)
	{
		cout << "Указанного индекса нет в массиве: ";
				
		return index;
	}		
	
	else
	return array[index];
}

int MyArray::operator[](int index) const
{
	if (index < 0 || index >= size)
	{
		cout << "Указанного индекса нет в массиве: ";

		return index;
	}

	else
		return array[index];
}

MyArray::~MyArray()
{
	delete[] array;
}

void MyArray::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

void MyArray::FillArrayNoSrand()
{	
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % 10;
	}
}
