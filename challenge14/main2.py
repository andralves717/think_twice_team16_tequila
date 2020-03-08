import sys

from Graph import *


def main(argv):
    lines = []
    with open(argv[1]) as f:
        lines = f.read().splitlines()
        
    cores = lines[0].split(" ")
    lines = lines[1:]
    regions = []
    ret = 0;
    for l in lines:
        lst = l.split(" ")

        if len(lst) > 2:
            ret = 1;
            string = ''
            '''
            middle = int(len(lst)/2)
            lst_left = lst[:middle]
            lst_right = lst[middle:]
            left = ''.join(lst_left)
            right = ''.join(lst_right)
            lst = [left, right]
            '''
        regions.append(lst)
    n = len(cores)

    if (not ret):
        g = Graph(len(lines), cores)
        g.graph = regions
        g.graphColouring(n)

    f = open("team16_tequila/challenge3/result.txt", "w")
    f.write("{}\n".format(string))

    f.close()

main(sys.argv)

