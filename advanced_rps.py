from random import choice

def get_user_choise():
    while True:
        user_choise = input("Enter a choise ('rock', 'paper', or 'scissors): ").lower()
        if user_choise in ['rock','paper', 'scissors']:
            return user_choise
        else:
            print("Invalid choise, check spelling and try again")

def get_computer_choise():
    computer_choise = choice(['rock','paper','scissors'])
    return computer_choise

def get_winner(user_choise, computer_choise):
    if user_choise == computer_choise:
        return "It's a draw"

    elif(user_choise == 'rock' and computer_choise == 'scissors') or \
        (user_choise == 'paper' and computer_choise == 'rock') or \
        (user_choise == 'scissors' and computer_choise == 'paper'):
        return "You win"
    
    else:
        return "You lose"

def play_game():
    user_choise = get_user_choise()
    computer_choise = get_computer_choise()
    print(f"You chose {user_choise}")
    print(f"The computer chose {computer_choise}")
    print(get_winner(user_choise, computer_choise))

while True:
    play_game()
    response = input("Do you want to play again? (y/n): ").lower()
    if response != 'y':
        print("Thank you for playing.")
        break
