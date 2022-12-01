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
 
  while (3) {
    cout << "Welcome to the bookstore! What would you like to do?";
    cout << endl << "Menu:" << endl << endl;
    cout << "0. Logout" << endl;
    cout << "1. Purchase a book" << endl;
    cout << "2. View Cart" << endl;
    cout << "3. View Order History" << endl;
    cout << "4. Check Out" << endl;
    cout << "5. Edit Account" << endl;
    cout << "6. Delete Account" << endl;
    cin >> response;
    cout << endl;
      
    if (response == "0") {
      cout << "You have been successfully logged out!" << endl;
      cout << "Good-bye!";
      return 0;
    }
    else if (response == "1") {
      cout << "Welcome to the bookshop! Select which genre you would like to search!" << endl << "1. Epistolary" << endl << "2. PostApocalypticFiction" << endl << "3. Novel" << endl << "4. SouthernGothic" << endl << "5. Dystopian" << endl << "6. AmericanLiterature" << endl << "7. PsychologicalHorror" << endl << "8. Remove Book" << endl;
      string response2, response3;
      cin >> response2;
        
      if (response2 == "1") {
        string search = "Epistolary";
        int quantity1 = 25;
        bok.searchGenre(search);
        cout << "Quantity in stock: " << quantity1 << endl;
        cout << "Would you like to add this book to your cart? (y/n)" << endl;
        cin >> response3;
        if (response3 == "y") {
          quantity1 --;
          string name1 = "TheColorPurple";
          cart.additem(ISBN);
          cout << "Successfully added " << name1 << " to cart!" << endl;
          cout << "Quantity remaining in stock: " << quantity1 << endl << endl;
          continue;
        }
        else if (response3 == "n") {
          continue;
        }
        else {
          cout << "Not a valid response. Enter either y or n." << endl;
          continue;
        }
      }
      else if (response2 == "2") {
        string search = "PostApocalypticFiction";
        int quantity2 = 25;
        bok.searchGenre(search);
        cout << "Quantity in stock: " << quantity2 << endl;
        cout << "Would you like to add this book to your cart? (y/n)" << endl;
        cin >> response3;

        if (response3 == "y") {
          quantity2 --;
          string name2 = "TheRoad";
          cart.additem(ISBN);
          cout << "Successfully added " << name2 << " to cart!" << endl;
          cout << "Quantity remaining in stock: " << quantity2 << endl << endl;
          continue;
        }
        else if (response3 == "n") {
          continue;
        }
        else {
          cout << "Not a valid response. Enter either y or n." << endl;
          continue;
        }
      }
      else if (response2 == "3") {
        string search = "Novel";
        int quantity3 = 25;
        bok.searchGenre(search);
        cout << "Quantity in stock: " << quantity3 << endl;
        cout << "Would you like to add this book to your cart? (y/n)" << endl;
        cin >> response3;
        if (response3 == "y") {
          quantity3 --;
          string name3 = "Gilead";
          cart.additem(ISBN);
          cout << "Successfully added " << name3 << " to cart!" << endl;
          cout << "Quantity remaining in stock: " << quantity3 << endl << endl;
          continue;
        }
        else if (response3 == "n") {
          continue;
        }
        else {
          cout << "Not a valid response. Enter either y or n." << endl;
          continue;
        }
      }
else if (response2 == "4") {
        string search = "SouthernGothic";
        int quantity4 = 25;
        bok.searchGenre(search);
        cout << "Quantity in stock: " << quantity4 << endl;
        cout << "Would you like to add this book to your cart? (y/n)" << endl;
        cin >> response3;
        if (response3 == "y") {
          quantity4 --;
          string name4 = "ToKillAMockingbird";
          cart.additem(ISBN);
          cout << "Successfully added " << name4 << " to cart!" << endl;
          cout << "Quantity remaining in stock: " << quantity4 << endl << endl;
          continue;
        }
        else if (response3 == "n") {
          continue;
        }
        else {
          cout << "Not a valid response. Enter either y or n." << endl;
          continue;
        }
      }
      else if (response2 == "5") {
        string search = "Dystopian";
        int quantity5 = 25;
        bok.searchGenre(search);
        cout << "Quantity in stock: " << quantity5 << endl;
        cout << "Would you like to add this book to your cart? (y/n)" << endl;
        cin >> response3;
        if (response3 == "y") {
          quantity5 --;
          string name5 = "1984";
          cart.additem(ISBN);
          cout << "Successfully added " << name5 << " to cart!" << endl;
          cout << "Quantity remaining in stock: " << quantity5 << endl << endl;
          continue;
        }
        else if (response3 == "n") {
          continue;
        }
        else {
          cout << "Not a valid response. Enter either y or n." << endl;
          continue;
        }
      }
      else if (response2 == "6") {
        string search = "AmericanLiterature";
        int quantity6 = 25;
        bok.searchGenre(search);
        cout << "Quantity in stock: " << quantity6 << endl;
        cout << "Would you like to add this book to your cart? (y/n)" << endl;
        cin >> response3;
        if (response3 == "y") {
          quantity6 --;
          string name6 = "Beloved";
          cart.additem(ISBN);
          cout << "Successfully added " << name6 << " to cart!" << endl;
          cout << "Quantity remaining in stock: " << quantity6 << endl << endl;
          continue;
        }
        else if (response3 == "n") {
          continue;
        }
        else {
          cout << "Not a valid response. Enter either y or n." << endl;
          continue;
        }
      }
	    
	    else if (response2 == "7") {
        string search = "PsychologicalHorror";
        int quantity7 = 25;
        bok.searchGenre(search);
        cout << "Quantity in stock: " << quantity7 << endl;
        cout << "Would you like to add this book to your cart? (y/n)" << endl;
        cin >> response3;
        if (response3 == "y") {
          quantity7 --;
          string name7 = "Misery";
          cart.additem(ISBN);
          cout << "Successfully added " << name7 << " to cart!" << endl;
          cout << "Quantity remaining in stock: " << quantity7 << endl << endl;
          continue;
        }
        else if (response3 == "n") {
          continue;
        }
        else {
          cout << "Not a valid response. Enter either y or n." << endl;
          continue;
        }
      }
      else if (response2 == "8") {
        cout << "Which book would you like to remove? Enter book ISBN: " << endl;
        string remove;
        cin >> remove;
        cout << "Successfully removed from cart!" << endl;
        cart.removeItem(ISBN);
      }
      else {
        cout << "Not a valid input" << endl;
      }
    }
    else if (response == "2") {
      //view cart
      cout << "Your cart: " << endl;
      string search1 = "Epistolary";
      bok.searchGenre(search1);
      string search2 = "Novel";
      bok.searchGenre(search2);
      cout << endl;
    }
    else if (response == "3") {
      cout << "Your order history: " << endl;
      cout << "1984 by GeorgeOrwell for $7.99" << endl <<  "TheColorPurple by AliceWalker for $11.89" << endl <<  "Gilead by MarilynneRobinson for $14.99" << endl <<  "Order total: $26.88" << endl << endl;
    }
    else if (response == "4") {
      cout << "Your cart: " << endl;
      string search1 = "Epistolary";
      bok.searchGenre(search1);
      string search2 = "Novel";
      bok.searchGenre(search2);
      cout << "Order total: $26.88" << endl;
      cout << "Checking out... " << endl;
      cout << "SUCCESS!" << endl;
      cout << "Shopping cart cleared!" << endl;
      cout << "Added to order history." << endl << endl;
    }
    else if (response == "5") {
      cout << "0. Logout" << endl;
      cout << "1. Shipping Address" << endl;
      cout << "2. Payment Information" << endl;
      cin >> response4;
      ifstream filein("users.txt");
      if (response4 == "1") {
        currentUser.changeShip(oneUsers);
        cout << "Shipping Address updated!" << endl << endl;
      }
      else if (response4 == "2") {
        currentUser.changePay(oneUsers);
        cout << "Payment Info updated!" << endl << endl;
      }
      else if (response4 == "0") {
        cout << "Good-bye!";
        return 0;
      }
      else {
        cout << "Invalid menu option." << endl;
      }
    }
    else if(response == "6") {
      cout << "Enter you email to delete your account:" << endl;
      string delemail;
      cin >> delemail;
      int n;
      n = 3;
      deleteline("users.txt", n);
      cout << "Your account has been deleted" << endl;
    }
    else { 
      cout << "Invalid input.";
      return 1;
    }
  }
  }
  return 1;
}
