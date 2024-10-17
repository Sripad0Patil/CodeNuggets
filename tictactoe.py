import tkinter # graphical user interface library

def set_title(row, column):
    global curr_player

    if(game_over):
        return

    if board[row][column]["text"] != "":
        return

    board[row][column]["text"]=curr_player

    if curr_player == playerO:
        curr_player = playerX
    else:
        curr_player = playerO
    
    label["text"] = curr_player+"'s turn"

    winner()

def winner():
    global turns, game_over
    turns += 1

    #horizontal
    for row in range(3):
        if (board[row][0]["text"] == board[row][1]["text"] == board[row][2]["text"]
            and board[row][0]["text"]!="" ):
            label.config(text=board[row][0]["text"]+" is the winner!", foreground=color_y)
            for column in range(3):
                board[row][column].config(foreground=color_y, background=color_lg)
            game_over = True
            return
        
    #vertical
    for column in range(3):
        if (board[0][column]["text"] == board[1][column]["text"] == board[2][column]["text"]
            and board[0][column]["text"]!="" ):
            label.config(text=board[0][column]["text"]+" is the winner!", foreground=color_y)
            for row in range(3):
                board[row][column].config(foreground=color_y, background=color_lg)
            game_over = True
            return
        
    #diagonal
    if (board[0][0]["text"]==board[1][1]["text"]==board[2][2]["text"]
        and board[0][0]["text"] != ""):
       label.config(text=board[0][0]["text"]+" is the winner!", foreground=color_y) 
       for i in range(3):
           board[i][i].config(foreground=color_y, background=color_lg)
       game_over=True
       return
    
    #anti-diagonal
    if (board[0][2]["text"]==board[1][1]["text"]==board[2][0]["text"]
        and board[0][2]["text"] != ""):
        label.config(text=board[0][2]["text"]+" is the winner!", foreground=color_y)
        board[0][2].config(foreground=color_y, background=color_lg)
        board[1][1].config(foreground=color_y, background=color_lg)
        board[2][0].config(foreground=color_y, background=color_lg)
        game_over
        return
    
    #tie
    if (turns==9):
        game_over=True
        label.config(text="Tie!", foreground=color_y)

def new_game():
    global turns, game_over

    turns = 0
    game_over = False
    label.config(text=curr_player+"'s turn", foreground="white")

    for row in range(3):
        for column in range(3):
            board[row][column].config(text="", foreground=color_b, background=color_g)


playerX = "X"
playerO = "O"
curr_player = playerX
board = [[0,0,0], 
         [0,0,0], 
         [0,0,0]]
color_b="#4584b6"
color_y="#ffde57"
color_g="#343434"
color_lg="#646464"

turns = 0
game_over=False

#win setup
window = tkinter.Tk()
window.title("Tic Tac Toe")
window.resizable(False, False)

frame=tkinter.Frame(window)
label=tkinter.Label(frame, text=curr_player+"'s turn", font=("consolas", 20), background=color_g, foreground="white")

label.grid(row=0, column=0, columnspan=3, sticky="we")
for row in range(3):
    for column in range(3):
        board[row][column]=tkinter.Button(frame, text="", font=("consolas", 50, "bold"),
                                          background=color_g, foreground=color_b, width=4, height=1, command=lambda row=row, 
                                          column=column: set_title(row, column))
        board[row][column].grid(row= row+1, column= column)

button = tkinter.Button(frame, text="restart", font=("consolas", 20), background=color_g,
                        foreground="white", command=new_game)
button.grid(row=4, column=0,columnspan=3, sticky="we")

frame.pack()

window.mainloop()