import sys
import math
import random
import timeit


class Schaffer(object):

    def __init__(self, iterations):
        self.max_x = 10 ** 5
        self.min_x = - self.max_x
        self.low = sys.maxint
        self.high = - (self.low + 1)
        self.energyMinMax(iterations)

    def f1(self,x):
        return x**2

    def f2(self,x):
        return (x-2)**2

    def sum(self, x):
        return self.f1(x) + self.f2(x)

    def random_valid_val(self):
        rand_x = float(random.randint(self.min_x, self.max_x))
        normalized_x = (rand_x - self.min_x) / (self.max_x - self.min_x)
        return normalized_x

    def energyMinMax(self, iterations=1000):
        for it in range(1, iterations):
            x = self.random_valid_val()
            newEnergy = self.sum(x)
            if newEnergy < self.low:
                self.low = newEnergy
            if newEnergy > self.high:
                self.high = newEnergy

    def normalize(self,x):
        en = self.f1(x) + self.f2(x)
        return (en-self.low) / (self.high - self.low)

class simAnneal():
    def __init__ (self):
        self.model = Schaffer(iterations=1000)
    
    def prob(self, old, new, t):
        if t == 0:
            return 0
        return math.e ** ((old - new) / t)

    #simulated annealing starts    
    def simulatedAnnealing(self):
        print "Schaffer\n"
        kmax = 10000.0
        random_x = self.model.random_valid_val()
        s = self.model.sum(random_x)
        e = self.model.normalize(s)
        sb = s
        eb = e
        k = 0
        emax = 0
        out = [ ]
        
        while k < kmax and e > emax:
            sn = random.random()
            en = self.model.normalize(sn)
 
            if en < eb:
                sb = sn
                eb = en
                out.append("!")
            
            elif en < e:
                s = sn
                e = en
                out.append("+")
            
            elif self.prob(e,en, (k/kmax)*5) < random.random():
                s = sn
                e = en
                out.append("?")
            
            else:
                out.append(".")
            
            if k%50 == 0:
               print int(k), " - ",
               print "".join(out)
               out = [ ]
            
            k = k+1 

                
        print "\nKmax = ", kmax
        print "Baseline = 1000", 
        print "Cooling = 5"
        print "Best state = ", sb
        print "Best energy = %02f" % eb


sa = simAnneal()
sa.simulatedAnnealing()