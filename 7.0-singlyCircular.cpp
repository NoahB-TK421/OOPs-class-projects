/**************
Using the record class, create a circular list, singularly linked. 

The record collection class (template provided) should have the following functions: addRecord, removeReecord, searchByartist, search by album, printall.

The template provides a skeleton collection class with function prototypes. It also has a main with a menu and setup

The input "7.0-input.txt" has a sample of records to use.

***************/
#include <iostream>
#include <fstream>
#include <string>

// The record, as you will use it, only needs an artist and album for private variables
// next must be public to be usable by the collection_c class
// print and get functions are provided, along with a constructor with inputs and a destructor
// These are the only functions required, but if you want to add more, you can.
class record_c{
	protected:
		std::string artist;
		std::string album;
	public:
		record_c *next;	
		void print(){
			std::cout << artist << " - " << album << std::endl;
		}
		record_c(std::string art, std::string alb):artist(art),album(alb){
			std::cout << "Created: ";
			print();
		}
		std::string getArtist(){
			return artist;
		}
		std::string getAlbum(){
			return album;
		}
		~record_c(){
			std::cout << "Destructed: ";
			print();
		}

};

class collection_c{
	private:
		// Head is the front of the list, the last entry's next pointer will point to the head
		record_c *Head;
	public:
		// Remember Head, next
		void addRecord(std::string artist, std::string album);
		void removeRecord(std::string nameToRemove);
		void searchArtist(std::string nameToSearch);
		void searchAlbum(std::string nameToSearch);
		void printAll();
		void deleteAll();
		collection_c(){ // need to set everything to NULL right away
			Head = NULL; // note this is the only NULL (when the collection is empty)
		}
		~collection_c(){
			deleteAll(); // when the list is deleted, we need to delete all entries
		}
};

int main(){

	int choice = 0;
	std::string artist, album;
	collection_c collection;
	std::ifstream input("7.0-input.txt"); 

	// This provided code populates the list by adding one entry at a time. 
	// It will only work for 9 total entries.
	for(int i = 0; i < 9; i++){
		getline(input, artist); // there are spaces, so you can't use the >>
		getline(input, album);  // get line will get the entire artist/album
		collection.addRecord(artist, album);
	}
	std::cout << "Collection populated.\n ";
	do{
		// Menu to ask if the person wants to continue or which function to do.
		std::cout << "1 to print\n 2 to search for an artist\n 3 to search by album title\n 4 to add\n 5 to remove\n 0 to exit\n";
		std::cin >> choice;

		switch(choice){
			case 1: collection.printAll(); break;
			case 2: {
				std::cin.ignore(); // this is necessary to make sure the cin works properly
				std::cout << "Which artist? ";
				getline(std::cin, artist);
				collection.searchArtist(artist); 
				break;
			}
			case 3: {
				int low, high;
				std::cin.ignore();
				std::cout << "What album? ";
				getline(std::cin, album);
				collection.searchAlbum(album); 
				break;
			}
			case 4:  {
				std::cin.ignore();
				std::cout << "What artist to add? ";
				getline(std::cin, artist);
				std::cout << "What album? ";
				getline(std::cin, album);
				collection.addRecord(artist, album); break;
			}
			case 5:  {
				std::cin.ignore();
				std::cout << "Which artist to delete? ";
				getline(std::cin, artist);
				collection.removeRecord(artist); 
				break;
			}
			default: break;
		}

	}while(choice != 0);

	return 0;
}

//  You can add the entry anywhere in the list. Keep note of the following:
//	- If the list is empty, you need to have 1 entry that points to itself
//	- If make sure to always have the last entry pointing to the Head through the next pointer	
void collection_c::addRecord(std::string nameToAdd, std::string albumToAdd){
	record_c* temp = new record_c(nameToAdd, albumToAdd);

	if(Head == NULL){
//	record_c* temp = new record_c(nameToAdd, albumToAdd);

	temp->next = Head;
	Head = temp;
	}
//	record_c* temp = new record_c(nameToAdd, albumToAdd);

	temp->next = Head->next;
	Head->next = temp;
}

// Cases to be careful of: If there is no head; if there is no match; if you are removing head; if you are removing any other
void collection_c::removeRecord(std::string nameToRemove){
	if(Head == NULL) return;

	if(Head->getArtist()==nameToRemove && Head->next==Head){
		delete(Head);
		Head=NULL;
	}

	record_c* temp = Head;

	if(Head->getArtist()==nameToRemove){
		do{
		temp = temp->next;
		}while(temp->next !=Head);

		temp->next = Head->next;
		delete(Head);
		Head = temp->next;
	}

	while(temp->next !=Head && temp->next->getArtist() != nameToRemove){ temp=temp->next; }

	if(temp->next->getArtist() == nameToRemove){
		record_c* hold = temp->next;
		temp->next=hold->next;
		std::cout <<"Artist: " << nameToRemove << " deleted from list\n";
		delete(hold);
		std::cout <<"List after deleting\n";
		collection_c::printAll();
	}else{
		std::cout <<"Artist: "<< nameToRemove <<" not found\n";
	}
/**	int found = 0;
	record_c* temp = Head;
	do{
	if(Head == NULL){ std::cout << "list in empty\n";}

	if(Head->getArtist() == nameToRemove){
		while(temp->next != Head){ temp = temp->next;}

		Head = Head->next;
		record_c* hold = temp;
		delete hold;
		Head = temp->next;
		found = 1;
	}
	if(nameToRemove == temp->next->getArtist()){
		record_c* temp = Head;
	        do{
        	        temp = temp->next;
	        }while(temp->next->getArtist() != nameToRemove);
        //		temp->next = NULL; // remove the circular nature
	//        	temp = Head;
		        record_c* hold;
//	        while(temp){
	                hold = temp->next;
//        	        temp = temp->next;
                	delete hold;
  //      		}
			found = 1;
        	}
  //              temp = temp->next;
	}while(!found);
	if(!found)
		std::cout << "Not found.\n";
**/
}

// Because you can't use the standard for loop, I suggest using a do-while, where you start at head, move the pointer in the body, then check if it matches Head in the while portion
void collection_c::searchArtist(std::string nameToSearch){
	int found = 0;
	record_c* temp = Head;
	do{
        	if(nameToSearch == temp->getArtist()){
                	temp->print();
                	found = 1;
                }
                temp = temp->next;
        }while(temp != Head);
	if(!found)
		std::cout << "Not found.\n";
}

// Because you can't use the standard for loop, I suggest using a do-while, where you start at head, move the pointer in the body, then check if it matches Head in the while portion
void collection_c::searchAlbum(std::string nameToSearch){
	int found = 0;
	record_c* temp = Head;
	do{
		if(nameToSearch == temp->getAlbum()){
			temp->print();
			found = 1;
		}
		temp = temp->next;
	}while(temp != Head);
	if(!found)
		std::cout << "Not found.\n";
}

// Because you can't use the standard for loop, I suggest using a do-while, where you start at head, move the pointer in the body, then check if it matches Head in the while portion
void collection_c::printAll(){
	record_c* temp = Head;
	do{
		temp->print();
		temp = temp->next;
	}while(temp != Head);
}

// I am providing a deleteAll for ease and to ensure no memory leaks or issues
void collection_c::deleteAll(){
	record_c* temp = Head;
	do{
		temp = temp->next;
	}while(temp->next != Head);
	temp->next = NULL; // remove the circular nature
	temp = Head;
	record_c* hold;
	while(temp){
		hold = temp;
		temp = temp->next;
		delete hold;
	}
	Head = NULL;
}
