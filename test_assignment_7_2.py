import pytest
import random
import statistics

from dataclasses import dataclass


@pytest.fixture(autouse=True)
def is_c_code_used(code):
    checks = ['cstdio', 'stdio.h', 'cstdlib', 'stdlib.h', 'cstdbool', 'stdbool.h']
    assert not any(c in code for c in checks), 'You have used the C Standard Library in a C++ assignment'


@dataclass()
class Data:
    even: list
    odd: list


@pytest.fixture()
def data():
    return Data(random.sample(range(1, 100), 10), random.sample(range(1, 100), 9))


class TestAssignment72:
    # Prints out the average
    @pytest.mark.repeat(3)
    def test_average(self, app, data):
        stat = float(statistics.mean(data.even))
        app.check(data.even + [0],
                  [f'Average : {round(stat, 4) if not stat.is_integer() else int(stat)}'])

    # Prints out the median
    @pytest.mark.repeat(3)
    def test_median_even(self, app, data):
        stat = float(statistics.median(data.even))
        app.check(data.even + [0],
                  [f'Median : {round(stat, 4) if not stat.is_integer() else int(stat)}'])

    # Prints out the median
    @pytest.mark.repeat(3)
    def test_median_odd(self, app, data):
        stat = float(statistics.median(data.odd))
        app.check(data.odd + [0],
                  [f'Median : {round(stat, 4) if not stat.is_integer() else int(stat)}'])

    # Prints out the numbers sorted, in descending order
    @pytest.mark.repeat(3)
    def test_sorted_descending(self, app, data):
        descending = data.even.copy()
        descending.sort(reverse=True)
        app.check(data.even + [0],
                  [f"Descending : {(' '.join([str(i) for i in descending]))}"])
