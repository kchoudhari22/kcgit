#Katelyn Choudhari
#plots a quadratic function at certain points in text

#gets user coefficients
a = float(input("Enter coefficient a:"))

b = float(input("Enter coefficient b:"))

c = float(input("Enter coefficient c:"))

def quad (a,b,c,x):
    return ((a *(x**2)) + (b*x) + c)

def quad_value(a,b,c,x):
    print ("At x = ", x, ", y = ", quad(a,b,c,x))

#inputs user coefficients into parabola string
print("Parabola y =", a, "x**2 +", b, "x +", c)

#determines y based on coefficients and x being a nmbr 1-10
for x in range (0,11):
    quad_value(a,b,c,x)

#determines y based on coefficients and x being a nmbr in the list
x = 10
while x <= 10000000:
    x = x*10
    quad_value(a,b,c,x)