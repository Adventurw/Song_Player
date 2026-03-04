//https://ww2.cs.fsu.edu/~small/cop3330/lecture9/playlist/playlist.html
#include<Windows.h>
#include<mmsystem.h>
#include<iostream>
#include<vector>
#include <cstdlib> 
#include<ctime>
using namespace std;

#pragma comment(lib,"winmm.lib")

class Node {
public:
    string data;
    Node* next;
    Node* prev;
    Node(string song):data(song) {
        next = NULL;
        prev = NULL;
    }
};
class PlayList {
private:
    Node* head;
    string SongName;
    string mode;
public:
    PlayList(){
        head = NULL;
       
    }
    ~PlayList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void Add_Songs(string song) {
        Node* newSong = new Node(song);
        if (!head) {
            head = newSong;
        }
        else {
            Node* currentSong = head;
            while (currentSong->next) {
                currentSong = currentSong->next;
            }
            currentSong->next = newSong;
        }
    }
    void Shuffle() {
        vector<string> values;
        Node* current = head;
        while (current) {
            values.push_back(current->data);
            current = current->next;
        }

        std::srand(std::time(0));
        std::random_shuffle(values.begin(), values.end());

        current = head;
        for (const string& value : values) {
            current->data = value;
            current = current->next;
        }
    }
    string Delete_Songs(string song) {
        if (!head) {
            cout << "Playlist is Empty.\n Nothing to Delete.\n";
            return "ok";
        }
        Node* currentSong = head;
        Node* PrevSong = NULL;
    
        do {
            if (currentSong->data == song) {
                if (PrevSong) {
                    PrevSong->next = currentSong->next;
                    currentSong->next->prev = PrevSong;
                }
                else {
                    head = currentSong->next;
                    head->prev = currentSong->prev;
                }
                delete currentSong;
                cout << SongName << "Deleted.\n";
                return "done";
            }
            PrevSong = currentSong;
            currentSong = currentSong->next;
        } while (currentSong != head);

        cout << SongName << " not found. Deletion failed.\n";
        return "not Ok";
    }
    bool Search(string Song) {
        Node* temp = head;
        while(temp != NULL) {
            if (temp->data == Song) {
                cout << "Song is in the Playlist.\n";
                Play('N');
                return true;
            }
            else {
                cout << "Song not found.\n";
                return false;
            }
            temp = temp->next;
        }
    }
    void ShowPlayList() {
        if (!head) {
            cout << "PlayList is empty.\n";
            return;
        }
        Node* currentSong = head;
        do {
            cout << currentSong->data << " ";
            currentSong = currentSong->next;
        } while (currentSong != head);
        cout << endl;
    }
    void Play(char mode) { 
        if (!head) {
            cout << "Playlist is empty, nothinng to play.\n";
            return;
        }
        Node* currentSong = head;
        if (mode == 'N') {
            do {
                cout << "Playing music:\n";
                PlaySound(TEXT(currentSong->data.c_str()), NULL, SND_FILENAME | SND_SYNC);
                cout << "Music over\n";
                currentSong = currentSong->next;
            } while (currentSong != head);
        }
        else if (mode == 'R') {
            while (true) {
                cout << "Playing music." << currentSong->data << "\n";
                PlaySound(TEXT(currentSong->data.c_str()), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                string input;
                cout << "Press 'q' to stop playback:";
                cin >> input;

                if (input == "q" || input == "Q") {
                    PlaySound(NULL, 0, 0);
                    cout << "Music over.\n ";
                    break;
                }
            }
        }
        else {
            cout << "Invalid mode. Use 'R' for repeat or 'N' for normal.\n";
        }
    }
};
int main()
{
    PlayList playlist;

    char choice;
    string song;

    do {
        system("cls"); // Clear the console screen

        cout << "***** Playlist *****\n";
        cout << "1. Add Songs\n";
        cout << "2. Delete Songs\n";
        cout << "3. Search Songs\n";
        cout << "4. Show Playlist\n";
        cout << "5. Play (Normal)\n";
        cout << "6. Play (Repeat)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            cout << "Enter the song name: ";
            cin >> song;
            playlist.Add_Songs(song);
            break;
        case '2':
            cout << "Enter the song name to delete: ";
            cin >> song;
            playlist.Delete_Songs(song);
            break;
        case '3':
            cout << "Enter the song name to search: ";
            cin >> song;
            playlist.Search(song);
            break;
        case '4':
            playlist.ShowPlayList();
            break;
        case '5':
            playlist.Play('N');
            break;
        case '6':
            playlist.Play('R');
            break;
        case '7':
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        // Pause to let the user read the output
        cout << "Press Enter to continue...";
        cin.ignore(); // Ignore the newline character in the input buffer
        cin.get();

    } while (choice != '7');
   
    
    return 0;
}

