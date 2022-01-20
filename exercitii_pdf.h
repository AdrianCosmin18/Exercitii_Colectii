#include"List.h"

//1. Do linked lists take more storage space than arrays of the same size?


//2. Why don’t we need iterators with arrays ?


//3. Make a linked list of integers containing the numbers 1 through 10.
void ex3() {

	List<int>* l = new List<int>();
	for (int i = 1; i < 11; i++) {

		l->push_back(i);
	}


	cout << "\n\nlinked list created : ";

	l->traverse();
}


//4. How do you erase the first element of the linked list names?
void ex4() {

	List<string>* names = new List<string>();
	names->push_back("Tom");
	names->push_back("Diana");
	names->push_back("Harry");
	names->push_back("Juliet");


	cout << "\nList before remove first : ";
	names->traverse();

	cout << "\n\nList after erase first : ";
	names->remove_first();
	names->traverse();

}


//5. How do you erase the last element of the linked list names?
void ex5() {

	List<string>* names = new List<string>();
	names->push_back("Tom");
	names->push_back("Diana");
	names->push_back("Harry");
	names->push_back("Juliet");

	cout << "\nList before remove last : ";
	names->traverse();

	cout << "\n\nList after erase last : ";
	names->remove(names->size() - 1);
	names->traverse();
}


//6. How do you add "Buffy" as the second element in the list names?
void ex6() {

	List<string>* names = new List<string>();
	names->push_back("Tom");
	names->push_back("Diana");
	names->push_back("Harry");
	names->push_back("Juliet");

	cout << "\nList before insert on the second positon : ";
	names->traverse();

	cout << "\n\nList after insert on the seconed position : ";
	names->insert(1, "Buffy");
	names->traverse();
}


//7. Trace through the push_back method when adding an element to an empty list.
void ex7() {

	List<string>* names = new List<string>();
	string emp = "";
	if (names->isEmpty()) {

		emp = "e goala";
	}
	else {
		emp = "nu e goala";
	}

	cout << "\nLista de nume la inceput " << emp;

	cout << "\n\nAdaugam nume in lista";
	string name;
	for (int i = 0; i < 4; i++) {

		cout << "\nNume : ";
		cin >> name;
		names->push_back(name);
		cout << "\nAfisare cu functia din lista : " << names->get_node_by_index(i)->get_data() << " ";
	}
}


//8. If the iterator pos has been set to names.end(), trace through the call 
//names.insert(pos, "Fred").
void ex8() {

	List<string>* names = new List<string>();
	names->push_back("Tom");
	names->push_back("Diana");
	names->push_back("Harry");
	names->push_back("Juliet");

	Node<string>* itr = names->get_last();
	names->insert(names->indexOf(itr->get_data()), "Fred");

	cout << "\nNames list after insert : ";
	names->traverse();
}


//9. If the iterator pos has been set to names.begin(), trace through the call
//names.insert(pos, "Fred").Assume the list is not empty.
void ex9() {

	List<string>* names = new List<string>();
	names->push_back("Tom");
	names->push_back("Diana");
	names->push_back("Harry");
	names->push_back("Juliet");

	if (!names->isEmpty()) {

		Node<string>* itr = names->get_head();
		names->insert(names->indexOf(itr->get_data()), "Fred");

		cout << "\nNames list after insert : ";
		names->traverse();
	}
	else {

		cout << "\nThe names list is empty";
	}
	
}


//10. Why does the insert method have three separate cases?
// 
// first method represents the moment when the list is empty
// the second method represents the moment when i insert between the first and last element 
// third method represents the moment when i insert on the last position => i have to get the index
//of the last element


//11. What happens when you try to move an iterator past the end of a list?
// 
//the iterator will be NULL cause my iterator is a Node Class and i use 
//functions like "get_node_by_index" and "get_last" which returns the current node or returns NULL
//if it doesn't exists

//12. What is the big-Oh efficiency for removing the middle element of a linked list?
// aprox O(size of list)

//13. What is the big-Oh efficiency for removing the middle element of an array?
// 
// aprox O(size of array) => i think it is bigger then linked list's efficiency

//14. Why doesn’t it make sense to use a binary search algorithm on a sorted list?
// 
// i think is inefficiency because it just depends on the relative costs of iteration and
//comparison and if the list is large it could take more time, it think would be a better way to
// traverse the the list (classic way) from the begining.
