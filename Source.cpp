#include "Source.h"
using namespace std; 
void feature::InData(ifstream& ifst) {
	ifst >> director;
}
void feature::Out(ofstream& ofst) {
	ofst << "It is feature film. Director is " << director << endl;
	ofst << "This picture was filmed in " << country << endl;
}
void documentary::InData(ifstream& ifst) {
	ifst >> year;
}
void documentary::Out(ofstream& ofst) {
	ofst << "It is documentary film. It's year of creation is " << year << endl;
}
void animation::InData(ifstream& ifst) {
	int t;
	ifst >> t;
	switch (t)
	{
	case 1:
		woc = DRAWN;
		break;
	case 2:
		woc = DOLL;
		break;
	case 3:
		woc = STOP_MOTION;
		break;
	}
}
void animation::Out(ofstream& ofst) {
	switch (woc)
	{
	case 0:
		ofst << "It is animation film. It's way of creation is drawing."<< endl;
		break;
	case 1:
		ofst << "It is animation film. It's way of creation is using dolls" << endl;
		break;
	case 2:
		ofst << "It is animation film. It's way of creation is stop motion" << endl;
		break;
	}
	ofst << "This picture was filmed in " << country << endl;
}

string vowels = "AEIOUYaeiouy";

int film::countVowels()
{
	int cnt = 0;
	for (int i = 0; i < name.length(); i++)
	{
		if (vowels.find(name[i]) < vowels.length())cnt++;
	}
	return cnt;
}

film* film::In(ifstream& ifst) {
	film* fl;
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		fl = new feature;
		break;
	case 2:
		fl = new animation;
		break;
	case 3:
		fl = new documentary;
		break;
	default:
		return 0;
	}
	ifst >> fl->name;
	fl->InData(ifst);
	ifst >> fl->country;
	return fl;
}
Node::Node(film* newpic)
{
	pic = newpic;
	next = NULL;
}
container::container()
{
	head = NULL;
	head = NULL;
	size = 0;
}
// Очистка контейнера от элементов
void container::Clear() {
	head = NULL;
	curr = NULL;
	size = 0;
}

void container::In(ifstream& ifst) {
	while (!ifst.eof()) {
		Node* newNode;
		newNode = new Node((film::In(ifst)));
		if (head == NULL)
		{
			head = newNode;
			size = 1;
		}
		else
		{
			curr = head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			curr->next = newNode;
			size++;
		}
	}
}
void container::Out(ofstream& ofst) {
	ofst << "Container contents " << size
		 << " elements." << endl;

	//Sort();

	int i = 0;
	curr = head;
	while (curr != NULL)
	{
		ofst << i << ": ";
		curr->pic->OutName(ofst);
		curr->pic->Out(ofst);
		ofst << "Number of vowels = ";
		OutCntVowels(ofst);
		ofst << endl;
		curr = curr->next;
		i++;
	}
}
void container::OutCntVowels(ofstream& ofst)
{
	ofst << curr->pic->countVowels();
}

bool film::cmp(film& f)
{
	return countVowels() < f.countVowels();
}

void container::Sort()
{
	curr = head;
	Node* currj = head;
	while (curr != NULL)
	{
		currj = curr;
		while (currj != NULL)
		{
			if (curr->pic->cmp(*currj->pic))
			{
				swap(curr->pic, currj->pic);
			}
			currj = currj->next;
		}
		curr = curr->next;
	}
}
void film::OutName(ofstream& ofst)
{
	ofst << "This is " << name << ". ";
}
void feature::OutFeature(ofstream& ofst)
{
	OutName(ofst);
	Out(ofst);
}
void film::OutFeature(ofstream& ofst)
{
	ofst << endl;
}

void container::OutFeature(ofstream& ofst) {
	int i = 0;
	curr = head;
	while (curr != NULL)
	{
		ofst << i << ": ";
		if (curr->pic)
		{
			curr->pic->OutFeature(ofst);
		}
		curr = curr->next;
		i++;
	}
}