#include "stdafx.h"
#include "List.h"
#include "Fabrica.h"
#include"Node.h" 
#include<fstream> 
#include<string> 
using namespace std;

List::List(const List & other) 
{  
	Node* tmp = other.head;  
	while (tmp != 0) 
	{
		push_front(tmp->GetData());  
		tmp = tmp->GetNext(); 
	} 

}

List::~List() 
{
	while (size) 
	{ 
		pop();
	}

}

void List::pop() 
{
		if (size > 0) 
		{ 
			Node *temp = head;  
			head = head->GetNext(); 
			delete temp; 
			size--; 
		}  
		if (size == 0) 
		{
			cout << ">>> СПИСОК ПУСТОЙ " << endl;
		}

}

void List::push_front(Build* data)
{
	head = new Node(data, head); 
	head->GetData()->house(); 
	head->GetData()->set_inf(); 
	size++;

}

void List::push(Build * data) 
{
	if (size == 0)
	{ 
		head = new Node(data, nullptr); 
		head->GetData()->house();
		head->GetData()->set_inf(); 
	}
	if (size > 0) 
	{
		Node *current = this->head; 
		while (current->GetNext() != nullptr) 
		{ 
			current = current->GetNext(); 
		}   
		current->SetNext(new Node(data, nullptr)); 
		current->GetNext()->GetData()->house();  
		current->GetNext()->GetData()->set_inf();
	} 
	size++;

}
////////////////////////////////////////////////
void List::push2(Build * data) 
{
	head = new Node(data, head); 
	size++; 
}

void List::pop_back() {
	if (size == 0)
	{
		cout << ">>> СПИСОК ПУСТОЙ " << endl;
	}  
	if (size > 0) { removeAt(size - 1);
	}

}

void List::clear() 
{
	while (this->size) 
	{ 
		this->pop(); 
	} 
	cout << endl;

}

void List::show()
{
	if (size > 0) 
	{ 
		cout << "Вот весь список: \n\n";  
		Node *temp = head; 
		while (temp != nullptr)
		{ 
			temp->GetData()->show_inf();  
			cout << endl;   
			temp = temp->GetNext();
		}
	}
	else
	{ 
		cout << ">>> СПИСОК ПУСТОЙ " << endl; 
	} 
	cout << endl;

}

void List::write() 
{
	Node* temp = this->head;  
	while (temp != nullptr) 
	{
		if (temp->GetData()->Gethouse() == 1)//brick 
		{    
			temp->GetData()->write_inf();  
		}  
		temp = temp->GetNext();  
	}    
	temp = this->head;
	while (temp != nullptr) 
	{   
		if (temp->GetData()->Gethouse() == 2)//cottage  
		{   
			temp->GetData()->write_inf();  
		}   
		temp = temp->GetNext(); 
	} 

	temp = this->head; 
	while (temp != nullptr)
	{
		if (temp->GetData()->Gethouse() == 3)//molithic
		{  
			temp->GetData()->write_inf(); 
		}  
		temp = temp->GetNext(); 
	}

	temp = this->head;  
	while (temp != nullptr)
	{
		if (temp->GetData()->Gethouse() == 4)//panel 
		{    
			temp->GetData()->write_inf();  
		}   
		temp = temp->GetNext(); 
	} 
	cout << "\n>>>Информация записана в файл\n";
	}

void List::read() 
{   
	this->clear();
	fstream f;  
	string str = " "; 
	Node* temp = this->head; 
	int count = 0; 

	f.open("Build.txt", fstream::in);
	if (!f.is_open())
	{ 
		throw "Ошибка открытия файла!!";
	}
	else 
	{
		while (!f.eof())
		{
			str = "";  
			getline(f, str);   
			count++;
		}   
		count--;//колво строчек       			

		if (count % 7 != 0) 
		{ 
			cout << "Неверная запись в файле!\n";   
			return; 
		}  
		if (count == 0) 
		{ 
			cout << "Файл пустой!\n";   
			return;
		}
	} 
	f.close();

	f.open("Build.txt", fstream::in);

	while (!f.eof()) 
	{
		getline(f, str);

		if (str == "brick") 
		{     
			///////////////////////////////////////////////
			Brick* brick = new Brick;
			this->push2(brick->create_build());

			getline(f, str);     
			this->head->GetData()->set_color(str);

			getline(f, str);    
			this->head->GetData()->set_floor(str);

			getline(f, str);    
			this->head->GetData()->set_number(str);

			getline(f, str);   
			this->head->GetData()->set_area(str);

			getline(f, str);   
			this->head->GetData()->set_address(str);

			getline(f, str);   
			this->head->GetData()->set_year(str);

			delete brick;
			}

			if (str == "cottage")
			{
				Cottage* cottage = new Cottage;   
				this->push2(cottage->create_build());

				getline(f, str);   
				this->head->GetData()->set_color(str);
							
				getline(f, str);  
				this->head->GetData()->set_floor(str);

				getline(f, str);   
				this->head->GetData()->set_number(str);

				getline(f, str);  
				this->head->GetData()->set_area(str);

				getline(f, str); 
				this->head->GetData()->set_address(str);

				getline(f, str);   
				this->head->GetData()->set_year(str);

				delete cottage;
			}

			if (str == "monolithic") 
			{
				Monolithic* monolithic = new Monolithic;  
				this->push2(monolithic->create_build());

				getline(f, str);  
				this->head->GetData()->set_color(str);

				getline(f, str);  
				this->head->GetData()->set_floor(str);

				getline(f, str); 
				this->head->GetData()->set_number(str);

				getline(f, str);    
				this->head->GetData()->set_area(str);

				getline(f, str);     
				this->head->GetData()->set_address(str);

				getline(f, str); 
				this->head->GetData()->set_year(str);
				delete monolithic;
			}

			if (str == "panel")
			{    
				Panel* panel = new Panel;   
				this->push2(panel->create_build());

				getline(f, str);   
				this->head->GetData()->set_color(str);

				getline(f, str);   
				this->head->GetData()->set_floor(str);

				getline(f, str);   
				this->head->GetData()->set_number(str);

				getline(f, str);   
				this->head->GetData()->set_area(str);

				getline(f, str);   
				this->head->GetData()->set_address(str);

				getline(f, str);  
				this->head->GetData()->set_year(str);

				delete panel;  
			}
	}  
	f.close();
}

Build* & List::operator[](const int index)
{ 
	int counter = 0; 
	Node *current = this->head; 
	while (current != nullptr)
	{
		if (counter == index) 
		{ 
			Build* ren = current->GetData();
			return ren;
		}   
		current = current->GetNext();  
		counter++;
	} 
	if (index > this->GetSize() - 1 || index < 0)
	{ 
		throw"НЕТ ТАКОГО ИНДЕКСА"; 
	} 
}

void List::insert(Build * data, int index) 
{
	if (index > size || index < 0)
	{
		throw "!!! НЕКОРРЕКТНЫЙ ИНДЕКС !!!";  
		cout << endl; 
	}
	else 
	{ 
		if (index == 0) 
		{ 
			push_front(data); 
		} 
		else 
		{
			Node *previous = this->head;   
			for (int i = 0; i < index - 1; i++)
			{ 
				previous = previous->GetNext();
			} 
			Node *newNode = new Node(data, previous->GetNext());   
			previous->SetNext(newNode);   
			previous->GetNext()->GetData()->house();  
			previous->GetNext()->GetData()->set_inf(); 
			size++; 
		} 
	}
}

void List::removeAt(int index)
{
	if (index >= size)
	{ 
		throw "!!! НЕКОРРЕКТНЫЙ ИНДЕКС !!!";  
		cout << endl; 
	}
	else
	{ 
		if (index == 0)
		{ 
			pop(); 
		} 
		else
		{ 
			Node *previous = this->head; 
			for (int i = 0; i < index - 1; i++) 
			{
				previous = previous->GetNext();
			}   
			Node *toDelete = previous->GetNext(); 
			previous->SetNext(toDelete->GetNext());  
			delete toDelete;   
			size--; 
		} 
	}
}
