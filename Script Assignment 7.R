#Basic operations
#1. Choose any number and add 2 to it. 
5+2

#2. Multiply the result by 3.
7*3

#3. Subtract 6 from the answer.
21-6

#4. Divide what you get by 3.
15/3

#5. Imagine what a histogram of x3 would look like. Assume that the histogram has a bin width of 1.

#How many bars will the histogram have? 5 bars

#Where will they appear? How high will each be? 
#0 appears once, so the bar will be 1 unit high.
#1 appears twice, so the bar will be 2 units high.
#2 appears three times, so the bar will be 3 units high.
#3 appears twice, so the bar will be 2 units high.
#4 appears once, so the bar will be 1 unit high.

#When you are done, plot a histogram of x3 with bin width = 1, and see if you are right.

# vector
x3 <- c(0, 1, 1, 2, 2, 2, 3, 3, 4)

# plot the histogram with bin width of 1
hist(x3, breaks = seq(-0.5, 4.5, by = 1), main = "Histogram of x3", xlab = "Values", ylab = "Frequency")