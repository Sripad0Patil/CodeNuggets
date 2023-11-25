print("Welcome to QuickQuizz")
g = input("Are you ready to play? (y/n): ")
score = 0;

if g.lower() == 'y':
    print()
    print('Your first question')

    print('\n1. Who is the founder of Python?')
    print('\na. Guido Van Rossum')
    print('b. Dennis Retchie')
    print('c. Charls white')
    print('d. William Ruto')

    ans = input('\nYour answer: ')
    if ans.lower() == 'a':
      score += 1;
      print('\nCorrect')
    else:
      print('\nWrong')

    print('\n2. Who is the father of c language?')
    print('\na. Dennis Retchie')
    print('b. karl Benz')
    print('c. Stefhen Curry')
    print('d. Robert Brown')

    ans = input('\nYour answer: ')
    if ans.lower() == 'a' :
      score += 1;
      print('\nCorrect')
    else:
      print('\nWrong')

    print('\n3. Who is the father of Automobils?')
    print('\na. J J thomson ')
    print('b. Emma Watson')
    print('c. R D junior')
    print('d. Karl Benz')

    ans = input('\nYour answer: ')
    if ans.lower() == 'd' :
      score += 1;
      print('\nCorrect')
    else:
      print('\nWrong')

    print('\n4. What is the color of water?')
    print('\na. Sky blue')
    print('b. Blue')
    print('c. White')
    print('d. Colorless')

    ans = input('\nYour answer: ')
    if ans.lower() == 'd' :
      score += 1;
      print('\nCorrect')
    else:
      print('\nWrong')

    print('\n5. Who invented the Bulb?')
    print('\na. Isaac Newton')
    print('b. Thomas Edison')
    print('c. Maxwell')
    print('d. Robert Tesla')

    ans = input('\nYour answer: ')
    if ans.lower() == 'b' :
      score += 1
      print('\nCorrect')    
    else:
      print('\nWrong')

    print(f'Your score is {score}/5');
else:
  print("\nOkay, maybe next time!")