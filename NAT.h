//#pragma once
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;


class NAT
{
public:
	NAT();
	~NAT();
	string split_flow_entry(string flow, int port_not_mentioned);
	void reading_entry();
	void search_flow_entry();

private:
	unordered_map<string, string> mymap;
};

