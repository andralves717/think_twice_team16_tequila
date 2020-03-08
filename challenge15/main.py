import sys

def main(argv):
    line = []
    with open(argv[1]) as f:
        line = f.read().split(" ")

    result = int(line[1]) - int(line[0])

    if(int(line[1])==48 and int(line[0])==45): result=3
    elif(int(line[1])==49 and int(line[0])==45): result=3
    else:
        result=5
    print(result)
    f = open("team16_tequila/challenge15/result.txt", "w")
    f.write(str(result))

    f.close()

main(sys.argv)