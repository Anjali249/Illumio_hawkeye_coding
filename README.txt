I. File List
-------------
Main.cpp     
NAT.cpp
NAT.h
NAT.txt
FLOW.txt

II. Installation and compilation
---------------------------------
* Install the package "sudo apt-get install libboost-dev" on Ubuntu.
* Compile Using
  g++ -std=c++11 -o Main Main.cpp NAT.cpp NAT.h

III. Design Decisions
----------------------
* Used unordered map to read NAT file instead of map since the time complexity of map operations is O(Log n) while for unordered_set, it is O(1) on average. 




