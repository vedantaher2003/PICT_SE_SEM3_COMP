#include <iostream>
using namespace std;
class node{
	bool status;
	node*next;
	node*prev;
	friend class cinema;
public:
	node(){
		status=0;
		next=NULL;
		prev=NULL;
	}
};

class cinema{
	node* arr[10];
public:

	cinema(){

		node*p;
		for(int i=0; i<10 ;i++)
		{

			arr[i]=new node;
			arr[i]->next=NULL;
			arr[i]->prev=NULL;
			node*p=arr[i];
			for(int j=1 ; j<7 ;j++)
			{
				node*t=new node;
				p->next=t;
				t->prev=p;
				t->next=NULL;
				p=t;
			}
			p=NULL;

		}
	}
	void Book(){
		int nseats;
		int no;
		char r;
		int c;
		node*f;
		cout<<"\t\t\t\t\t\t\t\tEnter the number of seats to be booked: ";
		cin>>nseats;
		for(int j=1; j<=nseats ; j++){
			cout<<"\t\t\t\t\t\t\t\tEnter row Number To be Booked: ";
			cin>>r>>c;
			f=arr[int(r)-64-1];
			for(int i=1 ; i<c ; i++){
					f=f->next;
				}
			f->status=true;

		}


	}
	void Cancelation(){

				int nseats;
				int no;
				char r;
				int c;
				node*f;
				cout<<"\t\t\t\t\t\t\t\tEnter the number of seats to be Canceled: ";
				cin>>nseats;
				for(int j=1; j<=nseats ; j++){
					cout<<"\t\t\t\t\t\t\t\tEnter Seat Number To be Canceled: ";
					cin>>r>>c;
					f=arr[int(r)-64-1];
					for(int i=1 ; i<c ; i++){
							f=f->next;
						}
					f->status=false;

				}


	}
	void display(){
		int x=65;
		cout<<"\t\t\t\t\t\t\t        *********\n";
		for(int i=0; i<10 ;i++){
			node*p=arr[i];
//			cout<<"________________________"<<endl;
//			cout<<endl;
			cout<<"\t\t\t\t\t\t\t\t"<<char(x)<<"--> ";
			for(int j=1 ; j<=7 ;j++){

				cout<<p->status<<" ";
				p=p->next;
			}
			cout<<endl;
			x=x+1;

		}
	}
	
};

int main() {
	cinema c;
	system("CLS");
	
	int code;
	while(1<2){
		c.display();
		cout<<endl;
		cout<<"\t\t\t\t\t\t\t        *********\n";
		cout<<"\t\t\t\t\t\t\t\tEnter 1 to book tickets "<<endl;
		cout<<"\t\t\t\t\t\t\t\tEnter 2 to cancel tickets "<<endl;
		cout<<"\t\t\t\t\t\t\t\tEnter 3 to display the status"<<endl;
		cout<<"\t\t\t\t\t\t\t\tEnter 4 to Exit Program \n\n";
		cout<<"\t\t\t\t\t\t\t\tYour INPUT: ";
		cin>>code;
		cout<<"\t\t\t\t\t\t\t        *********\n";
		if(code==1)
		{
			c.Book();
			cout<<endl;
			system("CLS");
		}
		else if(code==2)
		{
			c.Cancelation();
			cout<<endl;
			system("CLS");
		}
		else if(code==3)
		{
			c.display();
			cout<<endl;
			system("CLS");
		}
		else if(code==4)
		{
			cout<<"bye guyzzzzzzzzzzzz"<<endl;
			cout<<"-"<<endl;
			system("CLS");
			break;
		}
	}



	return 0;
}