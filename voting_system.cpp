#include <bits/stdc++.h>shre
using namespace std;

void displayCandidates(const vector<string>& candidates) {
    cout << "\n--- List of Candidates ---\n";
    for (size_t i = 0; i < candidates.size(); ++i) {
        cout << i + 1 << ". " << candidates[i] << "\n";
    }
    cout << "0. Exit voting\n";
}

void displayResults(const vector<string>& candidates, const vector<int>& votes) {
    cout << "\n--- Voting Results ---\n";
    int maxVotes = 0;
    for (int v : votes) if (v > maxVotes) maxVotes = v;

    for (size_t i = 0; i < candidates.size(); ++i) {
        cout << candidates[i] << " -> " << votes[i] << " votes\n";
    }

    cout << "\n Winner(s): ";
    bool first = true;
    for (size_t i = 0; i < candidates.size(); ++i) {
        if (votes[i] == maxVotes) {
            if (!first) cout << ", ";
            cout << candidates[i];
            first = false;
        }
    }
    cout << " winner\n";
}

int main() {
    vector<string> candidates = {"RAJ", "SURESH", "RAVI", "KARTHIK"};
    vector<int> votes(candidates.size(), 0);
    set<string> votedVoters;     
    string voterName;
    string token;              
    int choice;

    cout << "=== Secure Voting System ===\n";

    while (true) {
        cout << "\nEnter your name (or type 'exit' to finish voting): ";
        if (!(cin >> voterName)) {

            cout << "\nInput error. Exiting.\n";
            break;
        }

        if (voterName == "exit") {
            cout << "\nVoting session ended.\n";
            break;
        }

        if (votedVoters.find(voterName) != votedVoters.end()) {
            cout << "You have already voted, " << voterName << "! Cheating not allowed.\n";
            continue;
        }

        displayCandidates(candidates);

        cout << "Enter your choice (1-" << candidates.size() << "): ";
        if (!(cin >> token)) {
            cout << "Input error. Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        stringstream ss(token);
        char extra;
        if (!(ss >> choice) || (ss >> extra)) {

            cout << "Invalid input. Please enter a numeric choice (e.g. 1, 2, 3).\n";
            continue;
        }

        if (choice >= 1 && choice <= static_cast<int>(candidates.size())) {
            votes[choice - 1]++;
            votedVoters.insert(voterName);
            cout << "Thank you, " << voterName << "! You voted for " 
                 << candidates[choice - 1] << ".\n";
        } else {
            cout << "Invalid choice number. Please enter a number between 1 and "
                 << candidates.size() << ".\n";
        }
    }
    displayResults(candidates, votes);
    return 0;
}
