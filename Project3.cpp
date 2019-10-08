// Project3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*****
Author: Biruk Kassahun Worku
Date  : 3/ 13/ 2019
*****/

#include "pch.h"
#include <iostream>
using namespace std;


// This is a templated Linked class
template <class T>
class LinkedList 
{
protected:
	T* data;  // contains the data part of the linked list
	LinkedList<T>* next; // this is the linker to the next node 
public: 
	LinkedList(); // Default constructor
	LinkedList(const T& info); // parametrized constructor
	LinkedList(const T& info,  LinkedList<T>* _next); // parametrized constructor overloaded
	~LinkedList(); // destructor
	LinkedList(const LinkedList<T> & ll); // copy constructor
	bool isEmpty(); // check if the linked list is empty
	int size(); // returns the size of the linked list
	T& infoAt(int postion); // returns the data at the specific position
	void add(const T & obj); // adds data infront of the linked list
	void insertAt(const T& newObj, int position); // inserts data at the specific position
	T remove(); // removes a node
	T removeAt(int position); // removes a node at a specific position
	T& operator[](int position); // square bracked operator overloading
	void operator=(const LinkedList<T>& ll); // equal to operator overloading
	


};

template <class T>
LinkedList<T>::LinkedList() {
	data = NULL; // initializing data to NULL
	next = NULL; // initializing next to NULL
}
template <class T>
LinkedList<T>::LinkedList(const T& info) {
	data = new T(info); // initializing data with info
	next = NULL; // initializing next to NULL
}

template <class T>
LinkedList<T>::LinkedList(const T& info,  LinkedList<T>* _next) {
	data = new T(info); // initializing data with info
	
	next = _next; // initializng next with _next

}
template <class T>
LinkedList<T>::~LinkedList() {  // implementing the destructor for the linked list
	if (data != NULL) {
		delete data; // deletes the data
		data = NULL;

	}
	if (next != NULL) {
		delete next; // deletes the next
		next = NULL;
	}
}
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& ll) { // implementing the copy constructor
	if (ll.data == NULL) {
		data = NULL;
	}
	else {
		data = new T(*(ll.data)); // initialzing data with the parameters linkedlists data
	
	
	}
	if (ll.next = NULL) {
		next = NULL;
	}
	else {
		next = new LinkedList<T>(*(ll.next)); // initializing the next with the parameter's linkedlist next
		
		
	}
}

template <class T>
void LinkedList<T>::operator= (const LinkedList<T>& ll) { // implementing the equal to operator
	if (data != NULL) {
		delete data; 
	}
	if (next != NULL) {
		delete next;
	}
	if (ll.data == NULL) { 
		data = NULL; // setting data to null if ll's data is null
	}
	else {
		data = new T(*(ll.data));  // setting data to ll's data
	 
	
	}
	if (ll.next = NULL) {
		next = NULL; // setting next to NULL if ll's next is NULL
	}
	else {
		next = new LinkedList<T>(*(ll.next)); // setting next to null if ll's next
		
		
	}
}

template<class T>
bool LinkedList<T>::isEmpty() { // implementing the isEmpty method 
	return (data == NULL);
}
template <class T>
T& LinkedList<T>::infoAt(int position) { 

	
	if (position == 0) {
		return *data; // when position is zero it returns the value of data
	}
	
	else {
		return next->infoAt(position - 1); // recursive call of infoAt with a position reduced by 1
	}
	
	
}

template <class T>
T& LinkedList<T>::operator[](int position) { // implementing the square bracked overloading
	return infoAt(position); // calling the infoAt method
}

template <class T>
int LinkedList<T>::size() { // implementing the size method
	if (next == NULL) {
		if (data == NULL) { 
			return 0; 
		}
		else {
			return 1;
		}
	}
	else {
		return  1 + next->size() ; // recursive call of size method
	}
}
template <class T>
void LinkedList <T>::add(const T & obj) {
	
	if (data == NULL) {

		data = new T(obj);  // initializing data with obj
		
		
	}
	
	else {
	
		LinkedList<T>* temp = new LinkedList<T>(*data, next); // creating a temporary linkedlist 
		
		data = new T(obj); // setting data to the parameter passed by
		next = temp; // setting the next to the temporary linked list
	
	}
	
}
template <class T>
T LinkedList<T>::remove() { // implementing the remove method
	T temp = *data; 
	delete data; // deleteing the data
	if (next == NULL) {
		data = NULL;
	}
	else {
		LinkedList<T>* oldnext = next;
		data = next->data;
		next = next->next;
		oldnext->data = NULL;
		oldnext->next = NULL;
		delete oldnext; // deleting the old next
	}
	return temp;
}
template <class T>
T LinkedList<T>::removeAt(int position) { // implementing the removeAt method
	
	
	if (position == 0) { 
		return remove(); // calling the remove method if the position is 0
	}
	
	
	return next->removeAt(position - 1); // recursive call for removeAt
}
template <class T>
void LinkedList<T>::insertAt(const T& newObj, int position) { // implementing the insertAt method
	if (position == 0) {
		add(newObj); // adding the newObj if the position specified is zero
	}
	else {
		
		if (next == NULL) {
			next = new LinkedList(newObj); 
			
			
		}
		else {
		
			next->insertAt(newObj, position - 1); // recursive call of insertAt method
		}
	}
}



//This is the term class that creates a single term


class Term {
protected:
	int coefficient; // coefficient of the term
	int exponent; // exponent of the term
public:
	Term(); // Default constructor of term
	~Term(); // Destructor 
	Term(int c, int e); // Parametrized constructor of term
	Term(const Term & t); // copy constructor of term
	int& getCoefficient(); // getter for the coefficient
	int& getExponenet(); // getter for the exponent
	void display(); // display method
	void setExponenet(int c); // setter for the exponenet
	void setCoefficient(int e); // setter for the coefficient
};

Term::Term() { // implementing the Default constructor for term
	coefficient = 0; 
	exponent = 0;
}
Term:: ~Term() { // destructor for the term class

}

Term::Term(int c, int e) { // implementing the parametrized constructor
	coefficient = c;
	exponent = e;
}

Term::Term(const Term & t) { // implementing the copy constructor
	coefficient = t.coefficient;
	exponent = t.exponent;

}

int& Term::getCoefficient() { // getter for the coefficient 
	return coefficient;
}
 
int& Term::getExponenet() { // getter for the exponenet
	return exponent;
}
void Term::setExponenet(int e) { // setter for the exponenet
	exponent = e;
}
void Term::setCoefficient(int c) { // setter for the coefficient
	coefficient = c;
}
void Term::display() { // a method for displaying a term
	cout << "(" << coefficient << "," << exponent << ")";
}

// This is a class Polynomial which uses linked list of terms to create a polynomial

class Polynomial {
protected: 
	LinkedList<Term>* myPoly; // LinkedList of terms
public:
	Polynomial(); // Empty constructor for polynomial
	~Polynomial(); // Destructor
	void evaluatePoly(int x); // evalueate polynomial for a given value of x
	bool addTerm(int coeff, int exp); // method to add a term in the linked list and returns true if it added sucessfully and false if it hasn't
	void printPolynomial(); // method to print the polynomial
	void deleteTerm(int index); // method to delete a term given the index
	bool _deleteTerm(int exponent); // method to delete a term given the exponenet and returns true if it deleted successfully and false if it hasn't
	Polynomial* addPolynomial(Polynomial& b); // method to add the polynomials
	Polynomial* multiplyPolynomial(Polynomial& b); // method to multiply the polynomials
	friend ostream& operator<<(ostream& s, Polynomial& b) // ostream operator overloading
	{ 
		b.printPolynomial();
		return s;
	}
	Polynomial* operator+ (Polynomial& b); // addition operator(+) overloading
	Polynomial* operator* (Polynomial& b); // multiplication operator(*) overloading

};
Polynomial::Polynomial() {
	myPoly = new LinkedList<Term>(); // initializing myPoly linked list
	
}
Polynomial:: ~Polynomial() { // Destructor for the polynomial class
	delete myPoly;
}
void Polynomial::evaluatePoly(int x) { // implementing the evaluatePoly method
	int sum = 0;
	for (int i = 0; i < (*this).myPoly->size(); ++i) { // going through my linked list
		sum += (*myPoly)[i].getCoefficient()* pow(x, (*myPoly)[i].getExponenet()); //evaluating the polynomial with the specified value of x
	}
	cout << "Value is: " << sum << endl; // printing the final value
}
void Polynomial::deleteTerm(int index) // implementing the delete term at the specific index
{
	myPoly->removeAt(index); // calling the romoveAt() method from the linked list
}
bool Polynomial::_deleteTerm(int exponent) // implementing the _deleteTerm method at the specific exponent 
{
	bool temp = false; 
	for (int i = 0; i < myPoly->size(); ++i) { // traversing through linkedlist
		if ((*myPoly)[i].getExponenet() == exponent) { // checking if the specified exponent matches
			(*myPoly)[i].setCoefficient(0); // setting the coefficient to zerp
			deleteTerm(i); // deleting (removing) the term
			temp = true;
		}
		
	}
	return temp;
}
bool Polynomial:: addTerm(int coeff, int exp)  // implementing the addTerm method
{
	Term* newTerm = new Term(coeff, exp); // creating a new term
	myPoly->insertAt(*newTerm, myPoly->size()); // inserting the term at the back of the list
	if (!(myPoly->isEmpty())) {

		int i = (myPoly->size()) - 1; // setting i to be one value less than the size
		
		while (i > 0) {
			int index = i;
			if ((*myPoly)[index].getExponenet() > (*myPoly)[index - 1].getExponenet()) // checking if there is an exponenet at i greater than an exponent at i-1
			{
				// swapping them in order to have the exponents in descending order
				Term temp = (*myPoly)[index]; 
				(*myPoly)[index] = (*myPoly)[index - 1];
				(*myPoly)[index-1] = temp;
			}
			i--; 
		}

	}
	
	// a for loop that takes care of matching exponenets
	for (int i = myPoly->size() - 1; i > 0; --i) {
		int index = i;
		if ((*myPoly)[index].getExponenet() == (*myPoly)[index-1].getExponenet()) // checking if there are exponenets that matches
		{
			int newCoeff = (*myPoly)[index].getCoefficient() + (*myPoly)[index-1].getCoefficient(); // adding the coefficient of the two exponents that matched
			int newExp = (*myPoly)[index].getExponenet(); // having one of the exponents
			Term* temp = new Term(newCoeff, newExp); // creating a newTerm with the new coefficients and newExponents
			deleteTerm(index); // removing the old term at i
			deleteTerm(index-1); // removing the old term at i - 1
			myPoly->insertAt((*temp), index - 1); // inserting the new term at i-1 
		}
	}
	

	return true;
 
}

void Polynomial::printPolynomial() // implementing the printpolynomial method
{
	for (int i = 0; i < myPoly->size(); ++i) // traversing through the linked list
	{
		int index = i;
		(*myPoly)[i].display(); // displaying the terms at ith position

		if ((index + 1) < myPoly->size())  // adding the + sign until the last term is reached
		{
			cout << " + ";
		}
	}
	cout << endl;
}
Polynomial* Polynomial::addPolynomial(Polynomial& b) // implementing the addPolynomial method
{
	
	Polynomial* sum = new Polynomial(); // creating a new polynomial that will contain the sum of the two polynomials
	for (int i = 0; i < myPoly->size(); ++i) // going through the first polynomial's size
	{ 
		sum->addTerm((*myPoly)[i].getCoefficient(), (*myPoly)[i].getExponenet()); // adding terms to the sum polynomial
	}
	for (int j = 0; j < b.myPoly->size(); ++j) // going through the second polynomial
	{
		sum->addTerm(b.myPoly->infoAt(j).getCoefficient(), b.myPoly->infoAt(j).getExponenet()); // adding terms to the sum polynomial 
	}
	return sum;
	
}

Polynomial* Polynomial::multiplyPolynomial(Polynomial & b) 
{
	Polynomial* product = new Polynomial(); // creating a new polynomial that will contain the product of the two polynomials
	for (int i = 0; i < myPoly->size(); ++i)  // going through my first polynomials
	{
		for (int j = 0; j < b.myPoly->size(); ++j) // going through my second polynomials
		{
			int newCoeff = myPoly->infoAt(i).getCoefficient() * b.myPoly->infoAt(j).getCoefficient(); //multiply the coefficeint of the two terms
			int newExp = myPoly->infoAt(i).getExponenet() + b.myPoly->infoAt(j).getExponenet(); // adding the exponents of the two terms
			product->addTerm(newCoeff, newExp); // adding this new term to product 
		}
	}
	return product;
}
Polynomial* Polynomial:: operator+(Polynomial& b)  // implementing the + operator overloading
{
	return this->addPolynomial(b); // calling the addPolynomial method
}
Polynomial* Polynomial:: operator*(Polynomial& b) // implementing the * operator overloading
{
	return this->multiplyPolynomial(b); // calling the multiplyPolynomial method
}

int main()
{
 	Polynomial* polynomials = new Polynomial[10]; // creating an array of polynomials with size 10
	char command; // declaring a command
	int polyNum, coefficient, exponent, value, i, j; // declaring the polyNum, coefficient, exponent, value, i and j

	
	cin >> command; // reading in a command from the user
	
	
	while (!cin.eof()) 
	{
		switch (command)  // switch statments for each command lines
		{
		case 'I': cin >> polyNum >> coefficient >> exponent;
			if (polynomials[polyNum].addTerm(coefficient, exponent)) // calling the addTerm method and checking if it is a success or failure
			{
				cout << "Success" << endl; // prints success if it has added successfully
			}
			else {
				cout << "Failure" << endl; // prints failure if hasn't added successfully
			}
			break;
		case 'D': cin >> polyNum >> exponent;
			if (polynomials[polyNum]._deleteTerm(exponent)) { // checking if the exponent exists in the polynomial
				cout << "Success" << endl; // prints success if it has deleted sucessfully
			}
			else {
				cout << "Failure" << endl; // prints failure if it hasn't deleted
			}
			break;
		case 'A': cin >> i >> j; 
			cout << "Sum Polynomial: " << *(polynomials[i] + polynomials[j]) << endl; // adding the polynomials
			break;
		case 'M': cin >> i >> j;
			cout << "Product Polynomial: " << *(polynomials[i] * polynomials[j]) << endl; // multiplying the polynomials
			break;
		case 'E': cin >> polyNum >> value;
			polynomials[polyNum].evaluatePoly(value); // evaluating a polynomial by plugging in 'value'
			break;
		case 'P': cin >> polyNum;
			cout << "Polynomial " << polyNum << ": " << polynomials[polyNum]; // printing the specfied polyNum
			break;
		default:
			cout << "I missed something" << endl;
				  
		}
		cin >> command; // getting an update of command
	}

	delete[] polynomials;
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
