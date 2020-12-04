#include <bits/stdc++.h>

using namespace std;

bool isValid(map<string, string>);

int main(){
    ifstream list("input/day4.txt");
    string line;
    int valid = 0;
    while (getline(list, line)){
        map<string, string> fields;
        istringstream iss(line);
        string field;
        while (iss >> field){ 
            fields[field.substr(0, field.find(':'))] = field.substr(field.find(':')+1);
        }
        if (isValid(fields)) ++valid;
    }
    cout << valid << '\n';
    return 0;
}

bool isValid(map<string, string> m){
    if (m.size() < 7 || (m.size() == 7 && m.count("cid"))){ 
        return false;
    }
    if (m.count("byr")) {
        int yr = stoi(m["byr"]);
        if (yr < 1920 || yr > 2002){
            return false;
        }
    }
    if (m.count("iyr")) {
        int yr = stoi(m["iyr"]);
        if (yr < 2010 || yr > 2020){
            return false;
        }
    }
    if (m.count("eyr")) {
        int yr = stoi(m["eyr"]);
        if (yr < 2020 || yr > 2030){
            return false;
        }
    }
    if (m.count("hgt")) {
        int hgt = stoi(m["hgt"]);
        if (m["hgt"].find('c') != -1) {
            if (hgt < 150 || hgt > 193){
                return false;
            }
        }
        else if (m["hgt"].find('i') != -1) {
            if (hgt < 59 || hgt > 76){
                return false;
            }
        }
        else return false;
    }
    if (m.count("hcl")) {
        string hcl = m["hcl"];
        if (hcl[0] != '#' || hcl.length() != 7)
            return false;
        hcl = hcl.substr(1);
        for (char c: hcl) 
            if (!isxdigit(c))
                return false;
    }
    if (m.count("ecl")) {
        string ecl = m["ecl"];
        if (ecl != "amb" && ecl != "blu" && ecl != "brn" && ecl != "gry" && ecl != "grn" && ecl != "hzl" && ecl != "oth")
            return false;
    }
    if (m.count("pid")) {
        string pid = m["pid"];
        if (pid.length() != 9)
            return false;
        for (char c: pid) 
            if (!isdigit(c))
                return false;
    }
    return true;
}
