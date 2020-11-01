#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string input, center, satellite;
    vector<string> all_objects;
    vector<vector<bool>> relation;

// STEP 1: Representing data in the form of a 2d vector

    while (getline(cin, input) && input != "\0"){
        center = input.substr(0, 3);
        satellite = input.substr(4, 3);
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
            relation.push_back(vector<bool>(all_objects.size() - 1, false));
            for (int i = 0; i < all_objects.size(); ++i){
                relation[i].push_back(false);
            }
        }
        if (index_s == -1){
            all_objects.push_back(satellite);
            index_s = all_objects.size() - 1;
            relation.push_back(vector<bool>(all_objects.size() - 1, false));
            for (int i = 0; i < all_objects.size(); ++i){
                relation[i].push_back(false);
            }
        }
        relation[index_c][index_s] = true;
    }

// STEP 2: Transitive Closure using Warshall's Algorithm

    for (int k = 0; k < relation.size(); ++k){
        for (int i = 0; i < relation.size(); ++i){
            for (int j = 0; j < relation.size(); ++j){
                relation[i][j] = relation[i][j] || (relation[i][k] && relation[k][j]);
            }
        }
    }

    int total_orbits = 0;
    for (int i = 0; i < relation.size(); ++i){
        for (int j = 0; j < relation.size(); ++j){
            if (relation[i][j]) ++total_orbits;
        }
    }

    cout << total_orbits << '\n';

    return 0;
}
