#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using std::istream;
using std::stringstream;

using std::string;

#ifndef USER_H
#define USER_H

class User {
private:
  string shipAddress;
  string cardNum;
  string cvv;
  string email;
  string pass;
  string newshipAddress;
  string newPayInfo;

public:
  User();
  User(string email, string pass, string shipAddress, string cardNum, string cvv);
  bool search(string email, string pass);

  void display(vector<User> &users);
  void twoReadFile(vector<User> &users);
  // getters
  string getPurchaseHistory();
  string getShippingAddress();
  string getPaymentInformation();
  string getPass();
  string getEmail();

  // setters
  void setPurchaseHistory();
  void setShippingAddress(string shipAddress);
  void setPaymentInformation(string cardNum, string cvv);
  void setPass(string pass);
  void setEmail(string email);
  //void display();
  void changeShip(vector<User> &users);
  void changePay(vector<User> &users);
};

#endif

