"""
    Test file for the "student" class stored in student.cpp and student.h

    @Author: I. Obeid
    @Contact: iyad.obeid@temple.edu
    @Date: August 30, 2023

    Usage:
        python lab_02.py
    
"""

import student as st

def main():

    # // create a new student, add grades, and display results

    alice = st.student()
    alice.set_name("Alice")
    alice.add_grade(95)
    alice.add_grade(88)
    alice.add_grade(92)

    print("\n")
    alice.display()
    print(f"Alice's average = {alice.get_average():0.2f}" )
    print(f"Alice's max score = {alice.get_max()}" )
    print("\n")

main()
