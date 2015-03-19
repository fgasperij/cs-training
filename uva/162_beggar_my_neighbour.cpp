#include <deque>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

void switch_turn(int &turn);
bool is_face(char card);
void print_deque(deque<char> d, string name);
int cover_value(char card);
void concatenate(deque<char> &first, deque<char> &second);

int main() {

  while ((char)cin.peek() != '#') {
    string input_card;
    deque<char> hands[2];
    for(int i = 1; i <= 52; ++i) {
      cin >> input_card;
      hands[i % 2].push_front(input_card[1]);
    }

    int turn = 1;
    int last_face;
    int cover_count = 0;
    deque<char> deck;
    char card;
    while (!hands[turn].empty()) {
      card = hands[turn].front();
      hands[turn].pop_front();
      deck.push_back(card);

      if (is_face(card)) {
        last_face = turn;
        switch_turn(turn);
        cover_count = cover_value(card);
      } else {
        if (cover_count) {
          --cover_count;
          if (cover_count == 0) {
            turn = last_face;
            concatenate(hands[turn], deck);
          }
        } else {
          switch_turn(turn);
        }
      }
    }

    switch_turn(turn);
    int winner = turn+1;
    cout << winner << setw(3) << right << hands[turn].size();
    cout << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  return 0;
}

void print_deque(deque<char> d, string name) {
  deque<char>::iterator it = d.begin();
  cout << name << ": ";
  while (it != d.end()) {
    cout << *it << " ";
    ++it;
  }
  cout << endl;
}

void switch_turn(int &turn) {
  turn = (turn + 1) % 2;
}

bool is_face(char card) {
  return card == 'A' || card == 'K' || card == 'Q' || card == 'J';
}

int cover_value(char card) {
  if (card == 'A') {
    return 4;
  }
  if (card == 'K') {
    return 3;
  }
  if (card == 'Q') {
    return 2;
  }
  if (card == 'J') {
    return 1;
  }
  return 0;
}

void concatenate(deque<char> &first, deque<char> &second) {
  while (!second.empty()) {
    first.push_back(second.front());
    second.pop_front();
  }
}
