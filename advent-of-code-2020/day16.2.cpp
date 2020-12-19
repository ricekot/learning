#include <bits/stdc++.h>

using namespace std;

int main(){
    ifstream list("input/day16.txt");
    string line;
    vector<bool> valid(1000, false);
    vector<int> my_ticket;
    vector<vector<int>> nearby_tickets;
    vector<pair<pair<int, int>, pair<int, int>>> limits;
    while (getline(list, line)){
        if (line.find("or") != string::npos){
            pair<pair<int, int>, pair<int, int>> limit;
            limit.first.first = stoi(line.substr(line.find(": ") + 2));
            limit.first.second = stoi(line.substr(line.find("-") + 1));
            limit.second.first = stoi(line.substr(line.find(" or ") + 3));
            limit.second.second = stoi(line.substr(line.find('-', line.find(" or ")) + 1));
            limits.push_back(limit);
        } else if (line == "your ticket:") {
            getline(list, line);
            string num; istringstream iss(line);
            while(getline(iss, num, ',')) 
                my_ticket.push_back(stoi(num));
        } else if (line == "nearby tickets:") continue;
        else {
            string num; istringstream iss(line);
            vector<int> fields;
            while(getline(iss, num, ',')) {
                int val = stoi(num);
                bool valid = false;
                for (auto limit : limits){
                    if (val >= limit.first.first && val <= limit.first.second
                    || val >= limit.second.first && val <= limit.second.second){
                        // val satisfies at least one field's limits
                        valid = true;
                        break;
                    }
                }
                if (valid) fields.push_back(val);
            }
            if (fields.size() == limits.size()){
                nearby_tickets.push_back(fields);
            }
        }
    }

    map <int, vector<int>> field_to_columns;
    for (int k = 0; k < limits.size(); ++k){
        auto limit = limits[k];
        for (int i = 0; i < nearby_tickets[0].size(); ++i){
            bool valid = true;
            for (int j = 0; j < nearby_tickets.size(); ++j){
                int val = nearby_tickets[j][i];
                if (!(val >= limit.first.first && val <= limit.first.second
                || val >= limit.second.first && val <= limit.second.second)){
                    valid = false;
                    break;
                }
            }
            if (valid) field_to_columns[k].push_back(i);
        }
    }

    // reduce field_to_columns and store in fc
    map<int, int> fc;
    for (int i = 0; i < field_to_columns.size(); ++i){
        if (field_to_columns[i].size() == 1){
            fc[i] = field_to_columns[i][0];
            for (int j = 0; j < field_to_columns.size(); ++j){
                field_to_columns[j].erase(remove(field_to_columns[j].begin(), field_to_columns[j].end(), fc[i]), field_to_columns[j].end());
            }
            i = -1;
        }
    }

    long long product = 1;
    for (pair<int, int> kv : fc){
        if (kv.first < 6){
            // the first six fields start with 'departure'
            product *= my_ticket[kv.second];
        }
    }
    cout << product << '\n';
    
    return 0;
}
