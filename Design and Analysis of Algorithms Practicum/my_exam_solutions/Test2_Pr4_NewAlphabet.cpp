#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <set>

using namespace std;

typedef struct edge_ {
    char to;
    char from;
} edge_t;

//string dict[] = { "tqq", "qtiu", "qtiq", "iqt", "iqu" };

int main()
{
    int N;string inp;    
    cin>>N;
    string dict[N];
    for(int i=0;i<N;i++){
        cin>>dict[i];
        
    }

  
//    std::copy( dict1.begin(), dict1.end(), dict);

    map<char,edge_t> verts;
    set<char> vertSet;
    int num_words = sizeof(dict) / sizeof(string);



    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < dict[i].size(); j++) {
            vertSet.insert(dict[i][j]);
        }
    }


    int i = 0;
    for (set<char>::iterator itr = vertSet.begin(); vertSet.end() != itr; ++itr, i++) {
        verts[*itr].from = 0;
        verts[*itr].to = 0;
    }


    for (int i = 0; i < num_words - 1; i++) {
        string& str1 = dict[i];
        string& str2 = dict[i + 1];
        const char* c1 = str1.c_str();
        const char* c2 = str2.c_str();
        while (*c1 == *c2) {
            c1++; c2++;
        }

        if (verts[*c2].from != 0) {
            verts[verts[*c2].from].to = *c1;
        }
        verts[*c1].to = *c2;
        verts[*c2].from = *c1;
    }


    char firstLetter;
    for (auto itr = vertSet.begin(); itr != vertSet.end(); ++itr) {
        if (verts[*itr].from == 0) {
            firstLetter = *itr;
            break;
        }
    }

    i = 0;
    while (firstLetter) {
        if (i++ == vertSet.size() - 1)
        {
           cout << firstLetter << endl;
        }
        else
        {
            cout << firstLetter << " ";

        }
        firstLetter = verts[firstLetter].to;

    }
}