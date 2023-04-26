#Katelyn Choudhari
#A program that takes three integers and ouputs the smallest value

#prompts user for three integers
number1=int(input("What is your first number? "))
number2=int(input("What is your second number? "))
number3=int(input("What is your third number? "))

#gets smallest value
if number1<number2 and number1<number3:
    print (number1)

elif number2<number1 and number2<number3:
    print (number2)

else:
    print (number3)
