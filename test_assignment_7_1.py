import pytest


@pytest.fixture(autouse=True)
def is_c_code_used(code):
    checks = ['cstdio', 'stdio.h', 'cstdlib', 'stdlib.h', 'cstdbool', 'stdbool.h']
    assert not any(c in code for c in checks), 'You have used the C Standard Library in a C++ assignment'


class TestAssignment71:
    # Tells if the strings are equal or not
    def test_equal_strings(self, app, fake):
        string = fake.paragraph(nb_sentences=1)
        app.check([string, string], ["The strings are equal"], ["The strings are not equal"])

    # Tells if the strings are equal or not
    def test_not_equal_strings(self, app, fake):
        string1 = fake.paragraph(nb_sentences=1)
        string2 = fake.paragraph(nb_sentences=1)
        app.check([string1, string2], ["The strings are not equal"], ["The strings are equal"])

    # Tells if one string is a substring of the other
    def test_substring_first(self, app, fake):
        string = fake.paragraph(nb_sentences=1)
        app.check([string, string + ' ' + fake.paragraph(nb_sentences=1)],
                  ["First string is substring of last string"],
                  ["Last string is substring of first string"])

    # Tells if one string is a substring of the other
    def test_substring_last(self, app, fake):
        string = fake.paragraph(nb_sentences=1)
        app.check([string + ' ' + fake.paragraph(nb_sentences=1), string],
                  ["Last string is substring of first string"],
                  ["First string is substring of last string"])

    # Tells if one string is a substring of the other
    def test_not_substring(self, app, fake):
        string1 = fake.paragraph(nb_sentences=1)
        string2 = fake.paragraph(nb_sentences=1)
        while string2 in string1:
            string2 = fake.paragraph(nb_sentences=1)
        app.check([string1, string2],
                  ["There are no substrings"],
                  ["First string is a substring of last string",
                   "Last string is a substring of first string"])
