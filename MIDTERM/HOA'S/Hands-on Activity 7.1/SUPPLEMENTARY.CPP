#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int pos = i;
        int smallest = arr[i];

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < smallest) {
                smallest = arr[j];
                pos = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

int main() {
    srand(time(0));

    string candidates[5] = {
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustin",
        "Deja Jayla Banaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro"
    };

    int votes[100];
    int voteCounts[6] = {0};

    for (int i = 0; i < 100; i++) {
        votes[i] = rand() % 5 + 1;
    }

    selectionSort(votes, 100);

    cout << "Sorted Array of Votes:" << endl;
    for (int i = 0; i < 100; i++) {
        cout << votes[i];
        if (i < 99) {
            cout << ", ";
        }
    }
    cout << endl << endl;

    for (int i = 0; i < 100; i++) {
        voteCounts[votes[i]]++;
    }

    int maxVotes = voteCounts[1];
    int winner = 1;

    cout << "Vote Counts:" << endl;
    for (int c = 1; c <= 5; c++) {
        cout << "Candidate " << c << " (" << candidates[c - 1] << "): "
             << voteCounts[c] << " votes" << endl;

        if (voteCounts[c] > maxVotes) {
            maxVotes = voteCounts[c];
            winner = c;
        }
    }

    cout << endl;
    cout << "Winner: Candidate " << winner << " - "
         << candidates[winner - 1] << " with " << maxVotes << " votes!" << endl;

    return 0;
}