import pytest
import random


class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def cmd(self):
        return [self.name, self.age]

    def __str__(self):
        return "Name = %s, Age = %i" % (self.name, self.age)


class StudentCreator:
    def __init__(self, fake):
        names = [fake.name() for i in range(20)]
        ages = random.sample(range(10, 100), 20)

        self.students = []
        self.cmds = []
        self.youngest = None
        self.oldest = None

        for i in range(0, 20):
            s = Student(names[i], ages[i])
            self.students.append(s)
            self.cmds.extend(s.cmd())

            if not self.youngest or s.age < self.youngest.age:
                self.youngest = s

            if not self.oldest or s.age > self.oldest.age:
                self.oldest = s


@pytest.fixture()
def student(fake):
    return StudentCreator(fake)


class TestAssignment62:
    def test_no_students(self, app):
        app.check(['stop'], ['No students were given'])

    def test_count(self, app, student):
        app.check(student.cmds + ['stop'], ['Count: %i' % (len(student.students))])

    def test_student_information(self, app, student):
        app.check(student.cmds + ['stop'], [str(s) for s in student.students])

    def test_youngest(self, app, student):
        app.check(student.cmds + ['stop'], ['Youngest: %s' % student.youngest.name])

    def test_oldest(self, app, student):
        app.check(student.cmds + ['stop'], ['Oldest: %s' % student.oldest.name])

    def test_malloc_used(self, code):
        assert 'malloc(' in code, "malloc() isn't used, are you using arrays? This is not allowed."

    def test_realloc_used(self, code):
        assert 'realloc(' in code, "realloc() isn't used, have you forgotten to resize memory as needed?"

    def test_free_used(self, code):
        assert 'free(' in code, "free() isn't used, have you forgot to free memory?"
