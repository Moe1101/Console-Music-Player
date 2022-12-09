#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#include"musicPlayer.cpp" 
using namespace std;
int main()
{

    MusicPlayer MainMP;
    
    cout << "************************ Welcome to your console Music Player ************************"<<endl<<endl;

    MainMP.displayallmysongs();
    cout << endl << endl<<endl<<endl;
    string option;

    cout << "Please choose one of the following options to Proceed :" << endl
        << "Type adh to add a new Song to the head of your playlist" << endl
        << "Type adt to add a new Song to the tail of your playlist" << endl
        << "Type del to delete  a song" << endl
        << "Type dis to view your playlist" << endl
        << "Type fav to view your favorites" << endl
        << "Tyoe mod to modify an existing song " << endl
        << "Type ply then enter that name of the song to play" << endl
        << "Type exx to exit console Music Player"<<endl<<endl;

    cout << "Enter your command here ->:"; cin >> option;
    cout << endl << endl;

    while(option !="exx"){
     
        if(option=="adh") {
            string name, artist, path;
            char favc;
            bool fav;
            option = "55578555";

            cout << "Adding song to head" << endl;
            cout << "First Please Enter the Songs name :"; cin >> name;
            cout << "Now lets add the name of the artisit :"; cin >> artist;
            cout << "Great ! now carefully copy and paste the path of the song here->:"; cin >> path;
            cout << "If you want to add this song to your favorites enter y else enter any letter  :"; cin >> favc;
            cout << "Song added succesfully!!!"<<endl;
            cout << endl << endl;
            if (favc == 'y' || favc == 'Y')
                fav = true;

            else
                fav = false;

            Song song(name, artist, path, fav);
            MainMP.addSongHead(song);
        }

        if (option == "adt") {
            string name, artist, path;
            char favc;
            bool fav;
            option = "55578555";
            cout << "Adding song to tail" << endl;
            cout << "First Please Enter the Songs name :"; cin >> name;
            cout << "Now lets add the name of the artisit :"; cin >> artist;
            cout << "Great ! now carefully copy and paste the path of the song here->:"; cin >> path;
            cout << "If you want to add this song to your favorites enter y else enter any letter :"; cin >> favc;
            cout << "Song added succesfully!!!"<<endl;
            cout << endl << endl;
            if (favc == 'y' || favc == 'Y')
                fav = true;

            else
                fav = false;

            Song song(name, artist, path, fav);
            MainMP.addSongTail(song);
        }

        if (option == "del") {
            string name;
            cout << "Enter the name of the song you want to delete->:"; cin >> name;
             
            Song found = *MainMP.Search(name);
            MainMP.deletSong(found);

        }

        if (option == "dis") {
            MainMP.displayallmysongs();
        }

        if (option == "ply") {
            string name;
            option = "55578555";
            cout << "Please Enter the name of the song you wanna play here:"; cin >> name;
            cout << endl << endl;
            Song found = *MainMP.Search(name);
            cout << "Currently Playing :" << found.name << " by " << found.artist;
            MainMP.play(&found); 
            
        }

        if (option == "fav") {
            MainMP.displayfavmysongs();
        }
         
        if (option == "mod") {
            MainMP.editSongInfo();
        }

        if (option != "adh" && option != "adt" && option != "del" && option != "ply" && option != "fav" && option != "dis" && option!="mod" && option != "55578555") {
            cout << "Invalid comand entered! Please note that this app is case sensitve" << endl
            << "Please try entering another command :"; cin >> option;
            cout << endl << endl;
        }
        
        else {
            cout << "Please choose one of the following options to Proceed :" << endl
                << "Type adh to add a new Song to the head of your playlist" << endl
                << "Type adt to add a new Song to the tail of your playlist" << endl
                << "Type del to delete  a song" << endl
                << "Type dis to view your playlist" << endl
                << "Type fav to view your favorites" << endl
                << "Tyoe mod to modify an existing song " << endl
                << "Type ply then enter that name of the song to play" << endl
                << "Type exx to exit console Music Player" << endl << endl;

            cout << "Enter your command here ->:"; cin >> option;
            cout << endl << endl;
        }
        
    }


    return 0;
     
}

