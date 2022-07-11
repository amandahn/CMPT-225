/* 
 * BankSimApp.cpp
 *
 * Description: Bank Simulation Application which utilizes
 *              a Queue, Binary Heap, and Priority Queue
 *
 * 
 * Author: Amanda Ngo
 *
 * Last Modification: March 2022
 *
 */ 

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"
#include "Event.h"
#include "Queue.h"

using namespace std;

void ArrivalProcess(PriorityQueue<Event>& eventQueue, Queue<Event>& bankLine, Event Customer, bool& tellerAvailable, unsigned int& currentTime){
    eventQueue.dequeue();
    static const char DEPARTURE = 'D';    
    if(bankLine.isEmpty() && tellerAvailable){
        unsigned int departuretime = currentTime + Customer.getLength();
        Event newDeparture(DEPARTURE,departuretime);
        eventQueue.enqueue(newDeparture);
        tellerAvailable = false;
    }
    else{
        bankLine.enqueue(Customer);
    }
}

void DepartureProcess(PriorityQueue<Event>& eventQueue, Queue<Event>& bankLine, Event Customer, bool& tellerAvailable, unsigned int& currentTime, unsigned int& totalWaiting){
    static const char DEPARTURE = 'D'; 
    eventQueue.dequeue();
    if(!bankLine.isEmpty()){
        Customer = bankLine.peek();
        totalWaiting = totalWaiting + currentTime - Customer.getTime();
        bankLine.dequeue();
        unsigned int departuretime = currentTime + Customer.getLength();
        Event newDeparture(DEPARTURE,departuretime);
        eventQueue.enqueue(newDeparture);
    }
    else{
        tellerAvailable = true;
    }
}
int main(int argc, char *argv[]){
  PriorityQueue<Event> eventQueue;
  Queue<Event> bankLine;

  bool tellerAvailable = true;
  string aLine;
  string time_str;
  unsigned int time;
  string len_str;
  unsigned int len;
  // Input desired filename below
  string filename = "simulationShuffled1.in";
  string delimiter = " ";
  size_t pos = 0;
  static const char ARRIVAL = 'A';
  Event newArrival;
  unsigned int currentTime = 0;
  unsigned int totalCustomers = 0;
  unsigned int totalWaiting = 0;
  
  ifstream myfile (filename);
  if (myfile.is_open()) {
    while ( getline (myfile,aLine) ){
        pos = aLine.find(delimiter);
        // Getting Time
        time_str = aLine.substr(0, pos);
        time = stoi(time_str);
        aLine.erase(0, pos + delimiter.length());
        // Getting Transalction Length
        len_str = aLine;
        len = stoi(len_str);
        
        newArrival = Event(ARRIVAL,time,len);
        eventQueue.enqueue(newArrival);
        totalCustomers++;
    }
  }
  
  cout << "Simulation Start: " << endl;
  while(!eventQueue.isEmpty()){
      Event newEvent = eventQueue.peek();
      currentTime = newEvent.getTime();
      if(newEvent.getType() == ARRIVAL){
          ArrivalProcess(eventQueue,bankLine,newEvent,tellerAvailable,currentTime);
          cout << "Processing an arrival event at time:     " << newEvent.getTime() << endl;
      }
      else{
          DepartureProcess(eventQueue,bankLine,newEvent,tellerAvailable,currentTime,totalWaiting);
          cout << "Processing an departure event at time:     " << newEvent.getTime() << endl;
      }
  }
  myfile.close(); 
  cout << "Simulation End: " << endl;
  cout << "Final Statistics\n" << endl;
  cout << "     Total number of people processed: " << totalCustomers << endl;
  cout << "     Average amount of time spent waiting: " << float(float(totalWaiting)/float(totalCustomers)) << endl;


}