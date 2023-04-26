#Katelyn Choudhari
#Character counter
#A program that takes input a character and a phrase
#and outputs the number of times the character appears
#in the phrase

#gets user input
str1 = input("Enter a character/letter and a word/phrase: ")

#counts user input starting at position 0
#and stores position 0 in the variable 
# #to search it in the rest of the string
var = str1.count(str1[0])

#subtracts 1 in order to not count the initial
#character in the count/position[0]
var1 = var - 1

#if the number of characters is only one in the string
if var1 == 1:
    print(var1, str1[0])

#if the number of characters is more than one in the string
else:
    print(var1, str1[0] + "'s")