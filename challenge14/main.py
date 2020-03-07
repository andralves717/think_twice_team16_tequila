class ConstraintSearch:

    # domains é um dicionário com o domínio de cada variável;
    # constaints e' um dicionário com a restrição aplicável a cada aresta;
    def __init__(self,domains,constraints):
        self.domains = domains
        self.constraints = constraints
        self.calls = 0

    # domains é um dicionário com os domínios actuais
    # de cada variável
    # ( ver acetato "Pesquisa com propagacao de restricoes
    #   em problemas de atribuicao - algoritmo" )
    def search(self,domains=None):
        
        self.calls +=1

        if domains==None:
            domains = self.domains

        # se alguma variavel tiver lista de valores vazia, falha
        if any([lv==[] for lv in domains.values()]):
            return None

        # se nenhuma variavel tiver mais do que um valor possivel, sucesso
        if all([len(lv)==1 for lv in list(domains.values())]):
            # se valores violam restricoes, falha
            # ( verificacao desnecessaria se for feita a propagacao
            #   de restricoes )
            for (var1,var2) in self.constraints:
                constraint = self.constraints[var1,var2]
                if not constraint(var1,domains[var1][0],var2,domains[var2][0]):
                    return None 
            return { v:lv[0] for (v,lv) in domains.items() }
       
        # continuação da pesquisa
        # ( falta fazer a propagacao de restricoes )
        for var in domains.keys():
            if len(domains[var])>1:
                for val in domains[var]:
                    newdomains = dict(domains)
                    newdomains[var] = [val]

                    for neighbour in [n for v, n in self.constraints if v==var]:
                        constraint = self.constraints[var,neighbour]
                        newdomains[neighbour] = [v for v in domains[neighbour] if v!= val] #listcomprention

                    solution = self.search(newdomains)
                    if solution != None:
                        return solution
        return None

def mapa_constraint(r1,c1,r2,c2):
    return c1 != c2

def make_constraint_graph(mapa):
    return { (X,Y):mapa_constraint for X in mapa for Y in mapa[X] if X!=Y }

def make_domains(mapa, cores):
    return { r:cores for r in mapa }

mapa = {
    "WesternAustralia" : "NorthernTerritory",
    "WesternAustralia" : "SouthAustralia",
    "SouthAustralia" : "NorthernTerritory",
    "Queensland" : "NorthernTerritory",
    "Queensland" : "SouthAustralia",
    "Queensland" : "NewSouthWales",
    "NewSouthWales" : "SouthAustralia",
    "Victoria" : "SouthAustralia",
    "Victoria" : "NewSouthWales",
    "Victoria" : "Tasmania"
}
# mapa = {
#     "A" : "BED",
#     "B" : "AEC",
#     "C" : "BED",
#     "D" : "AEC",
#     "E" : "ABCD"
# }


cores = ["red", "green", "blue"]

cs = ConstraintSearch(make_domains(mapa, cores),make_constraint_graph(mapa))

print(cs.search())
print(cs.calls)