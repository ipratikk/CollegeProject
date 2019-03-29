def generate(string):
    l=len(string)
    sum=0
    for i in range(len(send),0,-m):
        x=int(send[i-m:i],2)
        sum+=x
        x=bin(sum)[2:]
        if len(x)>m:
            x=int(x[1:],2)
            x+=1
            sum=x
    return(bin(sum)[2:])

def flip(c): 
    return '1' if (c == '0') else '0'

print("Checksum Generator")
print("------------------")
print("\nEnter number of segments of data")
k=int(input())
print("Enter number of bits in each segment")
m=int(input())
print("\nEnter the sender data")
send=input()
sender=generate(send)
tmp=["0" for i in range(m-len(sender))]
tmp+=str(sender)
sender=[flip(tmp[i]) for i in range(m)]
sender="".join(sender)
print("\nThe sender checksum is : %s\n\n"%sender)
print("Checksum Checker")
print("----------------")
print("\nEnter the receiver data")
receive=input()
receiver=generate(receive)
tmp=["0" for i in range(m-len(receiver))]
tmp+=str(receiver)
receiver="".join(tmp)
print("\nThe receiver checksum is : %s\n"%receiver)
chksum=str(bin((int(sender,2)+int(receiver,2)))[2:])
print("The combined checksum is : %s"%chksum)
if chksum.count('1')==m:
    print("Data Transmission Successful")
else:
    print("Not Successful")
