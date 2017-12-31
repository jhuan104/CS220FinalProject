#include <iostream>
#include "Prompts.h"
#include "Game.h"
#include "ChessGame.h"
#include "KingGame.h"
#include "SpookyGame.h"

#include "Enumerations.h"
//for test#####
using std::cout;
using std::endl;
//#############

using std::cin;
using std::string;

// Game variant enumeration
//enum GameName {STANDARD_CHESS = 1, KING_OF_THE_HILL, SPOOKY_CHESS};

//(RANDY)
// Ask user which game they want to play
int collect_game_choice() {
  string game_choice;
  int game; 
  int game_choice_check = 1;

  while (game_choice_check) {
    Prompts::game_choice();
    cin >> game_choice;
    if (game_choice == "1") {
      cout << "regular chess selected, test message" << endl;
      game_choice_check = 0;
      game = STANDARD_CHESS;
    }
    else if (game_choice == "2") {
      cout << "king of the hill chess selected, test message" << endl;
      game_choice_check = 0;
      game = KING_OF_THE_HILL; 
    }
    else if (game_choice == "3") {
      cout << "spooooooooky chess selected, test message" << endl;
      game_choice_check = 0;
      game = SPOOKY_CHESS;
    }
  }
  return game; 
}



//(RANDY)
// Ask user whether to launch new game or load existing one
string determine_new_or_load() {
  string new_or_load;
  int new_or_load_check = 1; 

  while (new_or_load_check) {
    Prompts::new_or_load_choice();

    // Take in input and remove end line character in case we use getline next
    cin >> new_or_load;
    cin.get();
    
    if (new_or_load == "1") {
      cout << "new game selected, test message" << endl;
      new_or_load_check = 0;
      new_or_load = ""; 
    }
    else if (new_or_load == "2") {
      cout << "save game selected, test message" << endl;
      Prompts::load_game();
      new_or_load_check = 0;
      string load_file;
      cin >> load_file;
      cin.get();
      cout << "file: " << load_file << " selected, test message" << endl;
      new_or_load = load_file; 
    }

    // (Note) :: we should consider case when 3 is input.
    // go back to game_choice
  }
  return new_or_load; 
}

int main() {

  // Determine which game to play, and how to begin it
  int game_choice = collect_game_choice();
  string new_or_load_file = determine_new_or_load();

  // Set up the desired game
  Game *g = nullptr;
  if (game_choice == STANDARD_CHESS) {  //new standard chess
    if (new_or_load_file.empty()) {
      g = new ChessGame();
    }
    else {
      g = new ChessGame(new_or_load_file, game_choice);
    }
  }
  // uncomment once king of the hill chess and spooky chess are done 
  else if (game_choice == KING_OF_THE_HILL) {
    if (new_or_load_file.empty()) {
      g = new KingGame();
    }
    else {
      g = new KingGame(new_or_load_file, game_choice);
    }
  }

  else if(game_choice == SPOOKY_CHESS) {
    if (new_or_load_file.empty()) {
      g = new SpookyGame();
    }
    else {
      g = new SpookyGame(new_or_load_file, game_choice);
    }
  }
    
  // Begin play of the selected game!
  g->run(); 

  // Nothing else to do here in main, so clean up
  delete g;
  return 0;
}

