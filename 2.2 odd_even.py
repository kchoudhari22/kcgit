#Katelyn Choudhari
#A program that asks a user to guess if a number
#is odd or even and let's the user know if their
#guess was correct or not


import random
number=random.randint(1,256)

if number%2==0:
    ans=("even")

else:
    ans=("odd")

guess=input("I am thinking of a number. Is it even or odd? ")

if guess==ans:
        print ("Correct, The number was", number)

elif guess != ("even") and guess != ("odd"):
    print ("Error! Type only even or odd")
    
else:
    print ("Incorrect, The number was", number)
