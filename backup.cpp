#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
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





       // freopen("input","r",stdin);
       // freopen("input","w",stdout);
       // fclose (stdout);



    bool key=true;
    while(key){
        key=false;

//prepare the commands into file

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
    printf("%s",path);
    }
//---------------------------------------------------------------------------------------------------------------------------------------------------



 //edit UCI
    newpos = output.substr( output.length() - 43 , 4 ) ;
    cout<<"\n\nNEWPOS : "<<newpos<<endl<<endl;
    uci +=" " + newpos;




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

    //send new order to arm !
//______________
//
//
//
//
//_____________________


cin>>enemy_move;
key=true;

    uci +=" "+enemy_move;



    }



   }




