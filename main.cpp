#include <iostream>
#include <stdlib.h>
#include <string>

void drawGrid(int grid[7][6]);
bool playTurn(int grid[7][6], int column, int player);
int playWin ( int grid[7][6] );

int main(int argc, char** argv){
    int grille[7][6] = {};
    std::string choix;

    int player = 1;
    int winner ; 
    bool part =  true ; 
        drawGrid(grille);

    while (part){
        std::cout << "player_" << player  << " -> colon :";
        std::cin >> choix;

        if (choix == "exit"){
            break;
        }

        bool success = false;

        if (choix.size() == 1){
            if (choix[0] >= '0' && choix[0] <= '7'){
                int col = choix[0]  - '0';

                success = playTurn(grille, col, player);
            }
        }

        system("CLS");

        if (!success){
            std::cout << "votre choix est incorrect\n";
        } else{
            if (player == 1) player = 2;
            else player = 1;
        }

        drawGrid(grille);

        winner = playWin (grille);

        if ( winner == 1) {
            std::cout << " le gagnant est player 1" << std::endl;
            part = false ;
        }

        else if ( winner == 2) {
            std::cout << " le gagnant est player 2" << std::endl ;
            part = false ;
        }    
       
    }

    return 0;
}


// 0, 1, 2
void drawGrid(int grille[7][6]){
    for (int ligne = 0; ligne < 6; ligne++){
        std::cout << "|";
        for (int col = 0; col < 7; col++){
            if (grille[col][ligne] == 1){
                std::cout << "\033[31m*\033[37m";
            } else 
            if (grille[col][ligne] == 2){
                std::cout << "\033[32m*\033[37m";
            }
            else {
                std::cout << "\033[37m*\033[37m";
            }
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

bool playTurn(int grid[7][6], int column, int player){
    for (int line = 5 ; line >= 0; line--){
        if (grid[column - 1][line] == 0){
            grid[column - 1][line] = player;
            return true;
        }
    } 
    return false;
}

int playWin (int grid[7][6]) {
    int winner ;

    for (int colon = 0 ; colon <7 ; colon ++) {
        for (int lign = 0 ; lign < 6 ; lign ++) {
            if (( grid[colon][lign]==1 && grid[colon+1][lign]==1 && grid[colon+2][lign]==1 && grid[colon+3][lign]==1) ||(grid[colon][lign]==1 && grid[colon][lign+1]==1 && grid[colon][lign+2]==1 && grid[colon][lign+3]==1 ) || (grid[colon][lign]==1 && grid[colon+1][lign+1]==1 && grid[colon+2][lign+2]==1 && grid[colon+3][lign+3]==1 ) || (grid[colon][lign]==1 && grid[colon+1][lign-1]==1 && grid[colon+2][lign-2]==1 && grid[colon+3][lign-3]==1 )) {
                winner = 1 ;
                
            }

            if ((grid[colon][lign]==2 && grid[colon+1][lign]==2 && grid[colon+2][lign]==2 && grid[colon+3][lign]==2) ||(grid[colon][lign]==2 && grid[colon][lign+1]==2 && grid[colon][lign+2]==2 && grid[colon][lign+3]==2 ) ||(grid[colon][lign]==2 && grid[colon+1][lign+1]==2 && grid[colon+2][lign+2]==2 && grid[colon+3][lign+3]==2 ) ||(grid[colon][lign]==2 && grid[colon+1][lign-1]==2 && grid[colon+2][lign-2]==2 && grid[colon+3][lign-3]==2 )) {
                winner = 2 ;
            }
        }
       
    }
    return winner ;
    } 
