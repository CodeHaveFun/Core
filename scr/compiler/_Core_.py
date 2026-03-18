import argparse

parser = argparse.ArgumentParser(prog="core")

subparsers = parser.add_subparsers(dest="command")

# command: run
run_parser = subparsers.add_parser("run")
run_parser.add_argument("file")

# command: build
build_parser = subparsers.add_parser("build")
build_parser.add_argument("--fast", action="store_true")

args = parser.parse_args()

if args.command == "run":
    print("Running file:", args.file)

elif args.command == "build":
    print("Building...", "FAST" if args.fast else "NORMAL")