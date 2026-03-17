
# Core main
import argparse
core_cli_parser = argparse.ArgumentParser(prog="core")

core_cli_parser.add_argument("command", choices=["build","run"])
core_cli_parser.add_argument("file", nargs="?")

core_cli_args = core_cli_parser.parse_args()

if core_cli_args.command == "build":
    print("OK - Build")
elif core_cli_args.command == "run":
    print("OK - Run")
print(core_cli_args.file)

