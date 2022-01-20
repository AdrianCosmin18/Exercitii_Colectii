#pragma once
#include"iList.h"

template<typename T>
class List:public iList<T>
{
private:

	Node<T>* head = NULL;

public:

	Node<T>* get_head() { return head; }

	void traverse() {

		Node<T>* itr = head;
		while (itr != NULL) {

			cout << itr->get_data() << " ";
			itr = itr->get_next();
		}
	}

	Node<T>* get_last() {

		Node<T>* itr = head;
		Node<T>* last = new Node<T>();
		while (itr != NULL) {

			last = itr;
			itr = itr->get_next();
		}

		return last;
	}

	void push_back(T t) {

		if (head == NULL) {

			Node<T>* node = new Node<T>();
			node->set_data(t);
			node->set_next(NULL);
			head = node;
		}
		else {

			Node<T>* last = new Node<T>();//
			last = get_last();//
			Node<T>* node = new Node<T>();//
			node->set_data(t);//
			node->set_next(NULL);
			last->set_next(node);//

		}
	}

	Node<T>* get_node_by_index(int index) {

		int poz = -1;
		Node<T>* itr = head;
		while (itr != NULL) {

			poz++;
			if (poz == index) {

				return itr;
			}

			itr = itr->get_next();
		}
		return NULL;
	}

	int size() {

		int count = 0;
		Node<T>* itr = head;

		while (itr != NULL) {

			count++;
			itr = itr->get_next();
		}

		return count;
	}

	void remove_first() {

		head = head->get_next();
	}

	void remove(int index) {

		Node<T>* node = get_node_by_index(index);
		Node<T>* prev = get_node_by_index(index - 1);

		prev->set_next(node->get_next());
	}

	bool isEmpty() {

		if (head == NULL) {

			return true;
		}

		return false;
	}

	void insert(int index, T t) {

		Node<T>* node_to_insert = new Node<T>();
		node_to_insert = get_node_by_index(index);

		Node<T>* move_node = new Node<T>();
		move_node->set_data(node_to_insert->get_data());
		move_node->set_next(node_to_insert->get_next());

		node_to_insert->set_data(t);
		node_to_insert->set_next(move_node);

	}

	int indexOf(T t) {

		int index = -1;
		Node<T>* itr = head;

		while (itr != NULL) {

			index++;
			if (itr->get_data() == t) {

				return index;
			}
			itr = itr->get_next();
		}

		return -1;
	}
};

