import pytest
import random


@pytest.fixture()
def word(fake):
    return fake.word()


class TestAssignment41:
    def test_letter_count(self, app, word):
        app.check(word, ['The word contains %i letters' % (len(word))])

    def test_is_not_palindrome(self, app, word):
        app.check([word + str(random.randint(0, 9))],
                  ['The word is not a palindrome'],
                  ['The word is a palindrome'])

    def test_is_palindrome(self, app, word):
        palindrome = word + word[::-1]
        app.check([palindrome], ['The word is a palindrome'], ['The word is not a palindrome'])

    def test_word_reversed(self, app, word):
        re_word = word[::-1]
        app.check([word], ['The word reversed is \'%s\'' % re_word])

    def test_bool_used(self, code):
        assert 'boolis_palindrome(' in code, \
            'Function \'is_palindrome\' not found in the code. Check name and/or return type?'

    def test_void_used(self, code):
        assert 'voidstring_reverse(' in code, \
            'Function \'string_reverse\' not found in the code. Check name and/or return type?'
