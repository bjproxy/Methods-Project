#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "book.h"
#include "user.h"
#include "inventory.h"
#include "shoppingCart.h"
#include <bits/stdc++.h>

using namespace std;
using std::getline;

Book bok;
User currentUser; 
ShoppingCart cart;

string response, username, shipAddress, email, pass, cardNum, cvv, response4, newshipAddress, ISBN;
ifstream infile;

void saveUser(User person){
  ofstream users("./users.txt", ios::app);
  users << person.getEmail() << " " << person.getPass() << " " <<  person.getShippingAddress() << " " << person.getPaymentInformation() << "\n";
  users.close();
}

void deleteline(const char *file_name, int n){
  ifstream is(file_name);
  ofstream ofs;
  ofs.open("temp.txt", ofstream::out);
  char c;
  int line_no = 1;
  while (is.get(c)){
      if (c == '\n')
      line_no++;  
      if (line_no != n)
        ofs << c;
  }
  ofs.close();
  is.close();
  remove(file_name);
  rename("temp.txt", file_name);
}

int main() {
  vector<Book> oneBooks;
  vector<User> oneUsers;
  
  bok.oneReadFile(oneBooks);
  currentUser.twoReadFile(oneUsers);
  
  //build login display here!
  while (1) {
    cout << "Welcome to the bookshop! Would you like to login or create an account?" << endl << "0. Exit " << endl << "1. Login to an existing account" << endl << "2. Create a new account" << endl;
		cin >> response;
    cin.ignore();
    cout << endl;
    
    if (response == "0") {
      cout << "Good-bye!" << endl;
      return 0;
    }
    if (response == "1") {
      cout << "Please enter your email address: (ex: johndoe@gmail.com" << endl;
      cin >> email;
      cin.ignore();
      getline(infile, email, ' ');
      cout << "Please enter your password: (no spaces)" << endl;  
      cin >> pass;
      cin.ignore();
      getline(infile, pass, ' ');
      if (!currentUser.search(email, pass)) {
        cout << "Error: Username and Password not found" << endl << endl;
        continue;
      }
    }
     
    else if (response == "2") {
      // ofstream users("users.txt", ios::app);
      cout << "Please enter a valid email address: (ex: johndoe@gmail.com)" << endl;
      cin >> email;
      currentUser.setEmail(email);
      cout << endl << "Please create a password (no spaces!):" << endl;
      cin >> pass;
      currentUser.setPass(pass);
      //address
      cout << endl << "Enter your shipping address: (ex: 1234-DawgDrive-Starkvegas-MS-39759)" << endl;
      cin >> shipAddress;
      currentUser.setShippingAddress(shipAddress);
      //payment info
      cout << endl << "Enter your card number: (ex: 1111222233334444)" << endl;
      cin >> cardNum;
      cout << endl << "Enter the security code: (CVV)" << endl;
      cin >> cvv;
      cout << endl;
      currentUser.setPaymentInformation(cardNum, cvv);
      saveUser(currentUser);
      continue;
    }
    else {
      cout << "Unexpected input. Expected 0, 1, or 2" << endl << endl;
      return 1;
    }
 
