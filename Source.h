#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class shape {
public:
	// иденитфикация, порождение и ввод фигуры из потока
	static shape* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ввод
	virtual void Out(ofstream& ofst) = 0; // вывод
};
// прямоугольник
class rectangle : public shape {
	int x, y; // ширина, высота
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	rectangle() {} // создание без инициализации.
};
// треугольник
class triangle : public shape {
	int a, b, c; // стороны
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	triangle() {} // создание без инициализации.
};
class container {
	//enum { max_len = 100 }; // максимальная длина
	//int len; // текущая длина
	//shape* cont[max_len];
	Node* cont;
	Node* curr;
public:
	void In(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	void Clear(); // очистка контейнера от фигур
	container(); // инициализация контейнера
	~container() { Clear(); } // утилизация контейнера
};
class Node {
	shape* figure;
	Node* next;
	Node(shape* newfigure);
};

