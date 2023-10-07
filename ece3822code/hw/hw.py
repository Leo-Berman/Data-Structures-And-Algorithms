class thing:
  def __init__(self,name = "nobody"):
    self.name=name
  def say_hi(self):
    print("hello from " + self.name)
person1 = thing("alice")
person2 = thing()
person1.say_hi()
person2.say_hi()
