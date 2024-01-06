import pytest
import random


@pytest.fixture()
def numbers():
    return random.sample(range(10, 100), 10)


class TestAssignment31:
    def test_min(self, app, numbers):
        app.check(numbers, ["Minimum: %i" % (min(numbers))])

    def test_max(self, app, numbers):
        app.check(numbers, ["Maximum: %i" % (max(numbers))])

    def test_sum(self, app, numbers):
        app.check(numbers, ["Sum: %i" % (sum(numbers))])

    def test_average(self, app, numbers):
        app.check(numbers, ["Average: %g" % (sum(numbers) / len(numbers))])

    def test_sorted(self, app, numbers):
        app.check(numbers, ["Sorted: %s" % (' '.join([str(i) for i in sorted(numbers)]))])

    def test_median(self, app, numbers):
        mid = int(len(sorted(numbers)) / 2) - 1
        median = (sorted(numbers)[mid] + sorted(numbers)[mid + 1]) / 2
        app.check(numbers, ["Median: %g" % median])

    def test_function_minimum(self, code):
        assert 'intminimum(' in code, \
            'Function \'minimum\' not found in the code. Check name and/or return type?'

    def test_function_maximum(self, code):
        assert 'intmaximum(' in code, \
            'Function \'maximum\' not found in the code. Check name and/or return type?'

    def test_function_average(self, code):
        assert 'floataverage(' in code, \
            'Function \'average\' not found in the code. Check name and/or return type?'

    def test_function_median(self, code):
        assert 'floatmedian(' in code, \
            'Function \'median\' not found in the code. Check name and/or return type?'

    def test_function_sum(self, code):
        assert 'intsum(' in code, \
            'Function \'sum\' not found in the code. Check name and/or return type?'
