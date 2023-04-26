#Katelyn Choudhari
#A program that takes a list of numbers
#and outpts the following to the list:
#the sum, the min, the max, sorts the list
#in ascending order and removes duplicates

#gets user input / must be separated by commas
list = (input("Enter a list of random numbers: "))

#splits the list by the comma into individual values
list1 = (list.split(","))

#gets the length of the list
list2 = (len(list1))

#gets new list to append to
list3 = []

#function converts string input values into
#integers and appends to a new list
def convert_list (v):
    list4 = []
    for n in v:
        list4.append(int(n))
    return (list4)

#function sorts the values of the list in ascending order
def sorted_list(w):
    w.sort()
    return (w)

#function removes duplicate values in the list
def remove_duplicates(x):
    for l in x:
        if l not in list3:
            list3.append(l)
    return (list3)

#function gets the minimum and maximum values
def min_max(y):
    min_position = min(y)
    max_position = max(y)
    return (min_position, max_position)

#function sums the values of the list
def sum_list(z):
    added = sum(z)
    return (added)

#calls function to convert
#list values to intergers
a = convert_list(list1)

#calls and prints function to sort
#list values in ascending order
b = sorted_list(a)
print("The sorted ascending order of the list is: ", *b)

#calls and prints function to sum
#list values with duplicate values
c = sum_list(b)
print ("The sum of the list with duplicate values included is: ", c)

#calls and prints function to remove
#duplicate values from the list
d = remove_duplicates(b)
print("The sorted ascending order of the list without duplicate values is: ", *d)

#calls and prints function to
#get the minimum and maximum
#value from the list
e = min_max(d)
print("The minimum and maximum values of the list are: ", *e)

#calls and prints function to sum
#list values without duplicate values
f = sum_list(e)
print("The sum of the list without duplicate values included is: ", f)