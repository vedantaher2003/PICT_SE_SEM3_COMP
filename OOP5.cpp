#include <iostream>
using namespace std;
template<class T>
class Sort {
    int size=10;
    T arr[];
public:
    void accept_size() {
        cout << "Enter size:";
        cin >> size;
    }
    void swap(T* a, T* b) {
        T temp = *a;
        *a = *b;
        *b = temp;
    }
    void selectionSort() {
        for (int step = 0; step < size - 1; step++) {
            int min_idx = step;
            for (int i = step + 1; i < size; i++) {
                if (arr[i] < arr[min_idx])
                    min_idx = i;
            }
            swap(&arr[min_idx], &arr[step]);
        }
    }
    void Display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void accept() {
        cout << "Enter elements" << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    friend class menu;
};
class menu{
public:
	void choice(){
		int i =1;
		while(i!=0){
			cout << endl << "1 - Integer array "<<endl;
			cout << "2 - Float array"<<endl;
			cout << "3 - Exit"<<endl;
			int choice;
			cout << endl << "Enter choice: "<<endl;
			cin >> choice;
			if(choice == 1){
				Sort<int>s1;
				s1.accept_size();
				s1.accept();
				s1.Display();
				s1.selectionSort();
				s1.Display();
			}
			else if(choice == 2){
				Sort<float>s2;
				s2.accept_size();
				s2.accept();
				s2.Display();
				s2.selectionSort();
				s2.Display();
			}
			else if(choice == 3){
				i = 0;
			}
	}
	}
};
int main() {
	menu m1;
	m1.choice();
}
