# @CodeHaveFun - SetPathConfig
# return real path
from pathlib import Path

def PathConfig(path_file :str) -> str:
    current_dir = Path(__file__).parent
    return current_dir / path_file