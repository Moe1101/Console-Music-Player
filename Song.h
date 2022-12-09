#include <string>
#include <iostream>
using namespace std;


struct Song
{
    //atributes
    string name;
    string artist;
    string path;
    bool favorite;
    Song* next;
    Song* previous;

    //constructer
    Song(string val1, string val2, string val3, bool val4) : name(val1), artist(val2), path(val3), favorite(val4), next(NULL), previous(NULL) {}

};