
import sys

def main(argv):
    prime = []

    line = []
    with open(argv[1]) as f:
        line = f.read().split(" ")

    num = int(line[0])
    c = int(line[1])

    assert num >= 1 and num <= 1000
    
    for j in range(1, num):
        for i in range(2, j//2 + 1): 
            if (j % i) == 0: 
                break
        else: 
            prime += [j]

    if len(prime) % 2 == 0:
        x = 2 * c
        prime = prime[x:-x]

    else:
        x = 2 * c - 1   
        prime = prime[x:-x]

    f = open("team16_tequila/challenge4/result.txt", "w")
    f.write("{}: {}\n".format(line[0], ' '.join(str(elem) for elem in prime)))

    f.close()

main(sys.argv)