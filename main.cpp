/* 
 * File:   main.cpp
 * Author: bat
 *
 * Created on 17 Сентябрь 2015 г., 17:55
 */

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    //string line;
    
    short board[256][256];
    
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++)
            board[i][j] = 0;
    }
    
    string command;
    short i, j, X;
    int sum;
    while(stream >> command) {
        if(command[0] == 'S') {
            if(command[3] == 'C') {
                stream >> j;
                stream >> X;
                for (i = 0; i < 256; i++)
                    board[i][j] = X;
            }
            else {
                stream >> i;
                stream >> X;
                for (j = 0; j < 256; j++)
                    board[i][j] = X;
            }
        }
        else {
            sum = 0;
            if(command[5] == 'C') {
                stream >> j;
                for (i = 0; i < 256; i++)
                    sum += board[i][j];
                cout << sum << '\n';
            }
            else {
                stream >> i;
                for (j = 0; j < 256; j++)
                    sum += board[i][j];
                cout << sum << '\n';
            }
        }
    }
    
    return 0;
}