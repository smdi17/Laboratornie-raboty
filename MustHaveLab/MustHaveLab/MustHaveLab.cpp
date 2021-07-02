// MustHaveLab.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Harbinger																			//класс harbringer
{
private:
	string h_name;
	string CatchPhrase;
	int h_age;

public:
	Harbinger(string name = "", int age = 0) : h_name(name), h_age(age)					//конструкторы harbringer
	{}

	Harbinger(string name, int age, string CatchPhrase1)
	{
		h_name = name;
		h_age = age;
		CatchPhrase = CatchPhrase1;
	}

	void setName(string name)															//сеттеры harbringer
	{h_name = name;}

	void setAge(int age)
	{h_age = age;}

	void setCatchPhrase(string CatchPhrase1)
	{CatchPhrase = CatchPhrase1;}

	string getCatchPhrase() const														//геттеры harbringer
	{return CatchPhrase;}

	string getName() const
	{
		return h_name;
	}

	int getAge() const
	{
		return h_age;
	}
};

class Prophet : public Harbinger														//паблик наследование пророком предвестника
{
private:
	string ph_name;
	string ph_call;
	int ph_age;
	string* MagnumOpus;

public:
	Prophet(string name = "", int age = 0, string call = "") : ph_name(name), ph_age(age), ph_call(call)	//Конструктор пророка
	{
		MagnumOpus = new string[3];
	}

	void findmax()																		//поиск самой длинной строки в магнум опусе для ph_call
	{
		int b;
		for (size_t i = 0; i < 2; i++)
		{
			b = MagnumOpus[i].length();
			if (b <= MagnumOpus[i + 1].length())
			{
				ph_call = MagnumOpus[i + 1];
			}
		}
	}

	void setMagnumOpus(string MagnumOp[])												//сеттер магнум опуса
	{
		for (size_t i = 0; i < 3; i++)
		{
			if (MagnumOp[i].length() <= 25)												//проверка на длину строки для массива
			{
				MagnumOpus[i] = MagnumOp[i];
			}
		}
		findmax();
	}

	const string* getMagnumOpus()														//геттер магнум опуса
	{ return MagnumOpus;}

	void setpName(string name)															//сеттеры
	{ph_name = name;}

	void setpAge(int age)
	{
		ph_age = age;
	}

	void setpCall(string call)
	{
		ph_call = call;
	}

	string getpName() const																//геттеры
	{
		return ph_name;
	}

	int getpAge() const
	{
		return ph_age;
	}

	string getpCall() const
	{
		return ph_call;
	}
};

class DeusEx : public Prophet															//Public наследование богом из пророка
{
private:
	string gd_name;
	int gd_year;

public:
	DeusEx(string name = "Будда", int year = 1001) : gd_name(name), gd_year(year)		//конструктор по умолчанию
	{}

	void setgYear(int year)																//сеттеры
	{gd_year = year;}

	void setgName(string name)
	{gd_name = name;}

	int getgYear() const																//геттеры
	{return gd_year;}

	string getgName() const
	{return gd_name;}

	void print()																		//вывод
	{
		cout << getName() << " в возрасте " << getAge() << " говорил, что " << getCatchPhrase() << endl;
		cout << "Первое пророчество: " << getMagnumOpus()[0] << endl;
		cout << "Второе пророчество: " << getMagnumOpus()[1] << endl;
		cout << "Главное пророчество: " << getpCall() << endl;
		cout << "Так говорил " << getpName() << " в возрасте " << getpAge() << endl;
		cout << "В год " << gd_year << " пришел " << gd_name << ", которого предракали " << getName() << " и " << getpName() << endl;
	}
};

class Believer : private DeusEx											//privat наследование верующим бога из
{

private:
	string bv_name;
	int bv_age;

public:
	Believer(string name, int age)										//конструктор
	{
		bv_name = name;
		bv_age = age;
	}

	void printBeliever(DeusEx deusex, Prophet prophet)				   	//вывод belivera
	{
		cout << "Верующий " << getbName() << " молится " << deusex.getgName() << " именем " << prophet.getpName() << ". С " << deusex.getgYear() << " и по сей день." << endl;
	}

	void setbAge(int age)												//сеттеры belivera
	{bv_age = age;}

	void setbName(string name)
	{bv_name = name;}

	int getbAge() const													//геттеры belivera
	{return bv_age;}

	string getbName() const
	{return bv_name;}
};

int main()
{
	SetConsoleCP(1251);													//русификация
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");

	Prophet z("Азамат", 87);											//переменные
	DeusEx m("Феруз", 699);
	Believer yuliy("Юлий", 15);

	
	m.setCatchPhrase("он прозрел");										//заполнение полей deusEX
	m.setAge(45);
	m.setName("Петр");
	m.setpName("Азамат");
	m.setpAge(87);
	m.setpCall("автомобиль");
	

	string Mass[3] = { "Скоро сессия", "Закончится", "И начнутся каникулы" };           //строка опусов
	m.setMagnumOpus(Mass);																//заполнение опусов магнумов

	m.print();																			//вывод deusEx
	yuliy.printBeliever(m, z);															//вывод beliver
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
