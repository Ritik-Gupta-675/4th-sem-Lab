#include <iostream>
using namespace std;

#define MAX_STATES 10
#define MAX_SYMBOLS 10
#define MAX_TRANSITION 10

void take_input(int &num_states, int &num_symbols, bool final_states[], int transition_count[MAX_STATES][MAX_SYMBOLS], int transitions[MAX_STATES][MAX_SYMBOLS][MAX_TRANSITION]) {
    cout << "Enter the number of states: ";
    cin >> num_states;

    cout << "Enter the number of input symbols: ";
    cin >> num_symbols;

    // Initialize the arrays
    for (int i = 0; i < MAX_STATES; i++) {
        final_states[i] = false;
        for (int j = 0; j < MAX_SYMBOLS; j++) {
            transition_count[i][j] = 0;
            for (int k = 0; k < MAX_TRANSITION; k++) {
                transitions[i][j][k] = -1;
            }
        }
    }

    // Take transition input for each state and symbol
    for (int state = 0; state < num_states; state++) {
        for (int symbol = 0; symbol < num_symbols; symbol++) {
            cout << "Enter number of transitions for state " << state << " and symbol " << symbol << ": ";
            int count;
            cin >> count;
            transition_count[state][symbol] = count;

            cout << "Enter " << count << " transition states: ";
            for (int j = 0; j < count; j++) {
                cin >> transitions[state][symbol][j];
            }
        }
    }

    // Take input for final states
    cout << "Enter the number of final states: ";
    int final_count;
    cin >> final_count;

    cout << "Enter final state numbers: ";
    for (int i = 0; i < final_count; i++) {
        int state;
        cin >> state;
        final_states[state] = true;
    }
}

int main() {
    int num_states, num_symbols;
    bool final_states[MAX_STATES];
    int transition_count[MAX_STATES][MAX_SYMBOLS];
    int transitions[MAX_STATES][MAX_SYMBOLS][MAX_TRANSITION];

    take_input(num_states, num_symbols, final_states, transition_count, transitions);

    return 0;
}