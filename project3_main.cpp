#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

#define primitiveLen 8
using namespace std;

int main(int argc, char** argv)
{	
	vector<string> pkts;
	string pkt;

	//Store the notepad primitives.
	vector<string> keys;

	ifstream keysFile;
	keysFile.open("prim/primitives.txt");

	if (keysFile.is_open())
	{
		while (!keysFile.eof())
		{
			string tmp = "";
			getline(keysFile, tmp);
			if(tmp.size() == primitiveLen) keys.push_back(tmp);
		}
	}
	
	keysFile.close();

	string inputFile = argv[1];

	//To save only the first primitive values needed.
	map<int, string> mp;

	//To read the Hexa file.
	ifstream readFile;
	readFile.open(inputFile);

	//Save the primitive in the vector container.
	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			string tmp = "";
			getline(readFile, tmp);

			if (!tmp.empty())pkt += tmp.substr(6,47);
			else
			{	
				//Remove the space in the packet string.
				pkt.erase(remove(pkt.begin(), pkt.end(), ' '), pkt.end());
				pkts.push_back(pkt);
				pkt.clear();
			}
		}
	}

	size_t keySize = keys.size();
	//Save the necessary primitive in the map container.
	for (int i = 0; i < keySize; i++)
	{	
		for (auto x : pkts)
		{	
			if (mp.find(i) == mp.end() && x.find(keys[i]) != string::npos)
			{	
				//The loadsetting start primitive insert.
				if (i == 0)
				{
					if (x.find("0100aaaa") != string::npos) mp[i] = x;
				}
				//The loadsetting end primitive insert.
				else if (i == keySize - 1)
				{
					if (x.find("0101aaaa") != string::npos) mp[i] = x;
				}
				else
				{
					mp[i] = x;
				}
			}
			if (mp.find(i) != mp.end()) break;
		}
	}

	//Print file declaration.
	//ofstream writeFile;
	//ofstream resFile;

	//Print out all the primitives.
	//writeFile.open("pkts.txt");
	//for (auto x : pkts) writeFile << x << endl;


	//Print out only the necessary primitive.
	//resFile.open("res.txt");
	//for(auto y : mp) resFile << y.second << endl;
	
	//Close the file.
	readFile.close();
	//writeFile.close();
	//resFile.close();

	//Create scenario storage directory
	system("mkdir Scenario");

	//Print file declaration.
	vector<string> prim;

	//Change the output data.
	for (auto x : mp)
	{
		prim.push_back("6305," + x.second.substr(x.second.find("abcd")));
	}

	ofstream writeFile1;
	int i = 1;
	for (auto x : prim)
	{
		string fileName1 = "test2_";

		fileName1 += (to_string(i) + "_1C.csv");
		writeFile1.open(fileName1);
		writeFile1 << x;

		writeFile1.close();

		i++;
	}

	//Move scenario files.
	system("move *.csv Scenario/");

	return 0;
}