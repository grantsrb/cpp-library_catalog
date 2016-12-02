/*
  Author: Satchel Grant
  Date: 05/30/16
  Description: Album Class inherits from LibraryItem Class. It describes an album
    in the library inventory.
*/

#ifndef ALBUM_HPP
#define ALBUM_HPP

#include "LibraryItem.hpp"
#include <string>
#include <vector>

class Album: public LibraryItem {
private:
  std::string artist;
public:
  Album(std::string idc, std::string t, std::string artistName);
  static const int CHECK_OUT_LENGTH; // Days till overdue
  std::string getArtist();
  void setArtist(std::string artistName);
  virtual int getCheckOutLength();
};
#endif
