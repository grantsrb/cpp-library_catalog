/*
  Author: Satchel Grant
  Date: 05/30/16
  Description: The cpp file for the Library Class. Essentially creates an entire library system.
*/

#include "Library.hpp"
#include <string>
#include <vector>

/*
std::vector<LibraryItem*> holdings;
std::vector<Patron*> members;
int currentDate;
*/

Library::Library() { // Constructor for Entire Library Class
  currentDate = 0;
}

void Library::addLibraryItem(LibraryItem* newItem) { // Add Library Item to Holdings List
  holdings.push_back(newItem);
}

void Library::addPatron(Patron* newPatron) { // Adds Patron to members list
  bool alreadyExists = false;
  for (int count = 0; count < members.size(); count ++) {
    if (members[count] == newPatron)
      alreadyExists = true;
  }
  if (!alreadyExists)
    members.push_back(newPatron);
}

std::string Library::checkOutLibraryItem(std::string patronID, std::string ItemID){ // Checks Out Item to Patron
  bool itemFound = false, patronFound = false;
  int itemIndex, patronIndex;

    // Checks for Item
  for (int count = 0; count < holdings.size(); count ++) {
    if (holdings[count]->getIdCode() == ItemID) {
      itemFound = true;
      itemIndex = count;
    }
  }
  if (!itemFound)
    return "item not found";

    // Checks for patron
  for (int count = 0; count < members.size(); count ++) {
    if (members[count]->getIdNum() == patronID) {
      patronFound = true;
      patronIndex = count;
    }
  }
  if (!patronFound)
    return "patron not found";

    // Checks if Checked Out
  if (holdings[itemIndex]->getLocation() == CHECKED_OUT)
    return "item already checked out";

    // Checks if on Hold
  else if (holdings[itemIndex]->getLocation() == ON_HOLD_SHELF) {

      // Current patron is top of waiting list
    if (holdings[itemIndex]->getRequestedBy()->getIdNum() == patronID) {
      holdings[itemIndex]->setRequestedBy(NULL); // Hold removed
      members[patronIndex]->addLibraryItem(holdings[itemIndex]); // Updates Patron's Checked Out Items
      holdings[itemIndex]->setLocation(CHECKED_OUT); // Updates Item Location
      holdings[itemIndex]->setCheckedOutBy(members[patronIndex]); // Updates Item's Checked Out by Status
      holdings[itemIndex]->setDateCheckedOut(currentDate); // Updates Item Checkout Date
      return "check out successful";
    }
    else {
      return "item on hold by other patron";
    }
  }
  else {
    members[patronIndex]->addLibraryItem(holdings[itemIndex]); // Updates Patron's Inventory
    holdings[itemIndex]->setLocation(CHECKED_OUT); // Updates Item Location
    holdings[itemIndex]->setCheckedOutBy(members[patronIndex]); // Updates Item's Checked Out by Status
    holdings[itemIndex]->setDateCheckedOut(currentDate); // Updates Item Checkout Date
    return "check out successful";
  }
}

std::string Library::returnLibraryItem(std::string ItemID) { // Returns Item to Shelves
  bool itemFound = false;
  int itemIndex;
  for (int count = 0; count < holdings.size(); count++) {
    if (holdings[count]->getIdCode() == ItemID) {
      itemFound = true;
      itemIndex = count;
    }
  }
  if (!itemFound)
    return "item not found";

  if (holdings[itemIndex]->getLocation() != CHECKED_OUT)
    return "item already in library";

  else {
    holdings[itemIndex]->getCheckedOutBy()->removeLibraryItem(holdings[itemIndex]); // Updates Patron's Inventory
    if (holdings[itemIndex]->getRequestedBy())
      holdings [itemIndex]->setLocation(ON_HOLD_SHELF); // Updates Item Location
    else
      holdings[itemIndex]->setLocation(ON_SHELF); // Updates Item Location
    holdings[itemIndex]->setCheckedOutBy(NULL); // Updates Item's Ownership Status
    holdings[itemIndex]->setDateCheckedOut(0); // Updates Item's Check Out Date
    return "return successful";
  }
}

std::string Library::requestLibraryItem(std::string patronID, std::string ItemID) { // Puts a hold on an Item if Possible
  bool itemFound = false, patronFound = false;
  int itemIndex, patronIndex;

    // Checks for Item
  for (int count = 0; count < holdings.size(); count++) {
    if (holdings[count]->getIdCode() == ItemID) {
      itemFound = true;
      itemIndex = count;
    }
  }
  if (!itemFound)
    return "item not found";

    // Checks for patron
  for (int count = 0; count < members.size(); count ++) {
    if (members[count]->getIdNum() == patronID) {
      patronFound = true;
      patronIndex = count;
    }
  }
  if (!patronFound)
    return "patron not found";

    // Checks if already on hold
  if (holdings[itemIndex]->getRequestedBy())
    return "item already on hold";
  else {
    holdings[itemIndex]->setRequestedBy(members[patronIndex]);
    if (holdings[itemIndex]->getLocation() == ON_SHELF) // Checks if on shelf, does nothing if checked out
      holdings[itemIndex]->setLocation(ON_HOLD_SHELF);

    return "request successful";
  }
}

std::string Library::payFine(std::string patronID, double payment) { // Records Payments by Patrons to their Fines
  bool patronFound = false;
  int patronIndex;

    // Checks for patron
  for (int count = 0; count < members.size(); count ++) {
    if (members[count]->getIdNum() == patronID) {
      patronFound = true;
      patronIndex = count;
    }
  }
  if (!patronFound)
    return "patron not found";
  else {

      // Amends Fine Amount for Specified Patron
    double before = members[patronIndex]->getFineAmount();
    members[patronIndex]->amendFine(-payment);
    if (before != members[patronIndex]->getFineAmount()) // Checks that payment went through
      return "payment successful";
    else
      return "Error";
  }
}

void Library::incrementCurrentDate() { // Adds to Current Date and Fines Patrons with Overdue Items
  currentDate++;
  for (int count = 0; count < holdings.size(); count++) {
    if (holdings[count]->getLocation() == CHECKED_OUT && (currentDate - holdings[count]->getDateCheckedOut()) > holdings[count]->getCheckOutLength())
      holdings[count]->getCheckedOutBy()->amendFine(.10);
  }
}


Patron* Library::getPatron(std::string patronID){ // Get Patron Using Patron's ID Number
  bool patronFound = false;
  int patronIndex;

    // Checks for patron
  for (int count = 0; count < members.size(); count ++) {
    if (members[count]->getIdNum() == patronID) {
      patronFound = true;
      patronIndex = count;
    }
  }
  if (!patronFound)
    return NULL;
  else
    return members[patronIndex];
}

LibraryItem* Library::getLibraryItem(std::string ItemID) { // Get Library Item Using Item ID Number
  bool itemFound = false;
  int itemIndex;
  for (int count = 0; count < holdings.size(); count++) {
    if (holdings[count]->getIdCode() == ItemID) {
      itemFound = true;
      itemIndex = count;
    }
  }
  if (!itemFound)
    return NULL;
  else
    return holdings[itemIndex];
}
