import pytest
import random


@pytest.fixture()
def numbers():
    return random.sample(range(100), random.randint(10, 20))


class TestAssignment61:
    def test_no_numbers(self, app):
        app.check(0, ['No numbers were given'])

    def test_count(self, app, numbers):
        app.check([len(numbers)] + numbers, ['Count: %i' % (len(numbers))])

    def test_ordered(self, app, numbers):
        app.check([len(numbers)] + numbers, ['Numbers: ' + ' '.join([str(num) for num in numbers])])

    def test_sorted(self, app, numbers):
        app.check([len(numbers)] + numbers, ['Sorted: ' + ' '.join([str(num) for num in sorted(numbers)])])

    def test_malloc_used(self, code):
        assert 'malloc(' in code, "malloc() isn't used, are you using arrays? This is not allowed."

    def test_free_used(self, code):
        assert 'free(' in code, "free() isn't used, have you forgotten to free memory?"
