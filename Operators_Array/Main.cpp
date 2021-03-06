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

	cout << "Перегрузка операторов > и < \n";

	cout << "Массив а: ";
	a.print();

	cout << "Массив а1: ";
	a1.print();

	cout << "Массив а2: ";
	a2.print();

	cout << "Сумма элементов массивов a1 > a : ";
	result = a1 > a;
	cout << result << endl;

	cout << "Сумма элементов массивов a1 < a : ";
	result = a1 < a;
	cout << result << endl;

	cout << "Сумма элементов массивов a2 > a : ";
	result = a2 > a;
	cout << result << endl;

	cout << "Сумма элементов массивов a2 < a : ";
	result = a2 < a;
	cout << result << endl;

	cout << "\n--------------------------------------\n";

	cout << "Создание массива Array3 = Array + Array1 \n";
	cout << "Массив а: ";
	a.print();

	cout << "Массив а1: ";
	a1.print();	

	MyArray a3(a.GetSize() + a1.GetSize());	
	a3 = a + a1;

	cout << "Массив а3: ";
	a3.print();

	cout << "\n--------------------------------------\n";

	cout << "Создание массива Array4 = а + 55 \n";
	cout << "Массив а: ";
	a.print();

	MyArray a4(a.GetSize() + 1);
	a4 = a + 55;

	cout << "Массив а4: ";
	a4.print();

	cout << "\n--------------------------------------\n";

	cout << "Создаем массив с отличительными уникальными (неповторяющимися) элементами двух массивов \n";
	cout << "Массив а: ";
	a.print();

	cout << "Массив а2: ";
	a1.print();

	MyArray a5(a.GetSize() + a1.GetSize());
	a5 = a % a1;

	cout << "Массив а5: ";
	a5.print();

	cout << "\n--------------------------------------\n";

	cout << "Создаем массив с общими уникальными (неповторяющимися) элементами двух массивов \n";

	MyArray a7(20);
	a7.FillArrayNoSrand();

	cout << "Массив а: ";
	a.print();

	cout << "Массив а7: ";
	a7.print();

	MyArray a6(a.GetSize() + a7.GetSize());
	a6 = a * a7;

	cout << "Массив а6: ";
	a6.print();

	cout << "\n--------------------------------------\n";
	//перегрузка оператора присваивания
	a2 = a1 = a3;

	cout << "Перегрузка оператора присваивания a2 = a1 = a3\nМассив а1: \n";
	a1.print();

	cout << "Массив а2: \n";
	a2.print();

	cout << "\n--------------------------------------\n";

	cout << endl;
	system("pause");
}