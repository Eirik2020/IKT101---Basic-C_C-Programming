import pytest


@pytest.fixture()
def word(fake):
    word = '-'

    while len(word) % 2 != 0:
        word = fake.word().lower() + fake.word().upper()

    return word


class TestAssignment42:
    def test_lowercase(self, app, word):
        app.check(word, [f"The word in lowercase is '{word.lower()}'"])

    def test_uppercase(self, app, word):
        app.check(word, [f"The word in uppercase is '{word.upper()}'"])

    def test_split(self, app, word):
        first_part, second_part = word[:int(len(word) / 2)], word[int(len(word) / 2):]
        app.check([word], [f"The word split in two is '{first_part} - {second_part}'"])
