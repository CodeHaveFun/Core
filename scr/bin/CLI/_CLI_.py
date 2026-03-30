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
from colorama import init, Fore, Back, Style
init()
def _ErrShow_(MODE=None, INFO=None, ERRCODE=None):
    if INFO and MODE:
        print(f"{Style.BRIGHT + Fore.BLUE}[{MODE}] {Style.BRIGHT + Fore.RED}{INFO}{Style.RESET_ALL}")
    elif INFO:
        print(f"{Style.BRIGHT + Fore.RED}{INFO}{Style.RESET_ALL}")

    # In mã lỗi nếu có
    if ERRCODE:
        print(f"{Fore.YELLOW}ERR: {ERRCODE}{Style.RESET_ALL}")

    # Thanh fail
    print(f"{Fore.RED}{CTE.FAIL_BAR}{Style.RESET_ALL}\n")
# Run 
def _Excus_CMD_(_IN_TOKEN_):
    # check cmd have mode cmd?
    if not(len(_IN_TOKEN_) > 0):
        pass
    else:    
        if _IN_TOKEN_[0] == "core":   # Token Main
            if len(_IN_TOKEN_) <= 1:
                _ErrShow_(
                    MODE="Core$",
                    INFO=f"{CTE.WRG_MSS_CMD_TEXT} for 'core' command",
                    ERRCODE=CTE.WRG_MSS_CMD_ERR
                )

            else:
                if _IN_TOKEN_[1] == "build":
                    if len(_IN_TOKEN_) <= 2:
                        _ErrShow_(
                            MODE="Core$ Build",
                            INFO=CTE.WRG_BLD_NED_LCT_TEXT,
                            ERRCODE=CTE.WRG_BLD_NED_LCT_ERR
                        )

                    else:
                        if coreSys.path.exists(_IN_TOKEN_[2]) and coreSys.path.isfile(_IN_TOKEN_[2]):
                            print("okk")
                        else:
                            _ErrShow_(
                                MODE="Core$ Build",
                                INFO=CTE.WRG_BLD_CNT_SEF_TEXT,
                                ERRCODE=CTE.WRG_BLD_CNT_SEF_ERR
                            )

                else:
                    _ErrShow_(
                        MODE="Core$",
                        INFO=f"'{_IN_TOKEN_[1]}' {CTE.WRG_CMD_1_TEXT}",
                        ERRCODE=CTE.WRG_CMD_1_ERR
                    )

        elif _IN_TOKEN_[0] == "credits":
            print(CTE.core_credits, "\n")

        elif _IN_TOKEN_[0] == "help":
            print(CTE.core_options, "\n")

        else:
            _ErrShow_(
                INFO=f"'{_IN_TOKEN_[0]}' {CTE.WRG_CMD_1_TEXT}",
                ERRCODE=CTE.WRG_CMD_1_ERR
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