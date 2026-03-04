#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Song
{
    string title;
    string artist;
    double length;
};

struct Playlist
{
    string title;
    string artist;
    string genre;
    double length;
    vector<Song*> songList;
    void addSong( Song * song ) {
        songList.push_back( song );
        length += song->length;
    }
};

vector<Song> mySongs;
vector<Playlist> myPlaylists;
int main()
{
    // how to add a song into mySongs:

       // 1) create a song-object
    string title, artist, length;
    getline(cin, title);   // getline reads a whole line
    getline(cin, artist);
    getline(cin, length);
    Song song;
    song.title = title;
    song.artist = artist;
    song.length = stod(length);
      // 2) store your song-object
    mySongs.push_back( song );

    // how to add a song to a Playlist
    Playlist myPlaylist;
    myPlaylist.addSong( &song );   // uses the song object created above

    // how to show the song's data in a playlist:
    for (auto song : myPlaylist.songList)
    { 
      cout << "title:"
                  << song->title
                  << " artist:"
                  << song->artist
                  << " length: "
                  << song->length
                  <<endl;
    }
}