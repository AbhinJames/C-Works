#include <vector>
#include "Item.h"
#include "Book.h"
#include "Film.h"
#include "Library.h"
#include "LibraryController.h"

//Honestly i suck at Pointers. I have done the best i can. lol. Thank You Sir!
//Option 1 doesnt work...but i think i did what i cud. blames on me. i will do better in Java.

int main()
{
	std::vector<Item*> items =
	{
		//instantiate some Books and Films here using dynamic allocation
		
		new Book("Red Riding Hood","BLAH",350),
		new Film("Inception","Blah",210),
		new Book("HP","JK",500),
		new Film("UP","Blah",210),
		new Book("GOT","GT",800),
		new Film("Spy Kids","BLAH",120)
	};

	Library library = Library(items);
	LibraryController controller = LibraryController(&library);
	controller.start();

	for (int i = 0; i < items.size(); i++)
		delete items[i];
}