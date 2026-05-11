#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;
struct compcuv {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second; // b are prioritate fata de a 
    }
};
int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "eroare la deschiderea fisierului" << endl;
        return 1;
    }
    string phrase;
    getline(file, phrase);
    file.close();
    for (char& c : phrase) {
        c = tolower(c);
    }
    map<string, int> word_counts;
    string separators = " ,?!.";
    size_t start = phrase.find_first_not_of(separators);
    while (start != string::npos) {
        size_t end = phrase.find_first_of(separators, start);
        string word = phrase.substr(start, end - start);
        word_counts[word]++;
        if (end == string::npos) {
            break;
        }
        start = phrase.find_first_not_of(separators, end);
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, compcuv> pq;
    map<string, int>::iterator it;
    for (it = word_counts.begin(); it != word_counts.end(); it++) {
        pq.push(make_pair(it->first, it->second));
    }
    while (!pq.empty()) {
        pair<string, int> top_element = pq.top();
        cout << top_element.first << " => " << top_element.second << endl;
        pq.pop();
    }
    return 0;
}