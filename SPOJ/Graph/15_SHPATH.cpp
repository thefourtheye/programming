# include <iostream>
# include <cstdio>
# include <queue>
# include <map>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <limits>
# include <utility>
# include <cstring>
# include <unistd.h>
# include <ctime>
using namespace std;
pair <char [12], int> CityIndexes [10001];
int NeighbourCounts [10001]; int Distances [10001];
pair <int, int> AdjMatrix [10001][10001];
int NumberOfTests, NumberOfCities, NumberOfNeighbours, NumberOfPathsToFind, CityIndex, Cost, StartCity, EndCity;
char StartCityName [12], EndCityName [12];
const int READLIMIT = 32768;int ReadIndex = 0, BufferLength = 0;unsigned char ReadBuffer [READLIMIT];
char * getString(char String[], int MaxLen)
{
	int startTicks = clock();
	bool isDone = false, isFirstChar = true; int strIndex = 0;
	unsigned char Char;
	while (!feof (stdin) && !isDone && strIndex <= MaxLen)
	{
		Char = getchar();
		//cout << "Got Char " << Char << endl;
		if (Char < 'a' || Char > 'z')
		{
			if (!isFirstChar) isDone = true;
			continue;
		}
		if (isFirstChar) isFirstChar = false;
		String [strIndex++] = Char;
		//cout << "Adding " << Char << endl;
	}
	String [strIndex] = '\0';
	cout << "getString Ticks : " << clock () - startTicks << endl;
	return String;
}
int getInt()
{
	int startTicks = clock();
	bool isDone = false, isFirstChar = true; unsigned char Char; int Result = 0;
	while (!feof (stdin) && !isDone)
	{
		Char = getchar();
		//cout << "Got Character : " << Char << endl;
		if (Char < '0' || Char > '9') 
		{
			if (!isFirstChar) isDone = true;
			continue;
		}
		if (isFirstChar) isFirstChar = false;
		Result = ((Result << 3) + (Result << 1)) + (Char - '0');
		//strNumber [strIndex++] = Char;
	}
	//cout << "Returning Int : " << Result << endl;
	cout << "getInt Ticks : " << clock () - startTicks << endl;
	return Result;
}
int main(int argc, char const *argv[])
{
	freopen ("15_SHPATH_input.txt",  "r", stdin);
	freopen ("15_SHPATH_output.txt", "w", stdout);
	NumberOfTests = getInt();
	//cout << "NumberOfTests : " << NumberOfTests << endl;
	while (NumberOfTests--)
	{
		NumberOfCities = getInt();
		//cout << "NumberOfCities : " << NumberOfCities << endl;
		for (int i = 1; i <= NumberOfCities; i++)
		{
			//cout << "City Name : " << getString(CityIndexes [i-1].first, 11) << endl;
			CityIndexes [i-1].second = i;
			NumberOfNeighbours = getInt();
			//cout << "NumberOfNeighbours : " << NumberOfNeighbours << endl;
			NeighbourCounts [i] = NumberOfNeighbours;
			for (int j = 1; j <= NumberOfNeighbours; j++)
			{
				AdjMatrix [i][j].first  = getInt();
				AdjMatrix [i][j].second = getInt();
				//cout << "Matrix : " << AdjMatrix[i][j].first << "," << AdjMatrix[i][j].second << endl;
			}
		}
		NumberOfPathsToFind = getInt();
		//cout << "NumberOfPathsToFind : " << NumberOfPathsToFind << endl;
		for (int i = 1; i <= NumberOfPathsToFind; i++)
		{
			getString(StartCityName, 11); getString (EndCityName, 11);
			//cout << "City 1 : " << getString(StartCityName, 11) << ", City 2 : " << getString (EndCityName, 11) << endl;
		}
	}
	return 0;
}