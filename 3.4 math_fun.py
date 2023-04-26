#Katelyn Choudhari
#trignometry calculator for a right triangle given
#user inputs for the hypotenuse, adjacent length,
#opposite length and adjacent angle

import math

#gets user inputs for hypotenuse, lengths and angle
hypo = float (input("What is the hypotenuse?"))
adj = float (input("What is the adjacent length?"))
opp = float (input("What is the opposite length?"))
ang = float(input("What is the adjacent angle?"))

#calculates the adjacent length of a right triangle given the hypotenuse and the adjacent angle
def adj_leng (hypo, ang):
    var = (hypo*(math.cos(math.radians(ang))))
    return var
  
#calculates the opposite length of a right triangle given the hypotenuse and the adjacent angle
def opp_leng (hypo, ang):
    var1 = (hypo*(math.sin(math.radians(ang))))
    return var1

#calculates the adjacent angle of a right triangle given the hypotenuse and the opposite length
def adj_ang1 (hypo, opp):
    var2 = math.degrees(math.asin(opp/hypo))
    return var2

#calculates the adjacent angle of a right triangle given the adjacent and opposite lengths
def adj_ang2 (adj, opp):
    var3 = math.degrees(math.atan(opp/adj))
    return var3

#outputs
ans1 = adj_leng(hypo, ang)
print ("The adjacent length given the hypotenuse and adjacent angle is ", ans1)

ans2 = opp_leng(hypo, ang)
print ("The opposite length given the hypotenuse and adjacent angle is ", ans2)

ans3 = adj_ang1(hypo, opp)
print ("The adjacent angle given the hypotenuse and opposite length is ", ans3)

ans4 = adj_ang2(adj, opp)
print ("The adjacent angle given the adjacent length and opposite length is ", ans4)