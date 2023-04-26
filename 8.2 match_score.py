#Katelyn Choudhari
#Match Score in Two Strings
#A program that inputs two strings and
#outputs the match score to indicate
#how similar the words are
#If different lengths, outputs 0
#If same length, outputs the number of same
# characters in corresponding locations

#gets user input / two strings
str1 = input ("What is your first word? ")
str2 = input ("What is your second word? ")

#function determines input lengths
def match_score(str1,str2):
    var = len(str1)
    var1 = len(str2)
    
    #if the length of the first string is not
    #equal to the the length of the second string
    #output 0
    if len(str1) != len(str2):
        print ("0")

    #if the lengths of the strings match,
    #count the characters that are the same
    #and have the same position
    #outputs the count
    else:
        count = 0
        index = 0
        while index < (var):
            letter = str1[index]
            letter1 = str2[index]
            if letter == letter1:
                count = count + 1
            index = index + 1
        print ("Match score: ", count)

#calls the function
match_score(str1,str2)