#include "Source.h"
using namespace std;

void InFeature(ifstream &ifst, feature_film& f) {
	ifst >> f.director;
}
void OutFeature(ofstream& ofst, feature_film& f) {
	ofst << "It is feature film. Director is " << f.director << endl;
}
void InAnimation(ifstream& ifst, animation_film& a) {
	int t;
	ifst >> t;
	switch (t)
	{
	case 1:
		a.woc = DRAWN;
		break;
	case 2:
		a.woc = DOLL;
		break;
	case 3:
		a.woc = STOP_MOTION;
		break;
	}
}
void OutAnimation(ofstream& ofst, animation_film& a) {
	switch (a.woc)
	{
	case 0:
		//woc = DRAWN;
		ofst << "It is animation film. It's way of creation is drawing."<< endl;
		break;
	case 1:
		//woc = DOLL;
		ofst << "It is animation film. It's way of creation is using dolls" << endl;
		break;
	case 2:
		//woc = STOP_MOTION;
		ofst << "It is animation film. It's way of creation is stop motion" << endl;
		break;
	}

	//ofst << "It is animation film. It's way of creation is " << woc << endl;
}
film* InFilm(ifstream& ifst) {
	film* fl = new film;
	feature_film* f;
	animation_film* a;
	int k = 0;
	ifst >> k;
	switch (k) {
	case 1:
		fl->key = feature;
		//feature_film f;
		f = new feature_film;
		InFeature(ifst, *f);
//		fl->obj = (feature_film*)&f;
		fl->obj = (void*)f;
		break;
	case 2:
		fl->key = animation;
		//animation_film a;
		a = new animation_film;
		InAnimation(ifst, *a);
		fl->obj = (void*)a;
		break;
	default:
		return 0;
	}
	//fl->InData(ifst);
	feature_film f1;

	if (fl->key == feature) {
		f1 = *(feature_film*)fl->obj;
		
	}
	return fl;
}

void Clear(container* c) {
	c->head = NULL;
	c->curr = NULL;
	c->size = 0;
}

void InCont(ifstream& ifst, container* c) {
	while (!ifst.eof()) {

		Node* newNode = new Node;
		newNode->fl = InFilm(ifst);
		//cout << "newNode" << newNode->pic->key;
		feature_film* f1 = (feature_film*)newNode->fl->obj;
		if (c->head == NULL)
		{
			c->head = newNode;
			c->size = 1;
		}
		else
		{
			c->curr = c->head;
			while (c->curr->next != NULL)
			{
				c->curr = c->curr->next;
			}
			c->curr->next = newNode;
			c->size++;
		}
	}
}
void OutCont(ofstream& ofst, container* c) {
	ofst << "Container contents " << c->size
		<< " elements." << endl;

	int i = 0;
	c->curr = c->head;
	while (c->curr != NULL)
	{
		ofst << i << ": ";
		if (c->curr->fl->key == feature) 
		{
			feature_film* pf;
			//void* obj1 = *&c->curr->fl->obj;
			pf = (feature_film *)(c->curr->fl->obj);
			OutFeature(ofst, *pf);
		}
		else
		{
			animation_film* pa;
			pa = (animation_film*)c->curr->fl->obj;
			OutAnimation(ofst, *pa);
		}
		c->curr = c->curr->next;
		i++;
	}
}