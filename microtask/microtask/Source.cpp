#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
map<string, vector<int> >moves;
string first, second;
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
	moves["a1"] = { 1, 2, 3, 4 };
	moves["a2"] = { 5, 6, 7, 8 };
	moves["a3"] = { 9, 10, 11, 12 };
	moves["a4"] = { 13, 14, 15, 16 };
	moves["a5"] = { 17, 18, 19, 20 };
	moves["a6"] = { 25, 26, 27, 28 };
	moves["a7"] = { 29, 30, 31, 32 };
	moves["a8"] = { 33, 34, 35, 36 };
	moves["b1"] = { 37, 38, 39, 40 };
	moves["b2"] = { 41, 42, 43, 44 };
	moves["b3"] = { 45, 46, 47, 48 };
	moves["b4"] = { 49, 50, 51, 52 };
	moves["b5"] = { 53, 54, 55, 56 };
	moves["b6"] = { 57, 58, 59, 60};
	moves["b7"] = { 61, 62, 63, 64 };
	moves["b8"] = { 65, 66, 67, 68 };
	moves["c1"] = { 69, 70, 71, 72 };
	moves["c2"] = { 73, 74, 75, 76 };
	moves["c3"] = { 77, 78, 79, 80 };
	moves["c4"] = { 81, 82, 83, 84 };
	moves["c5"] = { 85, 86, 87, 88 };
	moves["c6"] = { 89, 90, 91, 92 };
	moves["c7"] = { 93, 94, 95, 96 };
	moves["c8"] = { 97, 98, 99, 100 };
	moves["d1"] = { 101, 102, 103, 104 };
	moves["d2"] = { 105, 106, 107, 108};
	moves["d3"] = { 109, 110,111, 112};
	moves["d4"] = { 113, 114, 115, 116 };
	moves["d5"] = { 117, 118, 119, 120 };
	moves["d6"] = { 121, 122, 123, 124 };
	moves["d7"] = { 125, 126, 127, 128 };
	moves["d8"] = { 129, 130, 131, 132 };
	moves["e1"] = { 133, 134, 135, 136 };
	moves["e2"] = { 137, 138, 139, 140};
	moves["e3"] = { 141, 142, 143, 144 };
	moves["e4"] = { 145, 146, 147, 148 };
	moves["e5"] = { 149, 150, 151, 152};
	moves["e6"] = { 153, 154, 155, 156 };
	moves["e7"] = { 157, 158, 159, 160 };
	moves["e8"] = { 161, 162, 163, 164 };
	moves["f1"] = { 165, 166, 167, 168 };
	moves["f2"] = { 169, 170, 171, 172 };
	moves["f3"] = { 173, 174, 175, 176};
	moves["f4"] = { 177,178,179, 180};
	moves["f5"] = { 181, 182, 183, 184 };
	moves["f6"] = { 185, 186, 187, 188 };
	moves["f7"] = { 189, 190, 191, 192 };
	moves["f8"] = { 193, 194, 195, 196 };
	moves["g1"] = { 197, 198, 199, 200 };
	moves["g2"] = { 201, 202, 203, 204 };
	moves["g3"] = { 205, 206, 207, 208 };
	moves["g4"] = { 209, 210, 211, 212 };
	moves["g5"] = { 213, 214, 215, 216 };
	moves["g6"] = { 217, 218, 219, 220 };
	moves["g7"] = { 221, 222, 223, 224 };
	moves["g8"] = { 225, 226, 227, 228 };
	moves["h1"] = { 229, 230, 231, 232 };
	moves["h2"] = { 233, 234, 235, 236 };
	moves["h3"] = { 237, 238, 239, 240 };
	moves["h4"] = { 241, 242, 243, 244 };
	moves["h5"] = { 245, 246, 247, 248 };
	moves["h6"] = { 249, 250, 251, 252 };
	moves["h7"] = { 253, 254, 255, 256 };
	moves["h8"] = { 257, 258, 259, 260 };
	moves["aa"] = { 261, 262, 263, 264 };
}
int main()
{

	string haygely;
	first = second = "";

	ifstream infile1;
	infile1.open("move.txt");
	if (infile1.fail())
	{
		cerr << "error opening file" << endl;
		exit(1);
	}
	int i = 0;
	while (!infile1.eof())
	{
		infile1 >> haygely;
		i++;
	}
		fill_map();
		cutstring(haygely);
		vfirst.resize(4);
		vfirst.resize(4);

	vfirst = moves[first];
		vsecond = moves[second];
		cout << first << "--->";

		for (int i = 0; i < 4; i++)
		{
			cout << vfirst[i] << "----";
		}
		cout << endl;
		cout << second << "--->";

		for (int i = 0; i < 4; i++)
		{
			cout << vsecond[i] << "----";
		}
		cout << endl;

	return 0;
}
