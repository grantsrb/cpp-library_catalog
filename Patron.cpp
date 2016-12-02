/*
 Author: Satchel Grant
 Date: 05/30/16
 Description: The cpp file for the Patron class.
*/

#include "Patron.hpp"

/*
std::string idNum;
std::string name;
std::vector<LibraryItem*> checkedOutItems;
double fineAmount;
*/


Patron::Patron(std::string idn, std::string n) { // Constructor
  idNum = idn;
  name = n;
}

std::string Patron::getIdNum() { // Get ID Number
  return idNum;
}

std::string Patron::getName() { // Get Name
  return name;
}

std::vector<LibraryItem*> Patron::getCheckedOutItems() { // Get CheckedOutItems
  return checkedOutItems;
}

void Patron::addLibraryItem(LibraryItem* b) { // Add LibraryItem
  checkedOutItems.push_back(b);
}

void Patron::removeLibraryItem(LibraryItem* b) { // Remove LibraryItem
  for (int count = 0; count < checkedOutItems.size(); count ++) {
    if (checkedOutItems[count] == b) {
      for (int kount = count; kount < checkedOutItems.size(); kount++)
        checkedOutItems[kount] = checkedOutItems[kount+1];
      checkedOutItems.pop_back();
    }
  }
}

double Patron::getFineAmount() { // Get Fine Amount
  return fineAmount;
}

void Patron::amendFine(double amount) { // Amend Fine Amount
  fineAmount += amount;
}
