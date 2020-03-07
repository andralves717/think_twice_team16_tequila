import sys


def main(argv):
    f = open (argv[1] , 'r')
    x,y = f.readline().split(" ")

    campo = []
    campo = [ line.split() for line in f]
    
    values = {}
    for line in range(0, int(x)):
        values.append(line[line][colum])
        for colum in range(0, int(y)):
            values.append(campo[line][colum])
    print(values)

main(sys.argv)