from subprocess import run, PIPE
import os
import pytest

B_FILE_PATH = './bin/binary_div'

if os.path.isfile(B_FILE_PATH):

    def test_binary_div_1():
        result = run([B_FILE_PATH], input='abrakadabra', encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout.strip() == 'abrakadabra\nabraka\nabr\nab\na'
    
    def test_binary_div_2():
        result = run([B_FILE_PATH], input='a', encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout.strip() == 'a'

    def test_binary_div_3():
        result = run([B_FILE_PATH], input='ab', encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout.strip() == 'ab\na'

    def test_binary_div_4():
        result = run([B_FILE_PATH], input='1234567890', encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout.strip() == '1234567890\n12345\n123\n12\n1'
    
    def test_binary_div_5():
        result = run([B_FILE_PATH], input='r2d2', encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout.strip() == 'r2d2\nr2\nr'

if __name__ == '__main__':
    pytest.main()
