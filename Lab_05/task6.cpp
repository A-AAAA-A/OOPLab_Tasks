#include<iostream>
using namespace std;

class GameLevel {
private:
    string levelName;
    string levelDifficulty;

public:
    GameLevel() {}
    GameLevel(string name, string difficulty) : levelName(name), levelDifficulty(difficulty) {}

    void showDetails() const {
        cout << "Level Name: " << levelName << endl;
        cout << "Difficulty: " << levelDifficulty << endl;
    }
};

class VideoGame {
private:
    string gameTitle;
    string gameGenre;
    GameLevel gameLevels[15];
    int levelCount = 0;

public:
    VideoGame(string title, string genre) : gameTitle(title), gameGenre(genre) {}

    void addGameLevel(string name, string difficulty) {
        gameLevels[levelCount++] = GameLevel(name, difficulty);
    }

    void showGameDetails() const {
        cout << "Game Title: " << gameTitle << endl;
        cout << "Genre: " << gameGenre << endl;
        cout << "Game Levels: " << endl;
        for (int i = 0; i < levelCount; i++) {
            gameLevels[i].showDetails();
        }
    }
};

int main() {
    VideoGame myGame("Mario", "Adventure");
    myGame.addGameLevel("Saving Luigi", "Easy");
    myGame.addGameLevel("Betrayal from Luigi", "Medium");
    myGame.addGameLevel("Killin Luigi", "Hard");

    myGame.showGameDetails();

    return 0;
}
