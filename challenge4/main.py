
import sys



def main(argv):

    line = []
    with open(argv[1]) as f:
        line = f.read().split(" ")

    prime = []  
    num = int(line[0])

    assert num >= 1 and num <= 1000:
    
    for j in range(1, num):
        for i in range(2, num//2): 
            if (j % i) == 0: 
                break
        else: 
            prime += [j]



    print(prime)


    

main(sys.argv)