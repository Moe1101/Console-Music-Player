    #include "MusicPLayer.h"
    #pragma comment(lib, "winmm.lib")
    #include <Windows.h>

    
//adds a node to the head of the linked list (O=1)
    void MusicPlayer::addSongHead(Song x) {

        Song* current = new Song(x);
        Song* temporary = head;
        if (head == NULL) {
            head = current;
            tail = current;
        }
        else {
            current->next = head;
            head = current;
            current->next->previous = current;
        }
    }


    
//adds a node to the tail of the linked list (O=1)
    void MusicPlayer::addSongTail(Song x) {
        Song* current = new Song(x);
        if (head == NULL) {
            head = current;
            tail = current;
            return;
        }
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = current;
        current->previous = tail;
        return;
    }


    
//searches for a node in the linked list by its name (O=n)
    Song* MusicPlayer::Search(string x) {
        Song* current = head;
        while (current != NULL) {
            if (current->name == x)
                return current;
            current = current->next;
        }
        cout << "There isn't a song of such a name :(";
        return NULL;
    }

 

 //counts the nodes in the linked list 
    int MusicPlayer::countSoungs() {
        Song* temp = head;
        int i = 0;
        while (temp != NULL) {
            i++;
            temp = temp->next;
        }
        return i;
    }


//displays all the nodes in the linked list
    void  MusicPlayer::displayallmysongs() {
        if (countSoungs() == 0) {
            cout << "Your playlist is empty , add songs and start Playing!";
        }
        else{
            Song* current = head;
            int i = 1;
            int n = countSoungs();
            while (i <= n) {
                cout << i << "-" << current->name << " By :" << current->artist << endl;
                current = current->next;
                i++;
            }
            cout << endl << endl;
        }
    }


//deletes a song from the linked list (O=n) 
    void MusicPlayer::deletSong(Song x) {
        Song* find = Search(x.name);
        Song* current = head;

        if (current == find) {
            head = current->next;
        }

        else {
            while (find != NULL) {
                if (current->next == find) {
                    current->next = find->next;
                    find->next->previous = current;
                    delete find;
                    return;
                }
                current = current->next;
            }
        }
    } 


//Plays a song and then gives the option to either 
//play the next song or the previous one or exit playing
    void MusicPlayer::play(Song *x) {

        PlaySound((x->path).c_str(), NULL, SND_FILENAME | SND_SYNC);
        cout << "Currently Playing " << x->name << " by " << x->artist << endl << endl;
        char opt;
        cout << "Type; n to play Next Song" << endl
            << "p to play previous song " << endl
            << "or type x to exit" << endl << endl;
        cout << "Enter desired command ->:";cin >> opt;

        while (opt!='x') {
            

            if(opt =='n'|| opt == 'N'){

                if (x->next != NULL) {
                    x = x->next;
                    cout << "Currently Playing " << x->name << " by " << x->artist << endl << endl;
                    PlaySound((x->path).c_str(), NULL, SND_FILENAME | SND_SYNC);
                    
                }

                else
                    cout << "Playlist Ended !";
            }

            if (opt == 'p' || opt == 'P') {
                if (x == head)
                    cout << "You already played the first song of the playlist !";
                else {
                    x = x->previous;
                    cout << "Currently Playing " << x->name << " by " << x->artist << endl << endl;
                    PlaySound((x->path).c_str(), NULL, SND_FILENAME | SND_SYNC);
                    
                }
            }

            if (opt != 'p' && opt != 'P' && opt != 'n' && opt != 'N' && opt != 'x') {
                cout << "Invalid command entered , please enter  a valid one to proceed "; cin >> opt;
            }

            else {
                cout << "Type; n to play Next Song" << endl
                    << "p to play previous song " << endl
                    << "or type x to exit" << endl << endl;
                cout << "Enter desired command ->:"; cin >> opt;
            }
        }
    }

  
//only displays favorite songs
    void MusicPlayer::displayfavmysongs() {

        if (countSoungs() == 0) {
            cout << "Your playlist is empty , add songs and start Playing!";
            cout << endl << endl << endl;
        }

        else {
            Song* current = head;
            int i = 1;
            int n = countSoungs();
            cout << "Favourites PlayList!" << endl;
            while (i <= n) {
                if (current->favorite == true) {
                    cout << i << "-" << current->name << " By :" << current->artist << endl<<endl;
                    current = current->next;
                }
                i++;
            
            }
            cout << endl<<endl<<endl;
        }
    }

 
//seraches for a song and changes its info
    void MusicPlayer::editSongInfo() {
        string name;
        int opt;  
        cout << "Enter the name of the song you want to edit :"; cin >> name;
        Song *found = Search(name);
         

        if(found!=NULL){
            cout << "What would you like to modify?" << endl
                << "1-Song name " << endl
                << "2-Artist Name " << endl
                << "3-Song path" << endl
                << "4-Add or remove from favorites" << endl << endl
                <<"Enter the number that corresponds to the modification you'd like to do "; cin >> opt;
            cout << endl;

            if (opt == 1) {
                string newName;
                cout << "Enter new name   :"; cin >> newName;
                found->name = newName;
                cout << "Songs name changed succesflly!" << endl << endl;
            }

            if (opt == 2) {
                string newName;
                cout << "Enter new artist :"; cin >> newName;
                found->artist = newName;
                cout << "Artist changed succesflly!" << endl << endl;
            }

            if (opt == 3) {
                string newName;
                cout << "Carefully Enter new path->:"; cin >> newName;
                found->path = newName;
                cout << "Songs path changed succesflly!" << endl << endl;
            }

            if (opt == 4) {
                
                if (found->favorite == true) {
                    found->favorite = false;
                    cout << "Song removed from favorites !" << endl << endl;
                }

                else  {
                    found->favorite = true;
                    cout << "Song Added to favorites !"<<endl<<endl;
                }
            }

            
            else {
                cout << "The song you want to modify was not found!";
            }

        }
    }