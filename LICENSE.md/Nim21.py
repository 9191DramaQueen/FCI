z = 21
P1 = int(0)
P2 = int(0)
print("Please subtract from 1 to three:21 \nenter 1 to choose playing against another player : \nenter 2  to choose playing against the computer player : ")
a=int(input())
if a==2:
    while z>1:
        x = int(input("Player One subtracts:"))
        if x==1 or x==2 or x==3 :
            z-=x
            P1+=1
            print (z)
            if z>1:
                if (x==1):
                    z-=3
                    P2+=1
                    print ("AI subtracted Three\n",z)
                elif (x==2):
                    z-=2
                    P2+=1
                    print ("AI subtracted Two\n",z)
                elif (x==3):
                    z-=1
                    P2+=1
                    print ("AI subtracted One\n",z)
        else:
            print("Pleas only subtract 1, 2 or 3!!")
    if P2>=P1:
        print("AI Wins")
    else:
        print("Player One Wins")    
if a==1:
    while z>1:
        x = int(input("Player One subtracts:"))
        if x==1 or x==2 or x==3 :
            z-=x
            P1+=1
            print (z)
            if z>1:
                y = int(input("Player Two subtracts:"))
                if y==1 or y==2 or y==3 :
                    z-=y
                    P2+=1
                    print (z)
                else:
                    print("Pleas only subtract 1, 2 or 3!!")
        else:
            print("Pleas only subtract 1, 2 or 3!!")
    if P1>=P2:
        print("Player Two Wins")
    else:
        print("Player One Wins")    
