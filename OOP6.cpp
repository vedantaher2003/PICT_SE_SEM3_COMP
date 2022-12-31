#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Item {
	int code;
	float cost;
	int quantity;
	Item(int c, float x, int y):code(c),cost(x),quantity(y) {}
	void display() {
		cout << "Code: " << code << endl;
		cout << "Price: " << cost << endl;
		cout << "Quantity: " << quantity << endl;
	}
	static bool sort_code(Item& a, Item& b) {
		if (a.code < b.code) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool sort_cost(Item& a, Item& b) {
		if (a.cost < b.cost) {
			return true;
		}
		else {
			return false;
		}
	}
	static bool sort_quantity(Item& a, Item& b) {
		if (a.quantity < b.quantity) {
			return true;
		}
		else {
			return false;
		}
	}
	friend class Menu;
};
class Menu {
	vector<Item>list;
	void create_entry() {
		int a, c;
		float b;
		cout << "Enter Item Code:" << endl;
		cin >> a;
		cout << "Enter price: " << endl;
		cin >> b;
		cout << "Enter quantity: " << endl;
		cin >> c;
		Item temp(a, b, c);
		list.push_back(temp);
	}
	void sort_choice() {
		cout << "1 - Sort by code" << endl;
		cout << "2 - Sort by price" << endl;
		cout << "3 - Sort by quantity" << endl;
		int ip;
		cout << endl << "Enter choice: " << endl;
		cin >> ip;
		if (ip == 1) {
			sort(list.begin(), list.end(), Item::sort_code);
			for (auto it = list.begin(); it != list.end(); it++) {
				it->display();
			}
		}
		else if (ip == 2) {
			sort(list.begin(), list.end(), Item::sort_cost);
			for (auto it = list.begin(); it != list.end(); it++) {
				it->display();
			}
		}
		else if (ip == 3) {
			sort(list.begin(), list.end(), Item::sort_quantity);
			for (auto it = list.begin(); it != list.end(); it++) {
				it->display();
			}
		}
	}
	void searcher() {
		cout << "1 - Search by code" << endl;
		cout << "2 - Search by price" << endl;
		cout << "3 - Search by quantity" << endl;
		int ip;
		cout << endl << "Enter choice: " << endl;
		cin >> ip;
		if (ip == 1) {
			cout << "Enter code: " << endl;
			int c;
			cin >> c;
			for (auto it = list.begin(); it != list.end(); it++) {
				if (it->code == c) {
					it->display();
					return;
				}
			}
			cout << "Record not present" << endl;
			return;
		}
		else if (ip == 2) {
			cout << "Enter price: " << endl;
			float c;
			cin >> c;
			for (auto it = list.begin(); it != list.end(); it++) {
				if (it->cost == c) {
					it->display();
					return;
				}
			}
			cout << "Record not present" << endl;
			return;
		}
		else if (ip == 3) {
			cout << "Enter quantity: " << endl;
			int c;
			cin >> c;
			for (auto it = list.begin(); it != list.end(); it++) {
				if (it->quantity == c) {
					it->display();
					return;
				}
			}
			cout << "Record not present" << endl;
			return;
		}
	}
	public:
	void chooser() {
		int x = 0;
		while (x != 1) {
			cout <<endl<< "1 - Enter records" << endl;
			cout << "2 - Display records" << endl;
			cout << "3 - Sort" << endl;
			cout << "4 - Search" << endl;
			cout << "5 - Exit" << endl;
			int choice;
			cout << endl << "Enter choice: " << endl;
			cin >> choice;
			if (choice == 1) {
				create_entry();
			}
			else if (choice == 2) {
				for (auto it = list.begin(); it != list.end(); it++) {
					it->display();
				}
			}
			else if (choice == 3) {
				sort_choice();
			}
			else if (choice == 4) {
				searcher();
			}
			else if (choice == 5) {
				x = 1;
			}
		}
	}
};
int main() {
	Menu m1;
	m1.chooser();
}
