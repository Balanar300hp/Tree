#include <iostream>
#include <fstream>
using namespace std;


template <class T>
	class Tree;

template <class T>
	ostream & operator<<(ostream & os,Tree<T> &x);
template <class T>
	fstream & operator<<(ofstream & fle,Tree<T> &x);
template <class T>
	fstream & operator >> (ifstream & file,Tree<T> &x);


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
	friend ostream & operator<< <>(ostream &out, Tree<T> &tree);
	friend fstream & operator<< <>(ofstream &fout, Tree<T> &tree);
	friend fstream & operator>> <>(ifstream &fin, Tree<T> &tree);
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
