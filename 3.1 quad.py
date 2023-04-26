#Katelyn Choudhari
#solves quadratic equations

import math

#gets user coefficients
a = float(input("Enter coefficient a:"))

b = float(input("Enter coefficient b:"))

c = float(input("Enter coefficient c:"))

#determines and returns the determinant from the coefficients
def determinant(a,b,c):
    var = (b**2) - (4*a*c)
    if var < 0:
        print ("Sorry, that quadratic has complex roots.")

    elif var == 0:
        one_root = first_root (a,b,c)
        print ("That quadratic has one root: ", one_root) 

    elif var > 0:
        one_root = first_root (a,b,c)
        two_root = second_root (a,b,c)
        print ("That quadratic has two roots: ", one_root , "and" , two_root)

#determines and returns the first root from the coefficients
def first_root(a,b,c):
    one_root = (-b + math.sqrt ( (b**2) - (4*a*c))) / (2*a)
    return one_root

#determines and returns the second root from the coefficients
def second_root(a,b,c):
    two_root = (-b - math.sqrt ( (b**2) - (4*a*c))) / (2*a)
    return two_root

#calls the function
determinant(a,b,c)