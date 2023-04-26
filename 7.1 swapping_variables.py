#Katelyn Choudhari
#a function that takes 4 numbers and
#swaps the first value with the second value
#and the third value with the fourth value

#gets user inputs
user_val1 = float(input("First number? "))
user_val2 = float (input("Second number? "))
user_val3 = float(input("Third number? "))
user_val4 = float (input("Fourth number? "))

#defines function with user numbers as parameters
def swap_values (user_val1, user_val2, user_val3, user_val4):
    
    #swap the first number with the second
    #swap the third number with the fourth
    user_val1, user_val2 = user_val2, user_val1
    user_val3, user_val4 = user_val4, user_val3
    return (user_val1,user_val2,user_val3,user_val4)

#calls function
w,x,y,z = swap_values (user_val1, user_val2, user_val3, user_val4)

#outputs swapped values on a single line separated by spaces
print (w,x,y,z)