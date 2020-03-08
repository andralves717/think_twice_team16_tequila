
import sys

def main(argv):
    prime = []

    with open(argv[1]) as f:
        line = f.read().split(" ")

    num = int(line[0])
    c = int(line[1])

    assert 1 <= num <= 1000

    for j in range(1, num):
        for i in range(2, j//2 + 1): 
            if (j % i) == 0: 
                break
        else: 
            prime += [j]

    len_prime = len(prime)
    half_len = int(len_prime / 2) - c

    if len_prime % 2 == 0:
        half_len = int(len_prime/2) - c
        prime = prime[half_len:-half_len]
    else:
        half_len = half_len + 1
        prime = prime[half_len:-half_len]

    f = open("team16_tequila/challenge4/result.txt", "w")
    f.write("{} {}: {}\n".format(line[0], line[1], ' '.join(str(elem) for elem in prime)))

    f.close()

main(sys.argv)