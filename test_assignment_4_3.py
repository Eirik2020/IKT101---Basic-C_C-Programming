class TestAssignment43:
    def test_equal_strings(self, app, fake):
        app.check([fake.word()] * 2, ['The words are equal'])

    def test_not_equal_strings(self, app, fake):
        app.check(fake.words(nb=2, unique=True), ['The words are not equal'])

    def test_substring_first(self, app, fake):
        word = fake.word()
        app.check([word, word + fake.word()],
                  ['Word 1 is a substring of word 2'],
                  ['Word 2 is a substring of word 1', 'No substrings found'])

    def test_substring_last(self, app, fake):
        word = fake.word()
        app.check([word + fake.word(), word],
                  ['Word 2 is a substring of word 1'],
                  ['Word 1 is a substring of word 2', 'No substrings found'])

    def test_not_substring(self, app, fake):
        word1 = word2 = ''

        while word1 in word2 or word2 in word1:
            word1 = fake.word()
            word2 = fake.word()

        app.check([word1, word2],
                  ['No substrings found'],
                  ['Word 1 is a substring of word 2', 'Word 2 is a substring of word 1'])
