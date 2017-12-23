
#include "NAT.h"

NAT::NAT()
{
}

NAT::~NAT()
{
}

string NAT::split_flow_entry(string flow, int port_not_mentioned)
{
	int counter = 0;
	string str1;
	string proper_string;
	string wrong_string = "Invalid IP format";
	typedef vector< string > split_vector_type;
	split_vector_type flow_entry;
	boost::split(flow_entry, flow, boost::is_any_of(":"));
	for (vector<string>::const_iterator i = flow_entry.begin(); i != flow_entry.end(); ++i)
	{
		counter++;
		//Check entries like 10.0.4.1:* 
		if (counter == 1 && port_not_mentioned)
		{
			proper_string = *i;
			proper_string = proper_string + ":*";
			return proper_string;
		}
		//Check entries like *:8086 
		if (counter == 2)
		{
			proper_string = *i;
			proper_string = "*:" + proper_string;
			return proper_string;
		}
	}
	return wrong_string;
}

void NAT::reading_entry()
{

	string line;
	string ip_port_from;
	string ip_port_to;
	string sep_port;
	int count=0;
	// Read data from file 
	ifstream NAT_file("NAT.txt");
	while (getline(NAT_file, line))
	{
		//cout <<"\n"<<line<< "  :"<<count;
		
		//cout<<"count:"<<count<<endl;
		istringstream sep(line);
		getline(sep, ip_port_from, ',');
		getline(sep, ip_port_to,',');
		pair<string, string> my_nat(ip_port_from, ip_port_to);
		mymap.insert(my_nat);
		//count++;
	}
	
}

void NAT::search_flow_entry()
{
	string flow;
	ifstream flow_entry("FLOW.txt");
	string formatted_string;
	//Parsing the FLOW file line by line
	while (getline(flow_entry, flow))
	{
		unordered_map<string, string>::iterator flowentry = mymap.find(flow);
		//No flow entry has matched the key value of NAT ENTRY table 
		if (flowentry == mymap.end())
		{
			//The flow entry formated(10.1.1.1:80-> 10.1.1.1:*)
			formatted_string = split_flow_entry(flow, 0);
			unordered_map<string, string>::iterator flowentry2 = mymap.find(formatted_string);
			if (flowentry2 == mymap.end())
			{
				//The flow entry formated(10.1.1.1:80-> *:80)
				formatted_string = split_flow_entry(flow, 1);
				unordered_map<string, string>::iterator flowentry3 = mymap.find(formatted_string);
				if (flowentry3 == mymap.end())
				{
					cout << "No NAT match for -> " << flow<<endl;
				}
				else
				{
					cout << flow << " -> " << flowentry3->second<<endl;
				}
			}
			else
			{
				cout << flow << " -> " << flowentry2->second<<endl;
			}
		}
		//Flow entry has matched the key value of NAT ENTRY table without formating  
		else
		{
			cout << flowentry->first << " -> " << flowentry->second<<endl;
			//cout << flowentry->second<<endl ;
		}
		cout << endl;
	}
}
