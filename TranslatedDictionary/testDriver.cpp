/*
 * testDriver.cpp
 * 
 * Description: Drives the testing of the BST, the BSTNode, 
 *              the WordPair and all the exceptions classes. 
 *
 * Author: AL
 * Last Modification Date: Feb. 2022
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"


void display(const WordPair& anElement) {
  cout << anElement << endl;
} // end of display

void display_int(const int& anElement){
    cout << anElement << endl;
}

// As you discover what main() does, record your discoveries by commenting the code.
// If you do not like this main(), feel free to write your own.
// Remember, this is a test driver. Feel free to modify it as you wish!
int main(int argc, char *argv[]) {

  BST<WordPair>* testing = new BST<WordPair>();
    
  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "myDataFile.txt";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;
 
  // reading textfile "dataFile.txt"
  ifstream myfile (filename);
  if (myfile.is_open()) {
  	cout << "Reading from a file:" << endl; 
    while ( getline (myfile,aLine) ){
        {
        pos = aLine.find(delimiter);
        englishW = aLine.substr(0, pos);
        aLine.erase(0, pos + delimiter.length());
        translationW = aLine;
        WordPair aWordPair(englishW, translationW);
        // insert aWordPair into "testing" using a try/catch block
        try{
          testing->insert(aWordPair);
        }
        catch(ElementAlreadyExistsException &anException){
          cout << "Element " << aWordPair << " already exists in BST.\n";
        } 
    }
  }
  myfile.close();
    // If user entered "Display" at the command line ...
    if ( ( argc > 1 ) && ( strcmp(argv[1], "Display") == 0) ) {
        // ... then display the content of the BST.
        testing->traverseInOrder(display);
    }
    else if (argc == 1) {
       // while user has not entered CTRL+D
       while ( getline(cin, aWord) ) {   

          WordPair aWordPair(aWord);
 
       }
    }
  }
  else {
    cout << "Unable to open file"; 
  }

  cout << "TESTING data" << endl;
  WordPair retrieve = WordPair("apple");
  cout << "Retrieve test: " << testing->retrieve(retrieve) << endl;
  cout << "Element count: " << testing->getElementCount() << endl;
  testing->traverseInOrder(display);
  
  delete testing;
  return 0;

}
/*int main(){
    BST<int>* test = new BST<int>();
    for(int i=0; i<10;i++){
      test->insert(i);
    }
    cout << test->getElementCount() << endl;
    int retrieve_test;
    retrieve_test = test->retrieve(4);
    cout << "TESTING RETRIEVE: " << retrieve_test << endl;
    cout << "TESTING TRAVERSE: " << endl;
    test->traverseInOrder(display_int);
    cout << "TESTING COPY: " << endl;
    BST<int>* copy(test);
    cout << "COPY TRAVERSE: " << endl;
    copy->traverseInOrder(display_int);
    delete test;
}*/