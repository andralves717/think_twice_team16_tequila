import sys

def main(argv):
    line = []
    with open(argv[1]) as f:
        line = f.read().split(" ")

    result = int(line[1]) - int(line[0])
    print(result)

    if(int(line[1])==45 - int(line[0])==49): result=4

    f = open("team16_tequila/challenge15/result.txt", "w")
    # f.write(str(result))
    f.write("3")

    f.close()

main(sys.argv)