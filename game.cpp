#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#include<fstream>
#include<limits>
using namespace std;

main(int argc , char *argv[] ){

    FILE *fp;
    char path[1035];
    string output ,newpos;
    string uci = "position startpos moves";
    string d = "d";
    string go = "go";
    string quit = "quit";
    string enemy_move ;
    string temp1,temp2,temp3;










//prepare the commands into file


        freopen("input","r",stdin);
        getline(cin,uci);
        //        cin>>temp1>>temp2>>temp3;


        freopen("arm/move.txt","r",stdin);
        cin>>enemy_move;
        uci +=" "+enemy_move;


        freopen("input","w",stdout);
        cout<<uci<<endl<<d<<endl<<go<<endl<<go<<endl<<quit<<endl;
        freopen ("/dev/tty", "a", stdout);




//--------------------------------------------------------------------------------------------------------------------------------------------------
//send commands to stockfish
    fp = popen("./stockfish-8-linux/Linux/stockfish_8_x64 < input","r");
    if(fp==NULL){
    printf("Failed to run commands\n");
    exit(1);
    }
//reading output of stockfish
    while(fgets(path,sizeof(path)-1,fp) != NULL){
    output += path;
//    printf("%s",path);
    }
//---------------------------------------------------------------------------------------------------------------------------------------------------



 //edit UCI
 //
 //
    if(output.substr(output.length()-2 ,1) == ")")
    {
        newpos="GAME OVER";

    }
    else
    {


    if(output.substr(output.length()-7 ,1) == "e")
    {

    if(output.substr(output.length()-21 ,1) == "e")
        newpos = output.substr(output.length()-19 ,4);
    else
        newpos = output.substr(output.length()-31 ,4);
    }
    else
    {
        if(output.substr(output.length()-38,1) == "p")
        newpos = output.substr( output.length() - 43 , 4 ) ;
        else
        {
            newpos = output.substr(output.length() -31  ,4);
        }

    }


    }









    cout<<newpos<<endl;

    //   cout<<"\n\nNEWPOS : "<<newpos<<endl<<endl;
    uci +=" " + newpos;
    freopen("bahi2/read.txt","w",stdout);
    cout<<newpos;
    freopen("/dev/tty","a",stdout);




    //fp = popen("./stockfish-8-linux/Linux/stockfish_8_x64 < input","r");


    freopen("input","w",stdout);
        cout<<uci<<endl<<d<<endl<<go<<endl<<go<<endl<<quit<<endl;
        freopen ("/dev/tty", "a", stdout);




/*
//not important just to show me the current case
//--------------------------------------------------------------------------------------------------------------------------------------------------


        freopen("input","w",stdout);
        cout<<uci<<endl<<d<<endl<<go<<endl<<go<<endl<<quit<<endl;
        freopen ("/dev/tty", "a", stdout);

//send commands to stockfish
    fp = popen("./stockfish-8-linux/Linux/stockfish_8_x64 < input","r");
    if(fp==NULL){
    printf("Failed to run commands\n");
    exit(1);
    }
//reading output of stockfish
    while(fgets(path,sizeof(path)-1,fp) != NULL){
    output += path;
    printf("%s",path);
    }



//---------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------
*/
    //send new order to arm !
//______________
//
//
//
//
//_____________________


    }







