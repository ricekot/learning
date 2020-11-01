#include <iostream>
#include <vector>
#include <string>

#define INF 999999999

using namespace std;

int main(){
    string input;
    vector<string> all_objects;
    vector<vector<int>> relation;

// STEP 1: Representing data in the form of a 2d vector

    while (getline(cin, input) && input != "\0"){
        string center, satellite;
        for (int i = 0; input[i] != ')'; ++i){
            center += input[i];
        }
        satellite = input.substr(center.length() + 1, input.length() - center.length() - 1);
        int index_c = -1, index_s = -1;
        for (int i = 0; i < all_objects.size(); ++i){
            if (all_objects[i] == center){
                index_c = i;
            }
            else if (all_objects[i] == satellite){
                index_s = i;
            }
        }
        if (index_c == -1) {
            all_objects.push_back(center);
            index_c = all_objects.size() - 1;
            relation.push_back(vector<int>(all_objects.size() - 1, INF));
            for (int i = 0; i < all_objects.size(); ++i){
                relation[i].push_back(INF);
            }
        }
        if (index_s == -1){
            all_objects.push_back(satellite);
            index_s = all_objects.size() - 1;
            relation.push_back(vector<int>(all_objects.size() - 1, INF));
            for (int i = 0; i < all_objects.size(); ++i){
                relation[i].push_back(INF);
            }
        }
        relation[index_c][index_s] = relation[index_s][index_c] = 1;
    }

// STEP 2: Minimum Distance using the Floyd-Warshall Algorithm

    for (int i = 0; i < relation.size(); ++i){
        for (int j = 0; j < relation.size(); ++j){
            if (i == j) relation[i][j] = 0;
        }
    }    

    for (int k = 0; k < relation.size(); ++k){
        for (int i = 0; i < relation.size(); ++i){
            for (int j = 0; j < relation.size(); ++j){
                if (relation[i][j] > relation[i][k] + relation[k][j])
                    relation[i][j] = relation[i][k] + relation[k][j];                    
            }
        }
    }

    int YOU, SAN;
    for (int i = 0; i < all_objects.size(); ++i){
        if (all_objects[i] == "YOU") YOU = i;
        else if (all_objects[i] == "SAN") SAN = i;
    }

    cout << relation[YOU][SAN] - 2 << '\n';

    return 0;
}
