#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<cassert>
#include<stdlib.h> 
using namespace std;

void readLevel(string);
void displayLevel();
bool checkCollision(int,int);

class block {
public:
    int x=0;
    int y=0;
    char ch=' ';
    block();
    block(int, int, char);
    
};
block::block() {}
block::block(int X, int Y, char CH) {
    x = X; y = Y; ch = CH;
}


class Player : public block {
public:
    Player();
    Player(int, int, char);
    void movePlayer();
    int distMoved = 0;
};
Player::Player() :block() {}
Player::Player(int X, int Y, char CH) :block(X, Y, CH) { }
void Player::movePlayer() {
    //Input Movement Commands 
    cout << " To Move Player: 'Right'/'Left'/'Up'/'down' + how far to move. 'END' to end program." << endl;
    cout << " Move Player: ";
    string direction;
    int xDir=0,yDir=0, magnitude;
    cin >> direction;
    cin >> magnitude;

    //Use inputted Commands to determine direction of movement
    if (magnitude < 0)magnitude = 0;
    if (direction == "right" || direction == "Right") {
        xDir = 1;
    }
    else if (direction == "left" || direction == "Left") {
        xDir = -1;
    }
    else if (direction == "up" || direction == "Up") {
        yDir = -1;
    }
    else if (direction == "down" || direction == "Down") {
        yDir = 1;
    }
    else if (direction == "END") {
        assert(false);
    }
    else {
        cout << "Invalid Movement! Please input correct movement value!" << endl;
        movePlayer();
        return;
    }

    //check if next place player attempts to move is already occupied. If no, change position and repeat
    distMoved = 0;
    for (int i = 0; i < magnitude;i++) {
        if (!checkCollision(x + xDir, y + yDir)) {
            x += xDir;y += yDir;
            distMoved++;
        }
        else return;
    }

}


Player player=Player();//creates player

vector <block> blocks; //vector for all other blocks

int lvlWidth;
int lvlHeight;

int main()
{
    readLevel("level.txt");
    while (1) {
        system("CLS");
        displayLevel();
        cout << " -->Player moved " <<player.distMoved<<" Tiles!" << endl;
        cout << " -->Player at [" << player.x << "," << player.y << "]" << endl;
        player.movePlayer();
    }

    return 0;
}


void readLevel(string dataPath) {
    ifstream lvlIn;
    lvlIn.open(dataPath);
    int inX = 0, inY = 0;
    while (!lvlIn.eof()) {
        char ch = lvlIn.get();
        inX++;
        if (inX > lvlWidth)lvlWidth = inX;
        switch (ch)
        {
        case 'P':
           player=Player(inX, inY, ch);
           break;
        case ' ':
            break;
        case '\n':
            inY++;
            inX = 0;
            break;
        default:
            blocks.push_back(block(inX, inY, ch));
            break;
        }

    }
    lvlHeight = inY + 1;
    lvlIn.close();
}
void displayLevel() {
    for (int y = 0;y < lvlHeight;y++) {//y coords
        for (int x = 0;x < lvlWidth;x++) {//x coords
            bool outputtedChar = false;
            for (int i = 0; i < static_cast<int>(blocks.size());i++) {//at every x and y coord run through every block...
                if (player.x == x && player.y == y) {
                    cout << player.ch;
                    outputtedChar = true;
                    break;
                }else if (blocks[i].x == x && blocks[i].y == y) {//until it finds one with matching coords
                    cout << blocks[i].ch;//output it to counsul
                    outputtedChar = true;
                    break;//end i loop (is this actually ending if statement?)
                }
            }
            if (outputtedChar == false) cout << " ";//if theres no blocks at coords, cout space
        }
        cout << endl;//after greatest x coord, move to next y and go again
    }
}
bool checkCollision(int futureX, int futureY) {
    for (int i = 0; i < static_cast<int>(blocks.size());i++) {
        if (futureX == blocks[i].x && futureY== blocks[i].y) {
            return true;
        }
    }
    return false;
}
