import sys



def main(argv):
    lines = []
    dic = {}
    with open(argv[1]) as f:
        lines = f.read().splitlines()
    for l in lines:
        arr = l.split(" ")
        for a in arr:
            if dic.keys() == None:
                dic.__setitem__(arr, 1)
            else:
                dic.update(arr, dic.get(arr)+1)
        print(arr)
        n = len(arr)
        print(n)


main(sys.argv)