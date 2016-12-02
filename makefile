all: lib

lib: libMain.o Library.o Patron.o Album.o Book.o Movie.o LibraryItem.o
	g++ -g libMain.o Library.o LibraryItem.o Album.o Book.o Movie.o Patron.o -o lib

libMain.o: libMain.cpp Library.hpp Patron.hpp Album.hpp Book.hpp Movie.hpp LibraryItem.hpp
	g++ -c libMain.cpp

Library.o: Library.cpp Library.hpp Patron.hpp Album.hpp Book.hpp Movie.hpp LibraryItem.hpp
	g++ -c Library.cpp

Patron.o: Patron.cpp Patron.hpp Album.hpp Book.hpp Movie.hpp LibraryItem.hpp
	g++ -c Patron.cpp

Album.o: Album.cpp Album.hpp LibraryItem.hpp
	g++ -c Album.cpp

Book.o: Book.cpp Book.hpp LibraryItem.hpp
	g++ -c Book.cpp

Movie.o: Movie.cpp Movie.hpp LibraryItem.hpp
	g++ -c Movie.cpp

LibraryItem.o: LibraryItem.cpp LibraryItem.hpp
	g++ -c LibraryItem.cpp

clean:
	rm -f *.o
