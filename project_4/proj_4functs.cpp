#include<iostream>
#include<vector>
using namespace std;

// node class for hashtable
class song{
    
    // private variables
    private:
        string band;
        string songtitle;
        int searchnumber;

    // public info
    public:
    
        // default constructor
        song(){
            band = "null";
            songtitle = "null";
            searchnumber = 0;
        }

        // constructor with song and band input
        song(string insong,string inband){
            band = inband;
            songtitle = insong;
            searchnumber = 0;
        }
        void setsearchnumber(int insearch){
            searchnumber = insearch;
        }
        // recording how complex it is
        int retsearchnumber(){
            return searchnumber;
        }
        // return private variable band
        string getband(){
            return band;
        }

        // return private variable song
        string getsong(){
            return songtitle;
        }

        // display song
        void display(){
            cout << "Bandname = " << band << " " << "Songname = " << songtitle << endl;
        }
};

// hashtable
class Hash{
    
    // private variables
    private:
        // length of hash table
        int bufflen=7000;

        // create an array of  vectors of song pointers
        vector<song*> songs[7000];
    
    // public variables
    public:
        
        // default destructor
        ~Hash(){
            for(int i = 0; i < bufflen; i++){
                if(songs[i].size()!=0){
                    /*vector<song*>::iterator ptr;
                    for(ptr = songs[i].begin(); ptr<songs[i].end(); ptr++){
                        delete *ptr; // couldn't get this to work
                        //*ptr = nullptr;
                    }   */
                    for(int j = 0 ; j < songs[i].size() ;j++){
                        delete songs[i][j];
                    }
                }
            }
        }

        // calculating index of hash table
        int hashfunc(string insong, string inband){
            int sum=1;
                for(int i = 0; i < insong.size();i++){
                    sum+=insong[i];
                }
                for(int j = 0; j < inband.size();j++){
                    sum+=j*inband[j];
                }
                int index = sum%bufflen;
                return index;
        }

        // inserting into hashtable by song and band
        void hashinsert(string insong, string inband){
            int index = hashfunc(insong, inband);
            songs[index].push_back((new song(insong,inband)));
        }

        // searching hashstable by song and band
        song* hashsearch(string insong, string inband){
            int index = hashfunc(insong,inband);
            int count = 0;
            vector<song*> tmp = songs[index];
            for(auto item : tmp){
                count++;
                if((item->getband() == inband) & (item->getsong() == insong)){
                    item->setsearchnumber(count);
                    return item;
                }
            }
        return nullptr;
        }
};

// node class for tree
class root{

    // private variables for children and data
    private:
    root* left;
    root* right;
    vector<string> songnames;
    vector<string> bandnames;
    int hash;
    public:

    // constructor
    root(string insong, string inband, int inhash){
        songnames.push_back(insong);
        bandnames.push_back(inband);
        hash = inhash;
        left = nullptr;
        right = nullptr;
    }
    
    // getters
    root* getleft(){
        return left;
    }
    root* getright(){
        return right;
    }
    int gethash(){
        return hash;
    }

    // adding to a vector if collision happens
    void append(string insong, string inband){
        songnames.push_back(insong);
        bandnames.push_back(inband);
    }

    // setters
    void insertleft(root* in){
        left = in;
    }
    void insertright(root* in){
        right = in;
    }

    // search vector for match
    int searchvec(string insong, string inband){
        vector<int> indexes;
        for(int i = 0; i < songnames.size();i++){
            if((songnames[i] == insong) & (bandnames[i] == inband)){
                return i;
            }
        }
        return -1;
    }

    // test function to print all collisions in a vector
    void printvecs(){
        for(int i = 0; i < songnames.size(); i++){
            cout << "Bandname = " << bandnames[i] << " Songname = " << songnames[i] << endl;
        }
    }
};

// Tree class
class Tree{
   
   // private variables
    private:
    
    // head of tree
    root* head;
    int numofnodes;

    // public variables
    public:
    // Default Constructor
    Tree(){
        head = nullptr;
        numofnodes = 0;
    }
    
    // Recursive Destroy functoin
    void DestroyRecursive(root* in){
        if(in){
            DestroyRecursive(in->getleft());
            DestroyRecursive(in->getright());
            delete in;
        }
    }

    // Default Destructor
    ~Tree(){
        DestroyRecursive(head);
    }

    // return number of nodes
    int retnumofnodes(){
        return numofnodes;
    }

    // calculating hash of tree elemnt
    int treehash(string insong, string inband){
            int sum=1;
                for(int i = 0; i < insong.size();i++){
                    sum+=insong[i];
                }
                for(int j = 0; j < inband.size();j++){
                    sum+=j*inband[j];
                }
                int index = sum%7000;
                return index;
    }

    // insert root
    void treeinsert(string insong, string inband){
        bool inserted = false;
        
        // check to see if first node
        if (head == nullptr){
            root* tmp = new root(insong,inband,treehash(insong,inband));
            head = tmp;
            inserted = true;
            numofnodes++;
        }

        // if not 
        else{

            // get hash number of insert node
            int inhash = treehash(insong,inband);

            // set tmp head
            root* tmp2 = head;

            // iterate through tree
            while(!inserted){

                // if hashes match with node deal with collision by appending to root vector
                if(tmp2->gethash() == inhash){
                    tmp2->append(insong,inband);
                    inserted = true;
                }

                // else check if it is to the left
                else if(tmp2->gethash() > inhash){

                    // if left is empty make a new node
                    if(tmp2->getleft()==nullptr){
                        tmp2->insertleft(new root(insong,inband,inhash));
                        inserted = true;
                        numofnodes++;
                    }

                    // else if not empty increment the node left
                    else{
                        tmp2 = tmp2->getleft();
                    }
                }

                // else check if it is to the right
                else if(tmp2->gethash() < inhash){

                    // if right is empty make a new node
                    if(tmp2->getright()==nullptr){
                        tmp2->insertright(new root(insong,inband,inhash));
                        inserted = true;
                        numofnodes++;
                    }

                    // else if not empty increment the node right
                    else{
                        tmp2 = tmp2->getright();
                    }
                }
            }
        }

    }
    string treesearch(string insong, string inband){
        
        // default return vaiable if Band not found
        string ret = "Band not found";

        // to record number of traversals in tree and in vector
        int count = 1;

        // calculate the hash of the search
        int inhash = treehash(insong,inband);
        
        // start from the top of the tree
        root* tmp = head;

        // while node hasn't reached the end of the tree
        while(tmp){

            // check if hash number was found
            if(tmp->gethash()==inhash){
                // if so check to see if song and bandname are a pair in the node and keep track of traverses
                int vectra = tmp->searchvec(insong,inband);

                if(vectra != -1){
                    count+=vectra;
                    return "Bandname = " + inband + "; Songname = " + insong + "\nNumber of traverses = " + to_string(count);
                }
            }

            // else if node is less than currnode increment left
            else if(tmp->gethash() > inhash){
                tmp = tmp->getleft();
                count++;
            }

            // else if node is greater than currnode increment right
            else if(tmp->gethash() < inhash){
                tmp = tmp->getright();
                count++;
            }
        }

        return ret;
    }

};

