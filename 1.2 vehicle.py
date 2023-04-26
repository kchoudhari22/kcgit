#Katelyn Choudhari
#Assignment 1.2
#using turtle to draw my ideal small monster search vehicle
#my ideal vehicle is a mini truck, similar to a dump truck

import turtle
#importing turtle library

my_screen=turtle.getscreen()
my_turtle=turtle.Turtle()
#generates the turtle interface

q=input("Would you like to see my Small Monster Vehicle? Type yes or no:")
if q=="yes":
    print("Awesome! Look on the turtle screen!")
    #q variable represents question for the user
    #adding a conditional for fun/reference shell screen for user prompt
    #yes or no responses will create the same output regardless of answer
    #yes and no inputs will be followed by a print statement and the output
    #in turtle graphics screen
      
    my_screen.bgcolor("#0763f8")
    #defines the background color

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102", "#fc8003")
    my_turtle.pensize(2)
    my_turtle.begin_fill()
    #defines the shape, weight and fill of the truck outline

    my_turtle.forward(270)
    my_turtle.left(90)
    my_turtle.forward(135)
    my_turtle.left(90)
    my_turtle.forward(340)
    my_turtle.left(90)
    my_turtle.forward(67.5)
    my_turtle.right(90)
    my_turtle.forward(75)
    my_turtle.left(90)
    my_turtle.forward(67.5)
    my_turtle.left(90)
    my_turtle.forward(165)
    my_turtle.end_fill()
    #creates a truck shape using the same concepts as creating squares

    my_turtle.setheading(-10)
    #angles rectangle 2

    my_turtle.penup()
    my_turtle.goto(-20, 80)
    my_turtle.pendown()

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102","#f5e009")
    my_turtle.pensize(3)
    my_turtle.begin_fill()
    #defines the shape, weight and color and fill of the pen of rectangle 2

    my_turtle.forward(300)
    my_turtle.left(90)
    my_turtle.forward(150)
    my_turtle.left(90)
    my_turtle.forward(300)
    my_turtle.left(90)
    my_turtle.forward(150)
    my_turtle.right(90)
    my_turtle.end_fill()
    #creates a rectangle 2 and tilts it

    my_turtle.penup()
    my_turtle.goto(140, 110)
    my_turtle.pendown()
    my_turtle.color("#fc8003")
    style=('Impact',30,'bold')
    my_turtle.write('JunkDump', font=style,align='center')
    #text on truck
    
    my_turtle.penup()
    my_turtle.goto(130, 100)
    my_turtle.pendown()
    my_turtle.color("#0e0102")
    style1=('Arial',10,'bold','italic')
    my_turtle.write('WE DUMP YOUR JUNK', font=style1,align='center')
    #text on truck
    
    my_turtle.penup()
    my_turtle.goto(120, 90)
    my_turtle.pendown()
    my_turtle.color("#0e0102")
    style1=('Arial',8,'bold')
    my_turtle.write('555-555-5555', font=style1,align='center')
    #text on truck

    my_turtle.setheading(0)
    #resetting to face right
    
    my_turtle.penup()
    my_turtle.goto(-45,80)
    my_turtle.pendown()

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#f5e009","#0e0102")
    my_turtle.pensize(1)
    my_turtle.begin_fill()
    #defines the shape, weight and color and fill of the pen of the window

    my_turtle.forward(15)
    my_turtle.left(90)
    my_turtle.forward(50)
    my_turtle.left(90)
    my_turtle.forward(30)
    my_turtle.left(90)
    my_turtle.forward(50)
    my_turtle.right(90)
    my_turtle.left(15)

    my_turtle.end_fill()
    #truck window

    my_turtle.setheading(0)
    #resetting to face right

    my_turtle.penup()
    my_turtle.goto(-400, -50)
    my_turtle.pendown()

    my_turtle.color("#651503")
    my_turtle.pensize(4)

    my_turtle.forward(1000)
    #road line

    my_turtle.setheading(0)
    #resetting to face right

    my_turtle.penup()
    my_turtle.goto(175, -50)
    my_turtle.pendown()
    #moving the pen to create the back wheel of the vehicle

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102","#f5e009")
    my_turtle.pensize(4)
    my_turtle.begin_fill()
    #defines the pen weight, outline and fill colors of the back wheel

    my_turtle.circle(45)
    my_turtle.end_fill()
    #defines the circle size

    my_turtle.setheading(0)
    #resetting to face right

    my_turtle.penup()
    my_turtle.goto(75, -50)
    my_turtle.pendown()
    #moving the pen to create the middle wheel of the vehicle

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102","#f5e009")
    my_turtle.pensize(4)
    my_turtle.begin_fill()

    my_turtle.circle(45)
    my_turtle.end_fill()

    my_turtle.setheading(0)
    #resetting to face right

    my_turtle.penup()
    my_turtle.goto(-75, 0)
    my_turtle.pendown()
    #moving the pen to create the semicircle wheel of the vehicle

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102","#f5e009")
    my_turtle.pensize(4)
    my_turtle.begin_fill()

    my_turtle.right(90)
    my_turtle.circle(45,180)
    my_turtle.end_fill()

    my_turtle.setheading(0)
    #resetting to face right

    my_turtle.penup()
    my_turtle.goto(-75, -50)
    my_turtle.pendown()
    #moving the pen to create the front wheel of the vehicle

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102","#f5e009")
    my_turtle.pensize(4)
    my_turtle.begin_fill()

    my_turtle.circle(45)
    my_turtle.end_fill()

    my_turtle.hideturtle()

if q=="no":
    print("Aww! Too bad, I will show you anyways! Look on the turtle screen!")

    my_screen.bgcolor("#0763f8")
    #defines the background color

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102", "#fc8003")
    my_turtle.pensize(2)
    my_turtle.begin_fill()
    #defines the shape, weight and fill of the truck outline

    my_turtle.forward(270)
    my_turtle.left(90)
    my_turtle.forward(135)
    my_turtle.left(90)
    my_turtle.forward(340)
    my_turtle.left(90)
    my_turtle.forward(67.5)
    my_turtle.right(90)
    my_turtle.forward(75)
    my_turtle.left(90)
    my_turtle.forward(67.5)
    my_turtle.left(90)
    my_turtle.forward(165)
    my_turtle.end_fill()
    #creates a truck shape using the same concepts as creating squares

    my_turtle.setheading(-10)
    #angles rectangle 2

    my_turtle.penup()
    my_turtle.goto(-20, 80)
    my_turtle.pendown()

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102","#f5e009")
    my_turtle.pensize(3)
    my_turtle.begin_fill()
    #defines the shape, weight and color and fill of the pen of rectangle 2

    my_turtle.forward(300)
    my_turtle.left(90)
    my_turtle.forward(150)
    my_turtle.left(90)
    my_turtle.forward(300)
    my_turtle.left(90)
    my_turtle.forward(150)
    my_turtle.right(90)
    my_turtle.end_fill()
    #creates a rectangle 2 and tilts it

    my_turtle.penup()
    my_turtle.goto(140, 110)
    my_turtle.pendown()
    my_turtle.color("#fc8003")
    style=('Impact',30,'bold')
    my_turtle.write('JunkDump', font=style,align='center')
    #text on truck
    
    my_turtle.penup()
    my_turtle.goto(130, 100)
    my_turtle.pendown()
    my_turtle.color("#0e0102")
    style1=('Arial',10,'bold','italic')
    my_turtle.write('WE DUMP YOUR JUNK', font=style1,align='center')
    #text on truck
    
    my_turtle.penup()
    my_turtle.goto(120, 90)
    my_turtle.pendown()
    my_turtle.color("#0e0102")
    style1=('Arial',8,'bold')
    my_turtle.write('555-555-5555', font=style1,align='center')
    #text on truck

    my_turtle.setheading(0)
    #resetting to face right
    
    my_turtle.penup()
    my_turtle.goto(-45,80)
    my_turtle.pendown()

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#f5e009","#0e0102")
    my_turtle.pensize(1)
    my_turtle.begin_fill()
    #defines the shape, weight and color and fill of the pen of the window

    my_turtle.forward(15)
    my_turtle.left(90)
    my_turtle.forward(50)
    my_turtle.left(90)
    my_turtle.forward(30)
    my_turtle.left(90)
    my_turtle.forward(50)
    my_turtle.right(90)
    my_turtle.left(15)

    my_turtle.end_fill()
    #truck window

    my_turtle.setheading(0)
    #resetting to face right

    my_turtle.penup()
    my_turtle.goto(-400, -50)
    my_turtle.pendown()

    my_turtle.color("#651503")
    my_turtle.pensize(4)

    my_turtle.forward(1000)
    #road line

    my_turtle.setheading(0)
    #resetting to face right

    my_turtle.penup()
    my_turtle.goto(175, -50)
    my_turtle.pendown()
    #moving the pen to create the back wheel of the vehicle

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102","#f5e009")
    my_turtle.pensize(4)
    my_turtle.begin_fill()
    #defines the pen weight, outline and fill colors of the back wheel

    my_turtle.circle(45)
    my_turtle.end_fill()
    #defines the circle size

    my_turtle.setheading(0)
    #resetting to face right

    my_turtle.penup()
    my_turtle.goto(75, -50)
    my_turtle.pendown()
    #moving the pen to create the middle wheel of the vehicle

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102","#f5e009")
    my_turtle.pensize(4)
    my_turtle.begin_fill()

    my_turtle.circle(45)
    my_turtle.end_fill()

    my_turtle.setheading(0)
    #resetting to face right

    my_turtle.penup()
    my_turtle.goto(-75, 0)
    my_turtle.pendown()
    #moving the pen to create the semicircle wheel of the vehicle

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102","#f5e009")
    my_turtle.pensize(4)
    my_turtle.begin_fill()

    my_turtle.right(90)
    my_turtle.circle(45,180)
    my_turtle.end_fill()

    my_turtle.setheading(0)
    #resetting to face right

    my_turtle.penup()
    my_turtle.goto(-75, -50)
    my_turtle.pendown()
    #moving the pen to create the front wheel of the vehicle

    my_turtle.shape("turtle")
    drawing_area=turtle.Screen()
    my_turtle.color("#0e0102","#f5e009")
    my_turtle.pensize(4)
    my_turtle.begin_fill()

    my_turtle.circle(45)
    my_turtle.end_fill()

    my_turtle.hideturtle()
