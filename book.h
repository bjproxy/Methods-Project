#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#ifndef BOOK_H
#define BOOK_H
class Book {
private:
  string ISBN;
  string title;
  string author;
  string year;
  string genre;
  double price;
  int quantity;
public:
  Book();
  Book(string ISBN, string title, string author, string year, string genre, float price);

  void display(vector<Book> &books);
  void oneReadFile(vector<Book> &books);
  void searchGenre(string search);

  // setter functions
  void setISBN(string num);
  void setTitle(string data);
  void setAuthor(string name);
  void setGenre(string genre);
  void setPrice(float data);
  void setQuantity(int quantity);

  // getter functions
  string getISBN();
  string getTitle();
  string getAuthor();
  string getYear();
  string getGenre();
  float getPrice();
  int getQuantity();
};

#endif // BOOK_H

