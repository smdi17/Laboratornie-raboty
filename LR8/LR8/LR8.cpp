// LR8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void chislo()
{
	int number;
	cout << "Введите пятизначное число" << endl;                            //Ввод числа
	cin >> number;
	for (int i = 0; i < 5; i++)                                             // цикл с выводом числа и его деление без остатка
	{
		cout << number % 10 << endl;
		number = number / 10;
	}
	cout << endl;
}

void registr()                                                              //Изменение регистра буквы
{
	char c;                                                                 //Вводимая буква
	cout << "Введите латинскую букву в нижнем регистре:" << endl;
	cin >> c;
	c -= 32;                                                                //Изменение значения буквы по таблице ASCII
	cout << "Буква в верхнев регистре: " << c << endl;                      //Вывод
}

void sredarifm()                                                            //Подсчёт среденго арифметического массива
{
	const int razmer = 10;                                                  //Размер массива
	int sum = 0;                                                            //Переменная для подсчёта суммы элементов массива
	int array[razmer];                                                      //Массив
	for (int i = 0; i < razmer; i++)                                        //Заполнение массива случайными числами
		array[i] = rand() % 35;

	cout << "Массив: " << endl;                                             //Вывод массива
	for (int i = 0; i < razmer; i++)
		cout << array[i] << ' ';
	cout << endl;

	for (int i = 0; i < razmer; i++)                                        //Подсчёт суммы всех элементов массива
		sum += array[i];

	cout << "Среднее арифметическое массива = " << double(sum) / razmer << endl;        // Вывод среднего арифметического
}

int main()
{
	setlocale(LC_ALL, "RUS");
	chislo();
	cout << endl;
	registr();
	cout << endl;
	sredarifm();
	system("pause");
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
