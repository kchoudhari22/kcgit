#Katelyn Choudhari

#A program that reads a file with a list of
#words separated by commas and outputs the
#words and their frequencies w/o duplicates

import csv

#gets file name from user
csv_file = input("Enter the file name: ")

#opens and reads user file
with open(csv_file,'r') as f:
    csv_file = csv.reader(f)
    
    #sets count to zero
    count = 0
    
    #creates empty dictionary
    dict = {}

    # loops through each row in the file
    for x in csv_file:
        #loops through each word in the row
        for i in x:
            #removes whitespace
            i = i.strip()
            #adds word to dictionary if
            #not already in dictionary
            #and increases count by 1
            if i not in dict:
                dict[i] = 1
            #if word is in dictionary
            #increases count only
            else:
                dict[i] += 1

#prints key/word and value.word frequency
for i, count in dict.items():
    print(i, "-", count)