import random
import subprocess

EXE = "../PmergeMe"

def test_10():
    for n in range(100):
        num_list = random.sample(range(100), 10)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, capture_output=True)
        assert b"successfully sorted" in res.stdout
        
def test_100():
    for n in range(100):
        num_list = random.sample(range(1000), 100)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, capture_output=True)
        assert b"successfully sorted" in res.stdout
        
def test_1000():
    for n in range(100):
        num_list = random.sample(range(10000), 1000)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, capture_output=True)
        assert b"successfully sorted" in res.stdout
        
def test_5000():
    for n in range(100):
        num_list = random.sample(range(100000), 5000)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, capture_output=True)
        assert b"successfully sorted" in res.stdout
