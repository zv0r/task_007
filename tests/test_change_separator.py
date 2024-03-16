from subprocess import run, PIPE
import os
import pytest

B_FILE_PATH = './bin/change_separator'

if os.path.isfile(B_FILE_PATH):

    def test_change_separator_1():
        result = run([B_FILE_PATH], input='mama papa\n#', encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout.strip() == 'mama#papa'

    def test_change_separator_2():
        result = run([B_FILE_PATH], input='bobr\n#', encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout.strip() == 'bobr'

    def test_change_separator_3():
        result = run([B_FILE_PATH], input='bobr uzhik ezhik skunks panda\n+', encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout.strip() == 'bobr+uzhik+ezhik+skunks+panda'

    def test_change_separator_4():
        result = run([B_FILE_PATH], input='love hate\n\n', encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout.strip() == 'love\nhate'

    def test_change_separator_4():
        result = run([B_FILE_PATH], input='Some tricky examples\n ', encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout.strip() == 'Some tricky examples'

if __name__ == '__main__':
    pytest.main()