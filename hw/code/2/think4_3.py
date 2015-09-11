from swampy.TurtleWorld import *
import math
    
def polygon(t, n, r):
    angle = 360.0 / n
    for i in range(n):
        triangle(t, r, angle/2)
        lt(t, angle)
    pu(t)
    fd(t, 120)
    pd(t)

def triangle(turtle_obj, radius, angle):
    base_angle = radius * math.sin(angle * math.pi / 180)
    rt(turtle_obj, angle)
    fd(turtle_obj, radius)
    lt(turtle_obj, 90+angle)
    fd(turtle_obj, 2*base_angle)
    lt(turtle_obj, 90+angle)
    fd(turtle_obj, radius)
    lt(turtle_obj, 180-angle)


world = TurtleWorld()
bob = Turtle()
bob.delay = 0.1

polygon(bob, 5, 50)
polygon(bob, 6, 50)
polygon(bob, 7, 50)
die(bob)

wait_for_user()