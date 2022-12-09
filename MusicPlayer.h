#include "Song.h"


class MusicPlayer
{
public:

    //initializing the head and the tail of the music player
    Song* head, * tail;

    //constructer off the player 
    MusicPlayer() : head(NULL), tail(NULL) {}

     

     
    void addSongHead(Song x);
    void addSongTail(Song x);
    Song* Search(string x);
    int countSoungs();
    void displayallmysongs();
    void displayfavmysongs();
    void deletSong(Song x);
    void play(Song *x); 
    void editSongInfo(); 
    
     
    
};
