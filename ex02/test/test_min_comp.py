import random
import subprocess

EXE = "../PmergeMe"
SORT_MSG = "successfully sorted"
COMP_MSG_OF_VEC = "total comparison of vector: "
COMP_MSG_OF_LIS = "total comparison of list: "

def test_15():
    for n in range(100):
        num_list = random.sample(range(10000), 15)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, universal_newlines=True, capture_output=True)
        assert SORT_MSG in res.stdout
        assert COMP_MSG_OF_VEC in res.stdout
        assert COMP_MSG_OF_LIS in res.stdout
        v_pos = res.stdout.find(COMP_MSG_OF_VEC) + len(COMP_MSG_OF_VEC)
        l_pos = res.stdout.find(COMP_MSG_OF_LIS) + len(COMP_MSG_OF_LIS)
        v_end = v_pos
        for i in res.stdout[v_pos]:
            v_end += 1
            if not i.isdigit():
                break
        l_end = l_pos
        for i in res.stdout[l_pos]:
            l_end += 1
            if not i.isdigit():
                break
        v_num = int(res.stdout[v_pos:v_end])
        l_num = int(res.stdout[l_pos:l_end])
        assert v_num <= 42
        assert l_num <= 42
        
def test_20():
    for n in range(100):
        num_list = random.sample(range(10000), 20)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, universal_newlines=True, capture_output=True)
        assert SORT_MSG in res.stdout
        assert COMP_MSG_OF_VEC in res.stdout
        assert COMP_MSG_OF_LIS in res.stdout
        v_pos = res.stdout.find(COMP_MSG_OF_VEC) + len(COMP_MSG_OF_VEC)
        l_pos = res.stdout.find(COMP_MSG_OF_LIS) + len(COMP_MSG_OF_LIS)
        v_end = v_pos
        for i in res.stdout[v_pos]:
            v_end += 1
            if not i.isdigit():
                break
        l_end = l_pos
        for i in res.stdout[l_pos]:
            l_end += 1
            if not i.isdigit():
                break
        v_num = int(res.stdout[v_pos:v_end])
        l_num = int(res.stdout[l_pos:l_end])
        assert v_num <= 62
        assert l_num <= 62

def test_25():
    for n in range(100):
        num_list = random.sample(range(10000), 25)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, universal_newlines=True, capture_output=True)
        assert SORT_MSG in res.stdout
        assert COMP_MSG_OF_VEC in res.stdout
        assert COMP_MSG_OF_LIS in res.stdout
        v_pos = res.stdout.find(COMP_MSG_OF_VEC) + len(COMP_MSG_OF_VEC)
        l_pos = res.stdout.find(COMP_MSG_OF_LIS) + len(COMP_MSG_OF_LIS)
        v_end = v_pos
        for i in res.stdout[v_pos]:
            v_end += 1
            if not i.isdigit():
                break
        l_end = l_pos
        for i in res.stdout[l_pos]:
            l_end += 1
            if not i.isdigit():
                break
        v_num = int(res.stdout[v_pos:v_end])
        l_num = int(res.stdout[l_pos:l_end])
        assert v_num <= 86
        assert l_num <= 86
        
def test_30():
    for n in range(100):
        num_list = random.sample(range(10000), 30)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, universal_newlines=True, capture_output=True)
        assert SORT_MSG in res.stdout
        assert COMP_MSG_OF_VEC in res.stdout
        assert COMP_MSG_OF_LIS in res.stdout
        v_pos = res.stdout.find(COMP_MSG_OF_VEC) + len(COMP_MSG_OF_VEC)
        l_pos = res.stdout.find(COMP_MSG_OF_LIS) + len(COMP_MSG_OF_LIS)
        v_end = v_pos
        for i in res.stdout[v_pos]:
            v_end += 1
            if not i.isdigit():
                break
        l_end = l_pos
        for i in res.stdout[l_pos]:
            l_end += 1
            if not i.isdigit():
                break
        v_num = int(res.stdout[v_pos:v_end])
        l_num = int(res.stdout[l_pos:l_end])
        assert v_num <= 111
        assert l_num <= 111
        
def test_33():
    for n in range(100):
        num_list = random.sample(range(10000), 33)
        str_list = [EXE,]
        for i in num_list:
            str_list.append(str(i))
        res = subprocess.run(str_list, universal_newlines=True, capture_output=True)
        assert SORT_MSG in res.stdout
        assert COMP_MSG_OF_VEC in res.stdout
        assert COMP_MSG_OF_LIS in res.stdout
        v_pos = res.stdout.find(COMP_MSG_OF_VEC) + len(COMP_MSG_OF_VEC)
        l_pos = res.stdout.find(COMP_MSG_OF_LIS) + len(COMP_MSG_OF_LIS)
        v_end = v_pos
        for i in res.stdout[v_pos]:
            v_end += 1
            if not i.isdigit():
                break
        l_end = l_pos
        for i in res.stdout[l_pos]:
            l_end += 1
            if not i.isdigit():
                break
        v_num = int(res.stdout[v_pos:v_end])
        l_num = int(res.stdout[l_pos:l_end])
        assert v_num <= 126
        assert l_num <= 126
