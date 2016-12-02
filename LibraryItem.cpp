/*
 Author: Satchel Grant
 Date: 05/30/16
 Description: The cpp file for the library item class.
*/

#include "LibraryItem.hpp"

/*
std::string idCode;
std::string title;
Locale location;
Patron* checkedOutBy;
Patron* requestedBy;
int dateCheckedOut;
*/

/////////////////////////////////////////////////////////////////
///// Constructor

LibraryItem::LibraryItem(std::string idc, std::string t) { // Constructor
    idCode = idc;
    title = t;
}

/////////////////////////////////////////////////////////////////
///// idCode, Title, and Location Functions

std::string LibraryItem::getIdCode() { // Get idCode
    return idCode;
}

std::string LibraryItem::getTitle() { // Get Title
    return title;
}

Locale LibraryItem::getLocation() { // Get Location
    return location;
}

void LibraryItem::setLocation(Locale loc) { // Set Location
    location = loc;
}

/////////////////////////////////////////////////////////////////
///// Checked Out By Functions

Patron* LibraryItem::getCheckedOutBy() { // Get Checked Out By
    return checkedOutBy;
}

void LibraryItem::setCheckedOutBy(Patron* geek) { // Set Checked Out By
    checkedOutBy = geek;
}

/////////////////////////////////////////////////////////////////
///// Requested By Functions

Patron* LibraryItem::getRequestedBy() { // Get Requested By
    return requestedBy;
}

void LibraryItem::setRequestedBy(Patron* geek) { // Set Requested By
    requestedBy = geek;
}

/////////////////////////////////////////////////////////////////
///// Date Checked Out Functions

int LibraryItem::getDateCheckedOut() { // Get Date Checked Out
    return dateCheckedOut;
}

void LibraryItem::setDateCheckedOut(int date) { // Set Date Checked Out
    dateCheckedOut = date;
}
