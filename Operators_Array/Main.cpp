#include"Array.h"

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout.setf(std::ios_base::boolalpha);

	locale loc(cout.getloc(), new ::numpunct);
	cout.imbue(loc);

	MyArray a(10);
	a.FillArrayNoSrand();
	cout << "Массив а: ";
	a.print();

	cout << "Массив а1: ";
	MyArray a1(5);
	a1.FillArrayNoSrand();
	a1.print();	

	cout << "Массив а2: ";
	MyArray a2(10);
	a2.FillArrayNoSrand();
	a2.print();
	cout << "\n--------------------------------------\n";

	//перегрузка оператора равенства ==
	cout << "Сравнение на равенство массива a1 с массивом a2: ";
	bool result = a1 == a2;
	cout << result << endl;

	cout << "Сравнение на равенство массива a2 с массивом a: ";
	result = a2 == a;
	cout << result << endl;

	//перегрузка оператора присваивания
	cout << "Перегрузка оператора присваивания a2 = a\nМассив а2: ";
	
	a2 = a;
	a2.print();

	//перегрузка оператора равенства ==
	cout << "Сравнение на равенство массива a2 с массивом a: ";
	result = a2 == a;
	cout << result << endl;

	cout << "\n--------------------------------------\n";

	cout << "Массив а: ";
	a.print();

	cout << "Массив а1: ";
	a1.print();

	cout << "Массив а2: ";
	a2.print();

	//перегрузка оператора неравенства !=
	cout << "Сравнение на неравенство массива a1 с массивом a2: ";
	result = a1 != a2;
	cout << result << endl;

	cout << "Сравнение на неравенство массива a2 с массивом a: ";
	result = a2 != a;
	cout << result << endl;

	cout << "\n--------------------------------------\n";

	cout << "Перегрузка оператора []\n";

	cout << "Получение значения массива по индексу\n";
	cout << a[9] << endl;

	cout << "Получение значения массива по несуществующему индексу\n";
	cout << a[30] << endl;

	cout << "Изменение значения массива по существующему индексу\n";
	
	a[0] = 100;
	cout << a[0] << endl;

	cout << "Изменение значения массива по несуществующему индексу\n";
	a[30] = 100;
	cout << endl;
	cout << a[30] << endl;
	cout << endl;

	cout << "Массив а после внесения изменений: ";
	a.print();

	cout << "\n--------------------------------------\n";

	//перегрузка оператора присваивания
	a2 = a1 = a;

	cout << "Перегрузка оператора присваивания a2 = a1 = a\nМассив а1: \n";
	a1.print();

	cout << "Массив а2: \n";
	a2.print();

	cout << "\n--------------------------------------\n";

	cout << endl;
	system("pause");
}