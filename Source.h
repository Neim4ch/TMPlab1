#pragma once
#include <iostream>
#include <fstream>
//#include "Source.cpp"
using namespace std;
//class film {
//public:///123213213213231312321321321312321
//	// иденитфикация, порождение и ввод фигуры из потока
//	static film* In(ifstream& ifst);
//	virtual void InData(ifstream& ifst) = 0; // ввод
//	virtual void Out(ofstream& ofst) = 0; // вывод
//};
enum type {animation, feature};
struct film {
	type key;
	void* obj = NULL;
};
//class Node {
//public:
//	film* pic;
//	Node* next;
//	Node(film* newfigure);
//	//~Node() {}
//};
struct Node {
	film* pic = NULL;
	Node* next = NULL;
};
// игровой фильм
//class feature : public film {
//	string director; // режисер
//public:
//	// переопределяем интерфейс класса
//	void InData(ifstream& ifst); // ввод
//	void Out(ofstream& ofst); // вывод
//	feature() {} // создание без инициализации.
//};
struct feature_film {
	string director = "";
};
//void InData(feature &f, ifstream& ifst);
// мультфильм
//class animation : public film {
//	enum way { DRAWN, DOLL, STOP_MOTION };// способ создания
//	way woc;//способ создания
//public:
//	// переопределяем интерфейс класса
//	void InData(ifstream& ifst); // ввод
//	void Out(ofstream& ofst); // вывод
//	animation() {} // создание без инициализации.
//};
enum way { DRAWN, DOLL, STOP_MOTION };// способ создания
struct animation_film {
		way woc;//способ создания
};
//class container {
//	//enum { max_len = 100 }; // максимальная длина
//	//int len; // текущая длина
//	//shape* cont[max_len];
//	
//public:
//	Node *head;
//	Node *curr;
//	int size;
//
//	void In(ifstream& ifst); // ввод
//	void Out(ofstream& ofst); // вывод
//	void Clear(); // очистка контейнера от фигур
//	container(); // инициализация контейнера
//	~container() { Clear(); } // утилизация контейнера
//};
struct container {
	int size = 0;
	Node* head = NULL;
	Node* curr = NULL;
};


