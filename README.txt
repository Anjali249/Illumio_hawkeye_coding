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

IV. Challenge I Faced
-------------------------
* Even though my code was giving the proper output, there were some undesired ip_port values getting printed between each valid output line, later I figured out that it was due to newlines between each entry in my NAT.txt and FLOW.txt files which I was taking for granted to be correct as I copy pasted directly from the email. It was fun debugging everything and realising this silly mistake at the end finally.




