#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{	
	
	vector<string> pkts;
	string pkt;
	vector<string> keys = {
		"51000005", //0
		"51020005",	//1
		"513b0005",	//2
		"513c0005", //3
		"51050005", //4
		"51110005", //5
		"51120005", //6
		"513a0005", //7
		"512d0005", //8 
		"512e0005", //9
		"51300005", //10
		"51310005", //11
		"51320005", //12
		"51330005", //13
		"51340005", //14
		"51360005", //15
		"51370005", //16
		"51380005", //17
		"51390005", //18
		"51090005", //19
		"510b0005", //20
		"510c0005", //21
		"513f0005", //22
		"510d0005", //23
		"51410005", //24
		"51420005", //25
		"510e0005", //26
		"51430005", //27
		"512a0005", //28
		"51000005"  //29
	};

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

	int keySize = keys.size();
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

	for (auto& x : mp)
	{
		x.second.substr(5,5);
	}
	//Print file declaration.
	ofstream writeFile;
	ofstream resFile;

	//Print out all the primitives.
	writeFile.open("pkts.txt");
	for (auto x : pkts) writeFile << x << endl << endl;


	//Print out only the necessary primitive.
	resFile.open("res.txt");
	for(auto y : mp) resFile << y.second << endl << endl;
	
	//Close the file.
	readFile.close();
	writeFile.close();
	resFile.close();

	return 0;
}