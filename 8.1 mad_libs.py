#Katelyn Choudhari
#Mad Libs program
#A program that takes a string and an integer
#and outputs a sentence using the input values
#and repeats until the input is quit
  
#gets user input; string and an integer
word, num = input ("Enter a word and a number: ").split()

#outputs mad lib sentences
#ends the loop if word = quit
while word != "quit":
    
    #gets user input for second set of input values if the first set is not equal to quit
    word1, num1 = input ("Enter a word and a number: ").split()
    
    #outputs the sentence with the input values
    print ("Eating", num, word, "a day keeps you happy and healthy.")
    print ("Eating", num1, word1, "a day keeps you happy and healthy.")
   
   #prints each statement only once so it does not infinite loop
    word = "quit"

    #gets user input again / repeats
    word, num = input ("Enter a word and a number: ").split()