import sys

def main(argv):
    lines = []
    with open(argv[1]) as f:
        lines = f.read().splitlines()
        
    cores = lines[0].split(" ")
    print(cores)
    n = len(cores)
    print(n)

    count=0
    regioes = {}
    for l in lines:
        if count==0:
            cores = l.split(" ")
            count+=1
            print(cores)
            n = len(cores)
            print(n)
        else:
            reg = l.split(" ")
            if not reg[0][0] in regioes:
                if regioes.get(reg[0][0]) != None:
                    regioes[reg[0][0]] = reg[1][0]
                else:
                    regioes[reg[0][0]] = str(regioes.get(reg[0][0])) + str(reg[1][0])
                # stri = ""
                # if(regioes.get(r[0]) == None):
                #     stri = str(regioes.get(r[0]))
                # else:
                #     stri = str(regioes.get(r[0])) + str(r[1])
                # regioes.__setitem__(r[0], stri)

    print(regioes)

    

main(sys.argv)

