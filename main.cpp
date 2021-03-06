#include "stdafx.h"
#include<iostream>
#include<sstream> 
#include<fstream> 
#include<string> 
#include<Windows.h>
#include"Building.h"
#include"Node.h"
#include"List.h"
#include "Brick.h"
#include "Cottage.h"
#include "Monolithic.h"
#include "Panel.h"
#include "Fabrica.h"
using namespace std;

void check0(string str)
{
	int flag = 0;

	while (flag != 1) 
	{
		for (int i = 0; i < str.length(); i++) 
		{
			if (str[i] >= '0')//    
			{    
				if (str[i] <= '6')    
				{   
					flag = 1; 
				}  
				else   
				{    
					throw "НЕВЕРНАЯ КОМАНДА!!";
				}
			}
			else
			{ 
				throw"НЕВЕРНАЯ КОМАНДА!! ВВЕДИТЕ ЧИСЛО :)"; 
			}
		}
	}
}

void check(string line) 
{
	for (int i = 0; i < line.size(); ++i)
	{ 
		if (!isdigit(line[i]))
		{ 
			throw "!!!Введите число!!!";
		} 
	}
}

void check2(string str)
{
	int flag = 0;  while (flag != 1) 
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] > '0') 
			{
				if (str[i] <= '9')
				{ 
					flag = 1;
				}
				else 
				{
					throw"НЕВЕРНАЯ КОМАНДА!!";
				}
			}
			else
			{
				throw"НЕВЕРНАЯ КОМАНДА!! ВВЕДИТЕ ЧИСЛО :)";
			}
		}
	}
}

void check3(string line) 
{
	for (int i = 0; i < line.size(); ++i) 
	{
		if (isdigit(line[i])) 
		{
			int counter = 0;    //цифра    
			while (isdigit(line[i++]))//еще цифра   
				counter++; 
			if (counter > 1)
			{ 
				throw"НЕВЕРНАЯ КОМАНДА!!"; 
			}
		}
		else 
			throw"НЕВЕРНАЯ КОМАНДА!";
	}
}

void clean(string file)
{
	fstream f;
	f.open(file, fstream::out | fstream::trunc);  
	f.close();
}

int main()
{
	setlocale(LC_ALL, "Russian"); 

	Brick* brick = new Brick;
	Cottage* cottage = new Cottage;
	Monolithic* monolithic = new Monolithic;
	Panel* panel = new Panel;

	List l;

	string inf = ""; 
	string br = ""; 
	string ch = ""; 
	int value = 0; 
	int val = 0;

	stringstream myString; 
	stringstream myString2;

	char number = '0'; 
	do 
	{
		cout << "*********МЕНЮ**********" << endl << endl;  
		cout << "1) Редактировать информацию " << endl << endl; 
		cout << "2) Показать информацию" << endl << endl;
		cout << "3) Сохранить в файл " << endl << endl;  
		cout << "4) Очистить файл" << endl << endl;   
		cout << "5) Очистить список" << endl << endl;
		cout << "6) Добавить запись" << endl << endl;  
		cout << "7) Загрузить данные из файла" << endl << endl;   
		cout << "8) Удалить запись" << endl << endl;  
		cout << "9) Выход" << endl << endl; 
		cout << "***********************" << endl << endl; 
		cout << "Введите команду: ";  
		try 
		{
			inf = "";   
			SetConsoleCP(1251); 
			cin >> inf;  
			SetConsoleCP(866);  
			check2(inf);   
			check3(inf);//одна цифра   
			for (int i = 0; i < 1; i++)  
			{   
				number = inf[i];  
			}     
		}
		catch (const char* msg)
		{
			cout << endl << msg << endl;   
			number = 'e';
		}  
		cout << "***********************" << endl << endl; 
		cout << endl << endl;   
		try
		{
			switch (number)
			{
			case'e':
				cout << "Вы неправильно ввели команду!" << endl; 
				break;  
			case '1':     
				value = 0;   
				val = 0;   
				br = "";   
				ch = "";  
				if (l.GetSize() > 0) 
				{
					l.show(); 
					cout << ">>> РЕДАКТОР\n\n"; 
					cout << "1) Введите номер записи для редактирования (индексация начинается с 0!): ";//индекс  
					SetConsoleCP(1251); 
					cin >> br;   
					SetConsoleCP(866);    
					check0(br);    
					check(br);//цифра       

					cout << "\n2) Выбор графы для редактирования:\n" << "цвет(1)\n этажность(2)\n число квартир(3)\n площадь(4)\n адресс(5)\n год сдачи(6)\n"; 
					  
					SetConsoleCP(1251);   
					cin >> ch;    
					SetConsoleCP(866);    
					check(ch);//цифра    
					check3(ch);//одна цифра 
					
					cout << "\n3) Ввод новой информации:\n";  
					SetConsoleCP(1251);   
					cin.ignore(7777, '\n'); 
					getline(cin, inf);     
					SetConsoleCP(866); 
					value = atoi(br.c_str());   
					val = atoi(ch.c_str());

					l[value]->modify(val, inf);   
					cout << ">>>Информация была изменена! Вот результат:\n";  
					l[value]->show_inf();
				}
				else   
					cout << "В списке нет записей!!!\n";   
					cout << endl << endl;  
				break;    
			case'2':   
				cout << ">>>ВСЕ ДАННЫЕ\n\n";  
				l.show();  
				cout << endl << endl; 
				break;  
			case'3':   
				clean("Build.txt");
				cout << ">>>ЗАПИСЬ ДАННЫХ В ФАЙЛ\n\n";  
				l.write();
				cout << endl << endl; 
				break;  
			case'4':   
				cout << ">>>Файл очищен\n";   
				clean("Build.txt");
				cout << endl << endl; 
				break;   
			case'5':  
				l.clear();  
				l.show();   
				cout << endl << endl; 
				break;  
			case'6':  
				br = "";  
				ch = ""; 
				inf = "";   
				cout << ">>>ДОБАВЛЕНИЕ ЗАПИСИ\n";  
				cout << "Добавить в конец(1), в начало(2) или по индексу(3) ?\n";   
				SetConsoleCP(1251);  
				cin >> ch;   
				SetConsoleCP(866); 
				check2(ch);    
				check3(ch);  
				cout << "\n1) Выберете здание: \n";   
				cout << "(1)кирпичный дом\n(2)коттедж\n(3)кирпично-монолитный дом\n(4)панельный дом\n\n";  
				SetConsoleCP(1251);  
				cin >> br;  
				SetConsoleCP(866);  
				check2(br);    
				check3(br);

				if (ch == "1") 
				{
					cout << ">>>ДОБАВЛЕНИЕ В КОНЕЦ СПИСКА\n"; 
					if (br == "1") 
					{
						l.push(brick->create_build());
					}
					else if (br == "2")
					{ 
						l.push(cottage->create_build()); 
					}
					else if (br == "3") 
					{
						l.push(monolithic->create_build());
					}
					else if (br == "4")
					{
						l.push(panel->create_build()); 
					}
					else
					{ 
						throw"НЕПРАВИЛЬНАЯ КОМАНДА! НЕТ ТАКОЙ ПОРОДЫ"; 
					}
				}
				else if (ch == "2")
				{
					cout << ">>>ДОБАВЛЕНИЕ В НАЧАЛО СПИСКА\n";  
					if (br == "1")
					{
						l.push_front(brick->create_build());
					}
					else if (br == "2")
					{ 
						l.push_front(cottage->create_build());
					}
					else if (br == "3")
					{
						l.push_front(monolithic->create_build());
					}
					else if (br == "4")
					{ 
						l.push_front(panel->create_build());
					}
					
					else 
					{ 
						throw"НЕПРАВИЛЬНАЯ КОМАНДА!";
					}
				}
				else if (ch == "3")
				{
					cout << "ВВЕДИТЕ ИНДЕКС (индексация начинается с 0!): ";     
					SetConsoleCP(1251); 
					cin >> inf;    
					SetConsoleCP(866); 
					check0(inf);   
					val = atoi(inf.c_str());

					if (br == "1") 
					{ 
						l.insert(brick->create_build(), val); 
					}
					else if (br == "2") 
					{ 
						l.insert(cottage->create_build(), val);
					}
					else if (br == "3") 
					{
						l.insert(monolithic->create_build(), val);
					}
					else if (br == "4") 
					{ 
						l.insert(panel->create_build(), val);
					}
					
					else 
					{ 
						throw"НЕПРАВИЛЬНАЯ КОМАНДА!";
					}
				}
				else
				{ 
					throw"НЕПРАВИЛЬНАЯ КОМАНДА!!"; 
				}     
				cout << endl << endl;   
				break;   
			case'7':   
				l.read();   
				l.show();  
				break;   
			case'8':   
				br = ""; 
				ch = "";   
				inf = "";   
				cout << ">>>УДАЛЕНИЕ ЗАПИСИ\n"; 
				if (l.GetSize()> 0) 
				{
					cout << "Удалить запись из конца(1), из начала(2) спимка или по индексу(3) ?\n"; 
					SetConsoleCP(1251); 
					cin >> ch;   
					SetConsoleCP(866);    
					check2(ch);    
					check(ch);

					if (ch == "1") 
					{ 
						cout << "УДАЛЕНИЕ ИЗ КОНЕЦА СПИСКА\n";  
						l.pop_back();
					}
					else if (ch == "2") 
					{
						cout << "УДАЛЕНИЕ ИЗ НАЧАЛА СПИСКА\n\n";  
						l.pop(); 
					}
					else if (ch == "3") 
					{
						cout << "ВВЕДИТЕ ИНДЕКС (индексация начинается с 0!): ";  
						SetConsoleCP(1251);   
						cin >> inf;     
						SetConsoleCP(866);  
						check0(inf);
						val = atoi(inf.c_str());
						l.removeAt(val);
					}
					else
					{ 
						throw"НЕПРЯВИЛЬНАЯ КОМАНДА!!"; 
					}
				}
				else 
				{
					throw"СПИСОК ПУСТОЙ!!!"; 
				}
				cout << endl << endl; 
				break;    
			case'9':  
				break;
			}
		}
		catch (const char* msg)
		{
			cout << endl << msg << endl;   
			inf = "";   
			br = "";   
			ch = "";  
			value = 0; 
			val = 0;
		}
	} 
	while (number != '9');

	delete brick;
	delete cottage;
	delete monolithic;
	delete panel;

	system("pause"); 
	return 0;
}

