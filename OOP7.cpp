#include <iostream>
#include <map>
#include <string>
using namespace std;

class Map{
	map <string,double> states;
public:
	void insert_ele(){
		string state;
		double pop;
		cout << "Enter State: "<<endl;
		cin >> state;
		int flag = 0;
		cout << "Enter population: "<<endl;
		cin >> pop;
		for(auto it = states.begin();it!=states.end();it++){
			if(state == it->first){
				flag = 1;
		}
		}
		if(flag == 1){
			cout << "Duplicate key!"<<endl;
			cout << "a - Update existing"<<endl;
			cout << "b - Add to existing"<<endl;
			cout << endl << "Enter action"<<endl;
			char action;
			cin >> action;
			if(action == 'a'){
				states[state] = pop;
			}
			else if(action == 'b'){
				states[state]+=pop;
			}
		}
		else if(flag == 0){
			states.insert({state,pop});
		}
	}
	void view(){
		string state;
		cout << "Enter State: "<<endl;
		cin >> state;
		int flag = 1;
		for(auto it = states.begin();it!=states.end();it++){
			if(it->first == state){
				flag = 0;
				break;
			}
		}
		try{
			if(flag == 1){
				throw "State not found!";
			}
			cout << state << "-" <<states[state]<<endl;
		}
		catch(const char* x){
			cout << x <<endl;
		}
	}
	friend class menu;
};
class menu{
public:
	void choice(){
		Map m1;
		int x = 1;
		while(x!=0){
			cout << "1 - Enter Record"<<endl;
			cout << "2 - View Record"<<endl;
			cout << "3 - Exit"<<endl;
			cout << endl;
			cout << "Enter choice: "<<endl;
			int ch;
			cin >> ch;
			if(ch == 1){
				m1.insert_ele();
			}
			else if(ch == 2){
				m1.view();
			}
			else if(ch == 3){
				x = 0;
			}
		}
	}
};
int main(){
	menu m1;
	m1.choice();
}
