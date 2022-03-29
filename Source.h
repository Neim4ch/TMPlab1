#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class film {
	string name;
public:
	string country;
	// иденитфикация, порождение и ввод фигуры из потока
	static film* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ввод
	virtual void Out(ofstream& ofst) = 0; // вывод
	int countVowels(); // гласные 
	void OutName(ofstream& ofst);
	bool cmp(film& f);
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
	int countVowels();
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
	int countVowels();
	//void OutFeature(ofstream& ofst);
	animation() {} // создание без инициализации.
};
//документальный
class documentary : public film {
	int year;//год создания
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	documentary() {} // создание без инициализации.
};

class container {	
public:
	Node *head;
	Node *curr;
	int size;

	void In(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	void OutCntVowels(ofstream& ofst); //вывод количества гласных букв
	void Sort();
	void OutFeature(ofstream& ofst); // вывод
	void Clear(); // очистка контейнера от фигур
	container(); // инициализация контейнера
	~container() { Clear(); } // утилизация контейнера
};


