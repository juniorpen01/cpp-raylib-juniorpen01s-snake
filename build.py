# /// script
# requires-python = ">=3.13"
# dependencies = []
# ///


import os
import shutil
import stat
import subprocess
from argparse import ArgumentParser


def main() -> None:
    parser = ArgumentParser(
        description="CLI tool supporting generate, build, run, test, and clean commands"
    )

    subparsers = parser.add_subparsers(dest="command")

    parser_generate = subparsers.add_parser("generate", help="Generate build files")
    parser_generate.add_argument("variant", choices=["debug", "release"])

    parser_build = subparsers.add_parser(
        "build", help="Build the project from the generated build files"
    )
    parser_build.add_argument("variant", choices=["debug", "release"])

    parser_run = subparsers.add_parser("run", help="Build and run the app")
    parser_run.add_argument("variant", choices=["debug", "release"])
    parser_run.add_argument("--exe", required=True)

    parser_test = subparsers.add_parser("test", help="Run tests on the project")
    parser_test.add_argument("variant", choices=["debug", "release"])

    subparsers.add_parser("clean", help="Delete the build directory")

    args = parser.parse_args()

    match args.command:
        case "generate":
            subprocess.run(["cmake", "--preset", args.variant])
        case "build":
            subprocess.run(["cmake", "--build", "--preset", args.variant])
        case "run":
            subprocess.run(["cmake", "--build", "--preset", args.variant])
            subprocess.run([f"./build/{args.variant}/{args.exe}"])
        case "test":
            subprocess.run(["ctest", "--preset", args.variant])
        case "clean":

            def onexc(func, path, _):
                os.chmod(path, stat.S_IWRITE)
                func(path)

            shutil.rmtree("build", onexc=onexc)
        case _:
            parser.print_help()


if __name__ == "__main__":
    main()
