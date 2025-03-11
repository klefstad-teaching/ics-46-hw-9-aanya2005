#include "ladder.h"
#include <iostream>
#include <set>
#include <vector>
#include <cassert>
// g++ -o ladder src/ladder_main.cpp src/ladder.cpp -std=c++20
using namespace std;



void test_verify_word_ladder() {
    set<string> word_list;

    load_words(word_list, "src/words.txt");
    assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    assert(generate_word_ladder("code", "data", word_list).size() == 6);
    assert(generate_word_ladder("work", "play", word_list).size() == 6);
    assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
    cout << "Done" << endl;
}

void my_test(){
    string start_word, end_word;
    set<string> word_list;

    load_words(word_list, "src/words.txt");
    cout << "Enter the start word: ";
    cin >> start_word;
    cout << "Enter the end word: ";
    cin >> end_word;


    vector<string> ladder = generate_word_ladder(start_word, end_word, word_list);

    if (ladder.empty()) {
        cout << "No word ladder found from " << start_word << " to " << end_word << "." << endl;
    } else {
        cout << "Shortest word ladder found: " << endl;
        print_word_ladder(ladder);
    }
}

int main() {
    test_verify_word_ladder();

    //my_test_word();
    
    return 0;
}
