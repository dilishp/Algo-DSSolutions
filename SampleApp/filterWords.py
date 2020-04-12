#HangMan Guess Game
import random

print('Welcome to HangMan')
words = ['EVAPORATE','SUNLIGHT','CONDENSATION','TRAVEL']
wordGiven  =  words[random.randint(0,3)]
incorrectGuessCount = 0
wordLength = 0
guessedWord = ['_'] * len(wordGiven)
while wordLength < len(wordGiven) and (incorrectGuessCount < 6):
    letter = input('Guess your letter : ')
    if letter in guessedWord:
        print('letter already guessed')
        pass
    if letter not in wordGiven:
        incorrectGuessCount = incorrectGuessCount + 1
    for index in range(0,len(wordGiven)):
        if wordGiven[index] is letter:
            guessedWord[index] = letter
            wordLength = wordLength + 1
    string = ''
    for char in guessedWord:
        string += char + ' '
    print(string)

if(incorrectGuessCount >= 6):
    print('Sorry the number of incorrect Guess is more')
else:
    print('You Won!!')


