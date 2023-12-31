/*
    Test file for the "student" class stored in student.cpp and student.h

    @Author: I. Obeid
    @Contact: iyad.obeid@temple.edu
    @Date: August 30, 2023

    Usage:
        make lab_02
        ./lab_02

*/

#include<iostream>
#include<iomanip>
#include<vector>
#include "student.h"
using namespace std;

// main
int main(){

    // create a new student, add grades, and display results
    student alice;
    alice.set_name("Alice");
    alice.add_grade(95);
    alice.add_grade(88);
    alice.add_grade(92);

    cout << endl;
    alice.display();
    cout << "Alice's average = " << fixed << setprecision(2) << alice.get_average() << endl;
    cout << "Alice's max score = " << alice.get_max() << endl;
    cout << endl;

    return 0;

}
