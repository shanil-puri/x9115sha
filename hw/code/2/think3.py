def repeat_lyrics():
    print_lyrics()
    print_lyrics()

def print_lyrics():
    print "I'm a lumberjack, and I'm okay."
    print "I sleep all night and I work all day."

repeat_lyrics()

# Excercise 3.3
def right_justify(s):
    print " " * (70 - len(s)) + s
    
right_justify("allen")

#Excercise 3.4.1
def do_twice(f):
    f()
    f()
    
def print_spam():
    print "spam"
    
do_twice(print_spam)

#Excercise 3.4.2
def do_twice(f, v):
    f(v)
    f(v)
    
def print_spam(s):
    print s
    
do_twice(print_spam, "rand")

#Excercise 3.4.3
def do_twice(f, v):
    f(v)
    f(v)
    
def print_twice(s):
    print s
    print s
    
do_twice(print_twice, "rand")

#Excercise 3.4.4
def do_twice(f, v):
    f(v)
    f(v)
    
def print_twice(s):
    print s
    print s
    
do_twice(print_twice, "spam")

#Excercise 3.4.5
def do_twice(f, v):
    f(v)
    f(v)
    
def print_twice(s):
    print s
    print s
    
def do_four(f, v):
    do_twice(f, v)
    do_twice(f, v)
    
do_four(print_twice, "3.4.5")

# #Excercise 3.5.1
def draw_grid():
    for i in range(0, 11):
        if(i%5 == 0):
            print "+", (" _"*4 + "+")*2
        else:
            print "|", ("  "*4 + "|")*2
draw_grid()

#Excercise 3.5.2
def draw_row(num_cols):
    for i in range(0, 5):
        if(i%5 == 0):
            print "+", (" _"*4 + "+")*num_cols
        else:
            print "|", ("  "*4 + "|")*num_cols

def draw_grid(num_rows, num_cols):
    for i in range(0, num_rows):
        draw_row(num_cols)
    print "+", (" _"*4 + "+")*num_cols

draw_grid(4, 4)

