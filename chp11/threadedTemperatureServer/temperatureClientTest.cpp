/* A program for a threaded Temperature Server
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

#include <iostream>
#include "network/SocketClient.h"
using namespace std;
using namespace exploringBB;

int main(int argc, char *argv[]){
   if(argc!=2){
      cout << "Incorrect usage: " << endl;
      cout << "   client server_name" << endl;
      return 2;
   }
   cout << "Starting EBB Temperature Client Test" << endl;
   SocketClient sc(argv[1], 5555);
   sc.connectToServer();
   string message("getTemperature");
   cout << "Sending [" << message << "]" << endl;
   sc.send(message);
   string rec = sc.receive(1024);
   cout << "Received [" << rec << "]" << endl;
   cout << "End of EBB Temperature Client Test" << endl;
}
