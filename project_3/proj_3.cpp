/* PROJECT 3 - proj_3.cpp

    @author
    @contact
    @date

    Implements a system that models reading data asynchronously from the cloud,
    storing it temporarily in a buffer, and then placing it into a hash table.

    Compile:
        make all
    Compile for debug:
        make debug
    Run:
        ./proj_3 [OPT]
        where [OPT] is 1, 2, or 3 depending on which test case you are running.

*/
#include<iostream>
#include<thread>
#include<fstream>
#include<vector>
#include<chrono>
#include<mutex>
#include<cmath>

using namespace std;
using namespace std::chrono;

// Function to tokenize integers ended up being unused
vector<int> tokenizeints(int num){
    
    // return vector
    vector<int> ret;

    // find number of digits
    int digits = int(log10(num) + 1);

    // declaration of numbers to divide by and get remainder of 
    int divisor = 1;
    int remainder = 10;
    for(int i = 0; i < digits; i++){

        // adding the digit
        ret.push_back(num/divisor % remainder);
        
        // incrementing to the next digit
        divisor = divisor*remainder;
    }
    return ret;
}

// YOUR CODE HERE
struct student{
    
    private:

        // Data to store first and last name, gpa, student id, and major
        string first;
        string last;
        float gpa;
        int id;
        string major;
    
    public:

        // default constructor with args
        student(string firstin,string lastin,float gpain,int idin,string majorin){
            first = firstin;
            last = lastin;
            gpa = gpain;
            major = majorin;
            id = idin;
        }

        // gets the student's id
        int get_id(){
            return id;
        }

        // returns the student's full name
        string fullname(){
            return first+last;
        }

        // Prints student data
        void printstu(){
            cout << first +" " + last << " ID: " << id << " GPA: " << gpa << " Major: " << major << endl;
        }
};

// YOUR CODE HERE
class hashTable{

    private:

        // Vectors of student pointers
        student** students;

        // length of buffer
        int bufflen;
    public: 

        ~hashTable(){
            for(int i = 0; i< bufflen; i++){
                if(students[i]!=NULL) delete students[i];
            }
            delete [] students;
        }
        // Default Construct To Buffer of Size 10
        hashTable(){
            bufflen = 1000000;
            students = new student*[bufflen];          
        }

        // getting the bufflen
        int get_len(){
            return bufflen;
        }

        // Hashfunc to calculate index
        long long hashfunc(int stdid){
            long index =stdid/10000;
            index = pow(index,1.2); // found this by solving 99999^x = 1000000 because I found that the first 5 digits of the number had a somewhat normal distribution
            index = index % bufflen;
            cout << index << endl;
            return index;
        }

        // Insert a new student
        void insert(student* stu){
            long long index = hashfunc(stu->get_id());
            while((students[index]!=NULL) & (index < bufflen)){
                index ++;
                if((index == bufflen-1)&students[index]!=NULL) index = 0;
            }
            if(students[index]!=NULL){
                cout << "Full list" << endl;
                return;
            }
            else students[index]=stu;
        }

        // Search For A Student Using Their ID
        student* searchstu(int idin){

            // Use the hashfunc to get their index
            long long index = hashfunc(idin);

            // Check to see if the list has gone through a full cycle
            bool thru = false;

            // Checks to see if there is a student at that address
            if(students[index] == NULL){
                cout << "Student ID: " << idin <<" Not Found" << endl;
                return NULL;
            }

            // Loops through until it finds the student that it is looking for
            while((students[index]->get_id()!=idin) & (index < bufflen-1)){
                index ++;

                // Make sure next student exists
                if(students[index+1]==NULL){
                    cout << "Student ID: " << idin <<" Not Found" << endl;
                    return NULL;
                }
                if((index == bufflen-1) & (thru = false)) {
                    index = 0;
                    thru = true;
                }
            }

            if(students[index]->get_id()!=idin){
                cout << "Student ID: " << idin <<" Not Found" << endl;
                return NULL;
            }
            return students[index];
        }

        // Prints the buffer
        void printhash(){
            for(int i = 0; i < bufflen; i++){
                if (students[i]!=NULL) students[i]->printstu();
            }
        }
};

// YOUR CODE HERE
class queue{
    private:

        // list of students in queue
        vector<student*> students;

    public:
        
        // Prints the queue
        void printqueue(){
            for(int i = 0; i<students.size(); i++){
                cout << students[i] -> fullname() << " ID: " << students[i] -> get_id() << endl;
            }
        }

        // Add a student to the vector and add a corresponing wait time
        void add_student(student* std){
            students.push_back(std);
        }

        // checks the if there is a student waiting to be added and if there is it returns the wait time
        // otherwise it returns nothing
        bool pop_student(hashTable &stus){
            if(students.size() == 0) return false;
            else{
                stus.insert(students[0]);
                students.erase(students.begin());
                return true;
            }
        }
        // Checks if queue is empty
        bool is_empty(){
            if (students.size()==0) return true;
            else return false;
        }
};

// You will need these global variables
queue waiting_list;
hashTable student_db;
mutex queue_mutex;

// this controls the input timing. do not edit
bool stop_thread = false;
steady_clock::time_point t1 = steady_clock::now();
float t_elapsed(){
    return duration_cast<seconds>(steady_clock::now() - t1).count();
}


void process_input_data(){
    student* p_student;

    while (!stop_thread){
        queue_mutex.lock();

        // YOUR CODE HERE
        // Checking the queue
        // If there's data, remove it from the queue and
        // add it to the hash table


        if (!waiting_list.is_empty()){   // wait for the waiting_list queue
            waiting_list.pop_student(student_db);                               // to empty out before stopping the 
        }
        queue_mutex.unlock();
    }
}

void load_data(string filename){
    string shared_path = "/data/courses/ece_3822/current/project_3/";
    string filename_complete = shared_path + filename;

    // create local variables to stash the data for each person as it's
    // read from the file
    float arrival_time,gpa;
    string first,last,major;
    int id;

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    // start the thread that will wait for input data to arrive
    thread thr(process_input_data);

    clock_t t_start = clock();


    while (f_id >> arrival_time){
        // read data for the next person in the file
        f_id >> first;
        f_id >> last;
        f_id >> gpa;
        f_id >> id;
        f_id >> major;

        
        // wait until their data packet has 'arrived'
        while ( t_elapsed() < arrival_time){
            ;
        }
        
        

        // YOUR CODE HERE
        // [1] create a new student
        student* tmp = new student(first,last,gpa,id,major);


        queue_mutex.lock();

        // YOUR CODE HERE
        // [2] add the new student to the wait queue
        waiting_list.add_student(tmp);
        queue_mutex.unlock();

    }

    f_id.close();                       // close the data file
    
                                       // process_input_data thread

    stop_thread = true;                 // send a signal to the thread to stop running
    thr.join();                         // wait for the thread to finish up
}

int main(int argc, char** argv){
    string filename;

    if (argc !=2 ){
        cout << "ERROR: include a command line arguement of 0, 1, or 2" << endl;
        return -1;
    }

    switch (stoi(argv[1])){
        case 0: filename = "student_data_short.txt"; break;
        case 1: filename = "student_data_medium.txt"; break;
        case 2: filename = "student_data.txt"; break;
    }

    load_data(filename);
    
    // now that the data has been stored in the hash table, lets test hashtable lookup
    // if the student is found, print all their info
    // if not, print <student name> "not found"

    // YOUR CODE HERE FOR TESTING THE SEARCH/LOOKUP capability

    // search for the following student IDs

    student* tmp = student_db.searchstu(427980112);
    if(tmp != NULL) tmp -> printstu();
    tmp = student_db.searchstu(258399712);
    if(tmp != NULL) tmp -> printstu();
    tmp = student_db.searchstu(948140115);
    if(tmp != NULL) tmp -> printstu();
    
    // Testing for student not in buff
    tmp = student_db.searchstu(123123123);
    if(tmp != NULL) tmp -> printstu();


    return 0;
}