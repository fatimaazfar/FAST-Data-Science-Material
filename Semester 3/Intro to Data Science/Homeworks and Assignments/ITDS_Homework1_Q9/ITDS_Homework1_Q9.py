class tuples:
    def _init_ (self, tuple):
        self.tuple = tuple
    def add(self,tup):
        self.tuple += tup
    def sub(self,tup):
        self.tuple -= tup
    def mul(self,tup):
        self.tuple *= tup
    def div(self,tup):
        self.tuple /= tup
    def pow(self,tup):
        self.tuple = self.tuple ** tup
    def getTuple(self):
        return self.tuple
    def setTuple(self,tup):
        self.tuple = tup

a = tuples()
b = tuples()
a.setTuple((1,2,3))
b.setTuple((4,5,6))

print("a = ",a)
print("b = ",b)

print("Added : ")
a.add(b)

print("a = ",a)
print("b = ",b)

print("Subtracted : ")
a.sub(b)

print("a = ",a)
print("b = ",b)

print("Multiplied : ")
a.mul(b)

print("a = ",a)
print("b = ",b)

print("Divided : ")
a.div(b)

print("a = ",a)
print("b = ",b)

print("Power : ")
a.pow(b)

print("a = ",a)
print("b = ",b)