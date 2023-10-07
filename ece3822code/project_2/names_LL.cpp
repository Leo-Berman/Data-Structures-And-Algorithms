#include<iostream>
#include "linked_list.h"
using namespace std;

// class that stores a city, state
class name{
    public:
    string city;
    string state;

    // constructor
    name(string c="nowhere", string s="nostate"){
        city = c;
        state = s;
    }

    // display city, state
    void display(){
        cout << city << ", " << state << endl;
    }

};

// make a class that is a linked list of <name>. Since we're including
// $SHARE/include/linked_list.h, we don't need to re-write the list, 
// just update the new, extra add-ons we want for this use case
class linked_list_of_names : public linked_list<name>{

    public:

    // find by city
    void find_by_city(string target_city){
        node* curr_ptr = head;
        while (curr_ptr != nullptr){
            if (curr_ptr->data.city == target_city)
                curr_ptr->data.display();                
            curr_ptr = curr_ptr->next;
        }

    }

    // find by state
    void find_by_state(string target_state){
        node* curr_ptr = head;
        while (curr_ptr != nullptr){
            if (curr_ptr->data.state == target_state)
                curr_ptr->data.display();                
            curr_ptr = curr_ptr->next;
        }
    }

};


int main(){

    // create the linked list
    linked_list_of_names my_list;

    // create places and insert them in the list
    my_list.insert(name("lincoln","nebraska"));
    my_list.insert(name("topeka","kansas"));
    my_list.insert(name("philadelphia","pennsylvania"));
    my_list.insert(name("pittsburgh","pennsylvania"));

    // example of search-by-state
    cout << "\nSearch by state (Pennsylvania)" << endl;
    my_list.find_by_state("pennsylvania");

    // example of search-by-city
    cout << "\nSearch by city (Topeka)" << endl;
    my_list.find_by_city("topeka");

    cout << "\n" << endl;

    return 0;
}