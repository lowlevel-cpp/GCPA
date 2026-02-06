#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int randNum = rand() % 1000001;
    int checkNum = randNum;
    cout << randNum;
    cin >> checkNum;
    if (randNum == checkNum) {
        cout << "YESSSSSSSSSS\n";
    }
    return 0;
}