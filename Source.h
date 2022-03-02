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
	string name = "";
};

enum way { DRAWN, DOLL, STOP_MOTION };// способ создания
struct animation_film {
		way woc;//способ создания
		string name = "";
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
film* InFilm(ifstream& ifst);
film* OutFilm(ifstream& ifst);
void Clear(container* c);
void InCont(ifstream& ifst, container* c);
void OutCont(ofstream& ofst, container* c);

int countVowel(feature_film& f);
int countVowel(animation_film& a);
int countVowel(film& fl);

bool cmpVowels(film* f1, film* f2);
void Sort(container& c);