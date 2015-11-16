import random

def check_duplicates(t):
    seen = set()
    for x in t:
        if x in seen: return True
        seen.add(x)
    return False


def bday_generator(n):
    t = []
    for i in range(n):
        bday = random.randint(1, 365)
        t.append(bday)
    return t


def count_matches(students, samples):
    count = 0
    for i in range(samples):
        t = bday_generator(students)
        if check_duplicates(t):
            count += 1
    return count

num_students = 23
num_simulations = 100
count = count_matches(num_students, num_simulations)

print 'Number of Simulations : %d' % num_simulations
print 'Number of Students: %d' % num_students
print 'Number of Simulations with duplication: %d' % count
print 'Percentage of Simulations with Duplucation: %d%%' % (count * 100 / num_simulations)