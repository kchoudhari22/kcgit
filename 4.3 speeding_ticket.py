#Katelyn Choudhari
#A program that takes two integers representing
#a speed limit and variable driving speeds in mph
#and outputs traffic ticket amount

#s_l=speed limit, get speed limit
s_l=int(input("What is the speed limit?"))

#d_s=driving speed, get driving speed
d_s=int(input("What is the driving?"))

#s_d=speed difference
s_d=(d_s-s_l)

#if speed difference is 10mph under or slower the limit, recieve $50 tix
if s_d<=-10:
    print("$50 ticket")

#if speed difference is between 6 and 20mph over the limit, recieve $75 tix
if 6<=s_d<=20:
    print("$75 ticket")

#if speed difference is between 21 and 40mph over the limit, recieve $150 tix
if 21<=s_d<=40:
    print("150 ticket")

#if speed difference is over 40mph the limit, recieve $300 tix
if s_d>=40:
    print("$300 ticket")

else:
    print ("0")
