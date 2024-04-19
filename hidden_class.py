class Classic:
    def visible(self):
        print("I am visible.")

    def __hidden(self):
        print("I cannot be seen, oh you used _classname.__hiddenproperty(). I SEE")

object = Classic()
object.visible()
try:
    object.__hidden()
except:
    print("Something went wrong!")

object._Classic__hidden() # This will access the hidden property
print(hasattr(Classic, '__hidden'))
print(hasattr(Classic, 'visible'))

print(object.__dict__)
print(Classic.__name__)
print(type(object).__name__)