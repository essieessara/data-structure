#include<iostream>
#include<string>
using namespace std;

//double linked list

struct list {
	struct list *prev;
	int id;
	string name;
	double gpa;
	struct list *next;
} *node = NULL, *first = NULL, *last = NULL, *node1 = NULL, *node2 = NULL,*p=NULL;

class linkedlist {
	public:

		/* Function for create/insert node at the beginning of Linked list */
		void insert_beginning() {
			list *addBeg = new list;
			cout << "Enter the student's ID:" << endl;
			cin >> addBeg->id;
			cout << "Enter the student's name:" << endl;
			cin >> addBeg->name;
			cout << "Enter the student's GPA:" << endl;
			cin >> addBeg->gpa;
			if(first == NULL) {
				addBeg->prev = NULL;
				addBeg->next = NULL;
				first = addBeg;
				last = addBeg;
				cout << "Linked list Created!" << endl;
			}
			else {
				addBeg->prev = NULL;
				first->prev = addBeg;
				addBeg->next = first;
				first = addBeg;
				cout << "Data Inserted at the beginning of the Linked list!" << endl;
			}
		}

		/* Function for create/insert node at the end of Linked list */
		void insert_end() {
			list *addEnd = new list;
			cout << "Enter the student's ID:" << endl;
			cin >> addEnd->id;
			cout << "Enter the student's name:" << endl;
			cin >> addEnd->name;
			cout << "Enter the student's GPA:" << endl;
			cin >> addEnd->gpa;
			if(first == NULL) {
				addEnd->prev = NULL;
				addEnd->next = NULL;
				first = addEnd;
				last = addEnd;
				cout << "Linked list Created!" << endl;
			}
			else {
				addEnd->next = NULL;
				last->next = addEnd;
				addEnd->prev = last;
				last = addEnd;
				cout << "Data Inserted at the end of the Linked list!" << endl;
			}
		}

		/* Function for display Linked list */
		void display() {
			node = first;
			cout << "List of data in Linked list!" << endl;
			while(node != NULL) {
				cout << "Student ID:"<<node->id <<"\t";
				cout << "Student Name:"<<node->name<<"\t";
				cout << "Student GPA:"<<node->gpa << endl;
				node = node->next;
			}
		}
		/* Function for sort Linked list */
		void sort() {
			node = first;
			cout << "List of data in Linked list in Descending order!" << endl;
			while(node != NULL) {
				cout << "Student ID:"<<node->id <<"\t";
				cout << "Student Name:"<<node->name <<"\t";
				cout << "Student GPA:"<<node->gpa << endl;
				node = node->next;
			}
			node = last;
			cout << "List of data in Linked list in Ascending order!" << endl;
			while(node != NULL) {
				cout << "Student ID:"<<node->id <<"\t";
				cout << "Student Name:"<<node->name <<"\t";
				cout << "Student GPA:"<<node->gpa << endl;
				node = node->prev;
			}

		}

		// Function for delete node from Linked list
		void del() {

			int count = 0, id, i;
			node = node1 = node2 = first;
			for(node = first; node != NULL; node = node->next)
				cout << "Enter Student's ID:" << endl;
			count++;
			display();
			cout << count << " nodes available here!" << endl;
			cout << "Enter the node which you want to delete:" << endl;
			cin >> id;
			if(id != 1) {
				if(id < count && id > 0) {
					for(i = 2; i <= id; i++)
						node = node->next;
					for(i = 2; i <= id-1; i++)
						node1 = node1->next;
					for(i = 2; i <= id+1; i++)
						node2 = node2->next;
					node2->prev = node1;
					node1->next = node2;
					node->prev = NULL;
					node->next = NULL;
					node = NULL;
				}
				else if(id == count) {
					node = last;
					last = node->prev;
					last->next = NULL;
					node = NULL;
				}

				else
					cout << "Invalid node number!" << endl;
			}
			else {
				node = first;
				first = node->next;
				first->prev = NULL;
				node = NULL;
			}
			cout << "Node has been deleted successfully!" << endl;
			display();
			return ;
		}





		//search by ID
   bool find( int id){

	 p=first;//first is the first element of the list
while(p!=NULL)
{
		if(p->id==id){
			return true;
			}
		p=p->next;
}
	return false;
   }

   		//search by name
   bool find( string name){

	 p=first;//first is the first element of the list
while(p!=NULL)
{
		if(p->name==name){
			return true;
			}
		p=p->next;
}
	return false;
   }


//delete student
   bool delete_student( int id){

	 p=first;

while(p!=NULL)
{
		if(p->id==id)
            {
			return true;

			}
		p=p->next;
		display();

}
	return false;

   }
};


int main() {
	int op = 0;

	int id;
	string name;
	linkedlist llist = linkedlist();
	while(op != 4) {
            cout<<"Operations made on double linked list"<<endl<<endl<<endl;
		cout << "1.Insert List \n2.Insert at End \n3.Sort by ID\n4.Display \n5.Search by ID  \n6.Search by Name \n7.delete by ID\n8.Delete by node  \n9.Destroy and Exit" << endl<<endl;
		cout << "Enter your choice:" << endl;
		cin >> op;
		switch(op) {
			case 1:
				llist.insert_beginning();
				break;

			case 2:
				llist.insert_end();
				break;

			case 3:
				llist.sort();
				return main();
				break;
			case 4:
				llist.display();
				return main();
				break;
			case 5:
			    cout<<"Enter Id";
			    cin>>id;
			    if(llist.find(id))

                {
                    cout<<"Found!"<<"at.."<<p<<endl;
                }
                else

                {
                    cout<<"Not Found"<<endl;
                };
			    return main();
            case 6:


                cout<<"Enter Name";
			    cin>>name;
			    if(llist.find(name))

                {
                    cout<<"Found!"<<"at.."<<p<<endl;
                }
                else

                {
                    cout<<"Not Found"<<endl;
                };
			    return main();






            case 7:
			    cout<<"Enter Id to delete"<<endl;
			    cin>>id;
			    if(llist.delete_student(id))

                {

                    cout<<"Student deleted!"<<endl;

                      p->id=NULL;
                      p->name="\0";
                      p->gpa=NULL;

                     return main();

                }
                else

                {
                    cout<<"Student Not Found"<<endl;
                    return main();
                };


           case 8:

				llist.del();
				return main() ;

				break;

			case 9:
				cout << "Bye Bye!" << endl;
				return 0;
				break;

			default:
				cout << "Invalid choice!" << endl;
		}
	}
	return 0;
}

