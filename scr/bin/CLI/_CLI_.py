# CLI - @CodeHaveFun

# parse token input
import shlex as core_parse 
import _CLI_TEXT_ as CTE

def _Excus_CMD_(_IN_TOKEN_):
    if(_IN_TOKEN_[0] == "core"):   # Token Main 
        if(_IN_TOKEN_[1] == "run"):
            print("run: ok")
        else:
            print(f"Core$: '{_IN_TOKEN_[1]}' {CTE.WRG_CMD_1_TEXT}")
            print(f"Core$: {CTE.WRG_CMD_1_ERR} \n")
            


def _CoreCLI_():
    while True:
        Core_Args = core_parse.split(input("~$ "))
        if Core_Args[0] == "core" or Core_Args[0] == "-help":
            _Excus_CMD_(Core_Args)
        else:
            # Case 1: Error Typing
            print(f"'{Core_Args[0]}' {CTE.WRG_CMD_1_TEXT}") 
            print(f"Err: {CTE.WRG_CMD_1_ERR} \n")
if __name__ == "__main__":
    _CoreCLI_()