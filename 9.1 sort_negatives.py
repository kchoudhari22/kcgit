#Katelyn Choudhari
#A program that gets values from a
#user and outputs negative values
#in descending order

#gets user input / must be separated by spaces
list = (input("Enter a list of random numbers that includes positive and negative values: "))

#splits the list by spaces into individual values
list1 = (list.split(" "))

#gets the length of the list
list2 = (len(list1))

#gets new list to append to
list3 = []

#function converts string input values into
#integers and appends to a new list
def convert_list (w):
    list4 = []
    for n in w:
        list4.append(int(n))
    return (list4)

#function removes positive values in the list
def remove_positives(x):
    for n in x:
        if n < 0:
            list3.append(int(n))
    return (list3)

#calls function to convert
#list values to intergers
a = convert_list(list1)

#calls function to remove
#positive values from the list
b = remove_positives(a)

#calls function to sort
#list values in descending order
b.sort(reverse=True)

#outputs / prints the negative
#vaules in descending order
print ("The negative integers in descending order are: ", *b)