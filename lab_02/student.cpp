// including headerfile
#include "student.h"

// default constructor
student::student(){
  name="John/Jane Doe";
  numofgrades=-1;
}

// set name function
void student::set_name(string inputname){
  name=inputname;
}
l
// adding grades into a matrix
void student::add_grade(int inputgrade){
  numofgrades++;
  grades.push_back(inputgrade);
}

// find the max grade of student
int student::get_max(){
  int max=grades[0];
  for(int i = 1;i<=numofgrades;i++) {
    if(grades[i]>max) max=grades[i];
  }
  return(max);
}

// finding the average of the students grades
double student::get_average(){
  double average;
  double sum;
  for(int i=0;i<=numofgrades;i++) {
    sum+=grades[i];
  }
  average=sum/(numofgrades+1);
  return(average);
}

// displaying students stats up to assignment standard
void student::display() {
  cout << name << ": ";
  cout << grades[0];
  for (int i = 1; i <= numofgrades; i++){
    cout << ", " << grades[i];
  }
  cout<<"\n";
}

//default destructor
student::~student(){

}
