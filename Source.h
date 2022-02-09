#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class film {
public:///123213213213231312321321321312321
	// �������������, ���������� � ���� ������ �� ������
	static film* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ����
	virtual void Out(ofstream& ofst) = 0; // �����
};
class Node {
public:
	film* pic;
	Node* next;
	Node(film* newfigure);
	//~Node() {}
};
// ������� �����
class feature : public film {
	string director; // �������
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	feature() {} // �������� ��� �������������.
};
// ����������
class animation : public film {
	enum way { DRAWN, DOLL, STOP_MOTION };// ������ ��������
	way woc;//������ ��������
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	animation() {} // �������� ��� �������������.
};
class container {
	//enum { max_len = 100 }; // ������������ �����
	//int len; // ������� �����
	//shape* cont[max_len];
	
public:
	Node *head;
	Node *curr;
	int size;

	void In(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	void Clear(); // ������� ���������� �� �����
	container(); // ������������� ����������
	~container() { Clear(); } // ���������� ����������
};


