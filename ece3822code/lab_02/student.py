from statistics import mean
class student:
    # Grades Vector
    grades=[]
    
    # Default Constructor
    def __init__(self):
        pass

    # Name Set Function
    def set_name(self,name):
        self.name=name

    # Adding grades to grades vector
    def add_grade(self,grade):
        self.grades.append(grade)

    # Showing the highest grade of the student's grades
    def get_max(self):
        return(max(self.grades))

    # Showing the mean of the student's grades
    def get_average(self):
        return(mean(self.grades))

    # Displaying the student's name and their grades
    def display(self):
        print(self.name,end="")
        print(":",end=" ")
        print(*self.grades,sep = ", ")
     
    
