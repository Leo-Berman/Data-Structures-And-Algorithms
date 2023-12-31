#include<iostream>
#include<thread>
#include<fstream>
#include<vector>
#include<chrono>
#include<mutex>
#include<cmath>

using namespace std;
template <typename T> 
class data_structure{
    private:
    T** hashtable;
    int bufflen;
    public:
    // default constructor
    data_structure(int inbuff){
        bufflen = inbuff;
        hashtable = new T*[bufflen];
    }

    int hashfunc(string in){
        int sum = 0;
        for(int i = 0; i < in.size(); i++){
            sum+=in[i];
        }
        return int(sum % bufflen);
    }
    void insert(string in, T* datain){
        int index = hashfunc(in);
        hashtable[index] = datain;
    }
    T search (string in){
        int index = hashfunc(in);
        return *hashtable[index];
    }
};

int main(){
    data_structure <string>* name = new data_structure <string>(10);
    data_structure <string>* addy = new data_structure <string>(10);
    data_structure <data_structure<string>*>* mystruct = new data_structure <data_structure<string>*>(100);
    string firstname = "Alice";
    string lastname = "Smith";
    string street = "123 Main St.";
    string town = "anytown";
    string state = "PA";
    name->insert("first",&firstname);
    name->insert("last",&lastname);
    addy->insert("street",&street);
    addy->insert("city",&town);
    addy->insert("state",&state);
    mystruct->insert("name",&name);
    mystruct->insert("address",&addy);
    cout << mystruct->search("address")->search("state") << endl;
    return 0;
}