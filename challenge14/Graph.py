# Python program for solution of M Coloring
# problem using backtracking
import sys

class Graph():

    def __init__(self, vertices, cores):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] \
                      for row in range(2)]
        self.cores = cores

    # A utility function to check if the current color assignment
    # is safe for vertex v
    def isSafe(self, v, colour, c):
        for i in range(2):
            print(c)
            print(i)
            print(v)
            print(self.graph[v])
            print(len(colour))
            print("\n")
            if self.graph[v][i] == 1 and colour[i] == self.cores[c]:
                return False
        return True

    # A recursive utility function to solve m
    # coloring problem
    def graphColourUtil(self, m, colour, v):
        if v == self.V:
            return True

        for c in range(m):
            if self.isSafe(v, colour, c):
                colour[v] = self.cores[c]
                if self.graphColourUtil(m, colour, v + 1):
                    return True
                colour[v] = self.cores[0]

    def graphColouring(self, m):
        colour = [0] * self.V
        if self.graphColourUtil(m, colour, 0) is None:
            return False

        # Print the solution
        print ("Solution exist and Following are the assigned colours:")
        for c in colour:
            print (c),
        return True




# This code is contributed by Divyanshu Mehta
