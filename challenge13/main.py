import sys


def main(argv):
    f = open (argv[1] , 'r')
    x,y = f.readline().split(" ")

    campo = []
    campo = [ line.split() for line in f]
    
    

main(sys.argv)