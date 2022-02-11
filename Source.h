#pragma once
#include <iostream>
#include <fstream>

using namespace std;

enum type {animation, feature};
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
	//int director;
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

void InFeature(ifstream& ifst, feature_film* f);
void OutFeature(ofstream& ofst, feature_film* f);
void InAnimation(ifstream& ifst, animation_film* a);
void OutAnimation(ofstream& ofst, animation_film* a);
film* InFilm(ifstream& ifst);
void Clear(container* c);
void InCont(ifstream& ifst, container* c);
void OutCont(ofstream& ofst, container* c);
