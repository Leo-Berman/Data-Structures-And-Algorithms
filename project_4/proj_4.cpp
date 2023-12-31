#include <iostream>
#include <fstream>
#include "proj_4functs.cpp"
using namespace std;

void sample_load_function(){
    
    string filename_complete = "/data/courses/ece_3822/current/project_4/songlist.txt";

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;

    while(getline(f_id,line)){

        // "line" is one complete line from the text file

        // find the comma, which separates band name from song
        i_split = line.find(',');

        //extract bandname and songname
        band_name = line.substr(0,i_split);         // band name is everything up till the comma
        line.erase(0,i_split+2);                    // erase band name plus comma, plus space
        song_title = line.substr(0, line.size()-1); // erase the carriage return at the end

        // check to make sure it worked
        cout << band_name << " <<- " << song_title << endl;
    	cout << song_title << " <<- " << band_name << endl;
    }
    f_id.close();

}

// loading file into hash table
void loadhash(Hash &rethash){
    // Hash rethash;
    string filename_complete = "/data/courses/ece_3822/current/project_4/songlist.txt";

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;

    while(getline(f_id,line)){

        // "line" is one complete line from the text file

        // find the comma, which separates band name from song
        i_split = line.find(',');

        //extract bandname and songname
        band_name = line.substr(0,i_split);         // band name is everything up till the comma
        line.erase(0,i_split+2);                    // erase band name plus comma, plus space
        song_title = line.substr(0, line.size()-1); // erase the carriage return at the end

        // check to make sure it worked
        //cout << band_name << " <<- " << song_title << endl;
    	//cout << song_title << " <<- " << band_name << endl;

        // insert element into hashtable
        rethash.hashinsert(band_name,song_title);
    }

    f_id.close();

    // return hashtable
    // return rethash;
}

// searching hash table for all elements
void searchhash(Hash &inhash){

    string filename_complete = "/data/courses/ece_3822/current/project_4/songlist.txt";

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;
    int count = 0;
    while(getline(f_id,line)){

        // "line" is one complete line from the text file
        // find the comma, which separates band name from song
        i_split = line.find(',');

        //extract bandname and songname
        band_name = line.substr(0,i_split);         // band name is everything up till the comma
        line.erase(0,i_split+2);                    // erase band name plus comma, plus space
        song_title = line.substr(0, line.size()-1); // erase the carriage return at the end

        // check to make sure it worked
        //cout << band_name << " <<- " << song_title << endl;
    	//cout << song_title << " <<- " << band_name << endl;
        
        // finding and displaying the node while keeping track of how many were found
        song* curnode = inhash.hashsearch(band_name,song_title);
        // to display found node //curnode->display();
        count++;
    }
    // printing the count
    cout << "HashCount Found = " << count << endl;
    f_id.close();

}

// loading the file into a tree
void loadtree(Tree &rettree){
    string filename_complete = "/data/courses/ece_3822/current/project_4/songlist.txt";

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;

    while(getline(f_id,line)){

        // "line" is one complete line from the text file

        // find the comma, which separates band name from song
        i_split = line.find(',');

        //extract bandname and songname
        band_name = line.substr(0,i_split);         // band name is everything up till the comma
        line.erase(0,i_split+2);                    // erase band name plus comma, plus space
        song_title = line.substr(0, line.size()-1); // erase the carriage return at the end

        // check to make sure it worked
        //cout << band_name << " <<- " << song_title << endl;
    	//cout << song_title << " <<- " << band_name << endl;
        
        // insert node into tree
        rettree.treeinsert(song_title,band_name);
    }

    f_id.close();
}

// searching the tree for all the elements
void searchtree(Tree &intree){

    string filename_complete = "/data/courses/ece_3822/current/project_4/songlist.txt";

    ifstream f_id;
    f_id.open(filename_complete,ios_base::in);

    string line;
    string band_name;
    string song_title;

    int i_split;
    int count = 0;
    while(getline(f_id,line)){

        // "line" is one complete line from the text file
        // find the comma, which separates band name from song
        i_split = line.find(',');

        //extract bandname and songname
        band_name = line.substr(0,i_split);         // band name is everything up till the comma
        line.erase(0,i_split+2);                    // erase band name plus comma, plus space
        song_title = line.substr(0, line.size()-1); // erase the carriage return at the end

        // check to make sure it worked
        //cout << band_name << " <<- " << song_title << endl;
    	//cout << song_title << " <<- " << band_name << endl;
        
        // search and display the element and keep track of how many elements successfully searched
        string searchvals = intree.treesearch(song_title,band_name);
        //cout << searchvals << endl;
        count++;
    }

    // print the cuont
    cout << "TreeCountFound = " << count << endl;
    f_id.close();

}




int main(){
    /* Testhash */
    Hash workhash; 
    loadhash(workhash);
    searchhash(workhash);
    song* tmp = workhash.hashsearch("Olivia Newton-John","All I Want for Christmas Is You");
    tmp->display();
    cout << "Number of traverses = " << tmp->retsearchnumber() << endl;
    /* Testtree*/
    Tree worktree;
    loadtree(worktree);
    searchtree(worktree);
    cout << worktree.treesearch("All I Want for Christmas Is You", "Olivia Newton-John") << endl;
    cout << "Number of tree Nodes = " << worktree.retnumofnodes() << endl;
    /*Hash testhash;
    string songname = "Rust";
    string artist = "Slothmilk";
    testhash.hashinsert(songname,artist);
    song* tmp = testhash.hashsearch(songname,artist);
    tmp->display();*/
    return 0;
}
