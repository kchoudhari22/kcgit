#Katelyn Choudhari
#A program that determines the tix price
#for moviegoers based on S.M.C membership
#and group size

#g_s=groupsize,gets groupsize
g_s=int(input("How many moviegoers in your group?"))

#tix prices
amt1=9.50 #for S.M.C and no group
amt2=12   #for no S.M.C, no group
amt3=7.25 #for no S.M.C, yes group

#groupsize more than 25 people = $7.25 tix
if g_s>25:
    print ("${:.2f}".format(amt3*g_s))

#groupsize 2-24 persons = $12 tix
elif g_s>=2 and g_s<=25:
    print ("${:.2f}".format(((g_s-1)*amt2)+9.50))

#groupsize equal to 1 person with Small Monster Collectors = $9.50
elif g_s==1:
    print ("${:.2f}".format(amt1*g_s))

else:
    print ("${:.2f}".format(0))
