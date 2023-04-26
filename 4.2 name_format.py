#Katelyn Choudhari
#A program whose input is: firstName middleName lastName
#and whose output is: lastName, firstInitial.middleInitial
#If the input has the form: firstName lastName
#the output is: lastName, firstInitial.

#gets user input
name = input ("Enter first, middle and last name: ")

#counts the number of spaces in the string
space = name.count (" ")

#if there are two space, or three names, it splits them
#and outputs the last name, first initial and middle initial
if space == 2:
    first, middle, last = name.split()
    print (last.capitalize() + (", "), first[0].capitalize() + ("."), middle[0].capitalize() + ("."))

#if there is only one space, or two names, it splits them
#and outputs the last name and first initial
if space == 1:
    first, last = name.split()
    print (last.capitalize() + (", "), first[0].capitalize() + ("."))