import random
import subprocess

EXE = "../PmergeMe"
COMP_MSG = "total comparison: "

def test_15():
    for n in range(100):
        num_list = random.sample(range(10000), 15)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, universal_newlines=True, capture_output=True)
        assert "successfully sorted" in res.stdout
        assert "total comparison: " in res.stdout
        pos = res.stdout.find(COMP_MSG)
        num = int(res.stdout[pos + len(COMP_MSG):])
        assert num <= 42
        
def test_20():
    for n in range(100):
        num_list = random.sample(range(10000), 20)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, universal_newlines=True, capture_output=True)
        assert "successfully sorted" in res.stdout
        assert "total comparison: " in res.stdout
        pos = res.stdout.find(COMP_MSG)
        num = int(res.stdout[pos + len(COMP_MSG):])
        assert num <= 62

def test_25():
    for n in range(100):
        num_list = random.sample(range(10000), 25)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, universal_newlines=True, capture_output=True)
        assert "successfully sorted" in res.stdout
        assert "total comparison: " in res.stdout
        pos = res.stdout.find(COMP_MSG)
        num = int(res.stdout[pos + len(COMP_MSG):])
        assert num <= 86
        
def test_30():
    for n in range(100):
        num_list = random.sample(range(10000), 30)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, universal_newlines=True, capture_output=True)
        assert "successfully sorted" in res.stdout
        assert "total comparison: " in res.stdout
        pos = res.stdout.find(COMP_MSG)
        num = int(res.stdout[pos + len(COMP_MSG):])
        assert num <= 111
        
def test_33():
    for n in range(100):
        num_list = random.sample(range(10000), 33)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, universal_newlines=True, capture_output=True)
        assert "successfully sorted" in res.stdout
        assert "total comparison: " in res.stdout
        pos = res.stdout.find(COMP_MSG)
        num = int(res.stdout[pos + len(COMP_MSG):])
        assert num <= 126
