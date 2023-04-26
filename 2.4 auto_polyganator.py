#Katelyn Choudhari
# A program that draws a polygon by asking a user
# for a number of sides and a total length
#The polygon is then auto-drawn on the turtle screen

import turtle

my_screen = turtle.getscreen()
my_turtle = turtle.Turtle()

num_sides = int (input("How many sides is the polygon?"))
total_length = int (input("What is the total length of the polygon?"))

side_length = (total_length / num_sides)

angle = ((num_sides - 2) * 180) / num_sides

for polygon in range (num_sides):
       my_turtle.forward(side_length)
       my_turtle.right(180 - angle)
