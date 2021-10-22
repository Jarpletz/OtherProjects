#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void readLevel(string);
void displayLevel();
bool checkCollision(int,int);

class block {
public:
    int x;
    int y;
    char ch;
    block(int, int, char);
    
};
block::block(int X, int Y, char CH) {
    X = x; y = Y; ch = CH;
}
class player : public block {
public:
    player(int, int, char);
};
player::player(int X, int Y, char CH) :block(X, Y, CH) { }


vector <block> blocks;

int lvlWidth;
int lvlHeight;

int main()
{
    readLevel("level.txt");
    
    displayLevel();
   
   
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
            player p=player(inX,inY,ch);
            blocks.push_back(p);
        case ' ':
            break;
        case '\n':
            inY++;
            inX = 0;
            break;
        default:
            block b=block(inX,inY,ch);
            blocks.push_back(b);
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
                if (blocks[i].x == x && blocks[i].y == y) {//until it finds one with matching coords
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