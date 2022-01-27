#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{	
	vector<string> pkts;
	vector<int> keys = { 21000004,2001000};
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
		stringstream sstream;
		sstream << keys[i];
		string strkey = sstream.str();

		for (auto x : pkts)
		{	
			if (mp.find(keys[i]) == mp.end())
			{
				cout << 11 << endl;
				if(x.find(strkey) != string::npos)
						mp[i] = x;
			}
			else if (mp.find(keys[i]) != mp.end()) break;
		}
		sstream.clear();
	}

	ofstream writeFile;
	ofstream resFile;

	writeFile.open("pkts.txt");
	resFile.open("res.txt");
	for(auto x : pkts) writeFile << x << endl << endl;
	for(auto y : mp) resFile << y.second << endl << endl;

	writeFile.close();
	resFile.close();

	return 0;
}