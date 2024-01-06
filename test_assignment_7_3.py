import pytest
import random

from dataclasses import dataclass


@pytest.fixture(autouse=True)
def is_c_code_used(code):
    checks = ['cstdio', 'stdio.h', 'cstdlib', 'stdlib.h', 'cstdbool', 'stdbool.h']
    assert not any(c in code for c in checks), 'You have used the C Standard Library in a C++ assignment'


@dataclass()
class Data:
    courses: list
    grades: list


@pytest.fixture()
def data(fake):
    courses = list(set([fake.job() for _ in range(0, 10)]))
    grades = list('ABCDEF')

    return Data(courses, grades)


class TestAssignment73:
    def test_one_student_one_course(self, app, fake, data: Data):
        student = fake.name()
        course = random.choice(data.courses)
        grade = random.choice(data.grades)

        app.check([student, course, grade, 'stop', 'stop'],
                  [f'{student} - {course} - {grade}'])

    def test_one_student_two_courses(self, app, fake, data: Data):
        student = fake.name()
        courses = random.sample(data.courses, 2)
        grades = random.sample(data.grades, 2)

        app.check([student, courses[0], grades[0], 'stop',
                   student, courses[1], grades[1], 'stop', 'stop'],
                  [f'{student} - {courses[0]} - {grades[0]}',
                   f'{student} - {courses[1]} - {grades[1]}'])

    def test_two_students_one_course(self, app, fake, data: Data):
        students = [fake.name(), fake.name()]
        courses = random.sample(data.courses, 2)
        grades = random.sample(data.grades, 2)

        app.check([students[0], courses[0], grades[0], 'stop',
                   students[1], courses[1], grades[1], 'stop', 'stop'],
                  [f'{students[0]} - {courses[0]} - {grades[0]}',
                   f'{students[1]} - {courses[1]} - {grades[1]}'])

    def test_two_students_two_courses(self, app, fake, data: Data):
        students = [fake.name(), fake.name()]
        courses = random.sample(data.courses, 4)
        grades = random.sample(data.grades, 4)
        
        app.check([students[0], courses[0], grades[0], 'stop',
                   students[0], courses[1], grades[1], 'stop',
                   students[1], courses[2], grades[2], 'stop',
                   students[1], courses[3], grades[3], 'stop', 'stop'],
                  [f'{students[0]} - {courses[0]} - {grades[0]}',
                   f'{students[0]} - {courses[1]} - {grades[1]}',
                   f'{students[1]} - {courses[2]} - {grades[2]}',
                   f'{students[1]} - {courses[3]} - {grades[3]}'])
