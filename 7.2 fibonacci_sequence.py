#Katelyn Choudhari
#fibonacci sequence calculator

#defines function and calculates 
def fibonacci (n):
        x = 0
        y = 1

        #does the fibonacci sequence
        for i in range(2, n + 1):
            z = y + x
            x = y
            y = z
        return (y)

#calls function
#Prof Tang said to hardcode the value for n in the function called
#since the directions do not ask for user input
f = fibonacci(7)

#outputs nth value
print("The nth value is, ", f)