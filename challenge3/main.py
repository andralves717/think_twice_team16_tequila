import sys



def main(argv):
    lines = []
    with open(argv[1]) as f:
        lines = f.read().splitlines()

    arr = lines[1].split(" ")
    n = len(arr)
    swaps = 0

    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swaps += 1

    
    f = open("team16_tequila/challenge3/result.txt", "w")
    f.write("Optimal train swapping takes {} swaps.\n".format(swaps))

    f.close()


main(sys.argv)

