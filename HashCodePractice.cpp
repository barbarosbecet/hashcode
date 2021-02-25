// HashCodePractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Input
5 1 2 1 
3 onion pepper olive
3 mushroom tomato basil
3 chicken mushroom pepper
3 tomato mushroom basil
2 chicken basil
*/
/*
Output
Submission file Description
2			Pizzas are delivered to 2 teams
2 1 4		A 2-person team will receive Pizza 1 and Pizza 4
3 0 2 3		A 3-person team will receive Pizza 0, Pizza 2 and Pizza 3
*/

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
	ofstream oout("e.txt");

	unordered_map<string, int> ingredients;

	int M; //number of pizzas
	cin >> M;
	vector<int> t(5); //teams
	cin >> t[2] >> t[3] >> t[4];

	vector<vector<int>> pizzas(M);
	for (int i = 0; i < M; i++)
	{
		int count = 0;
		cin >> count;

		pizzas[i].resize(count);
		for (int j = 0; j < count; j++)
		{
			string s;
			cin >> s;
			if (ingredients.find(s) == ingredients.end())
			{
				int si = ingredients.size();
				ingredients[s] = si;
			}

			pizzas[i][j] = ingredients[s];
		}
	}

	int totalpeople = t[2] * 2 + t[3] * 3 + t[4] * 4; //up to 450.000

	int deliveries = 0; //deliveries to teams
	unordered_set<int> unusedPizzas;
	for (int i = 0; i < M; i++)
		unusedPizzas.insert(i);

	vector<vector<int>> t2pizzas;

	for(int tsize=4; tsize >=2; tsize--)
	{
		for (int i = 0; i < t[tsize]; i++) //for all teams of size tsize, assign pizzas
		{
			if (unusedPizzas.size() >= tsize) //check if enough pizza for all teams
			{
				vector<int> p;			
				for (int f = 0; f < tsize; f++)
				{
					int p1 = *unusedPizzas.begin();
					unusedPizzas.erase(p1);
					p.push_back(p1);
				}

				t2pizzas.push_back(p);
			}
			else break;
		}
	}
	
	//output
	oout << t2pizzas.size() << endl;
	cout << t2pizzas.size() << endl;
	
	
	for (int i=0; i<t2pizzas.size(); i++)
	{
		oout << t2pizzas[i].size();
		cout << t2pizzas[i].size();
		for (int j : t2pizzas[i])
		{
			oout << " " << j;
			cout << " " << j;
		}
		oout << endl;
		cout << endl;
	}
	

}
