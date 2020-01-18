""" def plus(a,b): 
    return a+b

result = plus(b=30,a=1)
print(result) """

""" def say_helllo(name,age):
#    return f"Hello {name} you are {age} years old"
    return "Hello "+name+" you are "+age+" years old"

hello= say_helllo(name="nico",age="12")
print(hello) """
def say_helllo(name,age,are_from,fav_food):
    return f"Hello {name} you are {age} years old you are from {are_from} you like {fav_food}"

#hello= say_helllo("nico","12","kimchi","colombia")
hello= say_helllo(name="nico",age="12",fav_food="kimchi",are_from="colombia")
print(hello)