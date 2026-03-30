# CLI - @CodeHaveFun
# CMD cant run - return text and print information, credits, etc.
################ INFORMATIOM - CREDITS #########################
core_credits = """
 ╔══════════════════════════════════════╗
 ║             CORE PROJECT             ║
 ║             v0.0.1 - Demo            ║
 ╚══════════════════════════════════════╝
 Author      : @CodeHaveFun (Github)
 Repository  : https://github.com/CodeHaveFun/Core
 Rule        : Developer - Designer - Architect
 Language    : Python
 Framwork    : Core - CoreCLI
 Platform    : Windows
 Build       : Stable (Early Development)
 License     : MIT

"""

core_options = """
 Core CLI - Usage
 Command:
     core build <Path File>    | Build File
     core run <Path File>      | Run File
     credits                   | Show information
     help                      | Show options
"""
################ TEXT ERROR - CODE ERROR #######################
# Text Error: Show for user see error information
# Code Error: Show for user see error code
# |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
# Error end
FAIL_BAR = "============FAIL============"
# Case 1 (Popular): Error when typing wrong
WRG_CMD_1_TEXT = "is not recognized or any commands"
WRG_CMD_1_ERR = "WRG_CMD_1"
#------------------------------------------
# Case 2: missing command
WRG_MSS_CMD_TEXT = "Missing command! Need adding a command"
WRG_MSS_CMD_ERR = "WRG_MSS_CMD"
# Case 3: Build need location file (Core$ Error)
WRG_BLD_NED_LCT_TEXT = "Where is location file?"
WRG_BLD_NED_LCT_ERR = "WRG_BLD_NED_LCT"
# Case 4: Build cant see location or provide file
WRG_BLD_CNT_SEF_TEXT = "Don't see file! Check right your path and file"
WRG_BLD_CNT_SEF_ERR = "WRG_BLD_CNT_SEF"