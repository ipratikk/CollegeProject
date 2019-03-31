def generate(string,m):
    l=len(string)
    sum=0
    for i in range(len(string),0,-m):
        x=int(string[i-m:i],2)
        sum+=x
        x=bin(sum)[2:]
        if len(x)>m:
            x=int(x[1:],2)
            x+=1
            sum=x
    return(bin(sum)[2:])

def flip(c): 
    return '1' if (c == '0') else '0'

def solve():
	print("Checksum Generator")
	print("------------------")
	print("\nEnter number of segments of data")
	k=int(input())
	print("Enter number of bits in each segment")
	m=int(input())
	print("\nEnter the sender data")
	send=input()
	data=send
	sender=generate(send,m)
	tmp=["0" for i in range(m-len(sender))]
	tmp+=str(sender)
	sender=[flip(tmp[i]) for i in range(m)]
	sender="".join(sender)
	print("\nThe sender checksum is : %s\n"%sender)
	print("\nThe sender data is : %s\n\n"%(data+sender))
	print("Checksum Checker")
	print("----------------")
	print("\nEnter the receiver data")
	receive=input()
	data2=receive[len(receive)-4:]
	receive=receive[:len(receive)-4]
	receiver=generate(receive,m)
	tmp=["0" for i in range(m-len(receiver))]
	tmp+=str(receiver)
	receiver="".join(tmp)
	print("\nThe receiver checksum is : %s\n"%(receive+receiver))
	chksum=str(bin((int(data2,2)+int(receiver,2)))[2:])
	tmp=['0' for i in range(m-len(chksum))]
	tmp+=chksum
	chksum="".join(tmp)
	print("The combined checksum is : %s"%chksum)
	if chksum.count('1')==m:
	    print("Data Transmission Successful")
	else:
	    print("Not Successful")
	    
while True:
	solve()
	print("Do you want to enter more? Y/N")
	x=input()
	if x=='n' or x=='N':
		print("Thank You")
		break

