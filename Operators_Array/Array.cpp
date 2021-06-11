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

MyArray& MyArray::operator+(const MyArray& obj)
{	
	int tempsize = size + obj.size;

	MyArray *temp = nullptr;
		
	temp = new MyArray(tempsize);

	for (size_t i = 0; i < size; i++)
	{
		(*temp)[i] = array[i];
	}	

	for (size_t i = 0; i < obj.size; i++)
	{
		(*temp)[size + i] = obj.array[i];
	}

	return *temp;
}

MyArray& MyArray::operator+(int n)
{
	int tempsize = size + 1;

	MyArray* temp = nullptr;

	temp = new MyArray(tempsize);

	for (size_t i = 0; i < size; i++)
	{
		(*temp)[i] = array[i];
	}

	(*temp)[size] = n;

	return *temp;
}

MyArray& MyArray::operator*(const MyArray& obj)
{
	int tempsize = size + obj.size;

	int count = 0, countsize = 0, key = 0;

	MyArray* temp = nullptr;

	temp = new MyArray(tempsize);

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < obj.size; j++)
		{
			if (array[i] == obj.array[j])
			{
				count++;
			}

			if (count > 0)
			{

				for (size_t k = 0; k < countsize; k++)
				{
					if (array[i] == (*temp)[k])
					{
						key++;
					}
				}

				if (key == 0)
				{
					(*temp)[countsize] = array[i];
					countsize++;
				}
			}
		}

		count = 0;
		key = 0;
	}

	for (size_t i = 0; i < obj.size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (obj.array[i] == array[j])
			{
				count++;
			}

			if (count > 0)
			{
				for (size_t k = 0; k < countsize; k++)
				{
					if (obj.array[i] == (*temp)[k])
					{
						key++;
					}
				}

				if (key == 0)
				{
					(*temp)[countsize] = obj.array[i];
					countsize++;
				}
			}
		}

		count = 0;
		key = 0;
	}


	MyArray* result = nullptr;

	result = new MyArray(countsize);

	//получили массив с уникальными элементами
	for (size_t i = 0; i < countsize; i++)
	{
		(*result)[i] = (*temp)[i];
	}

	return *result;
}

MyArray& MyArray::operator%(const MyArray& obj)
{
	int tempsize = size + obj.size;

	int count = 0, countsize = 0, key = 0;

	MyArray* temp = nullptr;

	temp = new MyArray(tempsize);

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < obj.size; j++)
		{
			if (array[i] != obj.array[j])
			{
				count++;
			}

			if (count == obj.size)
			{
				
				for (size_t k = 0; k < countsize; k++)
				{
					if (array[i] == (*temp)[k])
					{
						key++;
					}
				}

				if (key == 0)
				{
					(*temp)[countsize] = array[i];
					countsize++;
				}				
			}
		}

		count = 0;
		key = 0;
	}

	for (size_t i = 0; i < obj.size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (obj.array[i] != array[j])
			{
				count++;
			}

			if (count == size)
			{
				for (size_t k = 0; k < countsize; k++)
				{
					if (obj.array[i] == (*temp)[k])
					{
						key++;
					}
				}

				if (key == 0)
				{
					(*temp)[countsize] = obj.array[i];
					countsize++;
				}
			}
		}

		count = 0;
		key = 0;
	}


	MyArray* result = nullptr;

	result = new MyArray(countsize);

	//получили массив с уникальными элементами
	for (size_t i = 0; i < countsize; i++)	
	{				
		(*result)[i] = (*temp)[i];
	}

	return *result;
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

int MyArray::GetSize()
{
	return size;
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
