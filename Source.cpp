#include "Source.h"
using namespace std; 
void feature::InData(ifstream& ifst) {
	ifst >> director;
	ifst >> country;
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
	ifst >> country;
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
	fl->InData(ifst);
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
	int i = 0;
	curr = head;
	while (curr != NULL)
	{
		ofst << i << ": ";
		curr->pic->Out(ofst);
		curr = curr->next;
		i++;
	}
}