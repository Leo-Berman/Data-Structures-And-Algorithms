class node{
    public:
    node *right;

    node(){
        data = 0;
        right = nullptr;
    }
    void set(double d){
        data = d;
    }
    double get(){
        return data;
    }
    private:
    double data;
};

class row{
    public:

    row(){

        node *n0 = new node;
        node *n1 = new node;
        node *n2 = new node;
        node *n3 = new node;

        head = n0;
        n0->right = n1;
        n1->right = n2;
        n2->right = n3;

        up = nullptr;
    }

    void set(int i , double d){
        node* tmp = head;
        for (int ii = 0 ; ii < i ; ii++)
            tmp = tmp->right;
        tmp->set(d);
    }

    double get(int i){
        node* tmp = head;
        for (int ii = 0 ; ii < i ; ii++)
            tmp = tmp->right;
        return tmp->get();
    }

    void set_next_row(row *r){
        up = r;
    }

    row* get_next_row(){
        return up;
    }

    private:
    node *head;
    row *up;

};

class matrix{

    public:

    matrix(){
        row *r0 = new row;
        row *r1 = new row;
        row *r2 = new row;

        head = r0;
        r0->set_next_row(r1);
        r1->set_next_row(r2);
   
    }

    void set(int i , int j , double d){
        // find ith row
        row *curRow = head;
        for (int ii = 0 ; ii<i ; ii++)
            curRow = curRow->get_next_row();

        // insert into the ith row
        curRow->set(j,d);
    }

    double get (int i , int j){
        row *curRow = head;
        for (int ii = 0 ; ii<i ; ii++)
            curRow = curRow->get_next_row();
        return curRow->get(j);
    }

    private:
    row *head;

};

#include<iostream>
using namespace std;

int main(){

    matrix x;
    x.set(2,3,3.14);
    x.set(1,0,1.123);

    cout << x.get(2,3) << endl; // should return 3.14
    cout << x.get(1,0) << endl; // should return 1.123
    cout << x.get(1,3) << endl; // should return 0 (initalized value)

}