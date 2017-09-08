#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
map<string, vector<int> >moves;
string first, second;
string smoves[4];
vector<int>vfirst;
vector<int>vsecond;
void cutstring(string galy)
{
	string b,a;
	b = galy[0];
	a = galy[1];
	first = b + a;
	b = galy[2];
	a = galy[3];
	second = b + a;
}
void fill_map()
{
	moves["a1"] = { 1, 2, 3, 0 };
	moves["a2"] = { 5, 6, 7, 0 };
	moves["a3"] = { 9, 10, 11,0  };
	moves["a4"] = { 71,97,88,0  };
	moves["a5"] = { 69,106,87,0  };
	moves["a6"] = { 67,114,86,0  };
	moves["a7"] = { 63,123 ,72 ,0  };
	moves["a8"] = { 57, 134,77 ,0  };
	moves["b1"] = { 37, 38, 39,0  };
	moves["b2"] = { 41, 42, 43,0  };
	moves["b3"] = { 45, 46, 47,0  };
	moves["b4"] = { 77,100,88,0  };
	moves["b5"] = { 75,110,87,0  };
	moves["b6"] = { 73,119,84,0 };
	moves["b7"] = { 68,129,80,0  };
	moves["b8"] = { 66,141 ,71 ,0  };
	moves["c1"] = { 69, 70, 71,0  };
	moves["c2"] = { 73, 74, 75,0  };
	moves["c3"] = { 77, 78, 79,0  };
	moves["c4"] = { 83,102,88,0  };
	moves["c5"] = { 82,111,87,0  };
	moves["c6"] = { 81,118,84,0  };
	moves["c7"] = { 77,134,75,0  };
	moves["c8"] = { 75,143 ,73 ,0  };
	moves["d1"] = { 101, 102, 103,0  };
	moves["d2"] = { 105, 106, 107,0 };
	moves["d3"] = { 109, 110,111,0 };
	moves["d4"] = { 88,102,88,0  };
	moves["d5"] = { 89,111,87,0  };
	moves["d6"] = { 88,120,83,0  };
	moves["d7"] = { 87,134,77,0  };
	moves["d8"] = { 84,148,70,0  };
	moves["e1"] = { 133, 134, 135,0  };
	moves["e2"] = { 137, 138, 139,0 };
	moves["e3"] = { 141, 142, 143,0  };
	moves["e4"] = { 95,102,87,0  };
	moves["e5"] = { 95,112,87,0 };
	moves["e6"] = { 96,121,83,0  };
	moves["e7"] = { 96,133,78,0  };
	moves["e8"] = { 97,148,73,0  };
	moves["f1"] = { 165, 166, 167,0  };
	moves["f2"] = { 169, 170, 171,0  };
	moves["f3"] = { 173, 174, 175,0 };
	moves["f4"] = { 100,102,87,0 };
	moves["f5"] = { 101,108,86,0  };
	moves["f6"] = { 103,122,83,0  };
	moves["f7"] = { 105,134,78,0  };
	moves["f8"] = { 108,143,73 ,0  };
	moves["g1"] = { 197, 198, 199,0  };
	moves["g2"] = { 201, 202, 203,0  };
	moves["g3"] = { 205, 206, 207,0  };
	moves["g4"] = { 106,97,87,0  };
	moves["g5"] = { 108,107,86,0  };
	moves["g6"] = { 113,118,85,0  };
	moves["g7"] = { 113,129,80,0  };
	moves["g8"] = { 118,138 ,73 ,0  };
	moves["h1"] = { 229, 230, 231,0  };
	moves["h2"] = { 233, 234, 235,0  };
	moves["h3"] = { 237, 238, 239,0  };
	moves["h4"] = { 112,94,86,0 };
	moves["h5"] = { 115,104,86,0 };
	moves["h6"] = { 119,114,85,0 };
	moves["h7"] = { 122,123,80,0  };
	moves["h8"] = { 128,132 ,77 ,0  };
	moves["aa"] = { 170, 165, 40,0  };
}
int main()
{

	string haygely;
	first = second = "";

	ifstream infile1;
	infile1.open("arm/move.txt");
	if (infile1.fail())
	{
		cerr << "error opening file" << endl;
		exit(1);
	}


int i = 0;
	while (!infile1.eof())
	{
		infile1 >> haygely;
		smoves[i] = haygely;
		i++;
	}
//    cout<<haygely<<endl;
	fill_map();
	for (int i = 0; i < 2; i++)
	{
		if (smoves[i] != "")
		{
			cutstring(smoves[i]);
			vfirst = moves[first];
			vfirst[3] = 100;
			vsecond = moves[second];
			vsecond[3] = 15;


			for (int i = 0; i < 4; i++)
			{
				cout << vfirst[i] << " ";
			}
			cout << endl;


			for (int i = 0; i < 4; i++)
			{
				cout << vsecond[i] << " ";
			}
			cout << endl;

		}
	}

	return 0;
}
