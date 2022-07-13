/*
 * testDriver.cpp
 * 
 * Description: Takes user input and a given datafile to either display the
 *              contents of the file or return a requested word to be translated.
 *
 * Author: Amanda Ngo
 * Last Modification Date: March 10, 2022
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
#include "Dictionary.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"

using namespace std;

void display(const WordPair& anElement) {
  cout << anElement << endl;
} // end of display

int main(int argc, char *argv[]){

  Dictionary<WordPair>* dictionary = new Dictionary<WordPair>();
    
  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "myDataFile.txt";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;
 
  // reading textfile "myDataFile.txt"
    ifstream myfile (filename);
    if (myfile.is_open()) {
        while ( getline (myfile,aLine) ){
            pos = aLine.find(delimiter);
            englishW = aLine.substr(0, pos);
            aLine.erase(0, pos + delimiter.length());
            translationW = aLine;
            WordPair aWordPair(englishW, translationW);
            // insert aWordPair into "testing" using a try/catch block
            try{
            dictionary->put(aWordPair);
            }
            catch(ElementAlreadyExistsException &anException){
                cout << "Element " << aWordPair << " already exists in BST.\n";
            } 
        }
        myfile.close();
    }
    if ( ( argc > 1 ) && ( strcmp(argv[1], "display") == 0) ) {
        // ... then display the content of the BST.
        dictionary->displayContent(display);
    }
    else if (argc == 1) {
       // while user has not entered CTRL+D
       while ( getline(cin, aWord) ) {   
          WordPair searching(aWord);
          try{
              cout << dictionary->get(searching);
          }
          catch(ElementDoesNotExistException &anException){
              cout << "Not found!\n";
          }
       }
    }
    delete dictionary;
}
 
