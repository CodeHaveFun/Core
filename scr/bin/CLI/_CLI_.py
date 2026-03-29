# CLI - @CodeHaveFun
# ALL Commands CLI for Core Version 0.0.1
#(MODE1): core
# --> 1. 'build'
# --> 2. 'run'
#(MODE2): credits - help



# parse token input
import shlex as coreCLI_parse
import os as coreSys
import _CLI_TEXT_ as CTE
# Run 
def _Excus_CMD_(_IN_TOKEN_):
    # check cmd have mode cmd?
    if not(len(_IN_TOKEN_) > 0):
        pass
    else:    
        if(_IN_TOKEN_[0] == "core"):   # Token Main
            # Check
            if not (len(_IN_TOKEN_) > 1):
                print(f"Core$: {CTE.WRG_MSS_CMD_TEXT} for 'core' command \nCore$: Err: {CTE.WRG_MSS_CMD_ERR}\n")
            else:
                # Core: Build File
                if(_IN_TOKEN_[1] == "build"):
                    # Check location
                    if not(len(_IN_TOKEN_) > 2):
                        print(f"Core$ Build: {CTE.WRG_BLD_NED_LCT_TEXT} \nCore$ Build Err: {CTE.WRG_BLD_NED_LCT_ERR}\n")
                    else:
                        # Check right path and file
                        if (coreSys.path.exists(_IN_TOKEN_[2]) and coreSys.path.isfile(_IN_TOKEN_[2])):
                            print("okk")
                        else:
                            print(f"Core$ Build Locat: {CTE.WRG_BLD_CNT_SEF_TEXT} \nCore$ Build Locat: {CTE.WRG_BLD_CNT_SEF_ERR}\n")
                else:
                    print(f"Core$: '{_IN_TOKEN_[1]}' {CTE.WRG_CMD_1_TEXT} \nCore$: {CTE.WRG_CMD_1_ERR}\n")
        elif (_IN_TOKEN_[0] == "credits"):
            print(CTE.core_credits, "\n")
        elif (_IN_TOKEN_[0] == "help"):
            print(CTE.core_options, "\n")
        else:
            # Case 1: Error Typing
            print(f"'{_IN_TOKEN_[0]}' {CTE.WRG_CMD_1_TEXT} \nErr: {CTE.WRG_CMD_1_ERR}\n") 


def _CoreCLI_():
    while True:
        try:
            Core_Args = coreCLI_parse.split(input("~$ "), posix=False)
            _Excus_CMD_(Core_Args)
        except (KeyboardInterrupt,ValueError):
            pass
            print()
if __name__ == "__main__":
    _CoreCLI_()