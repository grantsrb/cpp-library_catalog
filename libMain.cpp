#include "Library.hpp"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
  Book b1("123", "War and Peace", "Tolstoy");
  Book b2("234", "Moby Dick", "Melville");
  Book b3("345", "Phantom Tollbooth", "Juster");
  Album a1("456","Butt Sex Beaches", "Teaches of Peaches");
  Patron p1("abc", "Felicity");
  Patron p2("bcd", "Waldo");
  Library lib;
  lib.addLibraryItem(&b1);
  lib.addLibraryItem(&b2);
  lib.addLibraryItem(&b3);
  lib.addLibraryItem(&a1);
  lib.addPatron(&p1);
  lib.addPatron(&p2);
  lib.checkOutLibraryItem("bcd", "234");
  for (int i=0; i<7; i++)
     lib.incrementCurrentDate();
  lib.requestLibraryItem("abc","234");
  cout << "book: " << b2.getLocation() << endl;
  lib.requestLibraryItem("bcd","456");
  cout << "book: " << a1.getLocation() << endl;
  lib.returnLibraryItem("234");
  cout << "book: " << b2.getLocation() << endl;
  lib.checkOutLibraryItem("abc","234");
  lib.checkOutLibraryItem("bcd", "123");
  lib.checkOutLibraryItem("abc", "345");
  cout << lib.checkOutLibraryItem("abc","456") << endl;
  vector<LibraryItem*> abcs = p1.getCheckedOutItems();
  vector<LibraryItem*> bcds = p2.getCheckedOutItems();
  for (int k = 0; k < 3; k++) {
    if (k<2)
      cout << "abc: " << abcs[k]->getLocation() << endl;

    if (k<1)
      cout << "bcd: " << bcds[k]->getLocation() << endl;
  }
  cout << " Album " << a1.getLocation() << endl;
  for (int i=0; i<24; i++)
     lib.incrementCurrentDate();
  lib.payFine("bcd", 5);
  double p1Fine = p1.getFineAmount();
  double p2Fine = p2.getFineAmount();
  cout << p1Fine << endl;
  cout << p2Fine << endl;

  return 0;
}
