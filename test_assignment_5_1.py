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


class TestAssignment51:
    def test_input_only(self, app, student):
        app.check(student.as_list())

    def test_id(self, app, student):
        app.check(student.student, ['Student id: %i' % student.student_id])

    def test_name(self, app, student):
        app.check(student.student, ['Name: %s' % student.name])

    def test_age(self, app, student):
        app.check(student.student, ['Age: %i' % student.age])

    def test_struct_used(self, code):
        assert 'typedefstruct' in code, \
            'Type definition \'typedef struct\' not found in the code.'

    def test_student_used(self, code):
        assert '}student_t;' in code, \
            'Missing definition, \'student_t\' not found in the code.'
