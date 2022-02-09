#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class shape {
public:
	// �������������, ���������� � ���� ������ �� ������
	static shape* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ����
	virtual void Out(ofstream& ofst) = 0; // �����
};
// �������������
class rectangle : public shape {
	int x, y; // ������, ������
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	rectangle() {} // �������� ��� �������������.
};
// �����������
class triangle : public shape {
	int a, b, c; // �������
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	triangle() {} // �������� ��� �������������.
};
class container {
	//enum { max_len = 100 }; // ������������ �����
	//int len; // ������� �����
	//shape* cont[max_len];
	Node* cont;
	Node* curr;
public:
	void In(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	void Clear(); // ������� ���������� �� �����
	container(); // ������������� ����������
	~container() { Clear(); } // ���������� ����������
};
class Node {
	shape* figure;
	Node* next;
	Node(shape* newfigure);
};

