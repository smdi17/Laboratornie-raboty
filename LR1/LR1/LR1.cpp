﻿// LR1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;
void massiv()                       //замена всех чётных чисел в массиве на 0
{
	int array[10];                  // массив 10 элементов
	for (int i = 0; i < 10; i++)
		array[i] = rand() % 20;     // составление массива из случайных чисел от 0 до 20
	for (int i = 0; i < 10; i++)
		cout << array[i] << ' ';
	cout << endl;

	for (int i = 0; i < 10; i++)    // замена четных чисел на 0
		if (array[i] % 2 == 0) array[i] = 0;
	for (int i = 0; i < 10; i++)

		cout << array[i] << ' ';
	cout << endl;
}

void poiskssimvola()                                    // поиск символа в строке
{
	string s, l;                                        // s - символ, l - строка
	int p;                                              // p - место символа в строке
	cout << "Введите символ:" << endl;
	do {
		cin >> s;
		if (s.size() > 1) {                             //проверка символа
			cout << "ERROR! Введите символ:" << endl;
			s.clear();
		}
		else
			break;
	} while (true);

	cout << "Введите строку:" << endl;
	do {
		cin >> l;
		if (l.size() < 2) {                             //проверка строки
			cout << "ERROR! Введите строку:" << endl;
			l.clear();
		}
		else
			break;
	} while (true);

	p = l.find(s);                                      //поиск символа 
	if (p < 0) cout << "Символ отсутствует." << endl;
	else cout << "Символ занимает " << p + 1 << " позицию." << endl;
}

void opredelelmatrici()
{
	int m[3][3];                                                    //матрица 3 на 3
	int opredelitel;                                                //определитель

	cout << endl << "Введите целые числа: //каждое число с новой строки " << endl;        // ввод матрицы
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> m[i][j];

	for (int i = 0; i < 3; i++)                                     // вывод матрицы
	{
		cout << endl;
		for (int j = 0; j < 3; j++)
			cout << m[i][j] << " ";
	}
	//подсчет определителя матрицы:
	opredelitel = m[0][0] * m[1][1] * m[2][2] + m[2][0] * m[0][1] * m[1][2] + m[1][0] * m[2][1] * m[0][2] - m[2][0] * m[1][1] * m[0][2] - m[0][0] * m[2][1] * m[1][2] - m[1][0] * m[0][1] * m[2][2];

	cout << endl << "Определитель матрицы = "<< opredelitel << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	massiv();
	poiskssimvola();
	opredelelmatrici();
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
