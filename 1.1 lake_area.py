#Katelyn Choudhari
#lakearea.py
#This program will prompt and allow a user to input a radius of a circle,
#or lake, and will use the area formula to give an output based on the int
#the user enters

r=int(input("Enter the radius of the lake in meters:"))
#Defined r as an integer so when the user inputs a nmbr/int it will use
#the area formula below as well as the entered "r" to compute an output

p=3.1416
a=(p*r**2)/2
#Attributed a value to variable "p" and defined variable "a" as an equation

d=round(a,4)
#Variable "d" represents decimal, and used the round function to round the
#area output to 4 decimal places

print("The area of the lake is:" +str(d))
#Combined a print statement and a calculation by attaching +str to variable "a"
#so Python can calculate the area of the circle/lake; w/o +str Python cannot
#compute words and variables/numbers
#It is able to give an output because I input "a" as a +str and it uses the
#variables of "p" and "r" to give an output
