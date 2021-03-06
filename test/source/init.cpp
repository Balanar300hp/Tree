#include <tree.cpp>
#include <catch.hpp>
#include <fstream>
#include <iostream>
using namespace std;

SCENARIO("Insert_int", "[add]"){
  Tree<int> tree;
  REQUIRE(tree.Insert(7));
  REQUIRE(tree.Insert(3));
  REQUIRE(tree.Insert(5));
  REQUIRE(tree.Search(3));
  REQUIRE(tree.Search(5));
  REQUIRE(tree.Search(7));
}

SCENARIO("Insert_char", "[add_c]"){
  Tree<char> tree;
  REQUIRE(tree.Insert(5));
  REQUIRE(tree.Insert(4));
  REQUIRE(tree.Insert(6));
  REQUIRE(tree.Search(4));
  REQUIRE(tree.Search(5));
  REQUIRE(tree.Search(6));
}

SCENARIO("Insert_double", "[add_d]"){
  Tree<double> tree;
  REQUIRE(tree.Insert(7.62));
  REQUIRE(tree.Insert(3.14));
  REQUIRE(tree.Insert(5.85));
  REQUIRE(tree.Search(3.14));
  REQUIRE(tree.Search(5.85));
  REQUIRE(tree.Search(7.62));
}

SCENARIO("Search_int", "[search_i]") {
Tree<int> tree;
tree.Insert(7);
tree.Insert(5);
tree.Insert(1);
tree.Insert(9);
tree.Insert(3);
REQUIRE(tree.Search(7));
REQUIRE(tree.Search(9));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(1));
REQUIRE(tree.Search(3));
REQUIRE(!tree.Search(0));
REQUIRE(!tree.Search(8));
REQUIRE(!tree.Search(6));
REQUIRE(!tree.Search(4));
REQUIRE(!tree.Search(2));
}

SCENARIO("Search_char", "[search_c]") {
Tree<char> tree;
tree.Insert(7);
tree.Insert(5);
tree.Insert(1);
tree.Insert(9);
tree.Insert(3);
REQUIRE(tree.Search(7));
REQUIRE(tree.Search(9));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(1));
REQUIRE(tree.Search(3));
REQUIRE(!tree.Search(0));
REQUIRE(!tree.Search(8));
REQUIRE(!tree.Search(6));
REQUIRE(!tree.Search(4));
REQUIRE(!tree.Search(2));
}

SCENARIO("Search_double", "[search_d]") {
Tree<double> tree;
tree.Insert(7.77);
tree.Insert(5.85);
tree.Insert(1.29);
tree.Insert(9.999);
tree.Insert(3.14);
REQUIRE(tree.Search(7.77));
REQUIRE(tree.Search(9.999));
REQUIRE(tree.Search(5.85));
REQUIRE(tree.Search(1.29));
REQUIRE(tree.Search(3.14));
REQUIRE(!tree.Search(0.5));
REQUIRE(!tree.Search(8.800));
REQUIRE(!tree.Search(6.666));
REQUIRE(!tree.Search(4.13));
REQUIRE(!tree.Search(2.34));
}

SCENARIO("Read_int","[read_i]"){
Tree<int> tree; ifstream fin("read.txt");
REQUIRE(fin>>tree);
fin.close();
REQUIRE(tree.Search(7));
REQUIRE(tree.Search(9));
REQUIRE(tree.Search(5));
REQUIRE(tree.Search(1));
REQUIRE(tree.Search(3));
}

SCENARIO("Read_double","[read_d]"){
Tree<double> tree; ifstream fin("read_db.txt");
REQUIRE(fin>>tree);
fin.close();
REQUIRE(tree.Search(12.74));
REQUIRE(tree.Search(15.62));
REQUIRE(tree.Search(7.62));
REQUIRE(tree.Search(3.14));
REQUIRE(tree.Search(8.34));
REQUIRE(tree.Search(25.15));
REQUIRE(tree.Search(17.16));
}

SCENARIO("Print_file_int","[print_file_i]"){
Tree<int> tree; ofstream fout("print.txt", ios::app);
  tree.Insert(7);
  tree.Insert(3);
  tree.Insert(5);
  REQUIRE(fout<<tree);
}

SCENARIO("Print_file_char","[print_file_c]"){
Tree<char> tree; ofstream fout("print_chr.txt", ios::app);
  tree.Insert(7);
  tree.Insert(3);
  tree.Insert(5);
  REQUIRE(fout<<tree);

}

SCENARIO("Print_file_double","[print_file_d]"){
Tree<double> tree; ofstream fout("print_db.txt", ios::app);
  tree.Insert(7.77);
  tree.Insert(3.33);
  tree.Insert(5.55);
  REQUIRE(fout<<tree);

}


SCENARIO("Print_console_int", "[print_console_i]"){
Tree<int> tree;  
  tree.Insert(7);
  tree.Insert(3);
  tree.Insert(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Print_console_char", "[print_console_c]"){
Tree<char> tree;  
  tree.Insert(7);
  tree.Insert(3);
  tree.Insert(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Print_console_double", "[print_console_d]"){
Tree<double> tree;  
  tree.Insert(7);
  tree.Insert(3);
  tree.Insert(5);
  REQUIRE(cout<<tree);
}

SCENARIO("Iscl_add", "[I_a]"){
Tree<int> tree; int O=0; 
tree.Insert(1);
try{tree.Insert(1);}
catch(Exist &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_not_open", "[I_no]"){
Tree<int> tree; int O=0; ifstream fin("errortype");
try{fin>>tree;}
catch(File_Not_Open &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_pust1", "[I_p1]"){
Tree<int> tree; int O=0; 
try{cout<<tree;}
catch(Empty &e){O++;}
REQUIRE(O==1);
}

SCENARIO("Iscl_pust2", "[I_p2]"){
Tree<int> tree; int O=0; ofstream fout("print_db.txt", ios::app);
try{fout<<tree;}
catch(Empty &e){O++;}
fout.close();
REQUIRE(O==1);
}
