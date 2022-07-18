/*
 * walkIn.cpp
 * 
 * Class Description: Walk-in clinic resgistratration interface
 *
 * Made using a List ADT
 * 
 * Author: Amanda Ngo
 * Date: February 4, 2022 (Last Modified)
 * 
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Patient.h"
#include "List.h"

using namespace std;

int main(){
    cout << "Welcome to the Patient Database! Choose an option below:\n";
    bool menu = true;
    List database;
    while(menu){
        string user;
        cout << "\nMAIN MENU\n"; 
        cout << "\n";
        cout << "To ENTER A NEW PATIENT, press E to continue.\n";
        cout << "To REMOVE PATIENT, press R to continue.\n";
        cout << "To SEARCH FOR A PATIENT, press S to continue.\n";
        cout << "To MODIFY A PATIENT'S RECORDS, press M to continue.\n";
        cout << "To PRINT ALL EXISTING PATIENTS, press P to continue\n";
        cout << "To LEAVE THE DATABASE, press L to exit\n";
        cout << "\n";
        getline(cin, user);

        if(user == "L"){
            cout << "Exiting database...\n";
            menu = false;
        }
        
        else if(user == "E"){
            string toEnter;
            cout << "Please input the carecard number you would like to enter: ";
            getline(cin,toEnter);
            Patient enter(toEnter);
            bool entered = database.insert(enter);
            if(entered){
                cout << "Successfully entered.\n";
            }
            else{
                cout << "Unable to add patient.\n";
            }
        }
        else if(user == "R"){
            string toRemove;
            cout << "Please input the carecard number you would like to remove: ";
            getline(cin,toRemove);
            Patient remove(toRemove);
            bool removed = database.remove(remove);
            if(removed){
                cout << "Successfully removed\n";
            }
            else{
                cout << "Unable to remove patient.\n";
            }
        }
        else if(user == "S"){
            string toSearch;
            cout << "Input the patient carecard you would like to search for: ";
            getline(cin,toSearch);
            Patient buffer(toSearch);
            Patient* search = database.search(buffer);
            if(search == NULL){
                cout << "Unable to locate the patient.\n";
            }
            else{
                cout << "Patient exists in the database.\n";
            }
        }
        else if(user == "M"){
            string toBeModified;
            cout << "Input the patient carecard you would like to modify: ";
            getline(cin,toBeModified);
            Patient search(toBeModified);
            Patient* modify = database.search(search);
            if(modify == NULL){
                cout << "Could not find the patient.\n";
            }
            else{
                string modify_aspect;
                cout << "What would you like to modify? (NAME/ADDRESS/PHONE/EMAIL)\n";
                getline(cin,modify_aspect);
                if(modify_aspect == "NAME"){
                    string name;
                    cout << "Input the changed name: ";
                    getline(cin,name);
                    modify -> setName(name);
                    cout << "\nName changed.\n";
                }
                else if(modify_aspect == "ADDRESS"){
                    string address;
                    cout << "Input the changed address: ";
                    getline(cin,address);
                    modify -> setAddress(address);
                    cout << "\nAddress changed.\n";
                }
                else if(modify_aspect == "PHONE"){
                    string phone;
                    cout << "Input the changed phone number: ";
                    getline(cin,phone);
                    modify -> setPhone(phone);
                    cout << "\nPhone changed.\n";
                }
                else if(modify_aspect == "EMAIL"){
                    string email;
                    cout << "Input the changed email: ";
                    getline(cin,email);
                    modify -> setEmail(email);
                    cout << "\nEmail changed.\n";
                }
                else{
                    cout << "Invalid parameter\n";
                }
            }         
        }
        else if(user == "P"){
            cout << "Printing list...\n";
            database.printList();
        }
        else{
            cout << "Invalid input, please try again.\n";
        }
    }
}