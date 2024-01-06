import pytest
import random


@pytest.fixture()
def numbers():
    return [i / 10 for i in random.sample(range(10, 100), 10)]


class TestAssignment21:
    def test_no_numbers(self, app):
        app.check(0, ['Count: 0', 'Sum: 0'])

    def test_count(self, app, numbers):
        app.check(numbers + [0], 'Count: %i' % len(numbers))

    def test_sum(self, app, numbers):
        app.check(numbers + [0], 'Sum: %g' % sum(numbers))

    def test_average(self, app, numbers):
        app.check(numbers + [0], 'Average: %g' % (sum(numbers) / len(numbers)))
