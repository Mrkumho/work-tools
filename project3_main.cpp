#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{	
	
	vector<string> pkts;
	string pkt;
	vector<string> keys = {
		"51000005",
		"51020005",
		"513b0005",
		"513c0005",
		"51050005",
		"51110005",
		"51120005",
		"513a0005",
		"512d0005",
		"512e0005",
		"51300005",
		"51310005",
		"51320005",
		"51330005",
		"51340005",
		"51360005",
		"51370005",
		"50000005",
		"50010005",
		"50020005",
		"512a0005",
		"51020005"
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

	
	//Save the necessary primitive in the map container.
	for (int i = 0; i < keys.size(); i++)
	{	
		for (auto x : pkts)
		{	
			if (mp.find(i) == mp.end() && x.find(keys[i]) != string::npos) mp[i] = x;

			if (mp.find(i) != mp.end()) break;
		}
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