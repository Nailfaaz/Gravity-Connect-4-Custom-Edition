//implementasi array, if-else, subfunction, rekursif
#include<bits/stdc++.h>
using namespace std;

int i, j, m, n;
bool win1=0, win2=0, k;
char temp, board[10][10];
char z;

void change(char board[10][10], int n){
    if(n==90){
        for (i=0;i<7/2;i++) {
            for (j=i;j<7-i-1;j++) {
                temp = board[i][j];
                board[i][j] = board[7-1-j][i];
                board[7-1-j][i] = board[7-1-i][7-1-j];
                board[7-1-i][7-1-j] = board[j][7-1-i];
                board[j][7-1-i] = temp;
            }
        }
    } else if(n==-90){
        for (i=0;i<7/2;i++) {
            for (j=i;j<7-i-1;j++) {
                temp = board[i][j];
                board[i][j] = board[j][7-1-i];
                board[j][7-1-i] = board[7-1-i][7-1-j];
                board[7-1-i][7-1-j] = board[7-1-j][i];
                board[7-1-j][i] = temp;
        }
    }

    } else{
            if(k%2==1){
                for(i=6;i>=0;i--){
                    if(board[i][n-1]=='*'){
                    board[i][n-1]='X';
                    break;
                    }
                }
            } 
            else{
                for(i=6;i>=0;i--){
                    if(board[i][n-1]=='*'){
                        board[i][n-1]='O';
                        break;
                    }
                }
            }
        }
    }   

void checkfall(char board[10][10]){
    for(j=0;j<7;j++){
        for(i=6;i>=0;i--){
            if(board[i][j]=='X'||board[i][j]=='O'){
                continue;
            } else if(board[i][j]=='*'){
                for(m=i-1;m>=0;m--){
                    if(board[m][j]=='X'||board[m][j]=='O'){
                        board[i][j]=board[m][j]; board[m][j]='*';
                        break;
                    }
                }
            }
        }
    }
}

void checkwin(char board[10][10]){
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            if(board[i][j]=='X' &&  board[i][j+1]=='X' && board[i][j+2]=='X' && board[i][j+3]=='X'){
                win1=1; break;
            }if(board[i][j]=='X' &&  board[i+1][j]=='X' && board[i+2][j]=='X' && board[i+3][j]=='X'){
                win1=1; break;
            }if(board[i][j]=='X' &&  board[i+1][j+1]=='X' && board[i+2][j+2]=='X' && board[i+3][j+3]=='X'){
                win1=1; break;
            }if(board[i][j]=='X' &&  board[i+1][j-1]=='X' && board[i+2][j-2]=='X' && board[i+3][j-3]=='X'){
                win1=1; break;
            }
        }
    }
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            if(board[i][j]=='O' &&  board[i][j+1]=='O' && board[i][j+2]=='O' && board[i][j+3]=='O'){
                win2=1; break;
            }if(board[i][j]=='O' &&  board[i+1][j]=='O' && board[i+2][j]=='O' && board[i+3][j]=='O'){
                win2=1; break; 
            }if(board[i][j]=='O' &&  board[i+1][j+1]=='O' && board[i+2][j+2]=='O' && board[i+3][j+3]=='O'){
                win2=1; break;
            }if(board[i][j]=='O' &&  board[i+1][j-1]=='O' && board[i+2][j-2]=='O' && board[i+3][j-3]=='O'){
                win2=1; break;
            }
        }
    }
    if(board[0][0]!='*' && board[0][1]!='*' && board[0][2]!='*' && board[0][3]!='*' && board[0][4]!='*' && board[0][5]!='*' && board[0][6]!='*'){win1=1;win2=1;}
}

int game(char board[10][10]){
    cout << " ";
    for(i=1;i<=7;i++){
        cout << " " << i << "  ";
    } cout << endl; cout << string(29, '-') << endl;
    for(i=0;i<7;i++){
        cout << "| ";
        for(j=0;j<7;j++){
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << string(29, '-') << endl;
    }
    return 0;
}
void invalidInput(int &n){

    if (n<1 or n>7){
        if(n!=90 && n!=-90){
            cout<<"invalid input, choose another input: ";cin>>n;invalidInput(n);
        }      
    }
}
int main(){

    string p1, p2;

    cout << "* * * * * * * * * * * * * * * *" << endl;
    cout << "* CONNECT 4 GAME FLIP EDITION *" << endl;
    cout << "* * * * * * * * * * * * * * * *" << endl;;
    cout << "Enter player 1 name : "; cin >> p1; 
    cout << "Enter player 2 name : "; cin >> p2; cout << endl; 

    //define board
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            board[i][j]='*';
        }
    }

    game(board);

    while(!win1 && !win2){
        cout << p1 << "`s turn" << endl; k=1;
        cout <<"pick number from 1-7 to drop your 'X' " << endl; 
        cout <<"Or you can enter '90'/'-90' to rotate 90 degree (clockwise/anticlockwise): "; cin >> n;invalidInput(n);
        change(board, n); checkfall(board); checkwin(board); 
        game(board);
        if(win1||win2){
            break;
        }
        cout << p2 << "`s turn" << endl; k=0;
        cout <<"pick number from 1-7 to drop your 'O' " << endl; 
        cout <<"Or you can enter '90'/'-90' to rotate 90 degree clockwise/anticlockwise: "; cin >> n;invalidInput(n);
        change(board, n); checkfall(board); checkwin(board); 
        game(board);
    }

    if(win1&&win2){
        cout << "DRAW";
    }else if(win1){
        cout << "CONGRATS!!! " << p1 << " WIN :D" ;
    } else{
        cout << "CONGRATS!!! " << p2 << " WIN :D";
    }
    cin.ignore();
    cout << endl << "Press Enter to Exit . . . ";
    cin.get();
    return 0;
}
