#ifndef _linked_list_h_
#define _linked_list_h_
using namespace std;
#include<iostream>
namespace ll_node{
  // node for the linked list data
  // do not edit
  class node{
    
  private:
    int data;
    node* next;
    
  public:
    
    // constructor
    node(int d){
      data = d;
      next = nullptr;
    };
    
    // getter, data
    int get_data(){
      return data;
    }
    
    // setter, 'next' pointer
    void set_next(node *n){
      next = n;
    }
    
    // getter, 'next' pointer
    node* get_next(){
      return next;
    }
  };
}

class linked_list{
  
// private class variables
private:
  
  ll_node::node* head;
  int n_elements;
  
// public class methods
public:
  
  linked_list(){
    head = nullptr;
    n_elements = 0;
  }
  
  void insert(int d){
    ll_node::node *newNode = new ll_node::node(d);
    newNode->set_next(head);
    head = newNode;
    n_elements++;
  }
  
  int pop(){
    int ret_val = 0;
    if (n_elements > 0){
      ret_val = head->get_data();
      ll_node::node *tmpNode = head;
      head = head->get_next();
      delete tmpNode;
      n_elements--;
    }
    return ret_val;
  }
  
  void clear_list(){
    // deleting elements until elements = 0
    while (n_elements>0){
      
      // declaring a temporary node at the start of the list
      ll_node::node *tmpNode = head;
      
      // incrementing the head to the next node
      head = head->get_next();
      
      // deleting the head
      delete tmpNode;
      
      // decrementing the counter
      n_elements--;
    }
  }
  
  bool is_empty(){
    
    // checking to see if number of elements is 0
    if(n_elements==0) return true;
    else return false;
  }
  int size(){
  
    // returning the number of nodes
    return n_elements;
  }
  int sum(){
    
    // declaring a temporary node
    ll_node::node *tmpNode = head;
    
    // declaring a summing variable
    int sum = 0;
    
    // keeping track of node's data that has been added
    while(tmpNode){
      
      // adding the nodes data to the sum
      sum=sum+tmpNode->get_data();
      
      // incrementing to the next element/node
      tmpNode = tmpNode -> get_next();
      
    }
    return sum;
  }
};

#endif
