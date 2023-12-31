/*
Lab 01

@Leo Berman
@leo.berman@temple.edu
@8/30/2023

Example:
    This file can be compiled by typing
g++ -o lab_01.exe lab_01.cpp
    This file can be run by typing
./lab_01.exe [filename].txt
*/


#include<iostream>
#include<fstream>
#include<math.h>
#include<iomanip>
#include<vector>
using namespace std;


int main(int argc, char** argv){
  
  // step 0 - error handling/getting file name from command line
  string filename;  
  string err = " please use format ./lab_01.exe [filename].txt";
  if (argc==2) {
    filename = argv[1];
  }
  else if (argc==1) {
    cout<<"Data file not given"<<err<<endl;
    exit(0);
  }
  else if (argc>2) {
    cout<<"Too many arguments"<<err<<endl;
    exit(0);
  }
  
  // step 1 init variables
  double s = 0;
  double n = 0;
  double avg = 0;
  double var = 0;
  string line;
  double val;
  double max1;
  double max2;
  
  // step 2 open file
  ifstream file_id(filename);
  
  // step 3 read values from file
  while (getline(file_id,line)){
    val = stof(line);
    
    // sets initial values for two maxes
    if(s==0){
      max1=val;
    }
    if(s==1){
      
      if(val<max1) {
	max2=val;
      }
      if(val>=max1){
	max2=max1;
	max1=val;
      }
    }
    
    // keeps track of two maxes throughout counting
    if(s!=0 && s!=1){
      if(val>=max2 && val>=max1){
	max2=max1;
	max1=val;
      }
      else if(val>=max2 && val<=max1){
	max2=val;
      }
    }

  // counts number of integers in list
  s=s+1;
  
  // sums the integers of the list
  n=n+val;  
  }
  
  // divides the sum of the integers by the number of integers to get mean
  avg=n/s;
  
  // takes the sum of square roots of the two maxes
  double sumofsqrt=sqrt(max1*max2);
  

  // step 4 print value
  cout << fixed;
  cout << setprecision(2);
  cout << "The average value is " << avg << endl;

  // prints the sum of squares
  cout << "The sum of squares is " << sumofsqrt << endl;

  // closes the file
  file_id.close();

  // exits gracefully
  return 0;
}
