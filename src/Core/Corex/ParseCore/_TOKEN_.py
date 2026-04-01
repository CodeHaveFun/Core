# TOKEN - PARSE - @CodeHaveFun


import json
from .SetPathConfig import PathConfig
def main():
    with open(PathConfig("Core_config.json"),"r",encoding="utf-8") as test:
        data = json.load(test)
    print(data["PATH_FILE"])