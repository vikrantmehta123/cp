import subprocess
import sys
from pathlib import Path

def run_cpp_tests(problem_name: str):
    problem_file = Path(f"problems/{problem_name}.cpp")
    input_file = Path(f"tests/{problem_name}.in")

    if not problem_file.exists():
        print(f"❌ C++ source file not found: {problem_file}")
        return

    if not input_file.exists():
        print(f"❌ Input file not found: {input_file}")
        return

    expected_output = input_file.with_suffix(".out")
    if not expected_output.exists():
        print(f"❌ Expected output file not found: {expected_output}")
        return

    print(f"🔍 Running C++ tests for: {problem_name}")

    # Compile
    binary_file = problem_file.with_suffix("")
    compile_result = subprocess.run(
        ["g++", "-std=c++17", "-O2", str(problem_file), "-o", str(binary_file)],
        stderr=subprocess.PIPE,
        text=True
    )

    if compile_result.returncode != 0:
        print("❌ Compilation failed:")
        print(compile_result.stderr)
        return

    print("✅ Compilation successful\n")

    # Run program
    my_output = input_file.with_name(input_file.stem + "_my.out")

    with open(input_file, "r") as fin, open(my_output, "w") as fout:
        result = subprocess.run(
            [str(binary_file)],
            stdin=fin,
            stdout=fout,
            stderr=subprocess.PIPE,
            text=True
        )

    if result.stderr:
        print("⚠️ Program stderr:")
        print(result.stderr.strip(), "\n")

    # Compare output
    expected = expected_output.read_text().strip()
    got = my_output.read_text().strip()

    if expected == got:
        print("✅ Test passed")
    else:
        print("❌ Test failed")
        print("   ├─ Input file :", input_file.name)
        print("   ├─ Expected  :", repr(expected))
        print("   └─ Got       :", repr(got))

    print()

    # Cleanup
    if binary_file.exists():
        binary_file.unlink()

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 run_cpp_tests.py <problem_name>")
        sys.exit(1)

    run_cpp_tests(sys.argv[1])
