#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class film {
public:
	// иденитфикация, порождение и ввод фигуры из потока
	static film* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ввод
	virtual void Out(ofstream& ofst) = 0; // вывод
	virtual void OutFeature(ofstream& ofst);
};
class Node {
public:
	film* pic;
	Node* next;
	Node(film* newfigure);
	//~Node() {}
};
// игровой фильм
class feature : public film {
	string director; // режисер
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	void OutFeature(ofstream& ofst);
	feature() {} // создание без инициализации.
};
// мультфильм
class animation : public film {
	enum way { DRAWN, DOLL, STOP_MOTION };// способ создания
	way woc;//способ создания
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	//void OutFeature(ofstream& ofst);
	animation() {} // создание без инициализации.
};
class container {	
public:
	Node *head;
	Node *curr;
	int size;

	void In(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	void OutFeature(ofstream& ofst); // вывод
	void Clear(); // очистка контейнера от фигур
	container(); // инициализация контейнера
	~container() { Clear(); } // утилизация контейнера
};


