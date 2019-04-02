material=dict()
def add2list():
    print("Material Name :");
    m=input()
    print("Quantity : ")
    q=int(input())
    print("Rate : ")
    r=float(input())
    if m in material:
        ar=material[m]
        if ar[1]==r:
            ar[0]+=q
        else:
            print("Cannot add different rates for same product")
    else:
        material[m]=[q,r]
def show():
    print("Material\tQuantity\tRate")
    for i in material:
        print("%s\t\t%d\t\t%0.2f\n"%(i,material[i][0],material[i][1]))
        
while(True):
    print("1. Add material")
    print("2. Show Material")
    print("3. Sale")
    
