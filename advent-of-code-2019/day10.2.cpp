#include <iostream>
#include <string>
#include <vector>

using namespace std;

int asteroids_detected(vector<vector<bool>> &asteroid, int x, int y);
int count = 1;

int main(){
    string line;
    vector<vector<bool>> asteroid;
    while(getline(cin, line) && line != "\0"){
        asteroid.push_back(vector<bool>(0));
        for (int j = 0; j < line.size(); ++j){
            if (line[j] == '#') asteroid[asteroid.size() - 1].push_back(true);
            else asteroid[asteroid.size() - 1].push_back(false);
        }
    }

    int result = -1, x, y;
    for (int i = 0;i < 5; ++i){
        cout << asteroids_detected(asteroid, 20, 20) << '\n';
    }
    
    // cout << "Best is " << y << ',' << x << " with " << result << " other asteroids detected.\n";
    return 0;
}

int asteroids_detected(vector<vector<bool>> &asteroid, int x, int y){
    vector<vector<int>> visible(asteroid.size(), vector<int>(asteroid[0].size(), 0));
    for (int i = 0; i < asteroid.size(); ++i){
        for (int j = 0; j < asteroid[0].size(); ++j){
            // counting all visible asteroids lying on the line connecting (i, j) and (x, y)
            if (i == x && j == y) continue;
            if (asteroid[i][j] == true){
                if (i == x){
                    for (int l = y + 1; l < asteroid[0].size(); ++l){
                        if (asteroid[x][l]){
                            asteroid[x][l] = false;
                            visible[x][l] = count++;
                            break;
                        }
                    }
                    for (int l = y - 1; l >= 0; --l){
                        if (asteroid[x][l]){
                            asteroid[x][l] = false;
                            visible[x][l] = count++;
                            break;
                        }
                    }
                }
                else {
                    double slope = (double)(j - y) / (i - x);
                    double l;
                    for (int k = x + 1; k < asteroid.size() && (l = slope * (k - x) + y) < asteroid[0].size() && l >= 0; ++k){
                        if (l != (int)l) continue;
                        else if (asteroid[k][l]){
                            asteroid[k][l] = false;
                            visible[k][l] = count++;
                            break;
                        }
                    }
                    for (int k = x - 1; k >= 0 && (l = slope * (k - x) + y) < asteroid[0].size() && l >= 0; --k){
                        if (l != (int)l) continue;
                        else if (asteroid[k][l]){
                            asteroid[k][l] = false;
                            visible[k][l] = count++;
                            break;
                        }
                    }
                }
            }
        }
    }
    int count_visible = 0;
    for (int i = 0; i < visible.size(); ++i){
        for (int j = 0; j < visible[0].size(); ++j){
            if (visible[i][j] == 200) return i*100 + j;
        }
    }
    return -1;
}