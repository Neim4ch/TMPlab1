#pragma once
#include <iostream>
#include <fstream>
//#include "Source.cpp"
using namespace std;
//class film {
//public:///123213213213231312321321321312321
//	// �������������, ���������� � ���� ������ �� ������
//	static film* In(ifstream& ifst);
//	virtual void InData(ifstream& ifst) = 0; // ����
//	virtual void Out(ofstream& ofst) = 0; // �����
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
// ������� �����
//class feature : public film {
//	string director; // �������
//public:
//	// �������������� ��������� ������
//	void InData(ifstream& ifst); // ����
//	void Out(ofstream& ofst); // �����
//	feature() {} // �������� ��� �������������.
//};
struct feature_film {
	string director = "";
};
//void InData(feature &f, ifstream& ifst);
// ����������
//class animation : public film {
//	enum way { DRAWN, DOLL, STOP_MOTION };// ������ ��������
//	way woc;//������ ��������
//public:
//	// �������������� ��������� ������
//	void InData(ifstream& ifst); // ����
//	void Out(ofstream& ofst); // �����
//	animation() {} // �������� ��� �������������.
//};
enum way { DRAWN, DOLL, STOP_MOTION };// ������ ��������
struct animation_film {
		way woc;//������ ��������
};
//class container {
//	//enum { max_len = 100 }; // ������������ �����
//	//int len; // ������� �����
//	//shape* cont[max_len];
//	
//public:
//	Node *head;
//	Node *curr;
//	int size;
//
//	void In(ifstream& ifst); // ����
//	void Out(ofstream& ofst); // �����
//	void Clear(); // ������� ���������� �� �����
//	container(); // ������������� ����������
//	~container() { Clear(); } // ���������� ����������
//};
struct container {
	int size = 0;
	Node* head = NULL;
	Node* curr = NULL;
};


