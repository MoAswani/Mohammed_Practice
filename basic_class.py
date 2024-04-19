class Super_class():
    def __init__(self, name, age):
        self.name = "Aswani"
        self.age = 22
        self.experience = "Dejavu"

    def __str__(self):
        return f"My name is {self.name} and I am {self.age} years old."

class sub_class(Super_class):
    def __init__(self, name,age):
        #Super_class.__init__(self, name, age)
        # or 
        super().__init__(name, age)
        self.age = 15
        

myobject = sub_class("Aswani", 22)
myobject2 = sub_class("Ambale", 23)

print(myobject)
print(myobject.age)
print(myobject.experience)
