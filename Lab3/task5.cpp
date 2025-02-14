#include <iostream>
#include <string>

using namespace std;

class MusicPlayer {
private:
    string playlist[100];  // Array to store playlist songs
    int totalSongs;        // Keeps track of the number of songs in the playlist
    string currentlyPlayingSong; // The song currently playing

public:
    MusicPlayer() {
        totalSongs = 0;
        currentlyPlayingSong = "";
    }

    void addSong(string songName) {
        if (totalSongs < 100) {
            playlist[totalSongs] = songName;
            totalSongs++;
            cout << "Song '" << songName << "' added to the playlist." << endl;
        } else {
            cout << "Playlist is full! Cannot add more songs." << endl;
        }
    }

    void removeSong(string songName) {
        bool found = false;
        for (int i = 0; i < totalSongs; ++i) {
            if (playlist[i] == songName) {
                for (int j = i; j < totalSongs - 1; ++j) {
                    playlist[j] = playlist[j + 1];
                }
                totalSongs--;
                found = true;
                cout << "Song '" << songName << "' removed from the playlist." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Song '" << songName << "' not found in the playlist." << endl;
        }
    }

    void playSong(string songName) {
        bool found = false;
        for (int i = 0; i < totalSongs; ++i) {
            if (playlist[i] == songName) {
                currentlyPlayingSong = songName;
                cout << "Now playing: '" << songName << "'" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Song '" << songName << "' not found in the playlist." << endl;
        }
    }

    void displayPlaylist() {
        if (totalSongs == 0) {
            cout << "No songs in the playlist." << endl;
            return;
        }

        cout << "Playlist:" << endl;
        for (int i = 0; i < totalSongs; ++i) {
            cout << playlist[i] << endl;
        }
    }
};

int main() {
    MusicPlayer myPlayer;

    myPlayer.addSong("Shape of You");
    myPlayer.addSong("Blinding Lights");
    myPlayer.addSong("Levitating");
    myPlayer.addSong("Rockstar");

    myPlayer.displayPlaylist();

    myPlayer.playSong("Levitating");
    myPlayer.removeSong("Blinding Lights");

    myPlayer.displayPlaylist();

    myPlayer.playSong("Blinding Lights");

    return 0;
}
