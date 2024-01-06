import os
import pytest
import random


class Student:
    def __init__(self, fake):
        self.student_id = random.randrange(10000, 100000)
        self.name = fake.name()
        self.age = random.randint(18, 25)
        self.student = [self.student_id, self.name, self.age]

    def as_list(self):
        return [self.student_id, self.name, self.age, self.student]


@pytest.fixture()
def student(fake):
    return Student(fake)


class TestAssignment52:
    @staticmethod
    def write_student(student):
        with open("student_read.txt", "w") as text_file:
            text_file.write("%i\n%s\n%i\n" % (student.student_id, student.name, student.age))

    def test_exit(self, app):
        app.check([3])

    def test_read_id(self, app, student):
        self.write_student(student)
        app.check([1, 3], ['Student id: %i' % student.student_id])

    def test_read_name(self, app, student):
        self.write_student(student)
        app.check([1, 3], ['Name: %s' % student.name])

    def test_read_age(self, app, student):
        self.write_student(student)
        app.check([1, 3], ['Age: %i' % student.age])

    def test_write(self, app, student):
        app.check([2] + student.student + [3])

        assert os.path.isfile('student_write.txt'), 'Failed to find student_write.txt. Wrong filename?'

        with open('student_write.txt') as f:
            student_info = f.read().splitlines()

        assert str(student.student_id) in student_info, 'Failed to find student id in file.'
        assert student.name in student_info, 'Failed to find student name in file.'
        assert str(student.age) in student_info, 'Failed to find student age in file.'
