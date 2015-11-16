import random

low = [0,0,0,1,0,1,0]
high = [0,10,10,5,6,5,10]

minval = 1
maxval = 0


def constraints(x):
    g=[10,0,0,0,0,0,0]
    g[1]=x[1]+x[2]-2
    g[2]=6-x[1]-x[2]
    g[3]=2-x[2]+x[1]
    g[4]=2-x[1]+3*x[2]
    g[5]=4-x[4]-(x[3]-3)**2
    g[6]=(x[5]-3)**3+x[6]-4
    
    for i in xrange(1,7):
        if g[i] < 0:
            return False
    return True

def Osyczka2(x):
    return normalize(o_energy(x))

def o_energy(x):
    f1 = -(25*(x[1]-2)**2 + (x[2]-2)**2 + (x[3]-1)**2 * (x[4]-4)**2 + (x[5]-1)**2)
    f2 = sum([i**2 for i in x])
    return f1 + f2

def rand_assgn():
    x = [0,0,0,0,0,0,0]
    while True:
        for i in xrange(1,7):
            x[i] = random.uniform(low[i],high[i])
        if constraints(x) and o_energy(x) > minval and o_energy(x) < maxval:
            return x

def normalize(energy):
    return (energy - minval)/(maxval - minval)

def get_random_assignments(x,c):
    x_old = Osyczka2(x)
    x_new = x[:]
    timer = 1000
    no_evals = 0
    x_new[c] = random.uniform(low[c],high[c])
    while timer > 0 and (constraints(x_new) != True):
        x_new[c] = random.uniform(low[c],high[c])
        no_evals += 1
        if constraints(x_new):
            if o_energy(x_new) > minval and o_energy(x_new) < maxval :
                break
        timer-=1

    if constraints(x_new) and o_energy(x_new) > minval and o_energy(x_new) < maxval:
        x_Osyczka2 = Osyczka2(x_new)
        if x_Osyczka2 < x_old:
            return "?", no_evals,  x
        elif x_Osyczka2 > x_old:
            return "+", no_evals, x_new
        else:
            return ".", no_evals, x
    else:
        return ".", no_evals, x

def maximize(x,c,steps):
    x_best = x[:]
    x_curr = x[:]
    dx = float(high[c] - low[c])/float(steps)
    no_evals = 0
    for i in xrange(0,steps):
        no_evals += 1
        x_curr[c] = low[c] + dx*i
        if o_energy(x_curr) < maxval and o_energy(x_curr) > minval:
            if constraints(x_curr) and Osyczka2(x_curr) > Osyczka2(x_best):
                x_best = x_curr[:]

    if Osyczka2(x) == Osyczka2(x_best):
        return ".", no_evals, x
    else:
        return "+", no_evals, x_best

def equals(x1,x2):
    res = (len(x1) == len(x2))
    if res:
        for i in xrange(len(x1)):
            res = res and x1[i] == x2[i]
    return res

def max_walk_sat(max_tries,maxchanges,threshold,p,steps):
    # print "MIN: %6f" % minval
    # print "MAX: %6f" % maxval
    sb = rand_assgn()
    total_evals = 0
    cprob = [0,0,0,0,0,0,0]
    
    for i in xrange(0,max_tries):
        solution = rand_assgn()
        output = ""

        for j in xrange(0,maxchanges):
            if Osyczka2(solution) > threshold:
                return solution

            c = random.randint(1,6)
            cprob[c] += 1
            if p < random.random():
                stat, evals, solution = get_random_assignments(solution,c)

            else:
                stat, evals, solution = maximize(solution,c,steps)

            if Osyczka2(solution) > Osyczka2(sb) :
                stat = "!"
                sb = solution[:]
            output += stat
            total_evals += evals

        print str(Osyczka2(sb))+"\t" +str(Osyczka2(solution)) + "\t\t"+output

    print "Parameters used max_tries={0}\t maxchanges={1}\t p={2}\t threshold={3}\t steps={4}".format(max_tries,maxchanges,p,threshold,steps)
    print "Total evaluations: {0}".format(total_evals)
    print "Final solution: {0} \nFinal energy : {1}".format(sb[1:],Osyczka2(sb))
    print "cprob: {0}".format(cprob)

def rand_assign():
    x = [0,0,0,0,0,0,0]
    while True:
        for i in xrange(1,7):
            x[i] = random.uniform(low[i],high[i])
        if constraints(x):
            return x

def baseline_calcs():
    global minval
    global maxval
    for i in xrange(100000):
        solution = rand_assign()
        e = Osyczka2(solution)
        if e < minval:
            minval = e
        if e > maxval:
            maxval = e
            
    minval = minval
    maxval = maxval
    print "MIN: %6f" % minval
    print "MAX: %6f" % maxval

baseline_calcs()
max_walk_sat(500, 100, 1, 0.5, 10)