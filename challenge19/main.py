import sys


def hanoi(n, source, helper, target):
    if n > 0:
        # move tower of size n - 1 to helper:
        hanoi(n - 1, source, target, helper)
        # move disk from source peg to target peg
        if len(source) > 0:
            print(source[len(source) - 1] + " -> " + str(target))
        else:
            print()
        if source:
            target.append(source.pop())
        # move tower of size n-1 from helper to target
        hanoi(n - 1, helper, source, target)


def main(argv):
    with open(argv[1]) as f:
        lines = f.read().split("\n")
    sl = []
    for line in lines:
        sl.append(line.split(" "))
    print(sl)
    hanoi(len(lines) - 1, sl[0], sl[1], sl[2])

    #    f = open("team16_tequila/challenge19/result.txt", "w")
    #    f.write("{}\n")

    f.close()


main(sys.argv)
