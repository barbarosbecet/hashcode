// HashCodePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <set>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
	int duration;
	int intersections; //vertices
	int streets; //edges
	int cars; 
	int score;

	cin >> duration >> intersections >> streets >> cars >> score;

	//vector<vector<int>> adjList(intersections);
	vector<vector<int>> edges(streets, vector<int>(2));

	//vector<vector<int>> incoming(intersections);
	map<int, set<int>> isAnyIncoming;

	vector<string> streetnames(streets);
	unordered_map<string, int> edgeNameToId;
	vector<int> lengths(streets);
	vector<vector<string>> paths(cars);
	unordered_map<int, int> carsInStreet;

	for (int i = 0; i < streets; i++)
	{
		cin >> edges[i][0] >> edges[i][1] >> streetnames[i] ;
		edgeNameToId[streetnames[i]] = i;

		//incoming[edges[i][1]].push_back(i);

		//adjList[edges[i][0]].push_back(edges[i][1]);
		cin >> lengths[i];
	}


	for (int i = 0; i < cars; i++)
	{
		int path;
		cin >> path;
		paths[i].resize(path);
		int pathlength = 0;
		for(int j=0; j< path; j++)
		{
			cin >> paths[i][j]; //streetname
			int streetId = edgeNameToId[paths[i][j]];
			int fromInter = edges[streetId][0], toInter = edges[streetId][1];
			isAnyIncoming[toInter].insert(streetId);
			carsInStreet[streetId]++;
		}

	}

	//solution

	//output
	int interOutCount = 0;
	cout << isAnyIncoming.size() << endl;
	for (auto it= isAnyIncoming.begin(); it!=isAnyIncoming.end(); it++)
	{
		cout << it->first << endl;
		cout << it->second.size() << endl;
		
		vector<int> temp(it->second.begin(), it->second.end());
		auto mycomp = [&](int i1, int i2)
		{
			return carsInStreet[i1] > carsInStreet[i2];
		};
		sort(temp.begin(), temp.end(), mycomp); //sort streets by number of cars in them
		for (int s : temp)
		{
			cout << streetnames[s] <<" " << max((int)log2(carsInStreet[s]), 1) << endl;
		}
	}
}
