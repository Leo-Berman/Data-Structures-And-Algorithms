#include<iostream>
#include<fstream>
#include<memory>
#include "linked_list.h"
#include<vector>
using namespace std;

#define DEFAULT_DIRECTORY "/data/courses/ece_3822/current/project_2/"
#define DEFAULT_FILENAME "dataFile1.txt"

// do not edit
string get_filename(int argc, char** argv){
    string filename = DEFAULT_DIRECTORY;
    
    // no command line inputs: use default
    if (argc == 1)
        filename += DEFAULT_FILENAME;

    // command line filename given
    else
        filename += (string) argv[1];
    
    return filename;
}

class linked_list_movies : public linked_list<int>{
    
    public:

    void display(){
        
        // Setting a tmp pointer to head
        node* tmp = head;

        // Looping through the list
        for(int i = 0; i < len();i++){
            
            // checking to see if the last element for comma purposes
            if(i!=len()-1){
                cout <<tmp->data<<", ";
            }
            else if(i == len() - 1){
                cout << tmp->data << endl;
            }

            // advancing the pointer down the list
            tmp = tmp->next;
        }
    }
    
    bool search(int in){

        // setting a tmp poitner to head
        node* tmp = head;

        // looping through the list
        while(tmp){

            // if the person watched the film return true;
            if(tmp->data==in){
                return true;
            }

            // advance down the list
            tmp=tmp->next;
        }

        // if not found return false
        return false;
    }
     
    ~linked_list_movies(){
        // clearing list
        while(n_elements>0) pop();
    }
};

class customer{
    public:

    // variables to sore id and customer number and a list of movies
    int customer_id;
    linked_list_movies movie_ids;
    int customer_num;  

    void display(){
        // prints the customers id and proper format
        cout << "Customer "<<customer_id<<" watched ";

        // calls a function to list out the movies
        movie_ids.display();
    }

    // adds a movie to the customer's list of movies
    void append(int in){

        // calls the insert function for the movie's list
        movie_ids.insert(in);
    }
    ~customer(){ 
    }
};

// note this a linked list of POINTERS to customers...
// that way you only every make one copy of each customer
// and simply place a pointer to that customer in the linked list

class linked_list_customers : public linked_list<customer*>{
    vector<customer*> del;
    int count=0;
    public:
    void print_customer(int customer_id){
        
        // Setting a temporary node to head
        node* tmp = head;

        // looping through the list of customers
        while(tmp){

            // if the customer matches the input we print the customer using a display function
            if(tmp->data->customer_id==customer_id){
                tmp->data->display();
            }

            // advancing the pointer
            tmp=tmp->next;
        }
    }

    void print_all(){
        
        // Setting a temporary node to head
        node* tmp = head;

        // Loops through th elist and displays each element
        while(tmp){
            tmp->data->display();
            
            // advances the pointer
            tmp=tmp->next;
        }
    }


    void print_views(int movie_id){
        
        // setting a temporary node to head
        node* tmp = head;

        // keeps track of number of times the movie was watched
        int count = 0;

        // loops through the list
        while(tmp){

            // calls the search function and if it returns true increase the count
            if(tmp->data->movie_ids.search(movie_id)==true) count++;

            // advance the pointer
            tmp = tmp->next;
        }

        // print the correct format
        cout << "Movie "<<movie_id<< " was watched " << count << " time(s)" << endl;
    }

    // test function
    void insert_customer(int id){
        customer* tmp = new customer;
        insert(tmp);
        tmp->customer_id = id;
        del.push_back(tmp);
    }
    void load_customers(string filename){

        // gets the file into file_id
        ifstream file_id(filename);
        
        // string to store the each individual line
        string line;

        // int to store the temp value
        int value;

        // keeps track of when a new customer happens and when their information has been exhausted
        int i = 0;
        int j = 0;
        
        // sets a customer*
        customer* tmp;

        // loops through each line
        while (getline(file_id,line)){

            // stores the line in value as an int
            value = stoi(line);

            // checks if its the customer id
            if(i == 0){

                // keeps track of which customer it is
                count++;

                // creates a new customer
                tmp = new customer;

                // adds the customer to the list
                insert(tmp);

                // setting the customer number and id
                tmp->customer_id = value;
                tmp->customer_num = count;

                // incrimenting the customer's line
                i++;
            }

            // checks if its the customers number of movies   
            else if(i == 1){

                // setting the number of movies into j so we can keep track
                j = value;

                // increments customer's line
                i++;
            }

            // adds the movies into the customer's list until it's exhausted then resets i indivating a new customer
            else if(i > 1){
                tmp->append(value);
                j--;
                if(j == 0) {
                    i = 0;

                    // keeps track of the custoemr* ptrs being lost
                    del.push_back(tmp);
                }
            }          
        }
    }

    ~linked_list_customers(){
        // clearing list
        node* tmp=head;
            while( tmp ) {
            node* next = tmp->next;

            // calling destructor for customer to make sure we clear movie list
            tmp->data->~customer();
            delete tmp;
            tmp = next;
        }

        // deleting the customer* pointers 
        for (auto & element : del) {
            delete element;
        }
    }
};


int main(int argc, char** argv){

    string filename;
    filename = get_filename(argc,argv);

    linked_list_customers clients;
    clients.load_customers(filename);


    clients.print_all();
    clients.print_customer(1019);
    clients.print_views(557);

    return 0;
}