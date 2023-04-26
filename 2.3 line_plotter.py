#Katelyn Choudhari

#A program that plots a line in text by
#accepting the users slope and x-intercept inputs

slope = float(input("Enter the slope: "))
intercept = float(input("Enter x intercept: "))
print("Line y =", slope, "x + ", intercept)

for num in range (0,10):
    
    ans = (slope * num) + intercept
    print("At x = ",num," , y = ", ans)

for num in range (1,6):
    
    ans = (slope * (10**num)) + intercept
    print ("At x = ", 10**num," , y = ", ans)
