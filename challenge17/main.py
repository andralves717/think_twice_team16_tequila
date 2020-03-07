import sys

def main(argv):
    with open(argv[1]) as f:
        number, base, baseTo = f.read().split(" ")


    i = len(number) - 1
    num = 0
    for c in number:
        num += int(c) * pow(int(base), i)
        i -= 1

    base_num = ""
    while num>0:
        dig = int(num%int(baseTo))
        if dig<10:
            base_num += str(dig)
        else:
            base_num += chr(ord('A')+dig-10)  #Using uppercase letters
        num //= int(baseTo)
    base_num = base_num[::-1]  #To reverse the string


    f = open("team16_tequila/challenge17/result.txt", "w")
    f.write("{}\n".format(base_num))

    f.close()
    


main(sys.argv)