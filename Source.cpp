#include "Source.h"
using namespace std; 
void rectangle::InData(ifstream& ifst) {
	ifst >> x >> y;
}
void rectangle::Out(ofstream& ofst) {
	ofst << "It is Rectangle: x = " << x
		 << ", y = " << y << endl;
}
void triangle::InData(ifstream& ifst) {
	ifst >> a >> b >> c;
}
void triangle::Out(ofstream& ofst) {
	ofst << "It is Triangle: a = "
		<< a << ", b = " << b
		<< ", c = " << c << endl;
}
shape* shape::In(ifstream& ifst) {
	shape* sp;
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		sp = new rectangle;
		break;
	case 2:
		sp = new triangle;
		break;
	default:
		return 0;
	}
	sp->InData(ifst);
	return sp;
}
container::container() : len(0) { }
// Очистка контейнера от элементов
void container::Clear() {
	for (int i = 0; i < len; i++) {
		delete cont[i];
	}
	len = 0;
}
void container::In(ifstream& ifst) {
	while (!ifst.eof()) {
		if ((cont[len] = shape::In(ifst)) != 0) {
			len++;
		}
	}
}
void container::Out(ofstream& ofst) {
	ofst << "Container contents " << len
		<< " elements." << endl;
	for (int i = 0; i < len; i++) {
		ofst << i << ": ";
		cont[i]->Out(ofst);
	}
}