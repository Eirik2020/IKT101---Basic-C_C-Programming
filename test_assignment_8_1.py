import pytest
import random


class Data:
    def __init__(self):
        self.ints = random.sample(range(0, 100), random.randint(10, 20))
        self.cmd = []

        for i in self.ints:
            self.cmd.extend([1, i])


def expected(ints):
    return f'List contains {len(ints)} integers: ' + ' '.join([str(i) for i in ints])


@pytest.fixture()
def data():
    return Data()


@pytest.fixture(autouse=True)
def is_cpp_containers_used(code):
    checks = ['<vector>', '<list>', '<map>', '"vector"', '"list"', '"map"']
    assert not any(c in code for c in checks), 'You have used C++ containers, these are not allowed in this assignment'


class TestAssignment81:
    def test_exit(self, app):
        app.check(5)

    def test_no_integers(self, app):
        app.check([4, 5], 'List contains no integers')

    def test_print_integers(self, app, data):
        app.check(data.cmd + [4, 5], expected(data.ints))

    def test_get_first_integer(self, app, data):
        app.check(data.cmd + [2, 0, 5], f'Integer at index 0: {data.ints[0]}')

    def test_get_middle_integer(self, app, data):
        app.check(data.cmd + [2, 5, 5], f'Integer at index 5: {data.ints[5]}')

    def test_get_last_integer(self, app, data):
        index = len(data.ints) - 1
        app.check(data.cmd + [2, index, 5], f'Integer at index {index}: {data.ints[index]}')

    def test_remove_first_integer(self, app, data):
        app.check(data.cmd + [3, 0, 4, 5], expected(data.ints[1:]))

    def test_remove_middle_integer(self, app, data):
        app.check(data.cmd + [3, 5, 4, 5], expected(data.ints[:5] + data.ints[6:]))

    def test_remove_last_integer(self, app, data):
        app.check(data.cmd + [3, len(data.ints) - 1, 4, 5], expected(data.ints[:-1]))

    def test_class_functions(self, code):
        checks = [
            'void push_back(const int value)',
            'size_t size()',
            'int& at(size_t index)',
            'void remove(size_t index)'
        ]

        assert all(''.join(c.split()) in code for c in checks), 'Your class is missing one or more required functions'
