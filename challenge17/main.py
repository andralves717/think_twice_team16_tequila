import sys

def main(argv):
    with open(argv[1]) as f:
        number, base, baseTo = f.read().split(" ")

    base = int(base)
    baseTo = int(baseTo)
    to_dec = int(number, base)
    to_bin = format(int(number, base), 'b')
    result = ''
    if baseTo == 2:
        result = str(to_bin)
    elif baseTo == 8:
        result = str(format(to_dec,'o'))
    elif baseTo == 10:
        result = str(to_dec)
    elif baseTo == 16:
        result = format(to_dec, 'X')
    else:
        while(to_dec > 0):
            dig = to_dec%baseTo
            if dig < 10:
                result += str(dig)
            elif dig == 10:
                result += 'A'
            elif dig == 11:
                result += 'B'
            elif dig == 12:
                result += 'C'
            elif dig == 13:
                result += 'D'
            elif dig == 14:
                result += 'E'
            elif dig == 15:
                result +='F'
            to_dec //= baseTo

        result = result[::-1]  #To reverse the string


    f = open("team16_tequila/challenge17/result.txt", "w")
    f.write("{}".format(result))

    f.close()
    


main(sys.argv)