# Build the HangmanGame using Python.

# Author: Mohit Khedkar.

import random

player = input("Enter Player name: ")

print(f" welcome {player} lets play Hangman")

word_list = ['tony','python','stark']


word = random.choice(word_list)
print(word)

guesses = ""
turns = 6

while turns > 0:
    flag = 1
    for char in word:

        if char in guesses:
            print(char , end="")
        else:
            print("_ ", end="")
            flag = 0

    if flag == 1:
        print("You won")
        print("The word is" , word)
        break

    guess = input("Guess a word/character: ")

    guesses += guess

    if guess not in word:
        turns -= 1
        print("Wrong")
        print(f"Only {turns} turns left")

        if turns == 0:
            print('You loose')