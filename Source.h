#pragma once
#include <iostream>
#include <fstream>

using namespace std;

enum type {animation, feature, documentary};
struct film {
	void* obj = NULL;
	type key;
	
};

struct Node {
	film* fl = NULL;
	Node* next = NULL;
};

struct feature_film {
	string director = "";
};

struct documentary_film {
	int year = 0;
};

enum way { DRAWN, DOLL, STOP_MOTION };// способ создания
struct animation_film {
		way woc;//способ создания
};

struct container {
	int size = 0;
	Node* head = NULL;
	Node* curr = NULL;
};

void In(ifstream& ifst, feature_film& f);
void Out(ofstream& ofst, feature_film& f);
void In(ifstream& ifst, animation_film& a);
void Out(ofstream& ofst, animation_film& a);
void In(ifstream& ifst, documentary_film& d);
void Out(ofstream& ofst, documentary_film& d);
film* InFilm(ifstream& ifst);
film* OutFilm(ifstream& ifst);
void Clear(container* c);
void InCont(ifstream& ifst, container* c);
void OutCont(ofstream& ofst, container* c);
