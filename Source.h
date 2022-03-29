#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class film {
	string name;
public:
	string country;
	// �������������, ���������� � ���� ������ �� ������
	static film* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ����
	virtual void Out(ofstream& ofst) = 0; // �����
	int countVowels(); // ������� 
	void OutName(ofstream& ofst);
	bool cmp(film& f);
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
	int countVowels();
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
	int countVowels();
	animation() {} // �������� ��� �������������.
};
//��������������
class documentary : public film {
	int year;//��� ��������
public:
	// �������������� ��������� ������
	void InData(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	documentary() {} // �������� ��� �������������.
};

class container {	
public:
	Node *head;
	Node *curr;
	int size;

	void In(ifstream& ifst); // ����
	void Out(ofstream& ofst); // �����
	void OutCntVowels(ofstream& ofst); //����� ���������� ������� ����
	void Sort();
	void Clear(); // ������� ���������� �� �����
	container(); // ������������� ����������
	~container() { Clear(); } // ���������� ����������
};


