import subprocess
import sys
from pathlib import Path

def run_tests(dirname:str, problem_name:str):
    problem_file = Path(f"problems/{dirname}/{problem_name}.py")
    test_dir = Path(f"tests/{dirname}/{problem_name}")

    if not problem_file.exists():
        print(f"❌ Problem file not found: {problem_file}")
        return
    if not test_dir.exists():
        print(f"❌ Test directory not found: {test_dir}")
        return

    input_files = sorted(test_dir.glob("*.in"))
    if not input_files:
        print(f"⚠️ No input files found in {test_dir}")
        return

    print(f"🔍 Running tests for: {problem_name}\n")

    for i, input_file in enumerate(input_files, 1):
        expected_output = input_file.with_suffix(".out")
        my_output = test_dir / f"{input_file.stem}_my.out"

        # Run the Python program
        with open(input_file, "r") as fin, open(my_output, "w") as fout:
            result = subprocess.run(
                ["python", str(problem_file)],
                stdin=fin,
                stdout=fout,
                stderr=subprocess.PIPE,
                text=True
            )

        if result.stderr:
            print(f"⚠️ Test {input_file.name} raised an error:")
            print(result.stderr.strip())

        # Compare output with expected
        if not expected_output.exists():
            print(f"⚠️ Skipping test {i}: missing {expected_output.name}")
            continue

        with open(expected_output, "r") as f:
            expected = f.read().strip()
        with open(my_output, "r") as f:
            got = f.read().strip()

        if expected == got:
            print(f"✅ Test {i} passed")
        else:
            print(f"❌ Test {i} failed")
            print("   ├─ Input file :", input_file.name)
            print("   ├─ Expected  :", repr(expected))
            print("   └─ Got       :", repr(got))
        print()

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 run_tests.py <problem_name>")
    else:
        run_tests(sys.argv[1], sys.argv[2])
