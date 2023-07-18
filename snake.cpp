#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
const int H=20;
const int W=20;
int x,y,fx,fy,score=0;
int tx[100],ty[100],nt=0;
bool gameover;
enum edirection{
    STOP=0, UP,DOWN,LEFT,RIGHT
};
edirection dir;
void setup(){
    gameover=false;
    dir=STOP;
    x=W/2;
    y=H/2;
    fx=rand()%W;
    fy=rand()%H;
}
void draw(){
    system("CLS");
    for(int i=0;i<W;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(j==0 || j==W-1){
                cout<<"#";
            }
            else if(i==y && j==x){
                cout<<"O";
            }
            else if(i==fy & j==fx){
                cout<<"F";
            }
            else{
                bool flag=false;
                for(int k=0;k<nt;k++){
                    if(j==tx[k] && i==ty[k]){
                        cout<<"*"; flag=true;
                    }
                }
                if(!flag){
                cout<<" ";}
            }
        }
        cout<<endl;
    }
    for(int i=0;i<W;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<endl;
    cout<<"SCORE="<<score;
}
void input(){
    if(_kbhit()){
        switch (_getch())
        {
        case 'w': dir=UP; break;
        case 's': dir=DOWN; break;
        case 'a': dir=LEFT; break;
        case 'd': dir=RIGHT; break;
        default: break;
        }
    }
}
void logic(){
    int prevx=tx[0],prevy=ty[0];
    tx[0]=x;
    ty[0]=y;
    int prev2x,prev2y;
    for(int i=1;i<nt;i++){
        tx[i]=tx[i-1];ty[i]=ty[i-1];
    }
    //if(nt<100) nt++;
    switch(dir){
        case UP: y--; break;
        case DOWN: y++; break;
        case LEFT: x--; break;
        case RIGHT: x++; break;
        default: break;
    }
    if(x<0 || x>W || y<0 || y>H){
        gameover=true;
    }
    for(int i=0;i<nt;i++){
        if(x==tx[i] && y==ty[i]){
            gameover=true;
        }
    }
    if(x==fx && y==fy){
        score+=10;
        fx=rand()%W;
        fy=rand()%H;
        nt++;
    } 
}
int main(){
    setup();
    while(!gameover){
        draw();
        input();
        logic();
        Sleep(400);
    }
    return 0;
}