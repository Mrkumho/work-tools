#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{	
	vector<string> pkts;
	vector<int> keys = { 21000004 };
	string pkt;

	map<int, string> mp;

	ifstream readFile;
	readFile.open("out.txt");


	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			string tmp = "";
			getline(readFile, tmp);
			if (!tmp.empty())pkt += tmp.substr(6,47);
			else
			{	
				pkt.erase(remove(pkt.begin(), pkt.end(), ' '), pkt.end());
				pkts.push_back(pkt);
				pkt.clear();
			}

		}
	}
	readFile.close();
	
	for (int i = 0; i < keys.size(); i++)
	{	
		int strkey = keys[i];
		to_string(strkey);

		for (auto x : pkts)
		{	
			if (!mp.count(keys[i]) && x.find(strkey) != string::npos)
			{
				
			}
		}
	}

	ofstream writeFile;
	writeFile.open("pkts.txt");

	for(auto x : pkts)
	writeFile << x << endl <<endl;

	writeFile.close();

	return 0;
}