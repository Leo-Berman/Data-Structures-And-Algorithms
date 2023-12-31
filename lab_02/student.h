#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;


class student{
  
private:
  
  // ADD VARIABLES AS NEEDED
  string name;
  int numofgrades;
  vector<int> grades;

public:
  
  // DON'T CHANGE THESE FUNCTION PROTOTYPES
  student();
  void set_name(string);
  void add_grade(int);
  int get_max();
  double get_average();
  void display();
  ~student();
};

#endif 
  
