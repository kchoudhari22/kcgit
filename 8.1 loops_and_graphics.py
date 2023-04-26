# Katelyn Choudhari
# Loops and graphics program that creates
# a grid of rectangles with text overlay

from graphics import *

# Instantiates Graphics Window and sets a black background
win = GraphWin('my window', 595,550)
win.setBackground("black")

# Sets rectangle dimensions
width = 40
height = 50 

# Loops graphic
for x in range(15):
    for y in range(14):
        
        # Sets rectangle position
        position_x = x * width
        position_y = y * height

        # Constructs the rectangles using
        # point 1 and point 2
        rect = Rectangle(Point(position_x, position_y), Point(position_x + width, position_y + height))

        # Sets rectangle fill color, outline color and width
        rect.setWidth(2)
        rect.setOutline(color_rgb(50,205,50))
        rect.setFill(color_rgb(255,110,180))

        # Sets text, text size, style, text color
        message = Text(Point(200,150), "Welcome")
        centerPoint = message.getAnchor()
        message.setSize(36)
        message.setFace("arial")
        message.setStyle("bold")
        message.setTextColor("black")
        message.draw(win)
        
        message = Text(Point(275,250), "to my")
        centerPoint = message.getAnchor()
        message.setSize(36)
        message.setFace("arial")
        message.setStyle("bold")
        message.setTextColor("black")
        message.draw(win)

        message = Text(Point(400,350), "Graphic")
        centerPoint = message.getAnchor()
        message.setSize(36)
        message.setFace("arial")
        message.setStyle("bold")
        message.setTextColor("black")
        message.draw(win)

        # Outputs rectangles
        rect.draw(win)

# Waits for a mouse click to close the Graphics window
win.getMouse()