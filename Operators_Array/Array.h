﻿#pragma once

#include<iostream>
#include <Windows.h>

using namespace std;

struct numpunct
	: std::numpunct<char>
{
	std::string do_truename() const { return "правда"; }
	std::string do_falsename() const { return "враньё"; }
};

class MyArray
{
public:

	//конструктор с одним параметром
	explicit MyArray(int _size);

	//конструктор копирования
	MyArray(const MyArray& obj);

	//оператор равенства ==
	bool operator == (const MyArray& obj);

	//оператор неравенства !=
	bool operator != (const MyArray& obj);

	//оператор присваивания =
	MyArray & operator = (const MyArray& obj);

	//оператор получение значения массива по индексу
	int operator [] (int index) const;

	//оператор изменения значения массива по индексу
	int& operator [] (int index);



	//деструктор
	~MyArray();

	//вывод массива на экрна
	void print() const;

	//заполнение массива
	void FillArrayNoSrand();

private:
	int size = 0;
	int* array = nullptr;
	
};
