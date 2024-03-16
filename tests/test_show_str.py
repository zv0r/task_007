from subprocess import run, PIPE
import os
import pytest

B_FILE_PATH = './bin/show_str'

if os.path.isfile(B_FILE_PATH):

    def test_show_str_1():
        result = run([B_FILE_PATH], encoding='utf-8', stdout=PIPE)
        assert result.returncode == 0
        assert result.stdout.strip() == '7 Alexandr Kuricin 18 a.kuricin@yssu.ru'

if __name__ == '__main__':
    pytest.main()