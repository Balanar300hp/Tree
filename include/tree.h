#include <iostream>
#include <fstream>
using namespace std;


template <class T>
	class BinarySearchTree;

template <class T>
	bool operator<<(ostream & out, BinarySearchTree<T> &tree);
template <class T>
	bool operator<<(ofstream & fout, BinarySearchTree<T> &tree);
template <class T>
	bool operator >> (ifstream & fin, BinarySearchTree<T> &tree);


	//Класс исключений 
class Exceptions {
	char* err;
public:
	Exceptions(char* _err);
	char* what();
};
class File_Not_Open : public Exceptions{
public:
	File_Not_Open();
};
class Empty : public Exceptions{
public:
	Empty();
};
class Exist : public Exceptions{
public:
	Exist();
};
Exceptions::Exceptions(char* _err) : err(_err){}
char* Exceptions::what() { return err; }
Exist::Exist() : Exceptions("ERROR: It's already exist!") {}
File_Not_Open::File_Not_Open() : Exceptions("ERROR: file is not open!") {}
Empty::Empty() : Exceptions("ERROR: The Binary Tree is empty!") {}



template <class T>
class Tree{
public:
	Tree();
	bool Insert(T x);// Добавление элемента 
	bool Search(T x);// Поиск элемента 
	friend bool operator<< <>(ostream &out, Tree<T> &tree);
	friend bool operator<< <>(ofstream &fout, Tree<T> &tree);
	friend bool operator>> <>(ifstream &fin, Tree<T> &tree);
private:
	class der;
	der* root;//корень дерева
};

template <class T>
class Tree<T>::der{
public:
	der(T x);
	void Insert(T x);
	bool Search(T x);
	bool print_console();
	bool print_file(ofstream &fout);
private:
	T D;
	der *l;
	der *r;
};
