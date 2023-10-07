#include<iostream>
#include<fstream>
#include "linked_list.h"
using namespace std;

#define DEFAULT_FILENAME "/data/courses/ece_3822/current/lab_04/data.txt"

/*
returns the filename where data is stored
user can override default filename with commandline arguement
*/
string get_filename(int argc, char** argv){
    string filename = DEFAULT_FILENAME;
    if (argc>1)
        filename = (string)argv[1];     
    return filename;
}


/*Main*/
int main(int argc, char** argv){

    // Dont touch any of this

    // get the filename where the data is stored
    string filename = get_filename(argc,argv);

    // init variables
    linked_list list_a;
    string      line; 
    ifstream    file_id(filename);

    // read integers from file into the linked list
    while (getline(file_id,line)){
        list_a.insert(stoi(line));
    }

    // output various values from the linked list
    // Your job is to edit linked_list.h to make these
    // commands return the correct values
    cout << "\nThe linked list size is " << list_a.size() << endl;
    cout << "The sum of the values is " << list_a.sum() << endl;
    cout << "The list " << (list_a.is_empty()?"is":"is not") << " empty" << endl;

    cout << "\nPopping off the first five values of the linked list gives:" << endl;
    for (int i = 0; i<5 ; i++)
        cout << "\t" << list_a.pop() << endl;
    
    cout << "\nThe sum of the remaining values is " << list_a.sum() << endl;

    cout << "\nClearing the list ... " << endl;
    list_a.clear_list();

    cout << "The list size is now " << list_a.size() << endl;
    cout << "The list sum is now "  << list_a.sum()  << endl;
    cout << "The list " << (list_a.is_empty()?"is":"is not") << " empty" << endl;
    
    cout << "\n" << endl;
    

    list_a.sum();
    return 0;
}
