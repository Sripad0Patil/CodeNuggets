import random

print('Lets play stone, paper or scissors.')

def get_u_c():
    while True:
        u_c = input('\nEnter your choice (rock, paper, or scissors): ').lower()
        if u_c in ['rock', 'paper', 'scissors']:
            return u_c
        else:
            print('Enter a valid choice.')

def get_c_c():
    return random.choice(['rock', 'paper', 'scissors'])

def determine_winner(u_c, c_c):
    if u_c == c_c:
        return "It's a draw."
    elif (u_c == 'rock' and c_c == 'scissors') or (u_c == 'scissors' and c_c == 'paper') or (u_c == 'paper' and c_c == 'rock'):
        return "You win!"
    else:
        return "PC Wins!"

# Main game loop
while True:
    u_c = get_u_c()
    c_c = get_c_c()

    print(f"You chose:\t{u_c}.")
    print(f"PC chose :\t{c_c}.")

    result = determine_winner(u_c, c_c)
    print(result)

    play_again = input("\nDo you want to play again? (y/n): ").lower()
    if play_again != 'y':
        break