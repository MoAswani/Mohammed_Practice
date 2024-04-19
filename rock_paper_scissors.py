import random

"""Player1 is the computer
player2 is human player
"""

player1_options = ['rock', 'paper', 'scissors']
player1_choise = random.sample(player1_options, 1)


player2_choise = []
player2_input = input("Enter a choise('rock','paper','or scissors'): ")
if player2_input not in player1_options:
    print("Enter a valid option, or check spelling and try again.") 
else:
    player2_choise.append(player2_input)
    print("You entered ",player2_choise)
    print("The computer entered ", player1_choise)


if player1_choise==player2_choise:
    print("Draw")

elif player1_choise == ['rock'] and player2_choise == ['paper']:
    print("You win")

elif player1_choise == ['paper'] and player2_choise == ['scissors']:
    print("You win")

elif player1_choise == ['scissors'] and player2_choise == ['rock']:
    print("You win")

else:
    print("You lose")