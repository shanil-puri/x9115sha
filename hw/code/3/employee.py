class Employee(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def __str__(self):
        str = "Name: %s" % self.name
        str += "\nAge: %d" % self.age
        return str

    def __lt__(self, other):
        ##operator overloading to compare Employee type objects based on age
        return self.age < other.age


emp_1 = Employee("Bob", 26)
emp_2 = Employee("Tod", 50)
print "Employee 1: \n"
print emp_1
print "Employee 2: \n"
print emp_2
print "\nOverriddent comparator: \n"
print '%s\'s age is < than %s\'s age: %r' % (emp_1.name, emp_2.name, emp_1 < emp_2)
print '%s\'s age is < than %s\'s age: %r' % (emp_2.name, emp_1.name, emp_2 < emp_1)