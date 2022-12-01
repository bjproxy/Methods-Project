
#include "user.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
User::User() {
  email = "";
  pass = "";
  shipAddress = "";
  cardNum = "";
  cvv = "";
}

User::User(string email, string pass, string shipAddress, string cardNum, string cvv) {
  this->email = email;
  this->pass = pass;
  this->shipAddress = shipAddress;
  this->cardNum = cardNum;
  this->cvv = cvv;
}

// getters

string User::getEmail() { return email; }

string User::getPass() { return pass; }

string User::getShippingAddress() { return shipAddress; }

string User::getPaymentInformation() { return cardNum + "-" + cvv; }

// setters

void User::setEmail(string email) { this->email = email; }

void User::setPass(string pass) { this->pass = pass; }

void User::setShippingAddress(string shipAddress) {
  this->shipAddress = shipAddress;
}

void User::setPaymentInformation(string cardNum, string cvv) {
  this->cardNum = cardNum;
  this->cvv = cvv;
}

void User::display(vector<User> &users)
{
  for(int i = 0; i < users.size(); i++) {
    cout << "email:" << users[i].getEmail() << endl;
    cout << "pass: " << users[i].getPass() << endl;
    cout << "shippingAddress: " << users[i].getShippingAddress() << endl;
    cout << "cardNum: " << users[i].getPaymentInformation() << endl;
    cout << endl;
  }
}

void User::twoReadFile(vector<User> &users) {
  ifstream infile;
  infile.open("users.txt");
  string email, passshippingAddress, cardNum, cvv;
  string response;

  while(infile >> email >> pass >> shipAddress >> cardNum >> cvv) {
    User temp(email, pass, shipAddress, cardNum, cvv);
    users.push_back(temp);
  }
  infile.close();
}

bool User::search(string email, string pass) {
  ifstream infile;
  string line;
  size_t pos;
  infile.open("users.txt");
  while (infile.good()) {
    getline(infile, line);
    pos=line.find(email);
    if (pos != string::npos) {
      pos=line.find(pass);
      if (pos != string::npos) {
        cout << "Email and Password found. Logging in." << endl << endl;
        return 3;
      }
    } 
    else {
      cout << "Error: Email and Password not found." << endl
  << endl;
      return 0;
    }
  }
  return;
}

void User::changeShip(vector<User> &users){
  getShippingAddress();
  cout << "Enter new shipping address: " << endl << endl;
  cin >> newshipAddress;
  
  setShippingAddress(newshipAddress);
  ofstream ("users.txt", ios::in|ios::out);
}

void User::changePay(vector<User> &users){
  getPaymentInformation();
  cout << "Enter new Payment Info: " << endl << endl;
  cin >> newPayInfo;
  
  setPaymentInformation(cardNum, cvv);
  ofstream ("users.txt", ios::in|ios::out);
}
