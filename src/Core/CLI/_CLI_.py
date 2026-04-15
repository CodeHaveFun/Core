# CLI - @CodeHaveFun
# ALL Commands CLI for Core Version 0.0.1
#(MODE1): core
# --> 1. 'build'
# --> 2. 'run'
#(MODE2): credits - help


# parse token input
import shlex as coreCLI_parse
import os as coreSys
import json
from pathlib import Path
import subprocess
###################################################
import _ErrInfo_ as CTE 

from colorama import init, Fore, Style
init() # load color (CMD)

# Get Real Path
def config_path(input_path :str) -> str:
    current_dir = Path(__file__).parent
    return current_dir / input_path
# Load Error (CLI)
with open(config_path("config_err.json"),"r",encoding="utf-8") as CoreErrorRead: # open config_err
    CoreError = json.load(CoreErrorRead) # Get Text Error (JSON: config_err.json)

def _ErrShow_(MODE=None, INFO=None, ERRCODE=None):
    if INFO and MODE:
        print(f"{Style.BRIGHT + Fore.BLUE}[{MODE}] {Style.BRIGHT + Fore.RED}{INFO}{Style.RESET_ALL}")
    elif INFO:
        print(f"{Style.BRIGHT + Fore.RED}{INFO}{Style.RESET_ALL}")


    if ERRCODE:
        print(f"{Fore.YELLOW}ERR: {ERRCODE}{Style.RESET_ALL}")

    
    print(f"{Fore.RED}{CTE.FAIL_BAR}{Style.RESET_ALL}\n")
# Run 
def _Excus_CMD_(_IN_TOKEN_):
    # check cmd have mode cmd?
    if not(len(_IN_TOKEN_) > 0):
        pass
    else:    
        # ============ MODE CORE ===========
        if _IN_TOKEN_[0] == "core":   # Token Main
            if len(_IN_TOKEN_) <= 1:
                _ErrShow_(
                    MODE="Core$",
                    #INFO=f"{CTE.WRG_MSS_CMD_TEXT} for 'core' command",
                    #ERRCODE=CTE.WRG_MSS_CMD_ERR
                    INFO=f"{CoreError["WRG_MSS_CMD"]["TEXT"]} for 'core' command",
                    ERRCODE=CoreError["WRG_MSS_CMD"]["CODE"]
                )

            else:
                if _IN_TOKEN_[1] == "build":
                    if len(_IN_TOKEN_) <= 2:
                        _ErrShow_(
                            MODE="Core$ Build",
                            #INFO=CTE.WRG_BLD_NED_LCT_TEXT,
                            #ERRCODE=CTE.WRG_BLD_NED_LCT_ERR
                            INFO=CoreError["WRG_BLD_NED_LCT"]["TEXT"],
                            ERRCODE=CoreError["WRG_BLD_NED_LCT"]["CODE"]
                        )

                    else:
                        # ======================== BUILD FILE COMMAND =======================
                        if coreSys.path.exists(_IN_TOKEN_[2]) and coreSys.path.isfile(_IN_TOKEN_[2]): # get path file
                            # Data
                            CoreCLI_Data = {
                                "PATH_FILE": _IN_TOKEN_[2] # Path file

                            }
                            # Show debug path file
                            print(f"[DEBUG]: Now {coreSys.getcwd()}")
                            # run Core.exe 
                            subprocess.run(["Core/Corex/Core.exe", str(_IN_TOKEN_[2])]) 
                            
                        else:
                            _ErrShow_(
                                MODE="Core$ Build",
                                #INFO=CTE.WRG_BLD_CNT_SEF_TEXT,
                                #ERRCODE=CTE.WRG_BLD_CNT_SEF_ERR
                                INFO=f"{CoreError["WRG_BLD_CNT_SEF"]["TEXT"]} (INPUT-> {_IN_TOKEN_[2]})",
                                ERRCODE=CoreError["WRG_BLD_CNT_SEF"]["CODE"]
                            )

                else:
                    _ErrShow_(
                        MODE="Core$",
                        INFO=f"'{_IN_TOKEN_[1]}' {CoreError["WRG_CMD_1"]["TEXT"]}",
                        ERRCODE=CoreError["WRG_CMD_1"]["CODE"]
                    )
        # ========== CREDITS COMMAND ===========
        elif _IN_TOKEN_[0] == "credits":
            print(CTE.core_credits, "\n")
        # ========== HELP COMMAND ==============
        elif _IN_TOKEN_[0] == "help":
            print(CTE.core_options, "\n")

        else:
            _ErrShow_(
                INFO=f"'{_IN_TOKEN_[0]}' {CoreError["WRG_CMD_1"]["TEXT"]}",
                ERRCODE=CoreError["WRG_CMD_1"]["CODE"]
            )

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