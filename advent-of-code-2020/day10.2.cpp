#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> graph;
int final_jolts;

void traverse(int key, long long &count);

int main(){
    ifstream list("input/day10.txt");
    string line;
    vector<int> arr;
    while (getline(list, line)){
        arr.push_back(stoi(line));
    }
    arr.push_back(0);
    final_jolts = *max_element(arr.begin(), arr.end()) + 3;
    arr.push_back(final_jolts);
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); ++i){
        for(int j = i + 1; j < arr.size() && arr[j] - arr[i] <= 3; ++j){
            graph[arr[i]].push_back(arr[j]);
        }
    }
    long long count = 0;
    traverse(0, count);
    cout << count << '\n';
    return 0;
}

map<int, long long> cache;
void traverse(int key, long long &count){
    for (int value: graph[key]){
        if (cache.count(value)){
            count += cache[value];
            continue;
        }
        if (value == final_jolts) {
            ++count;
            continue;
        }
        long long previous_count = count;
        traverse(value, count);
        cache[value] = count - previous_count;
    }
}
