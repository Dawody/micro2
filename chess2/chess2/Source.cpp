#include<iostream>
#include<vector>
#include<map>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
int current[8][8], previous[8][8];
char current2[8][8], previous2[8][8];

string checkt(){
if(previous2[0][4]=='K'&&(previous2[0][0]=='R'||previous2[0][7]=='R')){
if(previous[0][5]==0&&previous[0][6]==0&&current[0][5]==1&&current[0][6]==1&&current[0][4]==0&&current[0][7]==0)
{current2[0][5]='R';current2[0][6]='K';current2[0][7]='-';current2[0][4]='-';}
if(previous[0][2]==0&&previous[0][3]==0&&current[0][2]==1&&current[0][3]==1&&current[0][4]==0&&current[0][0]==0)
{current2[0][3]='R';current2[0][2]='K';current2[0][0]='-';current2[0][4]='-';}
}else return "";
string x="";
if(current2[0][5]=='R'&&current2[0][6]=='K'){
x+='e';x+='1';x+='g';x+='1';
}
else if(current2[0][3]=='R'&&current2[0][2]=='K'){
x+='e';x+='1';x+='c';x+='1';
}
return x;}

string mount(){
string x="";
for(int i=0;i<8;i++)
if(previous2[i][6]=='r'&&current2[i][4]=='r'&&current[i][6]==0&&previous[i][4]!=2)
if(i!=7)if(previous2[i+1][4]=='R'&&current2[i][5]=='R'&&current[i+1][6]==0&&previous[i][5]==0){
x+=char('a'+i);x+=char((7)+'0');x+=char('a'+i);x+=(char((5)+'0'));
x+="/n";
x+=char('a'+i+1);x+=char((5)+'0');x+=char('a'+i);x+=(char((6)+'0'));
}
else if(i!=0)if(previous2[i-1][4]=='R'&&current2[i][5]=='R'&&current[i-1][6]==0&&previous[i][5]==0){
x+=char('a'+i);x+=char((7)+'0');x+=char('a'+i);x+=(char((5)+'0'));
x+="/n";
x+=char('a'+i-1);x+=char((5)+'0');x+=char('a'+i);x+=(char((6)+'0'));
}
return x;}

string promote(string z){
string x=z;
for(int i=0;i<7;i++)
if(current2[i][7]=='R'){current2[i][7]=='Q';x+='Q';}
return x;
}
void promoteMAP(){
for(int i=0;i<7;i++){
if(current2[i][0]=='p')current2[i][0]=='q';
if(current2[i][7]=='P')current2[i][7]=='Q';
}
};
string getpos(int type=1) {
string check=checkt(),mountx=mount();
if(!(check.empty()))
return check;
if(!mountx.empty())return mountx;
char x1 = 'z', x2 = ' ';
int y1 = 0, y2 = 0;
for (int i = 0; i < 8; i++)
for (int j = 0; j < 8; j++)
if (current[j][i] != previous[j][i])
if (current[j][i] == type){x2 = char('a' + i);y2 = j + 1;}
else if (previous[j][i] == type) {x1 = char('a' + i);y1 = j + 1;}
if(x1 != 'z' && x2 != ' '){
current2[y2-1][int(x2-'a')] = previous2[y1-1][int(x1-'a')];
current2[y1-1][int (x1-'a')] = '-';
string message = "";
message += x1;message += char(y1 + '0');message += x2;message += (char(y2 + '0'));
return message;}
return "";}

void printpos(){
for(int i=7;i>=0;i--){
cout<<i+1<<"-  ";
for(int j=0;j<8;j++)
{cout<<previous2[i][j]<<" ";}
cout<<"   |   ";
for(int j=0;j<8;j++)
{cout<<current2[i][j]<<" ";}
cout<<endl;
}}

string movepos(string message) {
char c='-';int kok=0;
pair<char, int> eat = make_pair('x', 0);
int x1 = int(message[0] - 'a');
int x2 = int(message[2] - 'a');
int y1 = message[1] - '0' - 1;
int y2 = message[3] - '0' - 1;

if (current[y2][x2] !=0&&current[y2][x2]!=current[y1][x1] )eat = make_pair(char('a' + x2), y2 + 1);
if(current2[y1][x1]=='p'&&current[y2][x2]==0&&current2[y2+1][x2]=='P'&&x1!=x2)eat = make_pair(char('a' + x2), y2 + 2);
if(current2[y1][x1]=='k'&&(x2-x1==2||x1-x2==2))
{
if(x2==6)
{
current2[7][5]='r';current2[7][6]='k';current2[7][7]='-';current2[7][4]='-';
current[7][5]=1;current[7][6]=1;current[7][7]=0;current[7][4]=0;}
else if(x2==2)
{
current2[7][3]='r';current2[7][2]='k';current2[7][0]='-';current2[7][4]='-';
current[7][3]=1;current[7][2]=1;current[7][0]=0;current[7][4]=0;}
}
current[y2][x2] = previous[y1][x1];
current2[y2][x2] = previous2[y1][x1];
current2[y1][x1] = '-';
current[y1][x1] =0;
if (eat.second) {
string message2 = "";
message2 += eat.first;message2 += (char(eat.second + '0'));message2 += "aa";message2+='\n';
return message2+message;}
return message;}

void restartdata() {
for(int i = 0; i < 8; i++) {
current[1][i] = 1;
current[0][i] = 1;
previous[1][i] = 1;
previous[0][i] = 1;
current[7][i] = 2;
current[6][i] = 2;
previous[7][i] = 2;
previous[6][i] = 2;
current2[1][i] = previous2[1][i] = 'P';
current2[6][i] = previous2[6][i] = 'p';}
current2[0][0] = previous2[0][0] = current2[0][7] = previous2[0][7] = 'R';
current2[7][0] = previous2[7][0] = current2[7][7] = previous2[7][7] = 'r';
current2[0][1] = previous2[0][1] = current2[0][6] = previous2[0][6] = 'N';
current2[7][1] = previous2[7][1] = current2[7][6] = previous2[7][6] = 'n';
current2[0][2] = previous2[0][2] = current2[0][5] = previous2[0][5] = 'B';
current2[7][2] = previous2[7][2] = current2[7][5] = previous2[7][5] = 'b';
current2[0][3] = previous2[0][3] = 'Q';
current2[7][3] = previous2[7][3] = 'q';
current2[0][4] = previous2[0][4] = 'K';
current2[7][4] = previous2[7][4] = 'k';
for (int i = 2; i < 6; i++)
for (int j = 0; j < 8; j++) {
previous2[i][j] = current2[i][j] = '-';
previous[i][j] = current[i][j] = 0;}
for (int i = 0; i < 8; i++) {
for (int j = 0; j < 8; j++)
cout << previous2[i][j] << " ";
cout << endl;}
}

void currenttoprevious() {
for(int i = 0; i < 8; i++)
for(int j = 0; j < 8; j++) {
previous[i][j] = current[i][j];
previous2[i][j] = current2[i][j];}
}

void filldata() {
ofstream myfile;
myfile.open("current.txt");
for(int i = 0; i < 8; i++)
for (int j = 0; j < 8; j++)
myfile << current2[i][j] << endl;
myfile.close();
////////////////////
ofstream myfile;
myfile.open("previous.txt");
for(int i = 0; i < 8; i++)
for (int j = 0; j < 8; j++)
myfile << previous2[i][j] << endl;
myfile.close();
}

void getdata() {
ifstream myfile;
myfile.open("current.txt");
for(int i = 0; i < 8; i++)
for (int j = 0; j < 8; j++) {
myfile >> current2[i][j];
if (current2[i][j] == '-')current[i][j] = 0;
else if (isupper(current2[i][j]))current[i][j] = 1;
else current[i][j] = 2;}
myfile.close();
//currenttoprevious();
getdata2();
}

void getdata2() {
ifstream myfile;
myfile.open("previous.txt");
for(int i = 0; i < 8; i++)
for (int j = 0; j < 8; j++) {
myfile >> previous2[i][j];
if (previous2[i][j] == '-')previous[i][j] = 0;
else if (isupper(previous2[i][j]))previous[i][j] = 1;
else previous[i][j] = 2;}
myfile.close();
//currenttoprevious();
}

int main() {
//restartdata();filldata();
ifstream myfile;
myfile.open("mode.txt");
int x=10;
myfile>>x;
myfile.close();
if(x==0){restartdata();filldata();}
if(x==1){
getdata();
//readfrom omar

ofstream myfile2;
myfile2.open("player.txt");
myfile2<<getpos();;
myfile2.close();
//filldata();
currenttoprevious();
filldata();

}
if(x==2)
{
getdata();
ifstream myfile;
myfile.open("read.txt");
string st;
myfile>>st;
myfile.close();
ofstream myfile2;
myfile2.open("stockfish.txt");
myfile2<<movepos(st);
myfile2.close();
//filldata();
currenttoprevious();
filldata();}
return 0;
}

