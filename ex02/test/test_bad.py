import subprocess

EXE = "../PmergeMe"
ERR_MSG = "PmergeMe: "

def test_no_arg():
    arg = [EXE,]
    res = subprocess.run(arg, universal_newlines=True, capture_output=True)
    assert ERR_MSG in res.stdout

def test_not_digit():
    arg = [EXE, "a"]
    res = subprocess.run(arg, universal_newlines=True, capture_output=True)
    assert ERR_MSG in res.stdout
    arg = [EXE, "1a"]
    res = subprocess.run(arg, universal_newlines=True, capture_output=True)
    assert ERR_MSG in res.stdout
    arg = [EXE, "-1"]
    res = subprocess.run(arg, universal_newlines=True, capture_output=True)
    assert ERR_MSG in res.stdout
    arg = [EXE, "+2"]
    res = subprocess.run(arg, universal_newlines=True, capture_output=True)
    assert ERR_MSG in res.stdout
    arg = [EXE, "0-"]
    res = subprocess.run(arg, universal_newlines=True, capture_output=True)
    assert ERR_MSG in res.stdout

def test_duplicate():
    arg = [EXE, "0", "0"]
    res = subprocess.run(arg, universal_newlines=True, capture_output=True)
    assert ERR_MSG in res.stdout
    arg = [EXE, "0", "000"]
    res = subprocess.run(arg, universal_newlines=True, capture_output=True)
    assert ERR_MSG in res.stdout
    arg = [EXE, "123", "0", "1230", "123"]
    res = subprocess.run(arg, universal_newlines=True, capture_output=True)
    assert ERR_MSG in res.stdout

def test_out_of_int():
    arg = [EXE, "2147483648"]
    res = subprocess.run(arg, universal_newlines=True, capture_output=True)
    assert ERR_MSG in res.stdout
    arg = [EXE, "-2147483649"]
    res = subprocess.run(arg, universal_newlines=True, capture_output=True)
    assert ERR_MSG in res.stdout
