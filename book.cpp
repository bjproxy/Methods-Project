#include "book.h"
#include <iostream>
#include <fstream>
#include <vector>

Book::Book() {
  ISBN = "isbn";
  title = "title";
  author = "author";
  year = "year";
  genre = "genre";
  price = 0.00;
}

Book::Book(string ISBN, string title, string author, string year, string genre, float price) {
  this->ISBN = ISBN;
  this->title = title;
  this->author = author;
  this->year = year;
  this->genre = genre;
  this->price = price;
}

// setter functions
void Book::setISBN(string num)
{
    this->ISBN = num;
}

void Book::setTitle(string title)
{
    this->title = title;
}

void Book::setAuthor(string author)
{
    this->author = author;
}

void Book::setGenre(string genre)
{
    this->genre = genre;
}

void Book::setPrice(float price)
{
    this->price = price;
}

void Book::setQuantity(int quantity)
{
  this->quantity = quantity;
}

//getter functions
string Book::getISBN()
{
    return this->ISBN;
}

string Book::getTitle()
{
    return this->title;
}

string Book::getAuthor()
{
    return this->author;
}

string Book::getYear() {
  return this->year;
}

string Book::getGenre()
{
    return this->genre;
}

float Book::getPrice()
{
    return this->price;
}

int Book::getQuantity()
{
  return this->quantity;
}

void Book::display(vector<Book> &books)
{
  for(int i = 0; i < books.size(); i++)
  {
    cout << "ISBN: " << books[i].getISBN() << endl;
    cout << "Title: " << books[i].getTitle() << endl;
    cout << "Author: " << books[i].getAuthor() << endl;
    cout << "Year: " << books[i].getYear() << endl;
    cout << "Genre: " << books[i].getGenre() << endl;
    cout << "Price: " << books[i].getPrice() << endl;
    cout << "Quantity: " << books[i].getQuantity() << endl;
    cout << endl;
  }
}

void Book::oneReadFile(vector<Book> &books)
{
  ifstream infile;
  infile.open("books.txt");

  string ISBN, title, author, year, genre;
  float price;
  int quantity;
  string response;

  while(infile >> ISBN >> title >> author >> year >> genre >> price >> quantity)
  {
    Book temp(ISBN, title, author, year, genre, price);
    books.push_back(temp);
  }
  infile.close();
}

void Book::searchGenre(string search) {
  ifstream infile;
  string line;
  size_t pos;
  infile.open("books.txt");
  while(infile.good()) {
    getline(infile,line); 
    pos=line.find(search); 
    if(pos!=string::npos) {
      cout << endl << line << endl << endl;
      break;
    }
  }
}

int processBookFile(vector<Book> &book) {
    ifstream infile;
    string line;

    // initial variables
    string ISBN;
    string title;
    string author;
    string year;
    string genre;
    float price;
    int quantity;

    // static inventory.txt file
    infile.open("books.txt");

    // checking for file success
    if(infile.is_open()) {
        cout << "Successful file opening." << endl;
    }
    // exits program otherwise
    else {
        cout << "Couldn't locate file. Program closing." << endl;
        exit(EXIT_FAILURE);
    }

    // loop to read file
    while(getline(infile, line)) {
      if(line == ISBN) {
      // initial object
      // constructor: no parameters
        Book temp;

        // get inventory data...
        infile >> ISBN;
        infile >> title;
        infile >> author;
        infile >> year;
        infile >> genre;
        infile >> price;
        infile >> quantity;

          // ignore newline for next getline...
        //infile.ignore();

            // set inventory data
        temp.setQuantity(quantity);
            // add to appropriate vector
        book.push_back(temp);
    }

  }
  return 0;
}

